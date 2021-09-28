#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
bool vs[1001];
bool BFS(int s, int t){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		s = q.front();
		q.pop();
		vs[s] = true;
		if(s == t) return true;
		for(int i = 0; i < ke[s].size(); i++){
			if(!vs[ke[s][i]]){
				vs[ke[s][i]] = true;
				q.push(ke[s][i]);
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
		for(int i = 0; i < v+1; i++){
			ke[i].clear();
		}
		
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		int test, s, t;
		cin >> test;
		for(int i = 0; i < test; i++){
			memset(vs, false, sizeof(vs));
			cin >> s >> t;
			if(BFS(s, t)) cout << "YES";
			else cout << "NO";
			cout << endl;
		}
	}
}

