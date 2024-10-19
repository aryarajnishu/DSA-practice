#include <bits/stdc++.h>
using namespace std;

int mainsquare(int n){
    if(n==0) return 0;
    int ans = n;
    for(int i=1 ; i*i < n ; i++){
        int temp = i*i;
        ans = min(ans , 1+mainsquare(n-temp));
    }
    return ans;

}

int main(){
    int n = 100;
    cout<<mainsquare(n);
}