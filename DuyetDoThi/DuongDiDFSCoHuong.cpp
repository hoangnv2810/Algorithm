#include<bits/stdc++.h>
using namespace std;

bool vs[1001];
int truoc[1001];
vector<int> ke[1001];
void DFS(int u){
	stack<int> s;
	s.push(u);
//	cout << u << " ";
	vs[u] = true;
	while(!s.empty()){
		u = s.top();
		s.pop();
		for(int i = 0; i < ke[u].size(); i++){
			if(!vs[ke[u][i]]){
//				cout << ke[u][i] << " ";
				s.push(u);
				s.push(ke[u][i]);
				vs[ke[u][i]] = true;
				truoc[ke[u][i]] = u;
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
		memset(vs, false, sizeof(vs));
		memset(truoc, 0, sizeof(truoc));
		for(int i = 1; i < v+1; i++){
			ke[i].clear();
		}
		int start, end;
		for(int i = 0; i < e; i++){
			cin >> start >> end;
			ke[start].push_back(end);
		}
		DFS(u);
		result(u, t);
		cout << endl;
	}
}

