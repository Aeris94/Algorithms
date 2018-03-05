#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
/*Dla tablicy dwuwymiarowej A o rozmiarach n � m, wype�nionej liczbami losowymi z przedzia�u [a, b] oblicz iloczyn element�w A[i][j], dla kt�rych suma indeks�w 
i oraz j  jest parzysta oraz osobno dla tych, kt�rych suma indeks�w jest nieparzysta. Czy mo�na obliczy� obie sumy �przechodz�c� przez tablic� jednokrotnie?*/
void show_array(int **table, int n, int m)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout << setw(4) << table[i][j];
		}
		cout << endl;
	}
}

int main()
{
	int n;
	int m;
	int a;
	int b;
	cout << "Podaj liczb� wierszy: ";
	cin >> n;
	cout << "Podaj liczb� kolumn: ";
	cin >> m;
	cout << "Podaj liczb� a dla zakresu[a,b]: ";
	cin >> a;
	cout << "Podaj liczb� b dla zakresu[a,b]: ";
	cin >> b;
	while(b<a)
	{
		cout << "Podaj b wi�ksze od a: ";
		cin >> b;
	}
	
	int **table = new int *[n];
	for(int i=0; i<n; i++)
		table[i] = new int[m];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			table[i][j] = rand() % (b-a+1) + a;
		}
	}
	show_array(table, n, m);
		
	int iloczyn_parzyste = 1;
	int iloczyn_nieparzyste = 1;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if((i+j)%2==0)
				iloczyn_parzyste = iloczyn_parzyste * table[i][j];
			else 
				iloczyn_nieparzyste = iloczyn_nieparzyste * table[i][j];	
		}
	}
	
	cout << "Iloczyn element�w table[i][j], dla kt�rych suma indeks�w i oraz j  jest parzysta wynosi: " << iloczyn_parzyste << endl;
	cout << "Iloczyn element�w table[i][j], dla kt�rych suma indeks�w i oraz j  jest nieparzysta wynosi: " << iloczyn_nieparzyste << endl;
	
	for(int i=0; i<n; i++)
		delete [] table[i];
	delete []table;	
	return 0;
}
