#pragma once
#include<string>

using namespace std;

class Word
{
	string syn, eng;
public:
	Word(string e, string k) : eng(e), syn(k) {}
	string getSyn() { return syn; }
	string geteng() { return eng; }
};

