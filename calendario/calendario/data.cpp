#include "Data.h"

Data::Data(){}

Data::Data(int g, int m, int a) {
	giorno = g;
	mese = m;
	anno = a;
}

Data::Data(int a) {
	anno = a;
}

bool Data::isBisestile() {
	return (anno % 4 == 0 && (anno % 100 != 0 || anno % 400 == 0));
}

bool Data::vaBeneInput(int day, int month) {
	if ((month > 0 && month < 13) && (day > 0 && day < 32)) {
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day <= 31)
				return true;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day <= 30)
				return true;
		case 2:
			if (isBisestile()) {
				if (day <= 29)
					return true;
			}
			else if (day <= 28) {
				return true;
			}
			break;
		}
	}
	return false;
}

istream & operator>>(istream & cin, Data & miaData) {
	do {
		cout << "Giorno: ";
		cin >> miaData.giorno;
		cout << "Mese: ";
		cin >> miaData.mese;
	} while (!(miaData.vaBeneInput(miaData.giorno, miaData.mese)));
	cout << "Anno: ";
	cin >> miaData.anno;
	return cin;
}

ostream & operator <<(ostream & cout, Data miaData) {
	string tmp;
	cout << miaData.toString();
	return cout;
}

bool operator ==(Data d1, Data d2) {
	return (d1.toString() == d2.toString());
}

int Data::isMax() {
	if (giorno == 31 && mese == 31) {
		return 1;
	}else {
		switch (mese) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (giorno == 31)
				return 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (giorno == 30)
				return 30;
			break;
		case 2:
			if ((isBisestile() && giorno == 29) || (!isBisestile() && giorno == 28))
				return 28;
			break;
		}
	}
	return 3;
}

void Data::operator ++() {
	switch (isMax()) {
	case 1:
		giorno = mese = 1;
		break;
	case 30:
	case 31:
	case 28:
		giorno = 1;
		mese++;
		break;
	case 3:
		giorno++;
	}
}

void operator +=(Data d, int x) {
	switch (d.isMax()) {
	case 1:
		d.mese = 1;
		d.giorno = x;
		break;
	case 30:
	case 31:
	case 28:
		d.mese++;
		d.giorno = x;
		break;
	case 3:
		d.giorno += x;
		if (d.isMax() != 3) {
			d.giorno -= d.isMax();
		}
	}
}

int Data::contaGiorni() {
	int numero;
	switch (mese) {
	case 1:
		numero = giorno;
		break;
	case 2:
		numero = 31 + giorno;
		break;
	case 3:
		numero = 59 + giorno;
		break;
	case 4:
		numero = 90 + giorno;
		break;
	case 5:
		numero = 120 + giorno;
		break;
	case 6:
		numero = 151 + giorno;
		break;
	case 7:
		numero = 181 + giorno;
		break;
	case 8:
		numero = 212 + giorno;
		break;
	case 9:
		numero = 243 + giorno;
		break;
	case 10:
		numero = 273 + giorno;
		break;
	case 11:
		numero = 304 + giorno;
		break;
	case 12:
		numero = 334 + giorno;
		break;
	}
	if (isBisestile())
		numero++;
	return numero;
}


string Data::toString() {
	string tmp = to_string(giorno) + "/" + to_string(mese);
	tmp+= "/" + to_string(anno);
	return tmp;
}


Data::~Data(){}
