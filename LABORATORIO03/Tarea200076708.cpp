#include <iostream>
using namespace std;

struct estructEstudiante{
    string nombre, nivel;
    int carnet, horas;
};

struct nodo{
    estructEstudiante dataEst;
    nodo *sig;
};

class claseEstudiante{
    private:
        nodo *pInicioPila;
        nodo *pInicioCola;
        void insertarInicioPrivada(estructEstudiante);
        void insertarFinPrivada(estructEstudiante);
    public:
        claseEstudiante(){
            pInicioPila = NULL;
            pInicioCola = NULL;
        }
        ~claseEstudiante(){
            nodo *aux;
            while(pInicioPila){
                aux = pInicioPila;
                pInicioPila = pInicioPila->sig;
                delete aux;
            }
            while(pInicioCola){
                aux = pInicioCola;
                pInicioCola = pInicioCola->sig;
                delete aux;
            }
        }
        void insertarInicioPublica();
        void mostrarDatosPila();
        void busquedaCarnet(int);
        void insertarFinPublica();
        void mostrarDatosCola();
};

void claseEstudiante::insertarInicioPrivada(estructEstudiante dataEst){
    nodo *n = new nodo;
    n->dataEst = dataEst;
    n->sig = pInicioPila;
    pInicioPila = n;
}

void claseEstudiante::insertarInicioPublica(){
    int masDatos = 0;
    do{
        estructEstudiante dataEst;

        cout << "\nNombre completo: ";
        getline(cin, dataEst.nombre, '\n');

        cout << "Carnet: ";
        cin >> dataEst.carnet;
        cin.clear(); cin.ignore(1000, '\n');

        cout << "Nivel de carrera: ";
        getline(cin, dataEst.nivel, '\n');

        cout << "Horas Sociales: ";
        cin >> dataEst.horas;
        cin.clear(); cin.ignore(1000, '\n');

        insertarInicioPrivada(dataEst);

        cout << "\nDesea ingresar mas datos? (1 = Si, 0 = No): ";
        cin >> masDatos;
        cin.clear(); cin.ignore(1000, '\n');

        cout << endl;
    }while(masDatos != 0);
}

void claseEstudiante::mostrarDatosPila(){
    nodo *aux = pInicioPila;
    while(aux){
        cout << "Nombre: " << aux->dataEst.nombre << endl;
        cout << "Carnet: " << aux->dataEst.carnet << endl;
        cout << "Nivel de carrera: " << aux->dataEst.nivel << endl;
        cout << "Horas Sociales: " << aux->dataEst.horas << endl;
        cout << endl;
        aux = aux->sig;
    }
}

void claseEstudiante::busquedaCarnet(int idBuscar){
    nodo *aux = pInicioPila;
    bool encontrado = false;
    while(aux){
        if(aux->dataEst.carnet == idBuscar){
            encontrado = true;
            cout << "Nombre: " << aux->dataEst.nombre << endl;
            cout << "Carnet: " << aux->dataEst.carnet << endl;
            cout << "Nivel de carrera: " << aux->dataEst.nivel << endl;
            cout << "Horas Sociales: " << aux->dataEst.horas << endl;
            cout << endl;
        }
        aux = aux->sig;
    }
    if(encontrado == false){
        cout << "Alumno no encontrado." << endl;
    }
}

void claseEstudiante::insertarFinPublica(){
    int masDatos = 0;
    do{
        estructEstudiante dataEst;

        cout << "\nNombre: ";
        getline(cin, dataEst.nombre, '\n');

        insertarFinPrivada(dataEst);

        cout << "\nDesea ingresar mas datos? (1 = Si, 0 = No): ";
        cin >> masDatos;
        cin.clear(); cin.ignore(1000, '\n');

        cout << endl;
    }while(masDatos != 0);
}

void claseEstudiante::insertarFinPrivada(estructEstudiante dataEst){
    nodo *n = new nodo;
    n->dataEst = dataEst;
    n->sig = NULL;
    if(!pInicioCola){
        pInicioCola = n;
    }
    else{
        nodo *s = pInicioCola;
        while(s->sig){
            s = s->sig;
        }
        s->sig = n;
    }
}

void claseEstudiante::mostrarDatosCola(){
    nodo *aux = pInicioCola;
    while(aux){
        cout << "Nombre: " << aux->dataEst.nombre << endl;
        cout << endl;
        aux = aux->sig;
    }
}

int main(void){
    cout << endl << endl;
    
    claseEstudiante varEstudiante;
    int opcion = 0, idBuscar = 0;

    do{
        cout << "\n\tUCA REGISTRO DE ESTUDIANTES" << endl;
        cout << "1. Ingresar un nuevo estudiante (pila)." << endl;
        cout << "2. Buscar estudiante por carnet." << endl;
        cout << "3. Mostrar todos los estudiantes." << endl;
        cout << "4. Pasar asistencia." << endl;
        cout << "5. Mostrar asistencia (cola)." << endl;
        cout << "0. Salir." << endl;
        cout << "Eliga una opcion: ";
        cin >> opcion;
        cin.clear(), cin.ignore(1000, '\n');

        switch(opcion){
            case 1:
                varEstudiante.insertarInicioPublica();
                cout << endl;
                break;
            case 2:
                cout << "\nIngrese el carnet del estudiante a buscar: ";
                cin >> idBuscar;
                cout << endl;
                varEstudiante.busquedaCarnet(idBuscar);
                break;
            case 3:
                cout << endl;
                varEstudiante.mostrarDatosPila();
                cout << endl;
                break;
            case 4:
                cout << endl;
                varEstudiante.insertarFinPublica();
                cout << endl;
                break;
            case 5:
                cout << endl;
                varEstudiante.mostrarDatosCola();
                cout << endl;
                break;
            default:
                break;
        }

    }while(opcion != 0);

    cout << endl;
    return 0;
}
