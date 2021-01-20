#include <iostream>
using namespace std;
int mcdIterativo(int, int);
int mcdRecursivo(int, int);
int main(void){
    int a, b;
    cout << "Ingrese los valores de A y B: " << endl;
    cin >> a >> b;
    cout << "MCD Iterativo: " << mcdIterativo(a,b) << endl;
    cout << "MCD Recursivo: " << mcdRecursivo(a,b) << endl;
    return 0;
}
int mcdIterativo(int a, int b){
    while(b != 0){
        if(a-b > b)
            a = a - b;
        else{
            int aux = b;
            b = a - b;
            a = aux;
        }
    }
    return a;
}
int mcdRecursivo(int a, int b){
    if (b == 0)
        return a;
    else{
        if(a-b > b)
            return mcdRecursivo(a-b, b);
        else
            return mcdRecursivo(b, a-b);
    }
}
/* Diferencias entre el metodo iterativo y el recursivo:
    Algo que note haciendo este ejercicio es que puedo reasignar variables
    facilmente en el metodo recursivo al momento de hacer la llamada recursiva
    de la funcion, en cambio al hacer el procedimiento iterativo tuve que 
    crear una variable auxiliar para poder reasignar las variables.

    Otra diferencia es el uso de recursos de cada metodo, ahora veo que 
    en algunos casos un metodo puede ser mas eficiente que otro.
*/
