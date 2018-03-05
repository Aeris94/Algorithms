#include <iostream>
#include <cmath>
using namespace std;
/*Napisz program wyznaczaj�cy pierwiastki wielomianu drugiego stopnia. Zwr�� uwag� na typ i argumenty funkcji oblicz(), delta() i czy_kwadratowa() 
podane w ich prototypach i definicjach. Nast�pnie napisz definicje tych funkcji oraz sprawd� poprawno�� dzia�ania ca�ego programu. W funkcji oblicz()wywo�aj
funkcj� delta() s�u��c� do obliczania warto�ci wyr�nika r�wnania kwadratowego (oznaczanego zwykle symbolem delta). */ 
 	
int oblicz_pierwiastki(float, float, float);  
bool czy_kwadratowa(float);          
double delta(float, float, float); 

int main()
{
	 float wsp_a, wsp_b, wsp_c;
	 cout << "Podaj wsp�czynnik a: "; cin >> wsp_a;
	 cout << "Podaj wspo�czynnik b: "; cin >> wsp_b;
	 cout << "Podaj wsp�czynnik c: "; cin >> wsp_c;
	
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
		cout << "R�wanie nie ma pierwiastk�w.";
	double pierwiastek_delta = sqrt(Delta);	
	double x1, x2;
	if(Delta ==0)
	{
		x1 = -b/(2*a);
		cout << "R�wnianie ma 1 pierwiastek: x = " << x1 << "." << endl;
	}
	else 
	{
		x1 = (-b - pierwiastek_delta)/2*a;
		x2 = (-b + pierwiastek_delta)/2*a;
		cout << "R�wnianie ma 2 pierwiastki x1 = " << x1 << ", x2 = " << x2 << "." << endl;
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
