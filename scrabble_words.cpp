#include<string>
#include<vector>
#include<iterator>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main(){
	string word;
	unordered_map<string, string> dictionary;
	ifstream dictFile("scrabble_dictionary2.txt");

	while(dictFile){
		dictFile >> word;
		dictionary.emplace(word, word);
	}

	cout << "Enter a word: ";
	cin >> word;

	while (cin){
		int count = 0;
		cout << endl;
		sort(word.begin(), word.end());
		unordered_map<string, string>::const_iterator got;

		do{
			got = dictionary.find(word);
			if (got != dictionary.end()){
				cout << got->second << " is a word." << endl;
				count++;
			}
		} while (next_permutation(word.begin(), word.end()));

		if (count == 0){
			cout << "No words were found given the letters: '" << word << "'" << endl;
		}
		cout << endl;

		cout << "Enter another word or" << endl;
		cout << "press 'q' to quit: ";
		cin >> word;

		if (word == "q"){
			return 0;
		}
	}
}


