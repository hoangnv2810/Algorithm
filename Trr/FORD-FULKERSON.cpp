#include<bits/stdc++.h>
using namespace std;

bool readFile(int graph[100][100], int &n){
	ifstream read ("DT.INP");
	if(read.is_open()){
		read >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				read >> graph[i][j];
			}
		}
		read.close();
		return true;
	}
	return false;
}

bool writeFile(int graph[100][100], int n, int value){
	ofstream write("DT.OUT");
	if(write.is_open()){
		write << value << endl;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				write << graph[i][j] << " ";
			}
			write << endl;
		}
		return true;
	}
	return false;
}

bool BFS(int rGraph[100][100], int s, int t, int n, int parent[]){
	bool visited[100];
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v = 1; v <= n; v++){
			if(visited[v] == false && rGraph[u][v] > 0){
				if(v == t){
					parent[v] = u;
					return true;
				}
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}	
	return false;
}

int Ford_Fulkerson(int graph[100][100], int s, int t){	
	int u, v, n = t;
	int rGraph[100][100]; 
	for (u = 0; u < 100; u++)
		for (v = 0; v < 100; v++)
			rGraph[u][v] = graph[u][v];

	int parent[100]; 
	int max_flow = 0; 
	while (BFS(rGraph, s, t, n, parent)) {
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main(){
	int n, graph[100][100];
	if(!readFile(graph, n)){
		cout << "Ko doc duoc file";
	}
	int val = Ford_Fulkerson(graph, 1, n);
	if(!writeFile(graph, n, val)){
		cout << "Ko viet dc file";
	}
}

