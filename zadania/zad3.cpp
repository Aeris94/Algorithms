#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
/*Dla tablicy dwuwymiarowej A o rozmiarach n × m, wype³nionej liczbami losowymi z przedzia³u [a, b] oblicz iloczyn elementów A[i][j], dla których suma indeksów 
i oraz j  jest parzysta oraz osobno dla tych, których suma indeksów jest nieparzysta. Czy mo¿na obliczyæ obie sumy „przechodz¹c” przez tablicê jednokrotnie?*/
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
	cout << "Podaj liczbê wierszy: ";
	cin >> n;
	cout << "Podaj liczbê kolumn: ";
	cin >> m;
	cout << "Podaj liczbê a dla zakresu[a,b]: ";
	cin >> a;
	cout << "Podaj liczbê b dla zakresu[a,b]: ";
	cin >> b;
	while(b<a)
	{
		cout << "Podaj b wiêksze od a: ";
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
	
	cout << "Iloczyn elementów table[i][j], dla których suma indeksów i oraz j  jest parzysta wynosi: " << iloczyn_parzyste << endl;
	cout << "Iloczyn elementów table[i][j], dla których suma indeksów i oraz j  jest nieparzysta wynosi: " << iloczyn_nieparzyste << endl;
	
	for(int i=0; i<n; i++)
		delete [] table[i];
	delete []table;	
	return 0;
}
