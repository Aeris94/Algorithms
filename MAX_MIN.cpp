#include <iostream>
using namespace std;
//zajdowanie wartosci najwiêkszej i najmniejszej z podanego zbioru
int main()
{
	int elementy;
	cout << "Podaj liczbê elementów do porównania: "; 
	cin >> elementy;
	int table[elementy];
	for (int i=0; i<elementy; i++)
	{
		cout << "Podaj liczbê: ";
		cin >> table[i];
	};
    int Max = table[0];
    int Min = table[0];
    
	for (int i=1; i<elementy; i++)
	{
		if(table[i]>Max) Max=table[i];
		if(table[i]<Min) Min=table[i];
	}
	cout << "Najwiêksza liczba sposrod podanych to: " << Max << endl;
	cout << "Najmniejsza liczba sposrod podanych to: " << Min << endl;
	
	return 0;
}
