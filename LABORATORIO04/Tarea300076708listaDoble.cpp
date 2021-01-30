// /Escriba un programa que elimine por búsqueda, el nodo anterior al dato de referencia.

#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble(){
            pInicio = NULL;
        }
        ~ListaDoble(){
            nodo *aux;
            while(pInicio){
                aux = pInicio;
                pInicio = pInicio->sig;
                delete aux;
            }
        }
        void insertarFinal(int);
        void mostrarLista();
        void eliminarElemento(int);
        void eliminarElementoAnteriorA(int);

};

void ListaDoble::insertarFinal(int dato){
    nodo *n = new nodo;
    n->dato = dato;
    n->sig = NULL;
    if(!pInicio){
        pInicio = n;
        pInicio->ant = NULL;
    }
    else{
        nodo *s = pInicio;
        while(s->sig)
            s = s->sig;
        s->sig = n;
        n->ant = s;
    }
}

void ListaDoble::mostrarLista(){
    nodo *aux = pInicio;
    cout << "Recorriento con sig:" << endl;
    while(aux->sig){
        cout << aux->dato << ' ';
        aux = aux->sig;
    }
    cout << aux->dato;

    cout << endl;
    cout << "Recorriento con ant:" << endl;
    while(aux->ant){
        cout << aux->dato << ' ';
        aux = aux->ant;
    }
    cout << aux->dato;
    cout << endl << endl;
}

void ListaDoble::eliminarElemento(int datoRef){
    if(!pInicio){ //no hay datos
        return;
    }
    else{
        nodo *s = pInicio, *p;

        if(s->dato == datoRef){ //se borra el primero
            pInicio = pInicio->sig;
            pInicio->ant = NULL;
            delete s;
        }
        else{
            while(s->sig && s->sig->dato != datoRef){
                s = s->sig; //s se detiene un nodo antes del q se borrara
            }
            if(!s->sig){ // no lo encuentra
                return;
            }
            else{
                if(!s->sig->sig){ // borrar el ultimo
                    p = s->sig;
                    s->sig = NULL;
                    delete p;
                }
                else{ // borrar en medio
                    p = s->sig;
                    s->sig = s->sig->sig;
                    p->sig->ant = s;
                    delete p;
                }
            }
        }
    }
}

void ListaDoble::eliminarElementoAnteriorA(int datoRef){
    nodo *s;
    s = pInicio;
    while(s && s->dato != datoRef)
        s = s->sig;
    if(!s)
        return;
    else if(s->ant)
        eliminarElemento(s->ant->dato);
}

int main(void){
    cout << endl << endl;

    ListaDoble objLista;
    for(int i = 1; i < 11; i++){
        objLista.insertarFinal(i);
    }

    cout << "Lista Inicial:" << endl;
    objLista.mostrarLista();

    cout << "Eliminar dato anterior al 8:" << endl;
    objLista.eliminarElementoAnteriorA(8);
    objLista.mostrarLista();

    cout << endl;
}
