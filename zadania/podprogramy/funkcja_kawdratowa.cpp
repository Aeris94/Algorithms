#include <iostream>
#include <cmath>
using namespace std;
/*Napisz program wyznaczaj¹cy pierwiastki wielomianu drugiego stopnia. Zwróæ uwagê na typ i argumenty funkcji oblicz(), delta() i czy_kwadratowa() 
podane w ich prototypach i definicjach. Nastêpnie napisz definicje tych funkcji oraz sprawdŸ poprawnoœæ dzia³ania ca³ego programu. W funkcji oblicz()wywo³aj
funkcjê delta() s³u¿¹c¹ do obliczania wartoœci wyró¿nika równania kwadratowego (oznaczanego zwykle symbolem delta). */ 
 	
int oblicz_pierwiastki(float, float, float);  
bool czy_kwadratowa(float);          
double delta(float, float, float); 

int main()
{
	 float wsp_a, wsp_b, wsp_c;
	 cout << "Podaj wspó³czynnik a: "; cin >> wsp_a;
	 cout << "Podaj wspo³czynnik b: "; cin >> wsp_b;
	 cout << "Podaj wspó³czynnik c: "; cin >> wsp_c;
	
	 if(czy_kwadratowa(wsp_a))	
	 {
	 	oblicz_pierwiastki(wsp_a, wsp_b, wsp_c);
	 }
	 else 
	 	cout << "Funkcja nie jest kwadratowa." << endl;
			
	
	return 0;
}
int oblicz_pierwiastki(float a, float b, float c)
{
	double Delta = delta(a, b, c);
	if (Delta < 0)
		cout << "Rówanie nie ma pierwiastków.";
	double pierwiastek_delta = sqrt(Delta);	
	double x1, x2;
	if(Delta ==0)
	{
		x1 = -b/(2*a);
		cout << "Równianie ma 1 pierwiastek: x = " << x1 << "." << endl;
	}
	else 
	{
		x1 = (-b - pierwiastek_delta)/2*a;
		x2 = (-b + pierwiastek_delta)/2*a;
		cout << "Równianie ma 2 pierwiastki x1 = " << x1 << ", x2 = " << x2 << "." << endl;
	}
}
bool czy_kwadratowa(float a)
{
	if(a==0) return false;
	else return true;	
}
double delta(float a, float b, float c)
{
	return b*b - 4*a*c;
}
