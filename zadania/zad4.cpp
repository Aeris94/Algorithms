#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
/*Napisz program sprawdzający, czy w wektorze liczb całkowitych istnieje para kolejnych elementów podzielnych przez k. 
Wynik zapisz do zmiennej typu logicznego i wykorzystaj ją później do wypisania odpowiedniego komunikatu na standardowym wyjściu. 
Program powinien również wypisać indeksy elementów takiej pary. 
Przykład: k = 3              
    2  7  8  6  9  5  6  3  9 
TAK, istnieje para kolejnych elementów podzielnych przez 3. Są to elementy o indeksach 3 i 4. */ 

int main()
{
	int n;
	cout << "Podaj liczbę elementów tablicy: ";
	cin >> n;
	int *tablica = new int[n];
	for(int i=0; i<n; i++)
	{
		tablica[i] = rand() %10 +1;
	}
	cout << "Wygenerowana tablica: " << endl;
	for(int i=0; i<n; i++)
	{
		cout << setw(4) << tablica[i];
		if((i+1)%10==0)
			cout << endl;
	}
	bool podzielny = false;
	int i=0;
	while(podzielny==false && i<n-1)
	{
		if(tablica[i]%3==0 && tablica[i+1]%3==0)
		{
			podzielny = true;
		}
		i++;
	}
	cout << endl;
	if(podzielny==true) cout << "Istnieje para elementów podzielnych przez 3. Są to elementy o indexach " << i -1<< " i " << i << endl;
	else if(podzielny==false) cout << "Nie ma pary kolejnych elementów podzielnych przez 3." << endl;
		
	delete []tablica;	
	return 0;
}
