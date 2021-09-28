#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long dp[n+1] = {0};
		dp[0] = 1;
		for(int i = 1; i <= n; i++){
			long long sum = 0;
			for(int j = 1; j <= 3; j++){
				if(i-j >= 0) sum += dp[i-j];
			}
			dp[i] = sum;
		}
		cout << dp[n] << endl;
	}
}

