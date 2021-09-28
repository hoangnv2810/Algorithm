#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		for(int i = 1; i <= n; i++){
			a[i] = i;
		}
		while(1){
			for(int i = 1; i <= n; i++) cout << a[i];
			cout << " ";
			int i = n-1;
			while(a[i] > a[i+1]) i--;
			
			
			if(i == 0) break;
			else {
				int j;
				for(j = n; j > i; j--){
					if(a[j] > a[i]) break;
				}
				swap(a[i], a[j]);
				int l = i+1, r = n;
				while(l < r){
				swap(a[l], a[r]);
					l++, r--;
				}
			}
			
		}
		cout << endl;
	}
}
