#include<iostream>
using namespace std;
void explainpair(){
    pair<int , int> p = {1,3};
    cout<<p.first<<" "<<p.second;
    cout<<endl;
    pair<int , pair<int , int >> q =  {1 ,{2,3}};
    cout<<q.first<<" "<<q.second.first << " "  <<q.second.second;
    cout<<endl;
    pair<int , int> arr[] = {{1,2} , {3,4} , {5,6} , {7,8}};
    cout<<arr[0].first<<" "<<arr[1].second;
}
int main(){
    explainpair();
}