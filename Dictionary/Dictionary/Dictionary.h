#include "English_Word.h"
#include <deque>

class Dictionary {
public:
    Dictionary();
    ~Dictionary();
    void insert(string word, vector<string> translation);
    void printWord(string word) const;
    void clear();
    void AddTranslate(string word, vector<string> translation);
    void ChangeTranslate(string word, vector<string> translation);
    void DeleteTranslate(string word);
    English_Word* find(string word) const;
    void findPopularWords(int count);
    void findNotPopularWords(int count);
private:
    English_Word* root;
    void insert(English_Word* cur, string word, vector<string> translation);
    void clear(English_Word* cur);
    English_Word* find(English_Word* cur, string word) const;
    deque<English_Word*> SortedPopularityWords(English_Word* cur, deque<English_Word*> words);
};

