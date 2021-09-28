#include<bits/stdc++.h>
using namespace std;

int main(){
		int n, *a;
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int dp[n];
		dp[0] = 1;
		for(int i = 1; i < n; i++){
			int temp = 0;
			for(int j = 0; j < i; j++){
				if(a[j] < a[i] && dp[j] > temp){
					temp = dp[j];		
				}
			}
			dp[i] = temp + 1;
		}
		cout << *max_element(dp, dp+n);
}

