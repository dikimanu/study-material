// 1. Bubble Sort
// Algorithm
// Start from the first element of the array.

// Compare the current element with the next element.

// If the current element is greater than the next element, swap them.

// Move to the next element and repeat until the end of the array.

// Repeat the whole process for n-1 passes until the array is sorted.

// // Pseudo Code
// for i = 0 to n-1
//     for j = 0 to n-i-2
//         if array[j] > array[j+1]
//             swap(array[j], array[j+1])
// C Code
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Bubble Sort
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
// 2. Insertion Sort
// Algorithm
// Start from the second element of the array.

// Compare it with elements before it.

// Shift all elements greater than the current element one position ahead.

// Insert the current element in its correct position.

// Repeat for all elements.

// Pseudo Code
// for i = 1 to n-1
//     key = array[i]
//     j = i-1
//     while j >= 0 and array[j] > key
//         array[j+1] = array[j]
//         j = j-1
//     array[j+1] = key
// C Code
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Insertion Sort
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
// 3. Merge Sort (for 5 numbers)
// Algorithm
// Divide the array into two halves.

// Recursively sort both halves.

// Merge the two sorted halves into one sorted array.

// Pseudo Code
// MergeSort(array, l, r)
//     if l < r
//         m = (l + r)/2
//         MergeSort(array, l, m)
//         MergeSort(array, m+1, r)
//         Merge(array, l, m, r)

// Merge(array, l, m, r)
//     create temp arrays L and R
//     copy data to L and R
//     merge L and R back into array[l..r]
// C Code
#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[5];
    printf("Enter 5 numbers: ");
    for(int i = 0; i < 5; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, 4);

    printf("Sorted array: ");
    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    return 0;
}


// 4. Quick Sort
// Algorithm
// Choose a pivot element (commonly the last element).

// Partition the array: elements smaller than pivot go left, larger go right.

// Recursively apply Quick Sort on left and right subarrays.

// Stop when the subarray has 1 or 0 elements.

// Pseudo Code
// QuickSort(array, low, high)
//     if low < high
//         pi = Partition(array, low, high)
//         QuickSort(array, low, pi-1)
//         QuickSort(array, pi+1, high)

// Partition(array, low, high)
//     pivot = array[high]
//     i = low - 1
//     for j = low to high-1
//         if array[j] < pivot
//             i = i + 1
//             swap array[i] with array[j]
//     swap array[i+1] with array[high]
//     return i+1
// C Code
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n-1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

