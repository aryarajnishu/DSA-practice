#include<bits/stdc++.h>
using namespace std;
int num_stair(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans  = num_stair(n-1) + num_stair(n-2);
    return ans;

}
int main(){
    int n ;
    cout<<"Enter number of stair :- ";
    cin>>n;

    cout<<num_stair(n);
}