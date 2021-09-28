#include<bits/stdc++.h>
using namespace std;
int dp[101][25001];
int main(){
	int t = 1;
	while(t--){
		int c, n;
		cin >> c >> n;
		int w[n+1];
		for(int i = 1; i <= n; i++) cin >> w[i];
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= c; j++){
				if(j < w[i]) dp[i][j] = dp[i-1][j];
				else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + w[i]);
			}
		}
		cout << dp[n][c] << endl;
	}
}

