#include<bits/stdc++.h>
using namespace std;

bool visited[1001];
int a[1001][1001], truoc[1001];
void DFS(int u, int v){
	stack<int> s;
	s.push(u);
	visited[u] = true;
	while(!s.empty()){
		u = s.top();
		s.pop();
		for(int i = 1; i <= v; i++){
			if(a[u][i] == 1 && !visited[i]){
				visited[i] = true;
				s.push(u);
				s.push(i);
				truoc[i] = u;
				break;
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
		DFS(u, v);
		result(u, t);
		cout << endl;
	}
}

