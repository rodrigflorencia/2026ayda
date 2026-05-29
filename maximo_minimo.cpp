/**Determinar valores maximos y minimos de un arreglo de numeros reales. Complejidad: O(log n)*/
#include <iostream>
using namespace std;

void maxMin(int v[],int ini,int fin,int & min, int & max)
{
    if (fin-2>ini)
    {
        int mitad = (fin+ini)/2;
        int min1=0;int min2=0;int max1=0;int max2=0;
        maxMin(v,ini,mitad,min1,max1);
        maxMin(v,mitad,fin,min2,max2);
        if (max1>max2)
            max = max1;
        else
            max = max2;
        if (min1<min2)
            min = min1;
        else
            min = min2;
        return;
    }
    /*casos base*/
    else
    {
        /*Dos elementos*/
        if (fin-2==ini)
        {
            if (v[ini]>v[ini+1])
            {
                min = v[ini+1];
                max = v[ini];
                return;
            }
            else
            {
                min = v[ini];
                max = v[ini+1];
                return;
            }
        }
        /*Un elemento*/
        else
        {
            min = v[ini];
            max = min;
            return;

        }
    }
}
int main()
{
    int arr[20];
    int min=0;
    int max = 0;
    maxMin(arr,0,20,min,max);
    cout<<"\nEl maximo es: "<<max<<" y el minimo: "<<min<<endl;
    return 0;

}
