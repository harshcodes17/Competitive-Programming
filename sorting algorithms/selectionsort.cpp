void selectionSort(int a[], int size) {
    int minIndex;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        // Swap elements
        int temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp;
    }
}
