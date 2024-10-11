#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> copy = {0,1,1,1,0,0,0,1,1,1,1};
    cout<<copy.size()<<endl;

    vector<vector<int>> ans;

    int i = 0, n = copy.size();

        while (i < n) {
            if(copy[i] == 0){
                i++;
                continue;
            }

            int st = i;
            while(i<n-1 &&  copy[i+1] > 0){
                i++;
            }
            int en = i; 

            ans.push_back({st,en});
            i++;
        }
    
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
}