#include<iostream>
#include<math.h>
// binary to decimal
using namespace std;
int main(){
    int n, a=0 ,i=0;
    cout<< "enter n :-";
    cin>>n;
    while(n>0){
        a = a + (n%10)*pow(2,i);
        i++;
        n = n/10;
    }
    cout<< a ;
}
