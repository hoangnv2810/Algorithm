#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k, sum = 0;
		cin >> n >> k;
		int* a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
		}
		int check = 0;	
		if(sum % k == 0){
			sum /= k;
		} else {
			check = 1;
		}
	
		for(int i = 0; i < n; i++){
			if(a[i] > sum ) check = 1;
		}
		if(check) cout << 0;
		else cout << 1;
		cout << endl;
		
	}
}
