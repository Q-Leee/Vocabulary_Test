#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Word.h"

using namespace std;

int main() {

	vector<Word> v;

	v.push_back(Word("human", "person"));
	v.push_back(Word("baby", "infant"));
	v.push_back(Word("society", "civilization"));
	v.push_back(Word("photo", "picture"));
	v.push_back(Word("painting", "canvas"));
	v.push_back(Word("love", "affection"));
	v.push_back(Word("emotion", "sentiment"));
	v.push_back(Word("doll", "marionette"));
	v.push_back(Word("happy", "joyful"));
	v.push_back(Word("sad", "sorrowful"));
	v.push_back(Word("slow", "sluggish"));
	v.push_back(Word("small", "tiny"));
	v.push_back(Word("strong", "powerful"));
	v.push_back(Word("smart", "intelligent"));

	int number = 0;
	int choice = 0;

	cout << "***** Start vocabulary test *****" << endl;
	srand(time(NULL));

	while (true)
	{
		cout << "Insert word : 1, Test : 2, Exit to press other number >> ";
		cin >> number;

		if (number == 1)
		{

			string eng, syn;
			cout << "Type 'exit' next to English then exit" << endl;

			while (true)
			{
				cout << "English >> ";
				cin >> eng;
				if (eng == "exit")
				{
					break;
				}
				cout << "Synonym? >> ";
				cin >> syn;
				v.push_back(Word(eng, syn));
			}
		}

		else if (number == 2)
		{

			cout << "Test Strating.. (only press 1 to 4 or exit)" << endl;

			while (true)
			{
				int r = rand() % v.size();
				cout << v[r].geteng() << " ? " << endl;

				vector<string> options;   //to store the answer of v[r].geteng() which is v[r].getSyn()
				options.push_back(v[r].getSyn());

				while (options.size() < 4)   //till options.size() = 4, put random synonyms into options vector
				{
					int x = rand() % v.size();
					auto it = find(options.begin(), options.end(), v[x].getSyn());
					if (it == options.end())
					{
						options.push_back(v[x].getSyn());
					}
				}

				random_shuffle(options.begin(), options.end());   //algorithm header, shuffle elements to avoid the same array

				for (int i = 0; i < 4; i++)
				{
					cout << "(" << i + 1 << ")" << options[i] << " ";
				}
				cout << endl;

				cin >> choice;

				if (choice >= 1 && choice <= 4)
				{
					if (options[choice - 1] == v[r].getSyn())   //choice will be 1~4 but index starts from 0
					{
						cout << "Excellent !!" << endl;
					}
					else
					{
						cout << "No !!" << endl;
					}
				}
				else
				{
					cout << "Invalid choice. Exiting test..." << endl;
					break;
				}
			}
		}

		else
		{
			cout << "Exit.." << endl;
			break;
		}
	}

	return 0;
}
