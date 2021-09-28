#include<bits/stdc++.h>
using namespace std;
int a[100][100], n, u;
int truoc[100];
bool chuaxet[100];
void DFS(int u){
	queue<int> q;
	q.push(u);
	chuaxet[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		cout << v << " ";
		for(int i = 1; i <= n; i++){
			if(a[v][i] && chuaxet[i] == false){
				chuaxet[i] = true;
				st.push(i);
				truoc[i] = v;
				break;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){

	}
}

