/**Determinar la mediana de dos vectores. Complejidad: O(log n)*/
#include <iostream>
#include<stdlib.h>
#define MAX 8
using namespace std;

int mediana (int v[],int minv,int maxv,int u[],int minu,int maxu)
{
    if (maxv-2>minv)
    {
        int med = (maxv - minv)/2;
        int posv = minv + med;
        int posu = minu + med;
        if (v[posv]==u[posu])
            return v[posv];
        else
        {
            if (v[posv]<u[posu])
                return mediana(v,maxv-med,maxv,u,minu,posu);
            else
                return mediana(v,minv,posv,u,posu,maxu);
        }
    }
    else
    {
        if (maxv-2==minv) // Dos elementos
        {
            // El siguiente bloque if - else (linea 29 a 43) se puede reemplazar por return max(min(v[minv], u[minu]), min(v[minv+1], u[minu+1])); 
            if (v[maxv-1]<u[minu])
                return v[maxv-1];
            else
            {
                if (u[maxu-1]<v[minv])
                    return u[maxu-1];
                else
                {
                    if (u[minu]<v[minv])
                        return v[minv];
                    else
                        return u[minu];
                }
            }
//////////////////
        }
        else
        {
            /*Un elemento*/
            if (v[minv]<u[minu])
                return v[minv];
            else
                return u[minu];

        }
    }
}

int main()
{
    int v[MAX];
    int u [MAX];
    inic (u,v);
    int med = mediana(u,0,MAX,v,0,MAX);
    cout<<endl<<"Mediana: "<<med<<"."<<endl;
    return 0;

}
