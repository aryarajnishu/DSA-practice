#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for(int j=low ; j<high ; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[i+1] , arr[high]);
    return i+1;
}


void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
    int n = arr.size();

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform Quick Sort
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
