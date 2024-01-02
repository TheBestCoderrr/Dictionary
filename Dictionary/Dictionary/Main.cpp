#include "Dictionary.h"
#include <Windows.h>

istream& operator>>(istream& in, vector<string> txt) {
	for (int i = 0; i < txt.size(); i++)
		in >> txt[i];
	return in;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Dictionary english;
	size_t user_answer = 1;
	cout << "0 - Exit\n1 - add word\n2 - add translate\n3 - change translate\n4 - delete translate\n5 - print word\n6 - print popular words\n7 - print not popular word" << endl;
	while (user_answer != 0) {
		cout << "Enter num: ";
		cin >> user_answer;
		switch (user_answer) {
		case 0:
			break;
		case 1:
			{
				string word;
				cout << "Enter word: ";
				cin >> word;
				cout << "Enter count translate words: ";
				size_t size;
				cin >> size;
				vector<string> translate(size);
				if (size) {
					cout << "Enter translate: ";
					cin >> translate;
				}
				english.insert(word, translate);
			}
			break;
		case 2:
			{
				string word;
				cout << "Enter word: ";
				cin >> word;
				cout << "Enter count translate words: ";
				size_t size;
				cin >> size;
				vector<string> translate(size);
				if (size) {
					cout << "Enter translate: ";
					cin >> translate;
				}
				english.AddTranslate(word, translate);
			}
			break;
		case 3:
			{
				string word;
				cout << "Enter word: ";
				cin >> word;
				cout << "Enter count translate words: ";
				size_t size;
				cin >> size;
				vector<string> translate(size);
				if (size) {
					cout << "Enter translate: ";
					cin >> translate;
				}
				english.ChangeTranslate(word, translate);
			}
			break;
		case 4:
			{
				string word;
				cout << "Enter word: ";
				cin >> word;
				english.DeleteTranslate(word);
			}
			break;
		case 5:
			{
				string word;
				cout << "Enter word: ";
				cin >> word;
				english.printWord(word);
			}
			break;
		case 6:
			{
				int count;
				cout << "Enter count: ";
				cin >> count;
				english.findPopularWords(count);
			}
			break;
		case 7:
			{
				int count;
				cout << "Enter count: ";
				cin >> count;
				english.findNotPopularWords(count);
			}
			break;
		default:
			cout << "Invalid variant" << endl;
			break;
		}
	}
}