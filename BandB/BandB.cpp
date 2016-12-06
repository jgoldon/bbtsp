// BandB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BB.h"
#include "Bruteforce.h"
#include "generator.h"


double PCFreq = 0.0;
__int64 licznik = 0;


void start()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "B³¹d!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	licznik = li.QuadPart;
}
double getTime()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	cout << "Operacja zajela: " << (li.QuadPart - licznik) / PCFreq << " milisekund" << endl;
	return double((li.QuadPart - licznik) / PCFreq);
}

int main()
{
	string name;
	int size;
	int n;
	int wybor;
	ifstream file;
	//cout << "Podaj ilosc miast." << endl;
	//Generator test(5);
	do
	{
		cout << "Wybierz operacje:\n";
		cout << "1 - oba algorytmy\n2 - przeglad zupelny\n3 - metoda podzialu i ograniczen\n4 - wygeneruj nowy plik\n5 - wyjscie" << endl << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			cout << "\nPodaj nazwe pliku:\n";
			cin >> name;
			file.open(name);
			file >> size;
			file.close();

			Bruteforce m(size);

			m.name = name;
			m.size = size;
			m.read();
			m.algorithm();
			cout << endl << "********************************************************************************" << endl;
			cout << endl;
			BB b(size);
			b.name = name;
			b.size = size;
			b.read();
			start();
			b.mcost(1);
			cout << "najkrotsza sciezka wg metody podzialu i ograniczen:\n";
			cout << "Dystans: " << b.getCost() << endl << endl;
			cout << "Trasa: " << endl;
			cout << endl << b.path << endl;
			getTime();
			cout << endl << "********************************************************************************" << endl;
			break;
		}
		case 2:
		{
			cout << "\nPodaj nazwe pliku:\n";
			cin >> name;
			file.open(name);
			file >> size;
			file.close();

			Bruteforce s(size);

			s.name = name;
			s.size = size;
			s.read();
			start();
			s.algorithm();
			getTime();
			cout << endl << "********************************************************************************" << endl;
			break;
		}
		case 3:
		{
			cout << "\nPodaj nazwe pliku:\n";
			cin >> name;
			file.open(name);
			file >> size;
			file.close();
			BB z(size);
			z.name = name;
			z.size = size;
			z.read();
			start();
			z.mcost(1);
			cout << "najkrotsza sciezka wg metody podzialu i ograniczen:\n";
			cout << "Dystans: " << z.getCost() << endl << endl;
			cout << "Trasa: " << endl;
			cout << endl << z.path << endl;
			getTime();
			cout << endl << "********************************************************************************" << endl;
			break;
		}
		case 4:
		{
			cout << "Podaj ilosc miast." << endl;
			cin >> n;
			generator test(n);
			break;
		}
		case 5:
			exit(0);
		default:
			break;
		}
	} while (wybor != 5);
	system("pause");
	return 0;
}

