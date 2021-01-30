#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *ant;
    nodo *sig;
};

class ListaSimple{
    private:
        nodo *pInicio;
    public:
        ListaSimple(){
            pInicio = NULL;
        }
        ~ListaSimple(){
            nodo *s;
            while(pInicio){
                s = pInicio;
                pInicio = pInicio->sig;
                delete s;
            }
        }
        void insertarFinal(int);
        void mostrarLista();
        void eliminarElemento(int);
        void eliminarElementoRecurrente(int);
        void mostrarListaPar();
        void mostrarListaImpar();

};

void ListaSimple::insertarFinal(int dato){
    nodo *n = new nodo;
    n->dato = dato;
    n->sig = NULL;
    if(!pInicio){
        pInicio = n;
    }
    else{
        nodo *s = pInicio;
        while(s->sig){
            s = s->sig;
        }
        s->sig = n;
    }
}

void ListaSimple::mostrarLista(){
    nodo *p = pInicio;
    while(p){
        cout << p->dato << ' ';
        p = p->sig;
    }
    cout << endl << endl;
}

void ListaSimple::eliminarElemento(int datoB){
    if(!pInicio)
        return;
    else{
        nodo *s = pInicio, *p;

        if(s->dato == datoB){
            pInicio = pInicio->sig;
            delete s;
        }
        else{
            while(s->sig && s->sig->dato != datoB)
                s = s-> sig;
            if(!s->sig)
                return;
            else{
                p = s->sig;
                s->sig = s->sig->sig;
                delete p;
            }
        }
    }
}

void ListaSimple::eliminarElementoRecurrente(int datoB){
    nodo *p = pInicio;
    while(p){
        if(p->dato == datoB)
            eliminarElemento(datoB);
        p = p->sig;
    }
}

void ListaSimple::mostrarListaPar(){
    nodo *p = pInicio;
    while(p){
        if(p->dato % 2 == 0)
            cout << p->dato << ' ';
        p = p->sig;
    }
    cout << endl << endl;
}

void ListaSimple::mostrarListaImpar(){
    nodo *p = pInicio;
    while(p){
        if(p->dato % 2 != 0)
            cout << p->dato << ' ';
        p = p->sig;
    }
    cout << endl << endl;
}

int main(void){
    cout << endl << endl;

    ListaSimple objLista;

    cout << "1. Eliminar los nodos de la misma recurrencia de un dato." << endl << endl;
    objLista.insertarFinal(3);
    objLista.insertarFinal(5);
    objLista.insertarFinal(3);
    cout << "\tDatos Iniciales:" << endl << "\t";
    objLista.mostrarLista();

    cout << "\tDato recurrente a eliminar: 3" << endl << endl;
    objLista.eliminarElementoRecurrente(3);

    cout << "\tDatos Finales:" << endl << "\t";
    objLista.mostrarLista(); 

    objLista.eliminarElemento(5);

    cout << "2. Mostrar solo los numeros pares de la lista." << endl << endl;
    for(int i=1; i<11; i++)
        objLista.insertarFinal(i);

    cout << "\tDatos Iniciales:" << endl << "\t";
    objLista.mostrarLista();

    cout << "\tDatos Pares:" << endl << "\t";
    objLista.mostrarListaPar();

    cout << "3. Mostrar solo los numeros impares de la lista." << endl << endl;
    
    cout << "\tDatos Iniciales:" << endl << "\t";
    objLista.mostrarLista();

    cout << "\tDatos Pares:" << endl << "\t";
    objLista.mostrarListaImpar();

    cout << endl;
    return 0;
}
