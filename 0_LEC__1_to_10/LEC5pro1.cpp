#include<iostream>
using namespace std;
int main(){
    int n; 
    cout<<" Enter n :- " <<endl;
    cin >> n;
    int pro = 1, sum = 0;
    while(n>0){
        pro = pro * (n%10);
        sum = sum + (n%10);
        n = n/10;
    }
    cout<< (pro - sum) <<endl;
}
