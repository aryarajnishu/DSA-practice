#include<bits/stdc++.h>
using namespace std;

int main(){
    // vector<vector<int>> nums;
    // int n,x;
    // cout<<"Enter numbers of row :- ";
    // cin>>n;
    // for(int i=0 ; i<n ; i++){
    //     vector<int> row;
    //     cout<<"Enter "<<i+1<<"th row element :- ";
    //     for(int j=0 ; j<n ; j++){
    //         cin>>x;
    //         row.push_back(x);
    //     }
    //     nums.push_back(row);
    // }
    vector<vector<int>> nums={{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0 ; i<3 ; i++){
        for(int j=2 ; j>=0 ; j--){
            cout<<nums[j][i]<<" ";
        }
        cout<<endl;
    }
    
}