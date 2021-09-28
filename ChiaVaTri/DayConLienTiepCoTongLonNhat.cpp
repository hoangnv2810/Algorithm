#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int res = INT_MIN, sum = 0;
		for(int i = 0; i < n; i++){
			sum += a[i];
			if(sum < 0) sum = 0;
			if(sum > res) res = sum;
		}
		cout << res << endl;
	}
}
// https://leetcode.com/problems/maximum-subarray/

