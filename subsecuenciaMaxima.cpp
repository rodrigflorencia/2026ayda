#include <iostream>

void printArray(int arr[], int ini, int fin)
{
    for (int i = ini; i < fin; i++)
        std::cout << arr[i] << " - ";
}
void subSecSumaMedia(int arr[], int ini,
                     int fin, int &iniSec, int &finSec, int &suma)
{
    int medio = (fin + ini) / 2;
    int i = -1;
    if (arr[medio] > 0)
    {
        i = medio;
        suma = 0;
        while ((i >= ini) && (arr[i] > 0))
        {
            suma = suma + arr[i];
            i--;
        }
        if ((i >= ini) && (arr[i] <= 0))
        {
            i++;
        }

        int j = medio + 1;
        while ((j <= fin) && (arr[j] > 0))
        {
            suma = suma + arr[j];
            j++;
        }
        if ((j <= fin) && (arr[j] <= 0))
            j--;

        iniSec = i;
        finSec = j;
    }
    else
    {
        suma = -1;
    }
}

void maximaSubsecuencia(int suma1, int ini1, int fin1, int suma2, int ini2, int fin2,
                        int suma3, int ini3, int fin3, int &suma, int &inisec, int &finsec)
{
    if ((suma1 >= suma2) && (suma1 >= suma3))
    {
        suma = suma1;
        inisec = ini1;
        finsec = fin1;
    }
    else if ((suma2 >= suma1) && (suma2 >= suma3))
    {
        suma = suma2;
        inisec = ini2;
        finsec = fin2;
    }
    else
    {
        suma = suma3;
        inisec = ini3;
        finsec = fin3;
    }
}

/**
 * Busca las posiciones de inicio y fin de la subsecuencia de suma máxima
 *
 */
void subsecuenciaMaxima(int arr[], int ini, int fin, int &suma, int &inisec, int &finsec)
{
    // Caso base: un elemento
    if ((fin == ini))
    {
        suma = arr[ini];
        inisec = ini;
        finsec = fin;
    }
    else
    {
        int mitad = (fin + ini) / 2;
        int suma1 = -1, ini1 = -1, fin1 = -1, suma2 = -1, ini2 = -1, fin2 = -1,
            suma3 = -1, ini3 = -1, fin3 = -1;
        subsecuenciaMaxima(arr, ini, mitad, suma1, ini1, fin1);
        subsecuenciaMaxima(arr, mitad + 1, fin, suma2, ini2, fin2);
        subSecSumaMedia(arr, ini, fin, ini3, fin3, suma3);
        maximaSubsecuencia(suma1, ini1, fin1, suma2, ini2, fin2,
                           suma3, ini3, fin3, suma, inisec, finsec);
    }
}
int main()
{
    int arr[] = {4, -1, 2, 1, -5, 4, 3, -2, 6, -1, 2, -3, 1, 4, -2, 1};

    printArray(arr, 0, 16);
    int ini, fin, suma;
    int n = 16;
    subsecuenciaMaxima(arr, 0, n - 1, suma, ini, fin);
    std::cout << "\nLa subsecuencia de suma maxima esta entre los indices " << ini << " y " << fin << ".\nLa suma es: " << suma << ".\n";
}
// 4, -1, 2, 1, -5, 4, 3, -2, 6, -1, 2, -3, 1, 4, -2, 1
//-5, -3, 2, -1, 3, -2, 1, -8, 4, -1, -3, 2, 1, -6, 3, -2
//-7, -2, 3, 5, 8, -1, 6, 4, -3, -9, 2, -1, 5, -4, -6, -2
//-4, 2, -1, 3, -7, 8, -2, 5, -1, 2, -9, 3, -2, 6, -1, -5
//-3, -7, -1, -5, -12, -4, -8, -2, -6, -9, -3, -11, -1, -4, -7, -2
// 15, -20, 10, -5, 25, -30, 8, 12, -3, 18, -25, 5, -2, 20, -10, 6
