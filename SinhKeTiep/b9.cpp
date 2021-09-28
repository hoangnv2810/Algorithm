#include<bits/stdc++.h>
using namespace std;
int cot[100];
void Try(int i, int b[], int c[], int d[], int n, int &res, int v[100][100]){
	for(int j = 1; j <= n; j++){
		if(b[j] == 0 && c[i+j-1] == 0 && d[i-j+n] == 0){
			cot[i] = j;
			b[j] = c[i+j-1] = d[i-j+n] = 1;
			if(i == n){
				int ans = 0;
				for(int k = 1; k <= n; k++){
					ans += v[k][cot[k]];
				}
				res = max(ans, res);
			} else {
				Try(i+1, b, c, d, n, res, v);
			}
			b[j] = c[i+j-1] = d[i-j+n] = 0;
		}
	}
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n = 8, res = 0;
		int b[100] = {0}, c[100] = {0}, d[100] = {0}, v[100][100];
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin >> v[i][j];
			}
		}
		
		Try(1, b, c, d, n, res, v);
		cout << res << endl;
	}
}

