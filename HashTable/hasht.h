
#include "stdafx.h"
#include <iostream>
#include <string>
#pragma once
using namespace std;

class hasht
{
private:
	static const int tableSize = 4;

	struct item {
		string name;
		string drink;
		item* next;
	};

	item* HashTable[tableSize];

public:
	hasht();
	int Hasht(string key);
	void AddItem(string name, string drink);
	int NumberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void FindDrink(string name);
	void RemoveItem(string name);

	~hasht();
};

