#include<bits/stdc++.h>
using namespace std;

bool visited[1001];
int a[1001][1001];
void DFS(int u, int v){
	stack<int> s;
	s.push(u);
	cout << u << " ";
	visited[u] = true;
	while(!s.empty()){
		u = s.top();
		s.pop();
		for(int i = 1; i <= v; i++){
			if(a[u][i] == 1 && !visited[i]){
				cout << i << " ";
				visited[i] = true;
				s.push(u);
				s.push(i);
				break;
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
		}
		DFS(u, v);
		cout << endl;
	}
}

