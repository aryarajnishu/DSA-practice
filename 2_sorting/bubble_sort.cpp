#include<bits/stdc++.h>
using namespace std;

void bubble(vector<int> &ans){
    for(int i=0 ; i<ans.size()-1 ; i++){
        for(int j=0 ; j<ans.size()-1-i ; j++){
            if(ans[j]>ans[j+1]){
                swap(ans[j],ans[j+1]);
            }
        }
    }
    for(int x : ans){
        cout<<x<<" ";
    }
}
int main(){
    vector<int> ans = {8,6,3,2,5,4,9,1,0,18};
    bubble(ans);
}