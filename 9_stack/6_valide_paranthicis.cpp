#include<bits/stdc++.h>
using namespace std;

bool valide_paranthics(string str){
    stack<char> s;
    for(int i=0 ; i<str.size() ; i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            s.push(str[i]);
        }
        else{
            if(!s.empty()){
                char top = s.top();
                if((str[i]==')' && top=='(')|| 
                (str[i]=='}' && top=='{')||
                (str[i]==']' && top=='['))
                {
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string str = "((){}[])";
    cout<<valide_paranthics(str);
    // int  x= 1;
    // cout<<x++;
    // cout<<x;
}