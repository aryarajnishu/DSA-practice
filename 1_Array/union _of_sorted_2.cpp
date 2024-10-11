#include<iostream>
#include<vector>
#include<math.h>
#include <algorithm>
using namespace std;

void sortArray(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();
    int i=0,j=0;
    vector<int> ans;
    while(i != n && j != m){
        if(a[i]>b[j] && a[i] != a[i-1]) {
            ans.push_back(a[i]);
            i++;
        }
        
    }
}
int main(){
    vector<int> a = {1,2,5,2,6,3,7,8};
    vector<int> b = {2,0,6,7,2,3,8,1,7,9,10};
    sortArray(a,b);
} 