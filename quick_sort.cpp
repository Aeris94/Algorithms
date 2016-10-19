#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
void show_array(int array[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout << setw(4) << array[i];
	}
	cout << endl;
}
int partition(int array[], int p, int r)
{
	int i =p;
	int j =r;
	int temp;
	while(true)
	{
		while(array[j] > array[p])
			j--;
		while(array[i] < array[p])
			i++;	
		if(i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
		else 
			return j;	
	}
}
void quick_sort(int array[], int p, int r)
{
	int k;
	if(p < r)
	{
		k = partition(array, p, r);
		quick_sort(array, p, k);
		quick_sort(array, k+1, r);
	}
}

int main()
{
	int size;
	cout << "Podaj ilosc elementów do posortowania: ";
	cin >> size;
	int *table = new int[size];
	
	for(int i=0; i<size; i++)
	{
		cout << "Podaj liczbê: ";
		cin >> table[i];
	}
	cout << "Tablica przed sortowaniem: " << endl;
	show_array(table, size);
	
	quick_sort(table, 0, size-1);
	
	cout << "Tablica po sortowaniu: " << endl;
	show_array(table, size);
	
	delete [] table;
	
	return 0;
}
