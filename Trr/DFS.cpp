#include<bits/stdc++.h>
using namespace std;
int a[100][100], n, u;
int truoc[100];
bool vs[100];
void DFSDeQuy(int u){
	vs[u] = true;
	for(int i = 0; i < ke[i].size(); i++){
		if(!vs[ke[u][i]]) {
			truoc[ke[u][i]] = u;
			DFSDeQuy(u);
		}
	}
}

void DFS(int u){
	stack<int> st;
	st.push(u);
	vs[u] = true;
	while(!st.empty()){
		int v = st.top();
		st.pop();
		cout << v << " ";
		for(int i = 1; i <= n; i++){
			if(a[v][i] && vs[i] == false){
				vs[i] = true;
				st.push(i);
				truoc[i] = v;
				break;
			}
		}
	}
}

int main(){
	
}

