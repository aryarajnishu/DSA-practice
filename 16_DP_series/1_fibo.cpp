#include <bits/stdc++.h>
using namespace std;

// int fibo(int n){
//     if(n==0 || n==1)
//     return 1;
//     return (fibo(n-1) + fibo(n-2));
// }


// int fibo1(int n){
//     if(n==0 || n==1)
//     return 1;
//     return fibo(n-1) + fibo(n-2);
// }
// int main(){
//     int n = 5;
//     cout<<fibo(5);
//     cout<<fibo1(5);
// }




int fibo(int n , vector<int> &dp){
    if(n<=1)
    return 1;

    if(dp[n] != -1) return dp[n];
    return dp[n] = fibo(n-1 , dp ) + fibo(n-2 , dp);
}

int main(){
    int n = 5;
    vector<int> dp(n+1 , -1);

    cout<<fibo(n , dp);

}