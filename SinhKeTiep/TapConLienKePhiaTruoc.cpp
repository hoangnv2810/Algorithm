#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k, *a;
		cin >> n >> k;
		a = new int[n];
		for(int i = 1; i <= k; i++){
			cin >> a[i];
		}
		int check = 1;
		for(int i = 1; i <= k; i++){
			if(a[i] == i) check *= 1;
			else check *= 0;
		}
		if(check) {
			for(int i = k; i >= 1; i--) cout << n-i+1 << " ";
		} else {
			int i = k;
			while(i > 0){
				while(a[i] == a[i-1]+1 && i > 1){
					i--;
				} 
				a[i]--;
				for(int j = i+1; j <= k; j++){
					a[j] = n-k+j;
				}
				break;
			}
			for(int i = 1; i <= k; i++) cout << a[i] << " ";	
		}
		cout << endl;
	}
}

