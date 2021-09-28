#include<bits/stdc++.h>
using namespace std;

bool visited[1001];
int a[1001][1001];
void BFS(int u, int v){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		u = q.front();
		q.pop();
		cout << u << " ";
		for(int i = 1; i <= v; i++){
			if(a[u][i] == 1 && !visited[i]){
				visited[i] = true;
				q.push(i);
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
		memset(visited, false, sizeof(visited));
		memset(a, 0, sizeof(a));
		int start, end;
		for(int i = 0; i < e; i++){
			cin >> start >> end;
			a[start][end] = 1;
			a[end][start] = 1;
		}
		BFS(u, v);
		cout << endl;
	}
}

