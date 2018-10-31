#pragma once
#include <string>
#include <iostream>
using namespace std;

class Data{
	friend istream & operator >> (istream&cin, Data&miaData);
	friend ostream & operator << (ostream&cout, const Data & miaData); //sennò copiare una classe richiede molto spazio. Ma non modifichi niente poiché è const.
	friend bool operator ==(Data, Data); //friend perché usa due oggetti
	
	friend void operator +=(Data, int); //non necessario il friend amicone <3
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

