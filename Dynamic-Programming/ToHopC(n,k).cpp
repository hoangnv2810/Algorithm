#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
//int nCr(int n, int k){
//	if(k == 0 || k == n) return 1;
//	return nCr(n-1, k-1) + nCr(n-1, k);
//}

//int nCr(int n, int k){
//	int dp[n+1][k+1];
//	for(int i = 0; i <= n; i++){
//		for(int j = 0; j <= min(i,k); j++){
//			if(j == 0 || j == i) dp[i][j] = 1;
//			else dp[i][j] = (dp[i-1][j-1]%mod + dp[i-1][j]%mod)%mod;
//		}
//	}
//	return dp[n][k]%mod;
//}

int nCr(int n, int k){
	int dp[k+1] = {0};
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = min(i, k); j > 0; j--){
			dp[j] = (dp[j] + dp[j-1])%mod;
		}
	}
	return dp[k]%mod;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << nCr(n, k) << endl;
	}
}

