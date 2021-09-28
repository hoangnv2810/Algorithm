#include<bits/stdc++.h>
using namespace std;
long long m = 1e9+7;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		sort(a, a+n);
		long long sum = 0, res;
		for(int i = 0; i < n; i++){
			sum += a[i]*i;
			sum %= m; 
		}
		cout << sum << endl;
	}
}
