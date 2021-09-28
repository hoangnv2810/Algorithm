#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int *a, n;
		cin >> n;
		a = new int[n];
		map<int, bool> mp;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]] = true;
		}
		sort(a, a+n);
		long long res = 0;
		for(long long i = a[0]; i <= a[n-1]; i++){
			if(mp[i] == false) res++;
		}
		cout << res << endl;
	}
}
