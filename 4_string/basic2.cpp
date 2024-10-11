#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main(){
    // string str = "arya";
    // string str1("sakshi");
    // cout<<str<<" "<<str1<<endl;
    // cout<<"enter your name :- ";
    // string name;
    // getline(cin,name);
    // cout<<name<<endl;
    //ascii value
    cout<<int('A')<<endl;
    string str = "arya@raj@nisshu@kumsr@sakshi@sinha";
    reverse(str.begin()+8,str.end()-2);
    cout<<str<<endl;
    cout<<str.substr(0,8)<<endl;
    cout<<str.substr(4)<<endl;
    string str1="arya ",str2 = "raj";
    string strr = str1+str2;
    cout<<str1+str2<<endl;
    cout<<strr<<endl;

}