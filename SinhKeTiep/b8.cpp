#include<bits/stdc++.h>
using namespace std;

int res = 0;
void Try(int i, int j , int m, int n, int a[100][100]){
	if(i == m-1 || j == n-1){
		res++;
		return;
	}
	if(i < m-1) Try(i+1, j, m, n, a);
	if(j < n-1) Try(i, j+1, m, n, a);
	if(i > m - 1 || j > n-1) return;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int m, n;
		cin >> m >> n;
		int a[100][100];
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		Try(0, 0, m, n, a);
		cout << res << endl;
		res = 0;
		
	}
}

