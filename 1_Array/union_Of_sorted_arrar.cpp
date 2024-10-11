#include<iostream>
#include<vector>
#include<math.h>
#include <algorithm>
using namespace std;

void sortArray(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();
    vector<int> ans;
    for(int i=0 ; i<n ; i++){
        ans.push_back(a[i]);
    }
    for(int i=0 ; i<m ; i++){
        ans.push_back(b[i]);
    }
    vector<int> temp;
    for(auto it : ans){
        temp.push_back(it);
    }
    vector<int> nis;
    sort(temp.begin(), temp.end());
    int i = 0;
    while(i<temp.size()){
        int count = 0;
        for(int j=i+1 ; j<temp.size() ; j++){
            nis.push_back(temp[i]);
            if(temp[i]==temp[j]){
                count++;
            }
        }
        i= i + count;
    }

    for(int x:nis){
        cout<<x<<" ";
    }
}
int main(){
    vector<int> a = {1,2,5,2,6,3,7,8};
    vector<int> b = {2,0,6,7,2,3,8,1,7,9,10};
    sortArray(a,b);
}