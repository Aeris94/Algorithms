#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
/*Napisz funkcj� dzielNaCyfry wyodr�bniaj�c� z danej liczby ca�kowitej jej kolejne cyfry i zapisuj�c� te cyfry w tablicy liczb 
ca�kowitych TC w kolejno�ci ich wyodr�bnienia. Nast�pnie napisz funkcje, kt�re wykorzystuj� cyfry zapisane w tablicy TC do sprawdzenia: 
a) czy cyfry liczby tworz� palindrom, 
b) czy liczba zawiera okreslona ilosc cyfr, kt�re tworz� palindrom.*/
const int MAX_C = 9;
int dziel_na_cyfry(long int, int[]);
void pokaz_cyfry(int, int[]);
bool palindrom(int[], int, int);
bool palindrom_dlugosc(int[], int, int);

int main()
{
	long int liczba;
	int TC[MAX_C];
	cout << "Podaj liczb� ca�kowit� maxymalnej liczbie cyfr 9: ";
	cin >> liczba;
	int n= dziel_na_cyfry(liczba, TC);
	cout << "Podana liczba sk�ada si� z nastepuj�cych cyfr: " << endl;
	pokaz_cyfry(n, TC);
	if(palindrom(TC, 0, n-1))
		cout << "Cyfry podanej liczby tworza palindrom." << endl;
	else 
		cout << "Cyfry podanej liczby nie tworz� palindromu." << endl;
	int dlugosc;
	cout << "Podaj d�ugosc sekwencji palidromowych jakie chcesz znalezc: ";
	cin >> dlugosc;
	if(palindrom_dlugosc(TC, n, dlugosc))
		cout << "Liczba zawiera sekwencje palindromowe o d�ugodci " << dlugosc;
	else 
		cout << "Liczba nie zawiera sekwencji palindromowych o d�ugosci " << dlugosc;				
	return 0;
}
int dziel_na_cyfry(long int liczba, int TC[]) 
{
	int ile_cyfr;
	while(liczba > 0)
	{
		TC[ile_cyfr++] = liczba%10;           
		liczba = liczba/10;
	}
	return ile_cyfr;
}
void pokaz_cyfry(int n, int TC[])
{
	for(int i=n-1; i>=0; i--)
		cout << setw(4) << TC[i];
	cout << endl;	
}
bool palindrom( int TC[], int pocz, int kon )    
{    
	for( int i = 0; i < (kon-pocz+1)/2; i++)  
     	if( TC[pocz+i] != TC[kon-i] ) 
		 	return false;   
	 return true; 
} 
bool palindrom_dlugosc(int TC[], int n, int dlugosc )   
{   
	 for( int i = 0; i < n-dlugosc+1; i++ )     
		 if( palindrom( TC, i, i+dlugosc-1 )) 
		 	return true;   
	 return false; 
} 
