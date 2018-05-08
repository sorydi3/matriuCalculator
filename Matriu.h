#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

class Matriu

{
public:
	Matriu();
	Matriu(int   nf, int nc);
	Matriu(const Matriu &t);
	Matriu &operator=(const Matriu &t);
	Matriu operator+(const Matriu&o);
	Matriu operator-(const Matriu &t);
	Matriu operator*(const Matriu &t);
	int obtNR()const;
	int obtNC()const;
	void read_mat();
	void show_mat() const;
	~Matriu();
private:
	int **_mat;
	int  _r;
	int  _c;
	void reservar();
	void free();
	void copy(const Matriu& o);
};


