// Mezclar dos subarreglos
void merge(int arr[], int izq, int mid, int der) {

    // Crear arreglos temporales
    int n1 = mid - izq + 1;
    int n2 = der - mid;

    int* izqArr = new int[n1];
    int* derArr = new int[n2];

    // Copiar datos a los arreglos temporales
    for (int i = 0; i < n1; i++)
        izqArr[i] = arr[izq + i];
    for (int j = 0; j < n2; j++)
        derArr[j] = arr[mid + 1 + j];

    // Mezclar los arreglos temporales de nuevo en arr[]
    int i = 0, j = 0, k = izq;

    while (i < n1 && j < n2) {
        if (izqArr[i] <= derArr[j]) {
            arr[k] = izqArr[i];
            i++;
        } else {
            arr[k] = derArr[j];
            j++;
        }
        k++;
    }
    
    // Copiar los elementos restantes de izqArr[], si los hay
    while (i < n1) {
        arr[k] = izqArr[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de derArr[], si los hay
    while (j < n2) {
        arr[k] = derArr[j];
        j++;
        k++;
    }
  
    
    delete[] izqArr;
    delete[] derArr;
}

void mergeSort(int arr[], int izq, int der) {
    if (izq < der) {
        int mid = izq + (der - izq) / 2;

        mergeSort(arr, izq, mid);
        mergeSort(arr, mid + 1, der);
        
        merge(arr, izq, mid, der);

    } 
}

int main() {
    int arreglo[]={ 64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    mergeSort(arreglo, 0, 9);
    return 0;
}

