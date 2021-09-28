#include<bits/stdc++.h>
using namespace std;

int oo = 1000000, a[100][100], e[100][100], n, d[100][100], s[100][100];
void FLOYD(int a[100][100]){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			d[i][j] = a[i][j];
			if(d[i][j] == oo) s[i][j] = 0;
			else e[i][j] = j;
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if((d[i][j] > d[i][k] + d[k][j]) && d[i][k] != oo){
					d[i][j] = d[i][k] + d[k][j];
					e[i][j] = e[i][k];
				}
			}
		}
	}
}


int main(){
	int t;
	cin >> t;
	while(t--){

	}
}

