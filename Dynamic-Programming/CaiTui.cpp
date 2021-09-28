#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
struct data{
	int a, c;
};

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, v;
		cin >> n >> v;
		data bag[n+1];
		for(int i = 1; i <= n; i++) cin >> bag[i].a;
		for(int i = 1; i <= n; i++) cin >> bag[i].c;
		
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= v; j++){
				if(j < bag[i].a) dp[i][j]= dp[i-1][j];
				else dp[i][j] = max(dp[i-1][j], bag[i].c + dp[i-1][j-bag[i].a]);
			}
		}
		cout << dp[n][v] << endl;
	}
}

