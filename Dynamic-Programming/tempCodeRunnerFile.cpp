t main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int dp[n+1];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int res = 0;
		for(int i = 1; i < n; i++){
			for(int j = 0; j < i; j++){
				if(a[i] > a[j])
					dp[i] = max(dp[i], dp[j]+1);
			}
			res = max(res, dp[i]);
		}
		cout << res << endl;
	}
}