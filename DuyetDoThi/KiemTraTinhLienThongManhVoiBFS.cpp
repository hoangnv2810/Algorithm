#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
bool vs[1001];
void BFS(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		u = q.front();
		q.pop();
		vs[u] = true;
		for(int i = 0; i < ke[u].size(); i++){
			if(!vs[ke[u][i]]){
				vs[ke[u][i]] = true;
				q.push(ke[u][i]);
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
		for(int i = 1; i <= v; i++){
			ke[i].clear();
		}
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
		}
		
		if(tplt(v) == 1) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}

