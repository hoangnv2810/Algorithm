#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int x[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
		int n, sum, a[10] = {0};
		cin >> n;
		int i = 0;
		while(i < 10){
			if(x[i] <= n){
				a[i]++;
				n = n - x[i];
			} 
			if(n == 0) break;
			else {
				if(n < x[i]) i++;
			}
		}
		int res = 0;
		for(int i = 0; i < 10; i++) res += a[i];
		cout << res << endl;
	}
}
