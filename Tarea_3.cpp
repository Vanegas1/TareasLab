#include <iostream>
#include <string>
using namespace std;

struct nodo
{
	int pupusas;
	string tipoPupas, bebida, ingredientes;
	nodo *sig;
};

class listaSimple
{
	
private:
	nodo *pInicio;

public:

	listaSimple();
	void agregarOrdenDePupusas(void);
	void mostrarOrdenDePupusas(void);
	void mostrarOrdenDePupusas(nodo *p);
};


listaSimple::listaSimple(void)
{
	pInicio = NULL;
}

void listaSimple::agregarOrdenDePupusas(void)
{
	nodo *nuevo;
	nuevo = new nodo;

	cout<<"\n";
	cout <<"Digite la cantidad de pupusas: "; cin >>nuevo->pupusas;
	cin.ignore(1000, '\n');
	cout <<"Digite el tipo de pupusa (arroz o maiz): "; getline(cin, nuevo->tipoPupas);
	cout <<"CocaCola, si o no: "; getline(cin, nuevo->bebida);
	cout <<"Ingrediente de las pupusas: "; getline(cin, nuevo->ingredientes);

	nuevo->sig = NULL;
	
	if (!pInicio)
	{
		pInicio = nuevo;
	}
	else
	{
	
		nodo *aux = pInicio;
		
		while (aux->sig != NULL)
			aux = aux->sig;
		
		aux->sig = nuevo;
	}
}

void listaSimple::mostrarOrdenDePupusas()
{

	nodo *uno = pInicio;
	if (!uno)
	{	
		cout<<"\n";
		cout <<"Orden no agregada"<< endl;
		return;
	}
	else
	{
        cout<<"\n";
		cout <<"Pupusas: "<< uno->pupusas<< endl;
		cout <<"Tipo de pupusas: "<< uno->tipoPupas << endl;
		cout <<"Con CocaCola: "<< uno->bebida << endl;
		cout <<"Tipo de ingredientes: "<< uno->ingredientes << endl;
		mostrarOrdenDePupusas(uno->sig);
	}
}

void listaSimple::mostrarOrdenDePupusas(nodo *uno)
{
	if (!uno)
		return;
	else
	{
        cout<<"\n";
		cout <<"Pupusas: "<< uno->pupusas<< endl;
		cout <<"Tipo de pupusas: "<< uno->tipoPupas << endl;
		cout <<"Con CocaCola: "<< uno->bebida << endl;
		cout <<"Tipo de ingredientes: "<< uno->ingredientes << endl;
		mostrarOrdenDePupusas(uno->sig);
	}
}

int main(void)
{
	listaSimple ordenPupas;

	int menu = 0;
	do
	{
		cout <<"\n\tMENU:\n\t";
		cout <<"1-Ingresar la orden de pupusas\n\t";
		cout <<"2-Mostrar la orden de pupusas\n\t";
		cout <<"3-Salir.\n\t";
		cout <<"Opcion: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			ordenPupas.agregarOrdenDePupusas();
			break;
		case 2:
			ordenPupas.mostrarOrdenDePupusas();
			break;
		case 3:
			break;
		default:
			cout<<"\n";
			cout << "Opcion incorrecta" << endl;
			break;
			
		}
	} while (menu != 3);

	return 0;
}