#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int *a, n;
		cin >> n;
		a = new int[n];
		
		for(int i = 0; i < n; i++) cin >> a[i];
		
		int sum = n*(n+1)/2;
		int res = 0;
		for(int i = 0; i < n; i++){
			res += a[i];
		}
		cout << sum-res << endl;
	}
}

