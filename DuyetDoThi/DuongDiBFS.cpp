#include<bits/stdc++.h>
using namespace std;

bool visited[1001];
int a[1001][1001], truoc[1001];
void BFS(int u, int v){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int i = 1; i <= v; i++){
			if(a[u][i] == 1 && !visited[i]){
				visited[i] = true;
				q.push(i);
				truoc[i] = u;
			}
		}
	}
}

void result(int s, int t){
	vector<int> res;
	if(truoc[t] == 0){
		cout << -1;
	} else {
		res.push_back(t);
		while(t != s){
			t = truoc[t];
			res.push_back(t);
		}
		for(int i = res.size()-1; i >= 0; i--){
			cout << res[i] << " ";
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e, u, t;
		cin >> v >> e >> u >> t;
		memset(visited, false, sizeof(visited));
		memset(a, 0, sizeof(a));
		int start, end;
		for(int i = 0; i < e; i++){
			cin >> start >> end;
			a[start][end] = 1;
			a[end][start] = 1;
		}
		BFS(u, v);
		result(u, t);
		cout << endl;
	}
}

