#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a, *b;
		cin >> n;
		a = new int[n];
		b = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b+n);
		int check = 1;
		for(int i = 0; i < n; i++){
			if(a[i] != b[i] && a[i] != b[n-i-1]){
				check = 0;
				break;
			}
		}
		if(check) cout << "Yes";
		else cout << "No";
		cout << endl;
	}
}

