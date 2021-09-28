#include<bits/stdc++.h>
using namespace std;

//int solution(int n, int k){
//	if(n == 0 || n == 1) return 1;
//	int sum = 0;
//	for(int i = 1; i <= k; i++){
//		if(n-i >= 0) {
//			sum += solution(n-i, k);
//		}
//	}
//	return sum;
//}

int solution(int n, int k){
	int dp[n+1] = {0};
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		int sum = 0;
		for(int j = 1; j <= k; j++){
			if(i-j >= 0) sum += dp[i-j];
		}
		dp[i] = sum;
	}
	return dp[n];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << solution(n, k) << endl;
	}	
}

