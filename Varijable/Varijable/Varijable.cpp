// Varijable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*
    cout << "Hello World!\n";

	cout << (5 < 3 || (7 / 2) > !(6 == 6)) && !!true || false;

	cout << endl;

	cout << !((!(true && false) && !(true || false)) && (!(false && true) || !(false || true)));
	
	cout << endl;

	cout << !(!(1 > 2 || 3 < 4) && (5 == 6 && 7 <= 8) || 9 >= 0);
		
	cout << endl;
	*/

	string s1 = "welcome";
	string s2 = "w3resource";
	string s3 = "";

	cout << "Velicina stringa s1 je " << s1.size() << endl;
	cout << "Znak na 3 poziciji je: " << s1[3] << endl;
	cout << "Je li string prazan? " << s1.empty() << endl;
	cout << "4 znaka od trece pozicije: " << s1.substr(3, 4);
	cout << "Zamjena: " << s1.replace(3, 4, "went");
	cout << "Dodavanje na kraj: " << s1.append("OOOO");
	cout << "Ubacivanje: " << s1.insert(3, "ubacivanje");
	getline(cin, s3);
	cout << s3 << endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
