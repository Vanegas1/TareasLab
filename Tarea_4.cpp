#include <iostream>
#include <string>

using namespace std;

struct lista{
    string nombre, perfilUsuario;
    int id;
};

lista solicitarLista(void){
    lista usuario;

    cout << "Digite el id: "; cin >> usuario.id; cin.ignore();
    cout << "Digite el nombre: "; getline(cin, usuario.nombre);
    cout << "Digite el perfil del usuario: "; getline(cin, usuario.perfilUsuario);

    return usuario;
}

void mostrarLista(lista usuario){
    cout << "id: " << usuario.id << "." << endl;
    cout << "Nombre: " << usuario.nombre << endl;
    cout << "Perfil de usuario: " << usuario.perfilUsuario<<endl;
    cout << "\n";
}

typedef lista T;

struct nodo{
    T dato;
    nodo *siguiente;
    nodo *anterior;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        ~ListaDoble(void);
        void insertFront(T);
        void traversalForwardDirection(void);
};

int menu(){
    int opcion = 0;

    cout << "1) ingresar un usuario." << endl;
    cout << "2) Mostrar usuarios." << endl;
    cout << "3) Salir." << endl;
    cout << "Opcion: "; cin >> opcion; cin.ignore();
    
    return opcion;
}

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->siguiente;
        delete p;
    }
}

void ListaDoble::insertFront(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->siguiente = pInicio;
    if(pInicio != NULL)
        pInicio->anterior = nuevo;
    pInicio = nuevo;
}



void ListaDoble::traversalForwardDirection(void){
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrarLista(saltarin->dato);
        saltarin = saltarin->siguiente;
    }
}

int main(void)
{
    ListaDoble usuario;
    
    bool continuar = true;
    lista p;
    lista pref;

    do{
        switch(menu())
        {   
            case 1: 
                p = solicitarLista();
                usuario.insertFront(p);
                cout << "Usuario almacenado exitosamente!" << endl;
                break;
            case 2:
                cout << endl << " .:Usuarios:." << endl;
                usuario.traversalForwardDirection();
                break;
            case 3: 
                continuar = false;
                break;
            default: 
                cout << "Opcion invalida." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}