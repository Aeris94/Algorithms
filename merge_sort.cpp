#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
void show_array(int *array, int n)
{
	for(int i=0; i<n; i++)
		cout << setw(4) << *(array +i);
	
	cout << endl;
}
void merge(int *array, int begin, int middle, int end)
{
    int i;
    int j;
    int k;
    int n1 = middle - begin + 1;
    int n2 =  end - middle;
    int Left[n1];
	int Right[n2];
 
    for (i = 0; i < n1; i++)
        Left[i] = array[begin + i];
    for (j = 0; j < n2; j++)
        Right[j] = array[middle + 1+ j];
  
	i =0;
    j =0;
    k = begin;  
   
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            array[k] = Left[i];
            i++;
        }
        else
        {
            array[k] = Right[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        array[k] = Left[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        array[k] = Right[j];
        j++;
        k++;
    }
}
 
void mergeSort(int *array, int begin, int end)
{
    if (begin < end)
    {
        int middle = (begin+end)/2;
        mergeSort(array, begin, middle);
        mergeSort(array, middle+1, end);
        merge(array, begin, middle, end);
    }
}
int main()
{
    int n;
    cout << "Podaj liczbê elementów do posortowania: ";
    cin >> n;
    int *array = new int[n];
    for(int i=0; i<n; i++)
    	*(array +i) = rand()%100 +1;
    cout << "Tablica przed sortowaniem: " << endl;
	
	
	clock_t s, f;
	double czas=0;
	s = clock();

	mergeSort(array, 0, n-1);	
	

    

	
	f = clock();
	czas = (double)(f - s) / (double)(CLOCKS_PER_SEC);
	cout << "Funkcja wykonywa³a siê: " << czas << endl << endl;	
    
	delete []array;
    return 0;
}
