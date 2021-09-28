#include<bits/stdc++.h>
using namespace std;

//int solution(int a[], int n, int sum){
//	if(sum == 0) return true;
//	if(n == 0) return false;
//	if(a[n-1] > sum) return solution(a, n-1, sum);
//	return solution(a, n-1, sum) || solution(a, n-1, sum-a[n-1]);
//}

//int solution(int a[], int n, int sum){
//	bool dp[n+1][sum+1];
//	for(int i = 0; i <= n; i++){
//		dp[i][0] = true;
//	}
//	for(int i = 0; i <= sum; i++){
//		dp[0][i] = false;
//	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= sum; j++){
//			if(j < a[i-1]) dp[i][j] = dp[i-1][j];
//			else dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
//		}
//	}
//	return dp[n][sum];
//}

// int solution(int a[], int n, int sum){
// 	int F[40005] = {0};
// 	F[0] = 1;
// 	for(int i = 1; i <= n; i++){
// 		for(int j = sum; j >= a[i-1]; j--){
// 			if(F[j] == 0 && F[j-a[i-1]] == 1){
// 				F[j] = 1;
// 			}
// 		}
// 	}
// 	return F[sum];
// }

int solution(int a[], int n, int sum){
	int dp[40005] = {0};
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = sum; j >= a[i]; j--){
			if(dp[j] == 0 && dp[j-a[i]] == 1) dp[j] = 1;
		}
	}
	return dp[sum];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a, sum;
		cin >> n >> sum;
		a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		if(solution(a, n, sum) == true) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}

