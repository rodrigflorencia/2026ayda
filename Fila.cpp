#include "Fila.hpp"

Fila::Fila()
{
    // Complejidad puntero: O(1)
    this->primero=nullptr;
    this->ultimo=nullptr;

    /** 
    // Complejidad array: O(this->capacidad)
    this->capacidad = 10;
    this->primero = new int[this->capacidad];
    for (int i = 0; i < this->capacidad; i++)
        this->primero[i] = 0;
    this->ielemento = 0;
    */
}

Fila::~Fila()
{
    // Complejidad con puntero O(#elementos ingresados)
    liberar_memoria();
    this->ultimo = nullptr;
    
    // Complejidad con array O(1)
    /**
    delete[] (this->primero);
    this->primero = nullptr;
    this->ielemento = 0;
    **/
}
void Fila::liberar_memoria()
{
    while (this->primero != nullptr)
    {
        Fila::Nodo * siguiente = this->primero->sig;
        delete this->primero;
        this->primero = siguiente;
    }
    this->primero = nullptr;
}
/*
void Fila::redimensionar()
{
    // Complejidad con array O(this->capacidad)
    int *auxiliar = new int[this->capacidad + 10];
    for (int i = 0; i < this->capacidad; i++)
        auxiliar[i] = this->primero[i];

    for (int i = this->capacidad; i < this->capacidad + 10; i++)
        auxiliar[i] = 0;
    this->capacidad = this->capacidad + 10;
    delete[] this->primero;
    this->primero = auxiliar;
    auxiliar = nullptr;
}
    */
Fila::Nodo * Fila::crear_nodo(Fila::Nodo *s, int d)
{
    Fila::Nodo * nuevo = new Fila::Nodo();
    nuevo->dato = d;
    nuevo->sig = s;
    return nuevo;
}
void Fila::agregarFila(int elemento)
{
    // Complejidad puntero: O(1)
    if (this->primero==nullptr){
        this->primero = crear_nodo(nullptr,elemento);
        this->ultimo = this->primero;
    } else {
        this->ultimo->sig=crear_nodo(nullptr,elemento);
        this->ultimo = this->ultimo->sig;
    }
    /**
    // Complejidad con array O(this->capacidad)
    if (this->ielemento >= this->capacidad)
    {
        this->redimensionar();
    }
    this->primero[this->ielemento] = elemento;
    this->ielemento = this->ielemento + 1;
    */
}

bool Fila::vaciaFila() const
{
    // Complejidad puntero: O(1)
     if (this->primero == nullptr)
        return true;
    return false;
    // Complejidad con array O(1)
    // return this->ielemento == 0;
}

int Fila::recuperarFila() const
{
    // Complejidad puntero: O(1)
    if (this->primero!=nullptr)
        return this->primero->dato;

    //Si confiamos en la precondición, podemos evitar el if: return this->primero->dato;

    // Complejidad con array O(1)
    // return this->primero[0];
}
void Fila::eliminarFila()
{
     // Complejidad puntero: O(1)
    if (this->primero!=nullptr){
        Fila::Nodo* aux = this->primero;
        this->primero = aux->sig;
        aux->sig = nullptr;
        delete(aux);
        aux = nullptr;

    }

    // Complejidad con array O(this->capacidad)
   /** *
    for (int i = 0; i < this->ielemento; i++)
        this->primero[i] = this->primero[i + 1];
    this->ielemento = this->ielemento - 1;*/
}
int main()
{
    Fila *f = new Fila();
    f->agregarFila(2);
    f->agregarFila(3);
    f->agregarFila(4);
    f->agregarFila(5);
    f->agregarFila(6);
    f->agregarFila(7);
    f->agregarFila(12);
    f->agregarFila(13);
    f->agregarFila(14);
    f->agregarFila(15);
    f->agregarFila(16);
    f->agregarFila(17);
    delete f;
}
