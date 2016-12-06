#pragma once
class Bruteforce
{
	int sums = 0;
	int min = INT_MAX;
	int** paths;
	int* permutations;
public:
	Bruteforce(int n);
	~Bruteforce();
	void permutation(int Value[], int n);
	void read();
	void algorithm();
	string name;
	int size;
};

