#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
        int a[m][n], dp[m][n];
        memset(dp, 0, sizeof(dp));
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				cin >> a[i][j];
				dp[i][j] = a[i][j];
			}
		}
        int res = 0;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(!a[i][j]) continue;
                else if(a[i][j] == a[i-1][j-1] && a[i][j] == a[i-1][j] && a[i][j] == a[i][j-1]){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        cout << res << endl;
	}
}