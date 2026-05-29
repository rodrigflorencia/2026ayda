/**Encontrar un elemento k tal que a[k]=k.*/

#include<stdlib.h>
#define MAX 8

using namespace std;


int elem (int v[],int minv,int maxv)
{
    if (maxv>=minv)
    {
        int med = (maxv + minv)/2;
    
        if (v[med]==med)
            return med;
        else
        {
            if (v[med]>med)
                return elem(v,minv,med-1);
            else
                return elem(v,med+1,maxv);
        }
    }
    else
    {
            cout<<"No se encontro el elemento.\n";
            return -1;

    }
}

int main()
{
    int v[MAX] ;
    inic(v);

    int el = elem(v,0,MAX);
    cout<<endl<<"Elemento: "<<el<<"."<<endl;
    
    return 0;

}
