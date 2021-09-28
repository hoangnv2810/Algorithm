#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a, x;
		cin >> n >> x;
		a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		int count = 0;
		for(int i = 0; i < n; i++){
			if(a[i] == x) count++;
		}
		if(count == 0) cout << -1;
		else cout << count;
		cout << endl;
	}
}

