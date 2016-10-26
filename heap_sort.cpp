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
	for(int i=1; i<=n; i++)
		cout << setw(4) << *(table + i);
	cout << endl;	
}
void max_heap(int *table, int i, int n)
{
	int index = 2*i;
	int temp;
	temp = table[i];
	while (index <= n)
    {
        if (index < n && table[index+1] > table[index])
            index = index + 1;
        if (temp > table[index])
            break;
        else 
        {
            table[index/2] = table[index];
            index = 2*index;
        }
    }
    table[index/2] = temp;
}

void build_max_heap(int *table, int n)
{
	for(int i = n/2; i >= 1; i--)
    {
        max_heap(table, i, n);
    }
}
void heap_sort(int *table, int n)
{
    for (int i = n; i >= 2; i--)
    {
    	swap(table[i], table[1]);
        max_heap(table, 1, i - 1);
    }		
}

int main()
{
	int n;
	cout << "Podaj liczbê elemetów do posortowania: ";
	cin >> n;
	int *table = new int[n+1];
	for(int i=1; i<=n; i++)
	{
	 	table[i] = rand()%100 + 1;
	}
	cout << "Tablica przed sortowniem: ";
	show_array(table, n);
	
	build_max_heap(table, n);
	heap_sort(table, n);
	
	cout << "Tablica po sortowaniu: ";
	show_array(table, n);
	
	delete []table;
	return 0;
}
