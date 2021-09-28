#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int l, int r, int x){
	if(l <= r) {
		int mid = (r-l)/2 + l;
		if(x == a[mid]) return mid+1;
		else if(x > a[mid]) return binary_search(a, mid+1, r, x);
		else return binary_search(a, l, mid-1, x);
	} 
	return -1;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a, x;
		cin >> n >> x;
		a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int res = binary_search(a, 0, n-1, x);
		if(res == -1) cout << "NO";
		else cout << res; 
		cout << endl;
	}
}

