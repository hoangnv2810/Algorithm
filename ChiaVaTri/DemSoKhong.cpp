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
		int res = 0;
		for(int i = 0; i < n; i++){
			if(a[i] == 0) res++;
		}
		cout << res;
		cout << endl;
	}
}

