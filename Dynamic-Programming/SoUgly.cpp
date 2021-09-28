#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int i2 = 0, i3 = 0, i5 = 0;
		int* dp = new int[n];
		dp[0] = 1;
		for (int i = 1; i < n; i++) {
			dp[i] = min(dp[i2] * 2, min(dp[i3] * 3, dp[i5] * 5));
			if (dp[i] == dp[i2] * 2) i2++;
			if (dp[i] == dp[i3] * 3) i3++;
			if (dp[i] == dp[i5] * 5) i5++;
		}
		cout << dp[n - 1] << endl;
	}
}