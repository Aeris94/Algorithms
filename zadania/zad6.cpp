#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
/*Napisz program sprawdzający czy w tablicy dwuwymiarowej o rozmiarach n × m, gdzie n, m > 2, elementy w każdym z wierszy są uporządkowane
 niemalejąco (zauważ, że wiersz jest uporządkowany, jeżeli nie zawiera pary elementów „burzących” uporządkowanie). Jeżeli są jakieś nieuporządkowane wiersze, 
 to zapisz ich indeksy w wektorze B.  Wyświetl liczbę takich wierszy, wektor B albo komunikat, że wszystkie wiersze są uporządkowane. */
void show_array(int **array, int n, int m)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout << setw(4) << array[i][j];
		cout << endl;
	}
}
void is_sort(int **array, int *wektor, int n, int m)
{
	int liczba_wierszy = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m-1; j++)
		{
			if(array[i][j+1] < array[i][j])
			{
				wektor[liczba_wierszy] = i;
				liczba_wierszy = liczba_wierszy + 1;
				break;
			}	
		}
	}
	if(liczba_wierszy==0)
		cout << "Wszystkie wiersze są uporzadkowane." << endl;
	else 
	{		
		cout << "Liczba nieuporzadkowanych wierszy wynosi: " << liczba_wierszy << endl;
		cout << "Indeksy nieuporządkowanych wierszy to: "; 
		for (int i=0; i<liczba_wierszy; i++)
			cout << setw(4) << wektor[i];
	}
}
int main()
{
	int n;
	int m;
	cout << "Podaj liczbę wierszy w tablicy: ";
	cin >> n;
	cout << "Podaj liczbę kolumn: ";
	cin >> m;
	int **table = new int *[n];
	for(int i=0; i<n; i++)
		table[i] = new int[m];
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			table[i][j] = rand()% 10 +1;
	
	cout << "Wygenerowana tablica: " << endl;
	show_array(table, n, m);
	int *wektor = new int[n];
	is_sort(table, wektor, n, m);
	
	for(int i=0; i<n; i++)
		delete [] table[i];
	delete [] table;
	delete [] wektor;
		
	return 0;
}
