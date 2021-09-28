#include<bits/stdc++.h>
using namespace std;

//int solution(int a[], int n, int sum){
//	if(n == 0 && sum != 0) return 0;
//	if(sum == 0) return 1;
//	
//	if(sum < a[n-1]) return solution(a, n-1, sum);
//	return solution(a, n-1, sum) || solution(a, n-1, sum-a[n-1]);
//}

int solution(int a[], int n, int sum){
	int dp[n+1][sum+1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			if(j == 0) dp[i][j] = 1;
			if(j < a[i-1]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j] || dp[j-a[i-1]];
		}
	}
	return dp[n][sum];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		
		int sum = 0;
		for(int i = 0; i < n; i++) sum += a[i];
		if(solution(a, n, sum/2) && sum%2 == 0) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}

