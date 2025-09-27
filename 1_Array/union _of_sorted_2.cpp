// #include<bits/stdc++.h>
// using namespace std;

// // void maxDistance(string s, int k) {
// //         int n = s.size();
// //         int m = 0;
// //         for(int i=0 ; i<s.size()-1 ; i++){
// //             if(s[i] == 'S' && s[i+1] == 'N'){
// //                 s[i+1] = 'S';
// //                 m++;
// //             }
// //             else if(s[i] == 'N' && s[i+1] == 'S'){
// //                 s[i+1] = 'N';
// //                 m++;
// //             }
// //             else if(s[i] == 'E' && s[i+1] == 'W'){
// //                 s[i+1] = 'E';
// //                 m++;
// //             }
// //             else if(s[i] == 'W' && s[i+1] == 'E'){
// //                 s[i+1] = 'W';
// //                 m++;
// //             }
// //             if(m==k){
// //                 break;
// //             }
// //         }
// //         int x=0,y=0;

// //         for(int i=0 ; i<n ; i++){
// //             if(s[i] == 'S'){
// //                 y=y-1;
// //             }
// //             else if(s[i] == 'N'){
// //                 y=y+1;
// //             }
// //             else if(s[i] == 'E'){
// //                 x=x+1;
// //             }
// //             else{
// //                 x=x-1;
// //             }
// //         }
// //         cout<<x<<" "<<y<<endl;
// //         cout<<s<<endl;
// //     }

// void maxDistance(string s, int k){
//     int n = s.size();  // Fix her
//     int n,s,e,w;
//     for(int i=0 ; i<n ; i++){
//         if(s[i] == 'S'){
//             s++;
//         }
//         else if(s[i] == 'N'){
//             n++;
//         }
//         else if(s[i] == 'E'){
//             e++;
//         }
//         else{
//             w++;
//         }
//     }
    
//     if((n-s) >= 0){
//         if()
//     }
//     else if((n-s) < 0){

//     }
//     else if((w-e) >= 0){

//     }
//     else if((w-e) < 0)

//     // unordered_map<char, int> mp;
//     // for (int i = 0; i < n; i++) {
//     //     mp[s[i]]++;
//     // }

//     // vector<pair<int, char>> d;
//     // for (auto i : mp) {
//     //     d.push_back({i.second, i.first});
//     // }

//     // sort(d.begin(), d.end());
//     // reverse(d.begin(), d.end());

//     // for (auto i : d) {
//     //     cout << i.first << " " << i.second << endl;
//     // }
    
//     // if(d[0].second == 'W')
// }

// int main(){
//     string s = "NSWWEW";
//     int k = 3;
//     maxDistance(s,k);
// }