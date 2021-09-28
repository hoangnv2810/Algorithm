#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a, k;
		cin >> n >> k;
		a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		
		sort(a, a+n);
		long long num1 = 0, num2 = 0, res;
		for(int i = 0; i < n; i++){
			if(i < k) num1 += a[i];
			else num2 += a[i];
		}
		res = abs(num1-num2);
		num1 = 0, num2 = 0;
		for(int i = 0; i < n; i++){
			if(i < n-k) num1 += a[i];
			else num2 += a[i];
		}
		if(res > abs(num1-num2)) cout << res;
		else cout << abs(num1-num2);
		cout << endl;
	}
}

