#include<bits/stdc++.h>
using namespace std;

string makestr(string s){
    int i=0;
    while((s[i] == ' ')){
        s.erase(s.begin() + i);
    }
    int j =0;
    while(j<s.size()){
        if(s[j]==' ' && s[j+1]==' '){
            s.erase(s.begin() + j);
            j--;
        }
        j++;
    }
    s.pop_back();
    return s;
}

int main(){
    string s = "   fly me   to   the   moon    i   ";
    cout<<makestr(s);
}