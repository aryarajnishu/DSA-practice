
#include<bits/stdc++.h>
using namespace std;
void selection(vector<int> &ans){
    int min,j;
    int n = ans.size();
    for(int i=0 ; i<n-1 ; i++){
        min = i;
        for(j=i+1 ; j<n ; j++){
            if(ans[j]<ans[min]){
                min = j;
            }
        }
        swap(ans[min], ans[i]);
    }
    for(int x :ans){
        cout<<x<<" ";
    }
}
int main(){
    vector<int> ans = {8,6,3,2,5,4,9,1,0};
    selection(ans);
}


























// void selection(vector<int> &ans){
//     int min,j;
//     for(int i=0 ; i<ans.size()-1 ;i++){
//         min = i;
//         for(j=i+1 ; j<ans.size() ; j++){
//             if(ans[min] > ans[j]){
//                 min = j;
//             }
//         }
//         swap(ans[min] , ans[i]);
//     }
//     for(int x : ans){
//         cout<<x<<" ";
//     }
// }