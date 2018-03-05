#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
/*Napisz program wypisuj¹cy na standardowym wyjœciu tabelkê relacji R, okreœlon¹ na zbiorze {1, 2, ... , n} w nastêpuj¹cy sposób R = { (x, y) | x dzieli y }. 
Tabela powinna byæ zapisana w tablicy dwuwymiarowej a dopiero potem wypisana na standardowe wyjœcie. 
Przyk³ad: Dla relacji R = {(1,1), (1,2), (1,3), (2,2), (3,3)} , tabelka bêdzie mia³a nastêpuj¹c¹ postaæ: 
   1 2 3 
 1 1 1 1 
 2 0 1 0 
 3 0 0 1 
Wartoœæ 1 oznacza, ¿e elementy x i y s¹ w relacji R, natomiast 0, ¿e nie s¹. */

int main()
{
	int n;
	cout << "Podaj liczbê elemnetów tabeli: ";
	cin >> n;
	int *table = new int[n];
	for(int i=0; i<n; i++)
	{
		table[i] = i+1;
		cout << setw(4) << table[i];
    }
    cout << endl << endl;
	int **are_in_relation = new int*[n];
	for(int i=0; i<n; i++)
		are_in_relation[i] = new int[n];
		
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(table[j] % table[i] ==0)
				are_in_relation[i][j] =1;
			else 
				are_in_relation[i][j] =0;				
		}
	}	
	cout << "Tablica relacji pomiêdzy liczbami: " << endl;
	cout << " ";
	for(int i=0; i<n; i++)
		cout << setw(4) << table[i];
	cout << endl << endl;		
	for(int i=0; i<n; i++)
	{
		cout << table[i];
		for(int j=0; j<n; j++)
			cout << setw(4) << are_in_relation[i][j];
		cout << endl << endl;
	}
			
	delete []table;
	for(int i=0; i<n; i++)
		delete []are_in_relation[i];
	delete []are_in_relation;
	return 0;
}
