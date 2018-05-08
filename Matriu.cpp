//#include "stdafx.h"
#include "Matriu.h"

Matriu::Matriu()
{
	_r = 2;
	_c = 2;
	reservar();
}

Matriu::Matriu(int  r, int c)
{
	_r = r;
	_c = c;
	reservar();

}
Matriu::Matriu(const Matriu& o)
{
	copy(o);
}
Matriu::~Matriu()
{
	free();
}
void Matriu::free() {
	for (int i = 0; i < _r; i++) {
		delete[]_mat[i];
	}
	delete[]_mat;
}

void Matriu::reservar() {
	_mat = new int*[_r];
	for (int i = 0; i < _r; i++) {
		_mat[i] = new int[_c];
	}
}

Matriu & Matriu::operator=(const Matriu &o) {
	// Pre: --; Post: s’ha assignat sense aliasing la informació de t a l’objecte actual
	if (this != &o) {
		free();
		copy(o);
	}
	return *this;
}
void Matriu::copy(const Matriu& o) {
	//pre: cert
	//post:
	_r = o._r;
	_c = o._c;
	reservar();
	for (int i = 0; i < o._r; i++) {
		for (int j = 0; j < o._c;j++) {
			_mat[i][j] = o._mat[i][j];
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Matriu::obtNR()const {
	return _r;
}
int Matriu::obtNC()const {
	return _c;
}

void Matriu::read_mat(){
//Pre: 0<=n<=N_FIL_MAX, 0<=m<=N_COL_MAX
//Post: mat[0..n-1,0..m-1] conté successivament els enters entrats
	for (int  i = 0; i<_r; i++) {
		//cout << "Entra fila " << i + 1 << " : ";
		for (int  j = 0; j<_c; j++)
		  cin >> _mat[i][j];
	}
}

void Matriu::show_mat()const {
	//Pre: 0<=n<=N_FIL_MAX, 0<=m<=N_COL_MAX
	//Post: s'han mostrat els n*m valors de mat[0..n-1,0..m-1]
	for (int  i = 0; i < _r; i++) {
		for (int j = 0; j < _c; j++)
			cout << " " << _mat[i][j] << " ";
		cout << endl;
	}
}


////////////////////////////mat sum///////////////////////
Matriu Matriu::operator+(const Matriu &o) {
	int **_mat_aux;
	int r = _r;
	int c = _c;
	//estic fen una copia de la matriu
	_mat_aux = new int*[r];
	for (int i = 0; i < r; i++) {
		_mat_aux[i] = new int[c];
	}
	//copian...
	for (int i = 0; i < _r; i++) {
		for (int j = 0; j < _c; j++) {
			_mat_aux[i][j] = _mat[i][j];
		}
	}

	for (int i = 0; i < _r; i++) {
		for (int j = 0; j < _c; j++) {
			_mat[i][j] = _mat_aux[i][j] + o._mat[i][j];
       	}
	}
	return *this;
}
		
Matriu Matriu::operator-(const Matriu &o) {
	int **_mat_aux;
	int r = _r;
	int c = _c;
	//estic fen una copia de la matriu
	_mat_aux = new int*[r];
	for (int i = 0; i < r; i++) {
		_mat_aux[i] = new int[c];
	}
	//copian...
	for (int i = 0; i < _r; i++) {
		for (int j = 0; j < _c; j++) {
			_mat_aux[i][j] = _mat[i][j];
		}
	}

	for (int i = 0; i < _r; i++) {
		for (int j = 0; j < _c; j++) {
			_mat[i][j] = _mat_aux[i][j] - o._mat[i][j];
		}
	}
	return *this;
}

Matriu Matriu::operator*(const Matriu &o) {
	int **_mat_aux;
	int r = _r;
	int c = _c;
	//estic fen una copia de la matriu
	_mat_aux = new int*[r];
	for (int i = 0; i < r; i++) {
		_mat_aux[i] = new int[c];
	}
	//copian...
	for (int i = 0; i < _r; i++) {
		for (int j = 0; j < _c; j++) {
			_mat_aux[i][j] = _mat[i][j];
		}
	}
	free();
	_r = o._r;
	_c = o._c;
	reservar();
	int p = o._r;
	for (unsigned i = 0; i<_r; i++) {
		for (unsigned j = 0; j<_c; j++) {
			int suma = 0;
			for (unsigned k = 0; k < _r; k++) {
				//cout << _mat_aux[i][k] << " * " << o._mat[k][j] << endl;
				suma =suma+( _mat_aux[i][k] * o._mat[k][j]);
			}
			//cout << suma << "<---suma" << endl;
			//cout << "end first-------------" << endl;
			//cout << "_mat abans-->" << _mat[i][k] << endl;
			_mat[i][j] = suma;
		}
	}
	return *this;
}