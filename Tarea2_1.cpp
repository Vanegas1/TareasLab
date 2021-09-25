#include <iostream>
using namespace std;

void demostracion(int);

int main(void){

   int muestra = 0;

    demostracion(muestra);

    return 0;
}

void demostracion(int dato){

    cout<<"Ingrese a continuacion el numero que desea ver: "; cin>>dato;

    for (int i = 1; i < dato+1; i++){

        cout<<i<<" "<<endl;
    }

    for (int i = dato-1; i >= 1; i--){

        cout<<i<<" "<<endl;
    }
}