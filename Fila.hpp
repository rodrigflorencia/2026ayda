#ifndef FILA_H
#define FILA_H

class Fila {
    public:
        Fila();
        ~Fila();
        void agregarFila(int elemento);
        bool vaciaFila() const;
        int recuperarFila() const;
        void eliminarFila();

    private:
        struct Nodo {
            int dato;
            Nodo * sig;
        };
        Nodo * primero;
        Nodo * ultimo;
        Nodo * crear_nodo (Nodo *s, int d);

        void liberar_memoria();

    /** 
        int * primero;
        int capacidad;
        int ielemento;
        void redimensionar();     
        */ 
};
#endif // FILA_H
