#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string decodedstring(string s){
    string ans = "";
    for(int i=0 ; i<s.size() ; i++){
        if(s[i] != ']'){
            ans.push_back(s[i]);
        }
        else{
            string str ="";
            while(!ans.empty() && ans.back() != '['){
                str.push_back(ans.back());
                ans.pop_back();
            }
            reverse(str.begin(),str.end());
            ans.pop_back();
            string num;
            while(!ans.empty() && ans.back()>='0' && ans.back()<'9'){
                num.push_back(ans.back());
                ans.pop_back();
            }
            int int_nums = stoi(num);
            while(int_nums){
                ans = ans + str;
                int_nums--;
            }
        }
    }
    return ans;
}
int main(){
    cout<<"Enter encoded string :- ";
    string s;
    cin>>s;
    cout<<decodedstring(s);
}