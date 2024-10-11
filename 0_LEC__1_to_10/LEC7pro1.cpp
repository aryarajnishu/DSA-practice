#include<iostream>
// revers of a number 
#include<math.h>
using namespace std;
int main(){
    int n ,ans =0 , x=1;
    cout<< "enter n :-";
    cin>>n;
    while(n!=0){
        ans = ans*10 + n%10;
        n = n/10;
    }
    cout<<ans;
}