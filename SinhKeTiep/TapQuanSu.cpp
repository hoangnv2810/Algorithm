#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k, *a, *b;
		cin >> n >> k;
		a = new int[k+1];
		b = new int[k+1];
		for(int i = 1; i <= k; i++) cin >> a[i];
		for(int i = 1; i <= k; i++) b[i] = a[i];
		while(1){
			int i = k;
			while(i > 0 && a[i] == n-k+i) i--;
			if(i == 0){
				cout << k << endl;
				break;
			} else {
				a[i]++;
				for(int j = i+1; j <= k; j++) a[j] = a[i]+j-i;
				int res = 0;
				for(int l = 1; l <= k; l++){
					for(int j = 1; j <= k; j++){
						if(b[l] == a[j]) res++;
					}
				}	 
				cout << k-res << endl;
				break;
			}
		}
	}
}

