#include<bits/stdc++.h>
using namespace std;
int n, s, t, a[100][100], d[100], truoc[100], chuaxet[100];
void DIJKSTRA(int s){
	for(int v = 1; v <= n; v++){
		d[v] = a[s][v];
		truoc[v] = s;
		chuaxet[v] = 0;
	}
	truoc[s] = 0; d[s] = 0; chuaxet[s] = 1;
	while(!chuaxet[t]){
		int min = INT_MAX;
		for(int v = 1; v <= n; v++){
			if(!chuaxet[v] && (min > d[v])){
				u = v;
				min = d[v];
			}
		}
		chuaxet[u] = 1;
		if(!chuaxet[t]){
			for(int v = 1; v <= n; v++){
				if(!chuaxet[v] && (d[u] + a[u][v] < d[v])){
					d[v] = d[u] + a[u][v];
					truoc[v] = u;
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

