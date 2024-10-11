#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        int x = size;
        arr[x] = val;

        while(x>1){
            int parent = x/2;
            
            if(arr[parent] < arr[x]){
                swap(arr[parent] , arr[x]);
                x = parent;
            }
            else{
                return;
            }
        }
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

    void print(){
        for(int i=1 ; i<=size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    heap h;
    h.insert(5);
    h.insert(9);
    h.insert(2); 
    h.insert(4);
    h.insert(6);
    h.insert(1);
    cout<<"heap is :- ";
    h.print();
    h.deletefromheap();
    cout<<"new heap is :- ";
    h.print();
    

}