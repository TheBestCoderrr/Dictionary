#include "Dictionary.h"


Dictionary::Dictionary() :root(nullptr) {}

Dictionary::~Dictionary()
{
    clear();
}

void Dictionary::insert(string word, vector<string> translation)
{
    if (root)
        insert(root, word, translation);
    else
        root = new  English_Word(word, translation);
}

void Dictionary::printWord(string word) const
{
    English_Word* find_word = find(root, word);
    if (!find_word) {
        cout << "Word not found" << endl;
        return;
    }
    find_word->print();
    find_word->setCounter(find_word->getCounter() + 1);
}

void Dictionary::clear()
{
    clear(root);
    root = nullptr;
}

English_Word* Dictionary::find(string word) const
{
    deque<English_Word*> words;
    return  find(root, word);
}

deque<English_Word*> Dictionary::SortedPopularityWords(English_Word* cur, deque<English_Word*> words)
{
    if (!cur) return words;
    if (words.empty()) words.push_back(cur);
    else {
        if (cur->getCounter() <= words[0]->getCounter()) words.push_front(cur);
        else if (cur->getCounter() >= words.back()->getCounter()) words.push_back(cur);
        else {
            for (int i = 1; i < words.size(); i++) {
                if (cur->getCounter() <= words[i]->getCounter()) {
                    words.insert(words.begin() + i, cur);
                    break;
                }
            }
        }
    }
    words = SortedPopularityWords(cur->getLeft(), words);
    words = SortedPopularityWords(cur->getRight(), words);
    return words;
}

void Dictionary::findPopularWords(int count)
{   
    deque<English_Word*> words;
    words = SortedPopularityWords(root, words);
    for (int i = 0; i < (count < words.size()? count: words.size()); i++)
        words.at(words.size() - i - 1)->print();
}

void Dictionary::findNotPopularWords(int count)
{
    deque<English_Word*> words;
    words = SortedPopularityWords(root, words);
    for (int i = 0; i < (count < words.size() ? count : words.size()); i++)
        words.at(i)->print();
}

void Dictionary::AddTranslate(string word, vector<string> translation)
{
    English_Word* find_word = find(root, word);
    if (!find_word) {
        cout << "Word not found" << endl;
        return;
    }
    vector<string> temp = find_word->getTranslation();
    for(int i = 0; i < translation.size(); i++)
        temp.push_back(translation[i]);
    find_word->setTranslation(temp);
}

void Dictionary::ChangeTranslate(string word, vector<string> translation)
{
    English_Word* find_word = find(root, word);
    if (!find_word) {
        cout << "Word not found" << endl;
        return;
    }
    find_word->setTranslation(translation);
}

void Dictionary::DeleteTranslate(string word)
{
    English_Word* find_word = find(root, word);
    if (!find_word) {
        cout << "Word not found" << endl;
        return;
    }
    find_word->setTranslation({});
}

void Dictionary::insert(English_Word* cur, string word, vector<string> translation)
{
    if (cur->getWord() == word) throw exception("Can't add 2 identical words");
    if (cur->getWord() < word)
        if (cur->getRight())
            insert(cur->getRight(), word, translation);
        else
            cur->setRight(new  English_Word(word, translation));
    else
        if (cur->getLeft())
            insert(cur->getLeft(), word, translation);
        else
            cur->setLeft(new  English_Word(word, translation));
}

void Dictionary::clear(English_Word* cur)
{
    if (!cur) return;
    clear(cur->getLeft());
    clear(cur->getRight());
    delete cur;
}
English_Word* Dictionary::find(English_Word* cur, string word) const
{
    if (!cur) return nullptr;
    if (cur->getWord() == word) return cur;
    if (cur->getWord() < word) return find(cur->getRight(), word);
    return find(cur->getLeft(), word);
}

