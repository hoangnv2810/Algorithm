#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1005];
bool vs[1005];

void DFS(int u){
	vs[u] = true;
	cout << u << " ";
	for(int i = 0; i < ke[u].size(); i++){
		if(vs[ke[u][i]] == false){
			DFS(ke[u][i]);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e, u;
		cin >> v >> e >> u;
		for(int i = 0; i <= v; i++){
			ke[i].clear();
		}
		memset(vs, false, sizeof(vs));
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		DFS(u);
		cout << endl;
	}
}

