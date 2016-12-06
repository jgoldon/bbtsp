#pragma once
class BB
{
	int** paths;
	int cost;
	int mincity(int n);
public:
	BB(int n);
	~BB();
	int getCost();
	void read();
	void mcost(int n);
	bool* route;
	string name;
	string path;
	int size;
};

