#include<iostream>
#include<vector>
using namespace std;

void printF(int ind,vector<int> &ans, int arr[], int n){
    if(ind == n){
        for(auto x : ans){
            cout<<x<<" ";
        }
        if(ans.size() == 0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    ans.push_back(arr[ind]);

    printF(ind+1,ans,arr,n);

    ans.pop_back();

    printF(ind+1,ans,arr,n);
}

int main(){
    int arr[3]= {3,1,2};
    vector<int> ans;
    int n = 3;
    printF(0,ans,arr,n);
    
}