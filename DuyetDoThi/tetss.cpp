#include<bits/stdc++.h>
using namespace std;
bool vs[1001];
vector<int> ke[1001];
void BFS(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		u = q.front();
		q.pop();
		vs[u] = true;
		cout << u << " ";
		for(int i = 0; i < ke[u].size(); i++){
			if(!vs[ke[u][i]]){
				q.push(ke[u][i]);
				vs[ke[u][i]] = true;
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
		memset(vs, false, sizeof(vs));
		for(int i = 0; i <= v; i++){
			ke[i].clear();
		}
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
		}
		BFS(u);
		cout << endl;
	}
}

