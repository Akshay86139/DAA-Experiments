#include<iostream>
using namespace std;


// 25/DA/008
// Akshay Kumar
class heap {
public:

    int arr[100];
    int size = 0;

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1) {
            int parent = index / 2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    void pop() {
        if(size == 0) return;

        arr[1] = arr[size];
        size--;

        int i = 1;

        while(i <= size) {

            int Lidx = 2*i;
            int Ridx = 2*i + 1;

            if(Lidx <= size && arr[Lidx] > arr[i]) {
                swap(arr[Lidx], arr[i]);
                i = Lidx;
            }
            else if(Ridx <= size && arr[Ridx] > arr[i]) {
                swap(arr[Ridx], arr[i]);
                i = Ridx;
            }
            else {
                return;
            }
        }
    }

    // Iterative heapify
    void heapify(int arr[], int n, int i) {

        while(true) {

            int largest = i;

            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n && arr[largest] < arr[left])
                largest = left;

            if(right < n && arr[largest] < arr[right])
                largest = right;

            if(largest == i)
                return;

            swap(arr[largest], arr[i]);

            i = largest;
        }
    }

    void heapSort(int arr[], int n) {

        // Build max heap
        for(int i = n/2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Sorting
        for(int i = n - 1; i > 0; i--) {

            swap(arr[0], arr[i]);

            heapify(arr, i, 0);
        }
    }
};