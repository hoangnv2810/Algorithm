#include<bits/stdc++.h>
using namespace std;
// wa
int minCoins(int a[], int n, int s, int index){
	if(s == 0) return 0;
	int res = INT_MAX;
	for(int i = index; i < n; i++){
		if(a[i] <= s){
			int sub = minCoins(a, n, s-a[i], index += 1);
			if(sub != INT_MAX && sub + 1 < res) res = sub+1;
		}
		index -= 1;
	}
	return res;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, s, sum = 0;
		int* a = new int[n];
		cin >> n >> s;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
		}
		int res = INT_MAX;
		if(sum < s) cout << -1 << endl;
		else if (minCoins(a, n, s, 0) == res) cout << -1 << endl;
		else
		cout << minCoins(a, n, s, 0) << endl;
	}
}
