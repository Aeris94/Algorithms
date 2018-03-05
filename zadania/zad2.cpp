#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
/*Do tablicy dwuwymiarowej A o rozmiarach n × m, wype³nionej liczbami losowymi z przedzia³u [10, 20] dodaj kolumnê jedynek przed kolumn¹ o 
indeksie k. Kolumny o wy¿szych indeksach przesuñ w prawo z jednoczesnym usuniêciem kolumny ostatniej. Pamiêtaj o w³aœciwej kolejnoœci 
poszczególnych operacji. */
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
void swap(int **table, int n, int m, int kol)
{
	for(int j=m-1; j>kol; j--)
	{
		for (int i=0; i<n; i++)
		{
			table[i][j] = table[i][j-1];
		}
	}	
	for (int i=0 ; i<n; i++)
	{
		table[i][kol+1] = 1; 
	}
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
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			table[i][j] = rand() %10 + 10;
		}
	}
	show_array(table, n, m);
	int kol;
	cout << "Podaj index kolumny: ";
	cin >> kol;
	while (kol<0 || kol>m-1)
	{
		cout << "Nie ma takiej kolumny!" << endl;
		cout << "Podaj index kolumny: ";
		cin >> kol;
	}
	swap(table, n, m, kol);
	show_array(table, n, m);

	for(int i=0; i<n; i++)
		delete [] table[i];
	delete []table;		
	return 0;
}
