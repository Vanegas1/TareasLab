#include <iostream>
using namespace std;

int main(void){

    int mayor = 0, menor = 0, a = 0, b = 0;
    
    cout <<"\n Por favor ingrese 2 numeros naturales a continuacion" << endl;
    cout <<"\n Ingrese un numero natural: "; cin >> mayor;
    cout <<"\n Ingrese un numero narutal: "; cin >> menor;

    a=mayor/menor;
    b=mayor%menor;

    while (b!=0){

        mayor=menor;
        menor=b;

        if (mayor>menor){

            a=mayor/menor;
            b=mayor%menor;
        }
    }
    
cout <<"\n Resultado del MCD es: " << menor;

return 0;

}