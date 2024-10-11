#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main(){
    char s1[50]="arya ";
    char s2[50]="raj";
    strcat(s1,s2);
    cout<<s1<<endl;
    int n = 18274;
    cout<<n<<endl;
    string str = to_string(n);
    cout<<str<<endl;
    str += "2";
    cout<<str<<endl;
    int x = 'a'-'A';
    cout<<x<<endl;
}