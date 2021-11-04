#include <iostream>
#include <string>

using namespace std;

struct nodo{
    int id, edad, peso;
    string nombre, razaPerro;
    nodo *siguiente;
};

class listaCircular{

private:
    nodo *pInicio;

public:

    listaCircular();
    void ingresarDatos(void);
    void buscarDatos();
    void eliminarDatos(void);
};

listaCircular::listaCircular(){
    pInicio = NULL;
}

void listaCircular::ingresarDatos(void){
    nodo *dato;
	dato = new nodo;

    cout<<"id: "; 
	cin>>dato->id;
    cin.ignore();
    cout<<"Digite el nombre del dueno: "; 
	getline(cin, dato->nombre);
    cout<<"Digite la raza de la mascota: "; 
	getline(cin, dato->razaPerro);
    cout<<"Digite el peso de la mascota: "<<"lb "; 
	cin>>dato->peso;
    cin.ignore();
    cout<<"Digite la edad de la mascota: "<<"anos "; 
	cin>>dato->edad;

	dato->siguiente = NULL;

	if (!pInicio){
		pInicio = dato;
	}
	else{
		nodo *aux = pInicio;
		while (aux->siguiente != NULL)
		aux = aux->siguiente;
		aux->siguiente = dato;
	}
}


void listaCircular::buscarDatos(){	

	nodo *saltarin = new nodo();

    saltarin = pInicio;

    bool encontrado = false;
    int idBuscado = 0;

    cout <<"ID: ";
    cin >>  idBuscado; cout << endl;
    cin.ignore();

    if (pInicio != NULL){
		do{  
			if (saltarin->id == idBuscado){
            cout <<"ID ["<<saltarin->id<<"]"<<endl;
            cout <<"Nombre del duenio: "<<saltarin->nombre<<endl;
            cout <<"Raza de la mascota: "<<saltarin->razaPerro<<endl;
            cout <<"Peso: "<<saltarin->peso<<" lb" <<endl;
            cout <<"Edad: " <<saltarin->edad <<" anos"<<endl;

            encontrado = true;
            }

            saltarin = saltarin->siguiente;

        } while (saltarin != pInicio && encontrado!= true);

        if(!encontrado){
            cout <<"ID no encontrado."<<endl;
        }

        }else{
            cout <<"Lista vacia"<<endl;
        }
}

void listaCircular::eliminarDatos(void){
	int id = 0;
	nodo *p = pInicio;
	nodo *q = NULL;

	cout<<"\nIngrese el ID: "; cin>>id;

    while ((p != NULL) && (p->id != id)){
		q = p;
		p = p->siguiente;
	}
	if (p == NULL){
		cout << "Persona no encontrada" << endl;
		return;
	}

	if (pInicio->id == id){
		pInicio = pInicio->siguiente;

		delete (p);
		cout<<"\tPersona eliminada\n";
		return;
	}

	if (q == NULL)
		p = p->siguiente;
	else
		q->siguiente = p->siguiente;
	delete (p);
	cout<<"\tPersona eliminada\n";
}

void menu(void){

    cout<<"1. Ingresar datos del cliente"<<endl;
    cout<<"2. Eliminar cliente"<<endl;
    cout<<"3. Mostrar clientes"<<endl;
    cout<<"4. Salir"<<endl;
    cout<<"opcion : ";
}

int main(void){
	listaCircular persona;
	int opcion;

    do{
        menu();
        cin>>opcion;
        cin.ignore();
        
        switch(opcion){

            case 1: persona.ingresarDatos();
                    cout<<"\n";
                    break;
            case 2: 
                    persona.eliminarDatos();
                    cout<<"\n";
                    break;
            case 3: 
					cout<<"\t.:Lista de personas:.\n";
                    persona.buscarDatos();
                    cout<<"\n";
                    break;
			case 4: 
					cout<<"Saliendo del programa...."<<endl;
					cout<<"\n";
					return 0;
                    default: 
					cout<<"!!Ingrese un numero valido!!"<<endl;
					cout<<"\n";
                    break;
        }
    }while(opcion != 4);


	return 0;
}