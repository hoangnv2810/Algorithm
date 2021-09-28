#include<bits/stdc++.h>
using namespace std;
vector<int> ke[10];
bool vs[10];
bool DFS(int u){
	vs[u] = true;
	for(int i = 0; i < ke[u].size(); i++){
		if(!vs[ke[u][i]]){
			DFS(ke[u][i]);
		} else if(vs[ke[u][i]]) return true;
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		for (int i = 0; i <= v; i++) {
			ke[i].clear();
		}
		memset(vs, false, sizeof(vs));
		for (int i = 0; i < e; i++) {
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
		}
		if (DFS(1)) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}

