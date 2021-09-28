#include<bits/stdc++.h>
using namespace std;
struct edge{
	int start;
	int end;
};

int find(int parent[], int i){
	if(parent[i] == -1) return i;
	else return find(parent, parent[i]);
}

void Union(int parent[], int x, int y){
	parent[x] = y;
}


int main(){
	int t;
	cin >> t;
	while(t--){	
		int v, e;
		cin >> v >> e;
		int parent[1001];
		vector<edge> vt;
		memset(parent, -1, sizeof(parent));
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			edge eg = {start-1, end-1};
			vt.push_back(eg);
		}
		
		int check = 0;
		for(int i = 0; i < e; i++){
			int x = find(parent, vt[i].start);
			int y = find(parent, vt[i].end);
			if(x == y){
				check = 1;
				break;
			}
			Union(parent, x, y);
		}
		if(check) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}

