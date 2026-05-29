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
                return mediana(v,maxv-med,maxv,u,minu,minu+med);
            else
                return mediana(v,minv,minv+med,u,maxu-med,maxu);
        }
    }
    else
    {
        if (maxv-2==minv)
        {
            /*Dos elementos*/
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
