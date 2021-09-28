#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int dp[n+1][k+10]; // NOTE
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= 9; i++){
            dp[1][i] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int so = 0; so <= 9; so++){
                for(int j = so; j <= k; j++){
                    dp[i][j] = (dp[i][j]%mod + dp[i-1][j-so]%mod)%mod;
                }
            }
        }
        cout << dp[n][k] << endl;
    }
}