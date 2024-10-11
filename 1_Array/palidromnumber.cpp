#include<iostream>
using namespace std;
bool isPalindrome(int x) {
        int a = x;
        int sum = 0;
        while(x!=0){
            sum = sum + x%10;
            if(x>=10){
                sum = sum*10;
            }
            x = x/10;
        }
        cout<<sum;
        if(sum == a){
            return true;
        }
        return false;
}
int main(){
    isPalindrome(1001);
    
}