#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int	n, k, *a;
		cin >> n >> k;
		a = new int[n];
		for(int i = 1; i <= n; i++) a[i] = 0;
		
		while(1){
			int sum = 0;
			string res = "";
			for(int i = 1; i <= n; i++){
				sum += a[i];
				res += a[i]+'0';
			}
			if(sum == k) cout << res << endl;
			
			int i = n;
			while(i > 0 && a[i] == 1){
				a[i] = 0;
				i--;
			}
			if(i == 0) break;
			else {
				a[i] = 1;
			}
		}
	}
}
