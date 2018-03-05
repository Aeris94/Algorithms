#include <iostream>
#include <iomanip> 
using namespace std; 
  
int minIndeks( int tablica[], int a, int b )
{    
	int min = a;     
 	for( int i = a+1; i <= b; i++ ) 
	if( tablica[i] < tablica[min] )  min = i; 
	return min; 
} 
void zamiana( int tablica[], int i, int j )
{     
	int buf = tablica[i];
	tablica[i] = tablica[j];     
	tablica[j] = buf;
} 
void selectionSort( int tablica[], int n )
{     
	for( int p = 0; p < n-1; p++ )         
	zamiana( tablica, p, minIndeks( tablica, p, n-1 )); 
} 
void piszTab( int tablica[], int n ) 
{  
	for( int i = 0; i < n; i++ )      
	cout << setw(6) << tablica[i];   
	cout << endl; 
} 
 
int main()  
{    
	int tablica[] = {0,  3, 2, 1, 5, -3};
	int n = sizeof(tablica)/sizeof(tablica[0]);        
	piszTab( tablica, n );    
	selectionSort( tablica, n );   
	piszTab( tablica, n );    
	return 0; 
} 
