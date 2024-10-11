#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0;

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }

    }
    void print(){
        for(int i=1 ; i<=size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deletefromheap(){
        if(size == 0){
            cout<<"there is nothing for delete : "<<endl;
            return;
        }
        else{
            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i<size){
                int leftchild = 2*i;
                int rightchild = 2*i + 1;

                if(leftchild < size && arr[i] < arr[leftchild]){
                    swap(arr[i] ,arr[leftchild]);
                    i = leftchild;
                } 

                else if(rightchild < size && arr[i] < arr[rightchild]){
                    swap(arr[i] ,arr[rightchild]);
                    i = rightchild;
                } 
                else{
                    return;
                }
            }
        }
    }

};

void heapify(int arr[] , int n , int i){
    int node = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[node]<arr[left]){
        node = left;
    }
    if(right <= n && arr[node]<arr[right]){
        node = right;
    }

    if(node != i){
        swap(arr[node] , arr[i]);
        heapify(arr , n , node);
    }
}

void heapsort(int arr[] , int n){
    int size = n;

    while(size > 1){
        swap(arr[1] , arr[size]);
        size--;

        heapify(arr  , size , 1);
    }
}

int main(){
    heap h;
    h.insert(5);
    h.insert(9);
    h.insert(2);
    h.insert(4);
    h.insert(6);
    h.insert(1);
    h.print();
    h.deletefromheap();
    h.print();

    int arr[6] ={-1 , 54 , 53 , 55 , 52 , 51};
    int n = 5;
    for(int i=n/2 ; i>0 ; i--){
        heapify(arr , n , i);
    }
    cout<<"array now :-"<<endl;
    for(int i=1 ; i<=n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // heapsort
    heapsort(arr , n);

    cout<<"Array in sorted :- "<<endl;
    for(int i=1 ; i<=n ; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    /// max heap 
    priority_queue<int> pq;

    pq.push(4);
    pq.push(9);
    pq.push(5);
    pq.push(1);

    cout<<"top element is :- "<<pq.top()<<endl;
    pq.pop();
    cout<<"top element is :- "<<pq.top()<<endl;
    cout<<"size  is :- "<<pq.size()<<endl;

    /// min heap;
    priority_queue<int , vector<int> , greater<int>> minheap;
    
    minheap.push(4);
    minheap.push(9);
    minheap.push(5);
    minheap.push(1);

    cout<<"top element is :- "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"top element is :- "<<minheap.top()<<endl;
    cout<<"size  is :- "<<minheap.size()<<endl;

    return 0;
}