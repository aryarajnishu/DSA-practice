#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums = {2,4,2,5,6};
    int n =  nums.size();
    int sum ;
    int max_sum = INT_MIN;
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            for(int k=i ; k<=j ; k++){
                cout<<nums[k]<<" ";
                
            }cout<<endl;
        }
    }
    cout<<endl;
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            sum = 0;
            for(int k=i ; k<=j ; k++){
                sum = sum +  nums[k];    
            }
            max_sum = max(max_sum , sum);
        }
        
    }
    cout<<"max sum is :- "<<max_sum;
}