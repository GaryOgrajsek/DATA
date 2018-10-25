#pragma once
#include<string>
#include <iostream>
using namespace std;

class Data{
	friend istream & operator >> (istream&cin, Data&miaData);
	friend ostream & operator << (ostream&cout, Data miaData);
	friend bool operator ==(Data, Data);
	
	friend void operator +=(Data, int);
	//friend int operator -(Data, Data);

private:
	int giorno, mese, anno;
	bool vaBeneInput(int, int);

public:
	Data();
	Data(int, int, int);
	Data(int);
	int contaGiorni();
	string toString();
	bool isBisestile();
	int isMax();
	void operator ++();
	~Data();
};

