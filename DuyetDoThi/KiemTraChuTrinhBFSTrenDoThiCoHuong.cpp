#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
bool cycleBFS(int v){
	vector<int> indegree(v+1, 0);
	for(int i = 1; i <= v; i++){
		for(int j = 0; j < ke[i].size(); j++){
			indegree[ke[i][j]]++;
		}
	}
	queue<int> q;
	for(int i = 1; i <= v; i++){
		if(indegree[i] == 0) q.push(i);
	}
	int count = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < ke[u].size(); i++){
			if(--indegree[ke[u][i]] == 0) q.push(ke[u][i]);
		}
		count++;
	}
	if(count == v) return false;
	else return true;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		for(int i = 0; i <= v; i++){
			ke[i].clear();
		}
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
		}
		if(cycleBFS(v)) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}

