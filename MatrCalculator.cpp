// MatrCalculator.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include"Matriu.h"
using namespace std;


int main()
{
	cout << "Primera matriu:" << endl;
	cout << "Entra les dimensions:" << endl;
	int r1, c1;
	cin >> r1>>c1;
	Matriu mat1(r1, c1);
	cout << "Entra els valors de la matriu:" << endl;
	mat1.read_mat();
	cout << "Introdueix operació [+-*]:" << endl;
	char op;
	cin >> op;
	cout << "Segona matriu:" << endl;
	cout << "Entra les dimensions:" << endl;
	int r2, c2;
	cin >> r2 >> c2;
	Matriu mat2(r2, c2);
	Matriu resultat(c2, r2);
	cout << "Entra els valors de la matriu:" << endl;
	mat2.read_mat();
		char ope;
		if (op == '*') {
			ope = '*';
		}
		else if (op == '+') {
			ope = '+';
		}
		else {
			ope = '-';
		}
		////////////////

		switch (ope)
		{
		case '-':
			if (c1 == c2 && r1 == r2) {
				resultat = mat1 - mat2;
				cout << "El resultat de l'operació és:" << endl;
				resultat.show_mat();
			}
			else {
				cout << "Les dimensions de les matrius no són vàlides" << endl;
			}
			break;
		case '*':
			if (c1 == r2) {
				resultat = mat1 * mat2;
				cout << "El resultat de l'operació és:" << endl;
				resultat.show_mat();
			}
			else {
				cout << "Les dimensions de les matrius no són vàlides" << endl;
			}
			break;
		case '+':
			if (c1 == c2 && r1 == r2) {
				resultat = mat1 + mat2;
				cout << "El resultat de l'operació és:" << endl;
				resultat.show_mat();
			}
			else {
				cout << "Les dimensions de les matrius no són vàlides" << endl;
			}
			break;
		default:
			cout << "not valid opcion" << endl;

			break;
		}
	
    return 0;
}

