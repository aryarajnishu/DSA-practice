#include<iostream>
#include<math.h>
using namespace std;
//accurrence     accurrence    accurrence    accurrence    accurrence 
void print(int arr[],int size){
    for(int i=0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
}   
int main(){
    int array[100];
    int arr[21]={7,9,6,9,8,7,9,5,5,9,9,8,6,6,7,7,6,8,8,8,9};
    int size = 21;
    for(int i=0 ; i<size ; i++){
        for(int j=i+1 ; j<size ; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int x;
    int a=0;
    for(int k=0 ; k<size ; k++){
        int sum=1;
        if(arr[k] == 0){
            continue;
        }
        for(int i=k ; i<k+1 ; i++){
            for(int j=i+1 ; j<size ; j++){
                if(arr[i] == arr[j] && arr[k] !=0){
                    sum++;
                    arr[j] = 0;
               }
            }
        }
        array[a] =  sum;
        a++;
        x = a;
        cout<<"number of occurrence of "<<arr[k]<<" is :- "<<sum;
        cout<<endl;
    }
    cout<<"number of occurence in form of arr :-  ";
    print(array,x);
    cout<<endl;
    int arya = 1;
    for(int i=0 ; i<x ; i++){
        for(int j=i+1 ; j<x ; j++){
            if(array[i] == array[j]){
                arya = 0;
            }
        }
    }
    if(arya == 1){
        cout<<"number of occurence is unique";
    }
    if(arya == 0){
        cout<<"number of occurence is not unique";
    }
}