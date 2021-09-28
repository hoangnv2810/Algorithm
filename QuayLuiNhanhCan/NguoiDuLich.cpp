#include<bits/stdc++.h>
using namespace std;
long a[16][16], x[16], vs[16], sum = 0, res = INT_MAX, n, minA = INT_MAX;

void Try(int i){
	if(sum + minA*(n-i+1) >= res) return;
	for(int j = 2; j <= n; j++){
		if(!vs[j]){
			x[i] = j;
			vs[j] = 1;
			sum += a[x[i-1]][j];
			if(i == n){
				res = min(res, sum + a[x[n]][x[1]]);
			} else {
				Try(i+1);
			}
			vs[j] = 0;
			sum -= a[x[i-1]][j];
		}
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] != 0){
				minA = min(minA, a[i][j]);
			}
		}
	}
	x[1] = 1;
	vs[1] = 1;
	Try(2);
	cout << res;
}
