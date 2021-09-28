#include<bits/stdc++.h>
using namespace std;

//int solution(int n){
//	if(n == 1) return 0;
//	int sub = INT_MAX, div2 = INT_MAX, div3 = INT_MAX;
//	if(n%2 == 0) div2 = solution(n/2);
//	if(n%3 == 0) div3 = solution(n/3);
//	sub = solution(n-1); 
//	return 1 + min(sub, min(div2, div3));	
//}

int solution(int n){
	int dp[n+1];
	dp[1] = 0;
	for(int i = 2; i <= n; i++){
		int res = dp[i-1];
		if(i%2 == 0) res = min(res, dp[i/2]);
		if(i%3 == 0) res = min(res, dp[i/3]);
		dp[i] = 1 + res;
	}
	return dp[n];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << solution(n) << endl;
	}
}
