#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1 ="oqiweurotipweoti";
    string str2 ="qoieutqpotpuqeqp";
    str2.push_back('a');
    cout<<str2<<endl;
    sort(str1.begin() , str1.end());
    sort(str2.begin() , str2.end());
    if(str1==str2){
        cout<<true<<endl;
    }
    else{
        cout<<false<<endl;
    }
}