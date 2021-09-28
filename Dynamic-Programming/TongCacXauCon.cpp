#include<iostream>
#include<string>
#include<vector>
using namespace std;


// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         string s;
//         cin >> s;
//         long long dp[s.length()];
//         dp[0] = int(s[0]-'0');
//         long long res = dp[0];
//         for(int i = 1; i < s.length(); i++){
//             dp[i] = (i+1)*(s[i]-'0') + 10*dp[i-1];
//             res += dp[i];
//         }
//         cout << res << endl;
//     }
// }

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<int> a;
        for(int i = 0; i < s.length(); i++){
            a.push_back(s[i]-'0');
        }
        long long res = 0;
        for(int i = 0; i < a.size(); i++){
            long long temp = 0;
            for(int j = i; j < a.size(); j++){
                temp = 10*temp + a[j];
                res += temp;
            }
        }
        cout << res << endl;
    }
}