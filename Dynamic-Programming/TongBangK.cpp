#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[n+1], dp[k+1];
		for (int i = 0; i < n; i++) cin >> a[i];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i = 1; i <= k; i++){
			for (int j = 0; j < n; j++) {
				if (i >= a[j]) 
					dp[i] = (dp[i] + dp[i - a[j]])%mod;
			}
		}
		cout << dp[k] << endl;
	}
}