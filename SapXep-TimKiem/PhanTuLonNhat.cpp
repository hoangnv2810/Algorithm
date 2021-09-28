#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a, k;
		cin >> n >> k;
		a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a+n);
		int i = n-1;
		while(k--){
			cout << a[i] << " ";
			i--;
		}
		cout << endl;
	}
}

