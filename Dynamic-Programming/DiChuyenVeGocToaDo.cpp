#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        long long dp[n+1][m+1];
        dp[0][0] = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if((i == 0 && j != 0) || (i != 0 && j == 0)){
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        cout << dp[n][m] << endl;
    }
}