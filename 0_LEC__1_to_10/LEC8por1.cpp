#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int a;
    cout<<"Enter a :-";
    cin>> a;
    int b;
    cout<<"Enter b :-";
    cin>> b;

    char op;
    cout<<"enter aperation :-";
    cin>> op;

    switch (op){
        case '+': cout<< (a+b);
            break;
        case '-': cout<< (a-b);
            break;
        case '*': cout<< (a*b);
            break;
        case '%': cout<< (a%b);
            break;
        case '/': cout<< (a/b);
            break;
        default : cout<<"please enter valid operation";
    }
    
}
