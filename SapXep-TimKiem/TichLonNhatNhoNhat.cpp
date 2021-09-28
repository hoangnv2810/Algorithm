#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, m, *a, *b;
		cin >> n >> m;
		a = new long long [n];
		b = new long long [m];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < m; i++) cin >> b[i];
		sort(a, a+n);
		sort(b, b+m);
		long long res = a[n-1]*b[0];
		cout << res << endl;
	}
}

