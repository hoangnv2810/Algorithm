#include<bits/stdc++.h>
using namespace std;

/// SAI
vector<int> ke[1001];
bool vs[1001];
int truoc[1001];
bool DFS(int u){
	stack<int> s;
	s.push(u);
	while(!s.empty()){
		u = s.top();
		s.pop();
		vs[u] = true;
		for(int i = 0; i < ke[i].size(); i++){
			if(!vs[ke[u][i]]){
				s.push(u);
				s.push(ke[u][i]);
				vs[ke[u][i]] = true;
				truoc[ke[u][i]] = u;
				break;
			} else if(truoc[u] != ke[u][i]){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		memset(vs, false, sizeof(vs));
		memset(truoc, 0, sizeof(truoc));
		for(int i = 1; i <= v; i++){
			ke[i].clear();
		}
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		int res = 0;
		for(int i = 1; i <= v; i++){
			if(!vs[i] && DFS(i)){
				res = 1;
				break;
			}
		}	
		if(res) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}

