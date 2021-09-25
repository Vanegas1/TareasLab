#include <iostream>
#include <string>
using namespace std;

struct nodo
{
	int carnet, edad;
	string nom, apell, tel, correo;
	nodo *sig;
};

class listaSimple
{
	
private:
	nodo *pInicio;

public:

	listaSimple();
	void agregarEnLista(void);
	void eliminarPersona(void);
	void mostrarPersonas();
	void mostrarPersonas(nodo *p);
};


listaSimple::listaSimple(void)
{
	pInicio = NULL;
}

void listaSimple::agregarEnLista(void)
{
	nodo *nuevo;
	nuevo = new nodo;

	cout<<"\n";
	cout <<"Digite el carnete: "; cin >>nuevo->carnet;
	cout <<"Digite la edad: "; cin >>nuevo->edad;
	cin.clear();
	cin.ignore(1000, '\n');
	cout <<"Digite el nombre: "; getline(cin, nuevo->nom);
	cout <<"Digite el apellido: "; getline(cin, nuevo->apell);
	cout <<"Digite el numero telefonico: "; getline(cin, nuevo->tel);
	cout <<"Digite el correo electronico: "; getline(cin, nuevo->correo);
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

void listaSimple::eliminarPersona(void)
{

	int carnet = 0;
	nodo *uno = pInicio;
	nodo *dos = NULL;
	cout<<"\n";
	cout <<"Digite el carnet que desea eleminar: ";
	cin >> carnet;

	while (uno != NULL && uno->carnet != carnet)
	{
		
		
		dos = uno;
		
		uno = uno->sig;
	}
	
	if (uno == NULL)
	{
		cout <<"La persona indicada no existe"<< endl;
		return;
	}

	
	if (pInicio->carnet == carnet)
	{
		
		pInicio = pInicio->sig;
		
		delete (uno);
		cout <<"La persona ha sido eliminada"<< endl;
		return;
	}

	

	if (dos == NULL)
		uno = uno->sig;
	else
		dos->sig = uno->sig;
	delete (uno);
	cout << "La persona ha sido eliminada"<< endl;
}

void listaSimple::mostrarPersonas()
{

	nodo *uno = pInicio;
	if (!uno)
	{	
		cout<<"\n";
		cout <<"Personas no agregadas"<< endl;
		return;
	}
	else
	{
        cout<<"\n";
		cout <<"Carnet: "<< uno->carnet << endl;
		cout <<"Edad: "<< uno->edad << endl;
		cout <<"Nombre: "<< uno->nom << endl;
		cout <<"Apellido: "<< uno->apell << endl;
		cout <<"Numero de telefono: "<< uno->tel << endl;
		cout <<"Correo electronico: "<< uno->correo << endl<< endl;
		mostrarPersonas(uno->sig);
	}
}

void listaSimple::mostrarPersonas(nodo *uno)
{
	if (!uno)
		return;
	else
	{
        cout<<"\n";
		cout <<"Carnet: "<< uno->carnet << endl;
		cout <<"Edad: "<< uno->edad << endl;
		cout <<"Nombre: "<< uno->nom << endl;
		cout <<"Apellido: "<< uno->apell << endl;
		cout <<"Numero de telefono: "<< uno->tel << endl;
		cout <<"Correo electronico: "<< uno->correo << endl<< endl;
		mostrarPersonas(uno->sig);
	}
}

int main(void)
{
	listaSimple persona;

	int menu = 0;
	do
	{
		cout <<"\n\tMENU:\n\t";
		cout <<"1-Digite persona\n\t";
		cout <<"2-Eliminar persona\n\t";
		cout <<"3-Mostrar personas\n\t";
		cout <<"4-Salir.\n\t";
		cout <<"Opcion: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			persona.agregarEnLista();
			break;
		case 2:
			persona.eliminarPersona();
			break;
		case 3:
			persona.mostrarPersonas();
			break;
		case 4:
			break;
		default:
			cout<<"\n";
			cout << "Opcion incorrecta" << endl;
			break;
			
		}
	} while (menu != 4);

	return 0;
}