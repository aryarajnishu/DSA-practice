#include<iostream>
using namespace std;
// int print(int n, int sum){
    
//     if(n<=0){
//         return sum;
//     }
//     print(n-1,sum+n);
// }
// int main(){
//     cout<<print(10, 0);
// }


// int print(int n, int sum){
//     if(n<=0){
//         return sum;
//     }
//     sum = n+print(n-1,sum);
// }
// int main(){
//     cout<<print(10, 0);
// }

// int print(int n){
//     int sum =0;
//     if(n<=0){
//         return sum;
//     }
//     sum = n+print(n-1);
// }
// int main(){
//     cout<<print(10);
// }

int print(int n){
    if(n==0){
        return 0;
    }
    return n + print(n-1);
}
int main(){
    cout<<print(10);
}