#include "stdafx.h"
#include <iostream>
#include <string>

#include "hasht.h"

using namespace std;


hasht::hasht()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;  
	}
}

void hasht::AddItem(string name, string drink)
{
	int index = Hasht(name);

	if (HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;

	}
	else
	{
		item* ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = n;
	}
}

int hasht::NumberOfItemsInIndex(int index)
{
	int count = 0;

	if (HashTable[index]->name == "empty")
	{
		return count;
	}
	else
	{
		count++;
		item* ptr = HashTable[index];
		while (ptr->next != NULL)
		{
			count++;
			ptr = ptr->next;
		}
	}
	return count;
}

void hasht::PrintTable()
{
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsInIndex(i);
		cout << "------------------\n";
		cout << "index = " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "# of items = " << number << endl;
		cout << "------------------\n";
	}

}

void hasht::PrintItemsInIndex(int index)
{
	item* ptr = HashTable[index];
	if (ptr->name == "empty")
	{
		cout << "index = " << index << " is empty\n";
	}
	else
	{
		cout << "index " << index << " contains the following items\n";

		while (ptr != NULL)
		{
			cout << "------------------\n";
			cout << ptr->name << endl;
			cout << ptr->drink << endl;
			cout << "------------------\n";
			ptr = ptr->next;
		}
	}
}

void hasht::FindDrink(string name)
{
	int index = Hasht(name);
	bool foundName = false;
	string drink;

	item* pointer = HashTable[index];
	while (pointer != NULL)
	{
		if (pointer->name == name)
		{
			foundName = true;
			drink = pointer->drink;
		}
		pointer = pointer->next;
	}
	if (foundName == true)
	{
		cout << "Favorite drink = " << drink << endl;
	}
	else
	{
		cout << name << "'s info was not found in the Hash Table\n";
	}
}

void hasht::RemoveItem(string name)
{
	int index = Hasht(name);

	item* delPtr;
	item* P1;
	item* P2;

	if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
	{
		cout << name << " was not found in the Hash Table\n";
	}
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL)
	{
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";

		cout << name << " was removed from the Hash Table\n";
	}
	else if (HashTable[index]->name == name)
	{
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;

		cout << name << " was removed from the Hash Table\n";
	}
	else
	{
		P1 = HashTable[index]->next;
		P2 = HashTable[index];

		while (P1 != NULL && P1->name != name)
		{
			P2 = P1;
			P1 = P1->next;
		}
		if (P1 == NULL)
		{
			cout << name << " was not found in the Hash Table\n";

		}
		else
		{
			delPtr = P1;
			P1 = P1->next;
			P2->next = P1;

			delete delPtr;
			cout << name << " was remove from the Hash Table";
		}


	}
}


int hasht::Hasht(string key)
{
	int hash = 0;
	int index;

	index = key.length();

	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash + (int)key[i]) * 17;
	}

	index = hash % tableSize;

	return index;
}


hasht::~hasht()
{
}
