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
		for(int i = 0; i < ke[u].size(); i++){
			if(!vs[ke[u][i]]){
				q.push(ke[u][i]);
				vs[ke[u][i]] = true;
			}
		}
	}
}

int tplt(int v){
	int k = 0;
	for(int i = 1; i <= v; i++){
		if(!vs[i]){
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
		int v, e;
		cin >> v >> e;
		memset(vs, false, sizeof(vs));
		for(int i = 0; i <= v; i++){
			ke[i].clear();
		}
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		cout << tplt(v);
		cout << endl;
	}
}

