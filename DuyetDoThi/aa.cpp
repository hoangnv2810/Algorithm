#include<bits/stdc++.h>
using namespace std;
bool visited[1000];
int a[1000][1000];
int n, e, u;
void DFS(int u){
	stack<int> s;
	s.push(u);
	visited[u] = true;
	cout << u << " ";
	while(!s.empty()){
		u = s.top();
		s.pop();
		for(int v = 1; v <= n; v++){
			if(a[u][v] == 1 && !visited[v]){
				cout << v << " ";
				visited[v] = true;
				s.push(u);
				s.push(v);
				break;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		memset(visited, false, sizeof(visited));
		memset(a, 0, sizeof(a));
		cin >> n >> e >> u;
		int start, end;
		for(int i = 1; i <= e; i++){
			cin >> start >> end;
			a[start][end] = 1;
			a[end][start] = 1;
		}
		DFS(u);
		cout << endl;
	}
}
