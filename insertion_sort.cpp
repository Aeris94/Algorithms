#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
//insertion_sort
void sort(int array[], int n); 
void show_array(int array[], int n); //funkcja wyswietlaj¹ca tablicê

int main()
{
	int x;
	cout << "Podaj ilosc elemetów tablcy: ";
	cin >> x;
	int table[x];
	for (int i =0; i<x; i++)
	{
		cout << "Podaj element: ";
		cin >> table[i];
	};
	cout << "Tablica przed sortowaniem: " << endl;
	show_array(table, x);
	sort(table, x);
	cout << endl << "Tablica po sortowaniu: " << endl;
	show_array(table, x);	


	
	return 0;
}
void sort(int array[], int n)
{
	int i=1;
	int temp;
	for (i; i<n; i++)
	{
		temp = array[i]; //element, który bêdzie wstawiony w odpowiednie miejsce tablicy
		int j = i-1;
		while(j>=0 && array[j] > temp)//przesuniêcie elemetów wiekszych od array[i] o index wy¿ej w tablcy;
		{
			array[j+1] = array[j]; 
			j--;		
		}
		array[j+1] = temp; //wstawienie elementu w odpowiednie miejsce
	}	
}
void show_array(int array[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout << array[i] << "  ";
		if((i+1)%10 ==0)
			cout << endl;
	}
}
