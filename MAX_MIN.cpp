#include <iostream>
using namespace std;
//zajdowanie wartosci najwi�kszej i najmniejszej z podanego zbioru
int main()
{
	int elementy;
	cout << "Podaj liczb� element�w do por�wnania: "; 
	cin >> elementy;
	int table[elementy];
	for (int i=0; i<elementy; i++)
	{
		cout << "Podaj liczb�: ";
		cin >> table[i];
	};
    int Max = table[0];
    int Min = table[0];
    
	for (int i=1; i<elementy; i++)
	{
		if(table[i]>Max) Max=table[i];
		if(table[i]<Min) Min=table[i];
	}
	cout << "Najwi�ksza liczba sposrod podanych to: " << Max << endl;
	cout << "Najmniejsza liczba sposrod podanych to: " << Min << endl;
	
	return 0;
}
