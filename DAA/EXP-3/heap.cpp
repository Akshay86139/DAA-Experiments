// A complete binary tree is a binary tree in which every level, except possibly the last one, is completely filled.
// in CBT nodes innsertion starts from left then moves toward right
// Max heap : child value should be less than root value
// of ith level in tree i its root 2i+1 will be its right child posn in  array and 2i of left


// 25/DA/008 
// Akshay Kumar
# include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]) swap(arr[parent],arr[index]);
            else return;
        }
    }
    void pop(){
        if(size == 0) return;
        arr[1] = arr[size];
        size--;
        int i = 1;
        while(i < size){
            int Lidx = 2*i + 1;
            int Ridx = 2*i;
            if(Lidx < size && arr[Lidx] > arr[i]) {
                swap(arr[Lidx],arr[i]);
                i = Lidx;
            }
            else if(Ridx < size && arr[Ridx] > arr[i]){
                swap(arr[Ridx],arr[i]);
                i = Ridx;
            }
            else return;
        }
    }
    // to make a array into heap , if n elements in array then from ((n/2)+1) to n elements are Leaf elements so we dont need to process them
    void heapify(int arr[],int n,int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i;
        if(left < n && arr[largest] < arr[left]) largest = left;
        if(right < n && arr[largest] < arr[right]) largest = right;

        if(largest != i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }

    void heapSort(int arr[], int n) {
        for(int i = n/2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        for(int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};