// 1. Linear Search
// Algorithm
// Start from the first element of the array.

// Compare each element with the target key.

// If a match is found, return the index.

// If no match is found, return -1.

// Pseudo Code
// LinearSearch(array, n, key)
//     for i = 0 to n-1
//         if array[i] == key
//             return i
//     return -1
// C Code
#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i; // found at index i
    }
    return -1; // not found
}

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);
    if(result != -1)
        printf("%d found at index %d\n", key, result);
    else
        printf("%d not found in the array\n", key);

    return 0;
}

// 2. Binary Search
// Algorithm
// Ensure the array is sorted.

// Set low = 0 and high = n-1.

// Find middle index mid = (low + high)/2.

// If array[mid] == key, return mid.

// If array[mid] < key, search in right half (low = mid + 1).

// If array[mid] > key, search in left half (high = mid - 1).

// Repeat until low > high. If not found, return -1.

// Pseudo Code
// BinarySearch(array, n, key)
//     low = 0
//     high = n-1
//     while low <= high
//         mid = (low + high)/2
//         if array[mid] == key
//             return mid
//         else if array[mid] < key
//             low = mid + 1
//         else
//             high = mid - 1
//     return -1
// C Code
#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted numbers:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);
    if(result != -1)
        printf("%d found at index %d\n", key, result);
    else
        printf("%d not found in the array\n", key);

    return 0;
}
