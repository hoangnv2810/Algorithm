#include<bits/stdc++.h>
using namespace std;
int vs[100], n;
long a[20][20], x[100], sum = 0, res = INT_MAX, amin = INT_MAX;

void Try(int i){
	if(sum + amin*(n-i+1) >= res) return;
	for(int j = 2; j <= n; j++){
		if(!vs[j]){
			x[i] = j;
			vs[j] = 1;
			sum += a[x[i-1]][j];
			if(i == n){
//				if(sum + a[x[n]][x[1]] < res){
//					res = sum + a[x[n]][x[1]];
//				}
				res = min(res, sum += a[x[n]][x[1]]);
			} else {
				Try(i+1);
			}
			sum -= a[x[i-1]][j];
			vs[j] = 0;
		}
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(i != j) amin = min(amin, a[i][j]);
		}
	}
	x[1] = 1;
	vs[1] = 1;
	Try(2);
	cout << res << endl;
}
