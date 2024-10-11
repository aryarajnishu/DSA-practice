#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> m;

    pair<string , int> p = make_pair("arya",2);
    // in map key is unique string if string is same then they update
    m.insert(p);
    p = make_pair("sakshi",1);
    m.insert(p);

    m["nishu"] = 3;
    m["raj"] = 4;
    m["nisha"] = 7;

    cout<<m["arya"]<<" "<<m["sakshi"]<<" "<<m["nishu"]<<" "<<m.at("raj")<<endl;

    cout<<m.size()<<endl;
    m.erase("nishu");
    cout<<m.size()<<endl;

    //traversal in map
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"seond type :- "<<endl;

    map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

}