#include "Arbol.h"
Nodo* arbol = NULL;

void subMenu(){
    Arbol objArbol;
    int subOpcion = 0;
    while (subOpcion != 4){
        cout << "\n 1. Preorden";
        cout << "\n 2. Inorden";
        cout << "\n 3. Postorden";
        cout << "\n 4. Regresar";
        cout << "\n\nDigite una opcion: ";
        cin >> subOpcion;
        system("cls");
        if( subOpcion == 1 ){
            objArbol.preOrden(arbol);
            cout << endl;
            system("pause");
            system("cls");
        }
        else if(subOpcion == 2){
            objArbol.inOrden(arbol);
            cout << endl;
            system("pause");
            system("cls");
        }
        else if(subOpcion == 3){
            objArbol.postOrden(arbol);
            cout << endl;
            system("pause");
            system("cls");
        }
    }
}

void menu(){
    Arbol objArbol;
    int contador = 0, opcion = 0, dato = 0;
    while(opcion != 9){
        cout << "\n 1. Insertar nodo";
        cout << "\n 2. Mostrar arbol";
        cout << "\n 3. Buscar en el arbol";
        cout << "\n 4. Recorridos de un arbol";
        cout << "\n 5. Altura y tamanio del arbol";
        cout << "\n 6. Suma total del arbol";
        cout << "\n 7. Peso del arbol";
        cout << "\n 8. Mostrar arbol cifrado";
        cout << "\n 9. Salir";
        cout << "\n\nDigite una opcion: ";
        cin >> opcion;
        system("cls");
        if(opcion == 1){
            cout << "Ingrese un dato: ";
            cin >> dato;
            objArbol.insertarNodo(arbol, dato);
            /*llammos al objeto para usar el metodo*/
            cout << endl;
            system("pause");
            system("cls");
        }
        else if(opcion == 2){
            cout << "A R B O L" << endl;
            objArbol.mostrar(arbol, contador);
            /*llammos al objeto para usar el metodo*/
            cout << endl;
            system("pause");
            system("cls");
        }
        else if(opcion == 3){
            cout << "Digite un elemento a buscar: ";
            cin >> dato;
            if(objArbol.buscar(arbol, dato) == true){
            cout << "Elemento " << dato << " encontrado dentro del arbol" << endl;
            }
            else{
            cout << "Elemento no pertenese al arbol";
            }
            cout << endl;
            system("pause");
            system("cls");
        }
        else if(opcion == 4){
            subMenu();
            cout << endl;
            system("pause");
            system("cls");
        }
        else if(opcion == 5){
            system("cls");
            cout << "La altura del arbol es : " << objArbol.alturaArbol(arbol) << endl;
            cout << "El tamanio del arbol es : " << objArbol.tamanioArbol(arbol) << endl;
            system("pause");
            system("cls");
        }
        else if(opcion == 6){
            system("cls");
            cout << "La suma del arbol es : " << objArbol.sumarTodosNodos(arbol) << endl;
            /*cout << "El tamanio del arbol es : " << objArbol.tamanioArbol(arbol) << endl;*/
            system("pause");
            system("cls");
        }
        else if(opcion == 7){
            system("cls");
            cout << "El peso del arbol es : " << objArbol.pesoArbol(arbol) << endl;
            /*cout << "El tamanio del arbol es : " << objArbol.tamanioArbol(arbol) << endl;*/
            system("pause");
            system("cls");
        }
        else if(opcion == 8){
            system("cls");
            Arbol arbolCifrado;
            objArbol.cifrarArbol(arbol, arbolCifrado, contador);
            cout << "ARBOL  CIFRADO" << endl;
            objArbol.mostrarArbolCifrado(arbolCifrado, contador);
            system("pause");
            system("cls");
        }
    }
}

int main(){
    menu(); /* llamando a la funcion menu */
    cout << endl;
    return 0;
}