#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void show_array(int *table, int n)
{
	for(int i=0; i<n; i++)
		cout << setw(4) << *(table + i);
	cout << endl;	
}
void build_max_heap(int *table, int n)
{
	int index;
	for(int i=n-1; i>=1; i--)
	{
		if(i%2==0)
			index = i/2 -1;
		else 
			index = i/2;
		if(table[i] > table[index])
			swap(table[i], table[index]);
	}
}
void heap_sort(int *table, int n)
{
	build_max_heap(table, n);
	swap(table[n-1], table[0]);
	if(n>1)
		heap_sort(table, n-1);	
}

int main()
{
	int n;
	cout << "Podaj liczbê elemetów do posortowania: ";
	cin >> n;
	int *table = new int[n];
	for(int i=0; i<n; i++)
	{
	 	table[i] = rand()%100 + 1;
	}
	cout << "Tablica przed sortowniem: ";
	show_array(table, n);
	heap_sort(table, n);
	cout << "Tablica po sortowaniu: ";
	show_array(table, n);
	
	delete []table;
	return 0;
}
