#include <iostream>
using namespace std;

#include "data.h"


char Menu();

char Menu()
{
	char scelta;
	cout << "-----------------Menu----------------\n";
	cout << "1: Visualizza date\n";
	cout << "2: Confronta due date\n";
	cout << "3: Visualizza il giorno successivo\n";
	cout << "4: Somma giorni\n";
	cout << "5: Differenza tra due date\n";
	cout << "-------------------------------------\n";
	cout << "0: Esci\n";
	cout << "Scelta: ";
	cin >> scelta;
	return scelta;
}

int main()
{
	Data d1(1, 1, 2018), d2;
	int x;
	char scelta;

	cout << "inserisci la seconda data: \n";
	cin >> d2;
	//ripeti...............

	do
	{
		system("cls");
		//menu
		scelta = Menu();
		switch (scelta)
		{
			//esci
		case '0': break;

			//visualizza date
		case '1': cout << "Data 1: " << d1 << "Data 2: " << d2 << endl;
			break;
			//dat1 e d2 sono uguali/diverse
		case '2': if (d1 == d2)
			cout << "data1 e data2 sono uguali\n";
				  else
					  cout << "data1 e data2 sono diverse\n";
			break;
			//d1++
		case '3': cout << "Data 1: " << d1 << endl;
			d1++;
			cout << "giorno successivo: " << d1 << "\n";
			break;
			//somma d1 e x
		case '4': cout << "Numero di giorni da sommare: ";
			cin >> x;
//			d1 += x;
			cout << "Somma: " << d1 << "\n";
			break;

			//differenza tra d1 e d2
		case '5': cout << "Data 1: " << d1 << " Data 2: " << d2 << endl;
//			cout << "Differenza tra le due date: " << d1 - d2 << "\n";
			break;
		case '6': cout << d2.contaGiorni();

			//carattere non valido
		default: cout << "Scelta non valida\n";
		}
		system("pause");
		//...finchè scelta non diventa 0
	} while (scelta != '0');
}