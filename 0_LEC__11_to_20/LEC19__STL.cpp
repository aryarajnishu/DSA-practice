#include<iostream>
#include<array>
#include<vector>
using namespace std;
int main(){
    array<int, 5> a = {1,5,3,6,4};
    for(int i=0 ; i<a.size() ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl; 
    // cout<<endl;
    // cout<<a.at(4)<<endl;
    // cout<<a.front()<<endl;
    // cout<<a.back();
    

    vector<int> v;
    vector<int> arr(5,1);
    for(int x:arr){
        cout<<x<<"  ";
    }
    cout<<endl;
    cout<<v.capacity()<<endl;
    v.push_back(1);
    cout<<v.capacity()<<endl;

    v.push_back(10);
    cout<<v.capacity()<<endl;

    v.push_back(3);
    cout<<v.capacity()<<endl;

    v.push_back(40);
    cout<<v.capacity()<<endl;

    v.push_back(400);
    cout<<v.capacity()<<endl;


    cout<<v.at(2)<<endl;
    for(int i=0 ; i<v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<v.capacity()<<endl;
    cout<<v.size()<<endl; 
    for(int x:v){
        cout<<x<<"  ";
    }
    cout<<endl;
    v.pop_back();

    for(int x:v){
        cout<<x<<"  ";
    }

    v.pop_back();
    for(int x:v){
        cout<<x<<"  ";
    }

}