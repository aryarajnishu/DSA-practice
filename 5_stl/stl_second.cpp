#include<iostream>
#include<vector>
using namespace std;
void explainvector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    cout<<v[0]<<endl;

    vector<pair<int , int >>vec;
    vec.push_back({1, 2});
    vec.emplace_back(3, 4);
    cout<<vec[0].first<<" "<<vec[0].second<<endl;
    cout<<vec[1].first<<" "<<vec[1].second<<endl;
    // in emplace back we can use pair integer without using currlybresh

    vector<int> a(5, 100); 
    //hear 5 is size , and 100 is valuse of each place

    vector<int>b(5);
    //hear 5 is a size and by default value is 0

    vector<int> v1(5,10);
    vector<int>v2(v1);
    //coppy v1 in v2


}
int main(){
    explainvector();
}