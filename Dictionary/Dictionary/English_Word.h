#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class English_Word {
public:
    explicit English_Word(string word, vector<string> translation, English_Word* left = nullptr, English_Word* right = nullptr) :
        word(word), translation(translation), left(left), right(right), counter(0) {}
    void print() const {
        cout << "Word: " << word << endl;
        cout << "Translate: | ";
        for (int i = 0; i < translation.size(); i++) cout << translation[i] << " | ";
        cout << endl; 
    }
    void setWord(string word) { this->word = word; }
    string getWord() const { return word; }
    vector<string> getTranslation() const { return translation; }
    void setTranslation(vector<string> translation) { this->translation = translation; }
    void setCounter(size_t counter) { this->counter = counter; }
    size_t getCounter() const { return counter; }
    English_Word* getLeft() const { return left; }
    void setLeft(English_Word* left) { this->left = left; }
    English_Word* getRight() const { return right; }
    void setRight(English_Word* right) { this->right = right; }
private:
    string word;
    vector<string> translation;
    size_t counter;
    English_Word* left;
    English_Word* right;
};

