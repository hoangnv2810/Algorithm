#include<bits/stdc++.h>
using namespace std;

bool vs[1001];
int a[1001][1001];
void BFS(int u, int v){
	queue<int> q;
	q.push(u);
	vs[u] = true;
	while(!q.empty()){
		u = q.front();
		q.pop();
		cout << u << " ";
		for(int i = 1; i <= v; i++){
			if(a[u][i] == 1 && !vs[i]){
				q.push(i);
				vs[i] = true;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e, u;
		cin >> v >> e >> u;
		memset(a, 0, sizeof(a));
		memset(vs, false, sizeof(vs));
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			a[start][end] = 1;
		}
		
		BFS(u, v);
		cout << endl;
	}
}

