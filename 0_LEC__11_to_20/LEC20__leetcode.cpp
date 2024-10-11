#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> v){
    int i =0, j = v.size()-1;
    while(i<=j){
        swap(v[i], v[j]);
        i++,j--;
    }
    return v;
}

int main(){
    vector<int> v;
    v.push_back(11);
    v.push_back(60);
    v.push_back(9);
    v.push_back(39);
    v.push_back(10);
    v.push_back(6);

    for(int x:v){
        cout<< x <<"  ";
    }cout<<endl;

    vector<int> ans = reverse(v);

    for(int x:ans){
        cout<< x <<"  ";
    }cout<<endl;
}