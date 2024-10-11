
#include <iostream>
using namespace std;
char uperTolower(char ch){
     if(ch >='A' && ch<='Z'){
          ch = ch +32;
     }
     return ch;
}

int main(){
     char ch = 'G';
     cout<<uperTolower(ch);
     return 0;
}
