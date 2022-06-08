#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int binary_search(int a[], int val, int low, int high) { // worst case = O(logn)
    int mid;

    if (low > high) {
        return (-1); // not found
    }

    mid = (low+high)/2;

    if (a[mid] == val) {
        return(mid);
    }
    if (a[mid] > val) {
        return( binary_search(a, val, low, mid-1));
    }
    else {
        return(binary_search(a, val ,mid+1 ,high));
    }
}

void print_sort(int a[], int n){
    for (int i = 0; i < n ; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}

// EASY ALGORITHMS
void bubble_sort(int a[], int n) { // worst case = O(n^2)
    int i, swapped = 1;
    while (swapped) {
        swapped = 0;
        for (i=0 ; i<n-1 ; i++) {
            if (a[i] > a[i+1]) {
                swap(&a[i], &a[i+1]);
                swapped = 1;
            }
        }
    }
}

void selection_sort(int a[], int n) { // worst case = O(n^2)
    int i, j, low, temp = 0;
    for (i=0 ; i<n-1 ; i++) {
        low = i;
        for (j=i+1 ; j<n ; j++) {
            if (a[j] < a[low]) {
                low = j;
            }
        }
        if (low != i) {
           swap(&a[i], &a[low]);
        }
    }
}

void insertion_sort(int a[], int n) { // worst case = O(n^2)
    int i, j;
    for (i=0 ; i<n-1 ; i++) {
        j = i;
        while ( (j > 0)  &&  (a[j] < a[j-1]) ) {
            swap(&a[j], &a[j-1]);
            j = j-1;
        }
    }
}


// FASTER ALGORITHMS

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    int lArr[n1], rArr[n2]; //temps
 
    for (i = 0; i < n1; i++)
        lArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rArr[j] = arr[mid + 1 + j];
 
    /* Merge temps*/
    i = 0; // Initial index of left subarray
    j = 0; // Initial index of right subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (lArr[i] <= rArr[j]) {
            arr[k] = lArr[i];
            i++;
        }
        else {
            arr[k] = rArr[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of lArr[] and rArr[], if there are any */
    while (i < n1) {
        arr[k] = lArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rArr[j];
        j++;
        k++;
    }
}
 
/* left is for left index and right is right index of the subarray of arr to be sorted */
void merge_sort(int arr[], int left, int right) { // worst case = O(nlogn)
    if (left < right) {
        int mid = left + (right - left) / 2;
 
        // Sort first and second halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
 
        merge(arr, left, mid, right);
    }
}



int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quick_sort(int array[], int low, int high) { // worst case = O(logn)
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}


int main() {
    int data[7] = {8, 7, 2, 1, 0, 9, 6};
  
    int n = sizeof(data) / sizeof(data[0]);
  
    print_sort(data, n);

    quick_sort(data, 0, n - 1);
    print_sort(data, n);

    int x[7] = {8, 7, 2, 1, 0, 9, 6};
    print_sort(x, n);

    insertion_sort(x, n);
    print_sort(x, n);

    int y[7] = {8, 7, 2, 1, 0, 9, 6};
    print_sort(y, n);

    bubble_sort(y, n);
    print_sort(y, n);

    int z[7] = {8, 7, 2, 1, 0, 9, 6};
    print_sort(z, n);

    selection_sort(z, n);
    print_sort(z, n);

    int a[7] = {8, 7, 2, 1, 0, 9, 6};
    print_sort(a, n);

    merge_sort(a, 0, n-1);
    print_sort(a, n);

}