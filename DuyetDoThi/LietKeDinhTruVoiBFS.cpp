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
		
		int k = 0;
		for(int i = 1; i <= v; i++){
			if(!vs[i]){
				k++;
				BFS(i);
			}
		}
		
		for(int i = 1; i <= v; i++){
			memset(vs, false, sizeof(vs));
			vs[i] = true;
			int dem = 0;
			for(int j = 1; j <= v; j++){
				if(!vs[j]){
					dem++;
					BFS(j);
				}
			}
			if(dem > k) cout << i << " ";
		}	
		cout << endl;
	}
}
