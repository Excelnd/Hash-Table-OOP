// HashTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include "hasht.h"

using namespace std;

int main()
{
	hasht Hashy;
	string name = "";

	Hashy.AddItem("Ihs", "Locha");
	Hashy.AddItem("Kim", "Iced Mocha");
	Hashy.AddItem("Emma", "Strawberry Smoothy");
	Hashy.AddItem("Annie", "Hot Chocolate");
	Hashy.AddItem("Sarah", "Passion Tea");
	Hashy.AddItem("Pepper", "Caramel Mocha");
	Hashy.AddItem("Mike", "Chai Tea");
	Hashy.AddItem("Steve", "Apple Cider");
	Hashy.AddItem("Bill", "Root Beer");
	Hashy.AddItem("Marie", "Skinny Latte");
	Hashy.AddItem("Susan", "Water");
	Hashy.AddItem("Joe", "Green Tea");

	Hashy.PrintTable();

	while (name != "exit")
	{
		cout << "Remove";
		cin >> name;
		if (name != "exit")
		{
			Hashy.RemoveItem(name);
		}
	}

	Hashy.PrintTable();

    return 0;
}

