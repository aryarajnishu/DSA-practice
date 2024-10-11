// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> a = {9,9,5,3,4,5};
//     vector<int> b = {9,9,4};
//     vector<int> ans;
//     int cury = 0;
//     int n = a.size(),m=b.size();
//     int i=0,j=0;
//     while(i<n || j<m){
//         if(cury){
//             int x = a[i++] + b[j++]+1;
//             if(x>9){
//             ans.push_back(x%10);
//             cury = 1;
//             }
//             else{
//             ans.push_back(x);
//             cury = 0;
//             }
//         }else{
//             int x = a[i++] + b[j++];
//             if(x>9){
//             ans.push_back(x%10);
//             cury = 1;
//             }
//             else{
//             ans.push_back(x);
//             }
//         }
//     }

//     int count = 0;

//     if(cury){
//         while(i<n){
//         if(count==0){
//             ans.push_back(a[i++]+1);
//             count++;
//         }
//         else{
//             ans.push_back(a[i++]);
//         }
//         }
//         while(j<m){
//             if(count==0){
//             ans.push_back(b[j++]+1);
//             count++;
//         }
//         else{
//             ans.push_back(b[j++]);
//         }
//         }
//     }
//     else{
//         while(i<n){
//         ans.push_back(a[i++]);
//         }
//         while(j<m){
//             ans.push_back(b[j++]);
//         }
//     }

//     for(int i=0 ; i<ans.size() ; i++){
//         cout<<ans[i]<<" ";
//     }

// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {9, 9, 5, 3, 4, 5}; // Example array 1
    vector<int> b = {9, 9, 4};          // Example array 2
    vector<int> ans;                    // To store the result
    int carry = 0;                      // Variable to track carry
    int n = a.size(), m = b.size();
    int i = 0, j = 0;

    // Process both vectors until one of them is exhausted
    while (i < n || j < m || carry) {
        int sum = carry; // Initialize sum with carry from the previous addition
        
        // Add the current element of vector a if it's within bounds
        if (i < n) {
            sum += a[i];
            i++;
        }
        
        // Add the current element of vector b if it's within bounds
        if (j < m) {
            sum += b[j];
            j++;
        }
        
        // Append the last digit of the sum to the result vector
        ans.push_back(sum % 10);
        
        // Calculate the new carry (1 if the sum is 10 or more, else 0)
        carry = sum / 10;
    }

    // Print the result
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
