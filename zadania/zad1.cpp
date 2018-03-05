#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;
/*Z tablicy dwuwymiarowej o rozmiarach n × m, wype³nionej liczbami losowymi z przedzia³u [1, 10], usuñ wiersz o zadanym indeksie z jednoczesn¹
 kompresj¹ tablicy (przesuniêciem do góry wszystkich wierszy le¿¹cych poni¿ej).*/ 
void show_array(int **table, int n, int m)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout << setw(4) << table[i][j];	
		cout << endl;
	}
}
void delete_row(int **table, int n, int m, int wiersz)
{
	for(int i = wiersz; i<n-1; i++)
		for(int j=0; j<m; j++)
			table[i][j] = table[i+1][j];
	delete [] table[n-1];
}
int main()
{
	int n;
	int m;
	cout << "Podaj liczbê wierszy: ";
	cin >> n;
	cout << "Podaj liczbê kolumn: ";
	cin >> m;
	int **table = new int *[n];
	for(int i=0; i<n; i++)
		table[i] = new int[m];
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			table[i][j] = rand() % 10 +1;
		
	cout << "Wygenerowana tablica: " << endl;
	show_array(table, n, m);	
	
	int wiersz;
	cout << "Podaj index wiersza, który chcesz usun¹æ z tablicy: ";
	cin >> wiersz;
	while(wiersz<0 || wiersz>n-1)
	{
		cout << "Nie ma takiego wiersza!!" << endl;
		cout << "Podaj numer wiersza: ";
		cin >> wiersz;	
	}
	delete_row(table, n, m, wiersz);
	cout << "Tablica po usuniêciu wiersza: " << endl;
	show_array(table, n-1, m);   
	
	for(int i=0; i<n-1; i++)
		delete [] table[i];
	delete [] table;
	return 0;
}
