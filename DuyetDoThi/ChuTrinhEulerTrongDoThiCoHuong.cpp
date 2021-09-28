#include<bits/stdc++.h>
using namespace std;

int check(int v, int deg[1001][2]){
	for(int i = 1; i <= v; i++){
		if(deg[i][0] != deg[i][1]) return 0;
	}
	return 1;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		int deg[v+1][2];
		memset(deg, 0, sizeof(deg));
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			deg[start][0]++;
			deg[end][1]++;
		}
		
		cout << check(v, deg) << endl; 
	}
}

