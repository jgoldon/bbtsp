#include "stdafx.h"
#include "BB.h"


BB::BB(int n)
{
	path = "1 --- ";
	cost = 0;
	size = n;
	paths = new int*[size];
	for (int i = 1; i <= size; i++)
	{
		paths[i] = new int[size];
	}

	route = new bool[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			route[j] = false;
		}

}


BB::~BB()
{
	//for (int i = 1; i <= size; i++)
	//	delete[] paths[i];
	//delete[] paths;
	//delete[] route;
}

int BB::getCost()
{
	return cost;
}

void BB::read()
{
	ifstream plik;
	plik.open(name);
	plik >> size;
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
		{
			plik >> paths[i][j];
		}

	cout << "Drogi:" << endl;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			cout << setw(6) << paths[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void BB::mcost(int n)
{
	int mcity;
	route[n] = true;
	mcity = mincity(n);
	stringstream temp;
	temp << n + 1;
	temp << " --- ";
	if (mcity == 999)
	{
		mcity = 1;
		temp << mcity;
		path += temp.str();
		cost += paths[n + 1][mcity];
		return;
	}
	path += temp.str();
	mcost(mcity);
}

int BB::mincity(int n) 
{
	int city = 999;
	int min = 999;
	int min2;
	for (int i = 1; i <= size; i++)
	{
		if ((paths[n][i] != 0) && (route[i] == false))
			if (paths[n][i] < min)
			{
				min = paths[i][1] + paths[n][i];
				min2 = paths[n][i];
				city = i;
			}
	}

	if (min != 999)
		cost += min2;
	return city;
}