#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n, ans=0, a=0, i=0;
    cout<< "enter n :-";
    cin>>n;
    while(n!=0){
       a = n%2;
       if(a==0)
        a=1;
       else a=0;
       ans =  ans + a*pow(2,i);
       i++;
       n=n/2;
    }
    cout<<ans;
}