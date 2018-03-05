#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
/*Napisz program sprawdzajšcy czy w tablicy dwuwymiarowej o rozmiarach n × m, gdzie n, m > 2, istnieje podtablica o rozmiarach 3 × 3 i
 sumie elementów mniejszej od k.*/  
 
int main()
{
	int n;
	int m;
	cout << "Podaj liczbę wierszy i kolumn w tablcy: ";
	cin >> n >> m;
	while(n<3 || m<3)
	{
		cout << "Błedne dane!! Podaj liczbę wierszy i kolumn większš od 2: ";
		cin >> n;
		cin >> m;
	}
	int **table = new int *[n];
	for(int i=0; i<n; i++)
		table[i] = new int[m];

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			table[i][j] = rand()%100 +1;
		
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout << setw(4) << table[i][j];
		cout << endl;
	}
	
	int suma = 0;
	int k;
	cout << "Podaj liczbę: ";
	cin >> k;
	int i=0;
	int j=0;
	for(;i<n-2; i++)
	{
		for(; j<m-2; j++)
		{
			suma = table[i][j] + table[i][j+1] + table[i][j+2] +
			       table[i+1][j] + table[i+1][j+1] + table[i+1][j+2] +
			       table[i+2][j] + table[i+2][j+2] + table[i+2][j+2];
			if(suma <k )
			{
				cout << "W tablicy istnieje podtablica 3x3 o sumie elementów mniejszych od " << k << endl;
				cout << "Pierwszy element tej tablicy ma index: [" << i << "," << j << "]." << endl;
				break;			
			}
				   	
		}
		if(suma <k)
			break;
	}
	if(suma >=k)
		cout << "W tablicy nie istnieje podtablica 3x3 o sumie elementów mniejszych od " << k << endl;
		
	for(int i=0; i<n; i++)
		delete [] table[i];
	delete table;			
	return 0;
}
