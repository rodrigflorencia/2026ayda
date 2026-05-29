/*** 
 * Dado un arreglo de numeros naturales ordenados crecientemente, 
 * implemente un algoritmo que determine si un numero dado pertenece al arreglo. 
 * Complejidad: O(log n)
 * */

int busqueda_binaria(int arr[],int ini,int fin,int buscar)
{
    if(ini>=fin)
        return -1;
    else
    {
        int mitad = (fin+ini) /2;
        if (arr[mitad]==buscar)
            return mitad;
        else
        {
            if (arr[mitad]>buscar)
                return busqueda_binaria(arr,ini,mitad-1,buscar);
            else
                return busqueda_binaria(arr,mitad+1,fin,buscar);
        }
    }
}


int main()
{
    int arr[8];
    inicOrdenado(arr,8);
    int buscar = rand()%8;
    cout<<"El numero: "<<buscar<<" en el arreglo:"<<endl;
    int pos = busqueda_binaria(arr,0,8,buscar);
    if (pos<0)
    {
        cout<<"\nno está en el arreglo\n";
    }else{
    cout<<"\nesta en la posicion: "<<pos<<endl;
    }
    return 0;
}

