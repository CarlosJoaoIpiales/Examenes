#include "Nodo.h"
class Arbol
{
    private:
        Nodo* arbol = NULL;
        Nodo *aux = NULL;
    public:
        void setArbol(Nodo*);
        Nodo* getArbol();
        Nodo* crearNodo(int);
        void insertarNodo(Nodo*&, int);
        void mostrar(Nodo*, int);
        bool buscar(Nodo*, int);
        void preOrden(Nodo*);
        void inOrden(Nodo*);
        void postOrden(Nodo*);
        int tamanioArbol(Nodo*);
        int alturaArbol(Nodo*);
        int sumarTodosNodos(Nodo*);
        int pesoArbol(Nodo*);
        int nivelArbol(Nodo*);
        void cifrarArbol(Nodo*, Arbol, int);
        void mostrarArbolCifrado(Arbol, int);
};

void Arbol::setArbol(Nodo* _arbol){
    arbol = _arbol;
}

Nodo* Arbol::getArbol(){
    return arbol;
}

Nodo* Arbol::crearNodo(int dato){
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->setDato(dato);
    nuevoNodo->setDerecha(NULL);
    nuevoNodo->setIzquierda(NULL);
    return nuevoNodo;
}

void Arbol::insertarNodo(Nodo*& arbol, int dato){
    if(arbol == NULL){
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
    }
    else{
        int raiz = arbol->getDato();
        if(dato < raiz){
            insertarNodo(arbol->getIzquierda(), dato);
        }
        else{
            insertarNodo(arbol->getDerecha(), dato);
        }
    }
}
/*Comprobamos si el arbol esta vacio, si ese es el caso creamos un nuevo nodo e
igualamos el arbol al nuevo nodo. Si el arbol cuenta con algén dato entonces creamos una
variable llamanda raiz para obtener si valor y establecer si el nuevo element va a la derecha o a
la izquierda*/

void Arbol::mostrar(Nodo* arbol, int contador){
    if(arbol == NULL){
        return;
    }
    else{
        mostrar(arbol->getDerecha(), contador+1);
        for(int i = 0; i < contador; i++){
            cout << " ";
        }
        cout<<arbol->getDato() << endl;
        mostrar(arbol->getIzquierda(), contador +1);
    }
}
/*Comprobamos si el árbol está vacío entonces retornamos el árbol
vacío, caso contrario aplicamos recursividad para ir mostrando los
datos del árbol*/

bool Arbol::buscar(Nodo* arbol, int dato){
    if(arbol == NULL){
        return false;
    }
    else if(arbol->getDato() == dato){
        return true;
    }
    else if(dato < arbol->getDato()){
        buscar(arbol->getIzquierda(), dato);
    }
    else{
        buscar(arbol->getDerecha(), dato);
    }
}

/*Para buscar un elemento comprobamos si el arbol está vacío, caso contrario verificamos
el nodo a ver si es el dato buscado, si este es menor buscamos a la derecha y si es mayor lo
buscamos a la izquierda*/
void Arbol::preOrden(Nodo* arbol){
    if(arbol == NULL){
        return;
    }
    else{
        cout << arbol->getDato() << " ";
        preOrden(arbol->getIzquierda());
        preOrden(arbol->getDerecha());
    }
}

/*El recorrido en preorden es: raiz, izquierda, derecha*/
void Arbol::inOrden(Nodo* arbol){
    if(arbol == NULL){
        return;
    }
    else{
        inOrden(arbol->getIzquierda());
        cout << arbol->getDato() << " ";
        inOrden(arbol->getDerecha());
    }
}

/*El recorrido en inorden es: izquierda, raiz, derecha*/
void Arbol::postOrden(Nodo* arbol){
    if(arbol == NULL){
        return;
    }
    else{
        postOrden(arbol->getIzquierda());
        postOrden(arbol->getDerecha());
        cout << arbol->getDato() << " ";
    }
}
/*El recorrido en postorden es: izquierda,derecha, raiz*/


/*calcular el tamanio del arbol*/
int Arbol::tamanioArbol(Nodo* arbol){
    if (arbol == NULL)
        return 0;
    else
        return 1 + tamanioArbol(arbol->getIzquierda()) + tamanioArbol(arbol->getDerecha());
}

/*Calcular la altura del arbol*/
int Arbol::alturaArbol(Nodo* arbol){
    int lh, rh;

    if (arbol == NULL)
        return -1;
    else {
        lh = alturaArbol(arbol->getIzquierda());
        rh = alturaArbol(arbol->getDerecha());
        return 1 + (lh > rh ? lh : rh);
    }
}

/*Suma de todos los elementos del arbol*/
int Arbol::sumarTodosNodos(Nodo* arbol){
    if (arbol == NULL)
        return 0;
    else {
        int centro = arbol->getDato();
        int izquierda = sumarTodosNodos(arbol->getIzquierda());
        int derecha = sumarTodosNodos(arbol->getDerecha());
        return centro + izquierda + derecha;
    }
}

/*Calcular el peso del arbol*/
int Arbol::pesoArbol(Nodo* arbol){
    int pes = 0;
    if (arbol == NULL)
        return 1;
    else {
        if (arbol->getDerecha() != NULL)
        {
            pes += pesoArbol(arbol->getDerecha());
        }
        if (arbol->getIzquierda() != NULL)
        {
            pes += pesoArbol(arbol->getIzquierda());
        }
        return pes;
    }
}

void Arbol::cifrarArbol(Nodo* arbol, Arbol arbolCifrado, int num){
    if(arbol == NULL){
        return;
    }
    else{
        cifrarArbol(arbol->getIzquierda(), arbolCifrado, num);
        
        cifrarArbol(arbol->getDerecha(), arbolCifrado, num);
        int n = arbol->getDato();
        int suma = 0;
        while (n > 0)
        {
            suma = suma + n%10;
            n = n/10;
        }
        arbolCifrado.insertarNodo(aux, suma);
    }
}

void Arbol::mostrarArbolCifrado(Arbol arbolCifrado, int num){
    arbolCifrado.mostrar(aux, num);
}