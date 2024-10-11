#include<iostream>
#include<vector>
using namespace std;
void explainvector(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.emplace_back(60);
    for(int i=0 ; i<6 ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int>::iterator it = v.begin();
    cout<<*(it)<<" ";
    it++;
    cout<<*(it)<<" ";
    cout<<endl;
    it = it +2;
    cout<<*(it)<<" ";
    cout<<endl;
    cout<<v[0]<<" "<<v.at(0);
    cout<<endl;
    cout<<v.back()<<" "; 
    cout<<endl;

for(auto it = v.begin(); it!=v.end(); it++){
    cout<<*(it)<<" ";
}
//print all element of vector using STL 
cout<<endl;

for(auto it : v){
    cout<<it<<" ";
}
cout<<endl;
//{10, 20, 30, 40, 50, 60}
v.erase(v.begin()+1);
//{10, 30, 40, 50, 60}
v.erase(v.begin()+1, v.begin()+3);
//{10,60}




//insert function
vector<int> v1{5,100};
vector<int>::iterator it = v.begin();
//{100, 100, 100, 100, 100}
v.insert(v1.begin(), 300);
//{300, 100, 100, 100, 100}
v.insert(v.begin()+1, 2, 200);
////{300, 200, 200, 100, 100}
//hear 2 is show how many time 200 will be insert
v.size();
//for size of vector
v.pop_back();
v1.swap(v);
//swap two vector;
v.clear();
//do empty of an vector;



    vector<int>::iterator its = v.end();
    //hear meaning of end is not 40 it is something other after -- in it it becom 40
    // (vector<int>::iterator it = v.rend();
    // vector<int>::iterator it = v.rebegin();)

}
int main(){
    explainvector();
}