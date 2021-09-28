#include<bits/stdc++.h>
using namespace std;
int a[100][100], n;
int chuaxet[100];
int TPLT_BFS(int a[100][100]){
	int k = 0;
	for(int i = 1; i <= n; i++) chuaxet[i] = 0;
	for(int i = 1; i <= n; i++){
		if(chuaxet[i] == 0){
			k++;
			BFS(i);
		}
	}
	return k;
}

int main(){
	int t;
	cin >> t;
	while(t--){

	}
}

