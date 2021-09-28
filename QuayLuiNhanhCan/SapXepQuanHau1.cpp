#include<bits/stdc++.h>
using namespace std;
void Try(int i, int a[], int b[], int c[], int d[], int n, int &res){
	for(int j = 1; j <= n; j++){
		if(a[j] == 0 && b[j] == 0 && c[i+j-1] == 0 && d[i-j+n] == 0){
			a[j] = b[j] = c[i+j-1] = d[i-j+n] = 1;
			if(i == n){
				res++;
			} else {
				Try(i+1, a, b, c, d, n, res);
			}
			a[j] = b[j] = c[i+j-1] = d[i-j+n] = 0;
		}
	}
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, res = 0;
		int a[100] = {0}, b[100] = {0}, c[100] = {0}, d[100] = {0};
		cin >> n;
		
		Try(1, a, b, c, d, n, res);
		cout << res << endl;
	}
}