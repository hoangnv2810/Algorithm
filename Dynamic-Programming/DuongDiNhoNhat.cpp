#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        int a[m][n], dp[m][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
            	if(i == 0 && j == 0) dp[i][j] = a[i][j]; //NOTE
                else if(i == 0) dp[i][j] = a[i][j] + dp[i][j-1];
                else if(j == 0) dp[i][j] = a[i][j] + dp[i-1][j];
                else dp[i][j] = a[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        cout << dp[m-1][n-1] << endl;
    }
}