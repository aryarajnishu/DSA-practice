#include<bits/stdc++.h>
using namespace std;

// void maxDistance(string s, int k) {
//         int n = s.size();
//         int m = 0;
//         for(int i=0 ; i<s.size()-1 ; i++){
//             if(s[i] == 'S' && s[i+1] == 'N'){
//                 s[i+1] = 'S';
//                 m++;
//             }
//             else if(s[i] == 'N' && s[i+1] == 'S'){
//                 s[i+1] = 'N';
//                 m++;
//             }
//             else if(s[i] == 'E' && s[i+1] == 'W'){
//                 s[i+1] = 'E';
//                 m++;
//             }
//             else if(s[i] == 'W' && s[i+1] == 'E'){
//                 s[i+1] = 'W';
//                 m++;
//             }
//             if(m==k){
//                 break;
//             }
//         }
//         int x=0,y=0;

//         for(int i=0 ; i<n ; i++){
//             if(s[i] == 'S'){
//                 y=y-1;
//             }
//             else if(s[i] == 'N'){
//                 y=y+1;
//             }
//             else if(s[i] == 'E'){
//                 x=x+1;
//             }
//             else{
//                 x=x-1;
//             }
//         }
//         cout<<x<<" "<<y<<endl;
//         cout<<s<<endl;
//     }

void maxDistance(string str, int k){
    int n1 = str.size();  // Fix here

    int n=0,s=0,e=0,w=0;
    for(int i=0 ; i<n1 ; i++){
        if(str[i] == 'S'){
            s++;
        }
        else if(str[i] == 'N'){
            n++;
        }
        else if(str[i] == 'E'){
            e++;
        }
        else{
            w++;
        }
    }
    
    if((n-s) >= 0){
        if(s<=k){
            n = n + s;
            k = k-s;
        }
        if(s>k){
            n = n + (s-k);
            k = 0;
        }
    }
    else if((n-s) < 0){
        if(n<=k){
            n = n + s;
            k = k-s;
        }
        if(n>k){
            n = n + (s-k);
            k = 0;
        }
    }
    else if((w-e) >= 0){

    }
    else if((w-e) < 0)

}

int main(){
    string s = "NSWWEW";
    int k = 3;
    maxDistance(s,k);
}