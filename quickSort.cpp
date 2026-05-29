int partition(int arr[], int izq, int der) {
    
    int pivot = arr[der];
    int i = izq;
    int j = der - 1;

    while (i <= j) {
        while (i <= j && arr[i] < pivot) {
            i++;
        }
        while (i <= j && arr[j] >= pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i], arr[der]);
    return i;
}

void quickSort(int arr[], int izq, int der) {
    if (izq < der) {     
        int pi = partition(arr, izq, der);
        quickSort(arr, izq, pi - 1);
        quickSort(arr, pi + 1, der);  
    } 
}

int main() {
    int arreglo[]={ 5, 3, 7, 6, 2, 1, 4};
    quickSort(arreglo,0, 6);
    return 0;
}
