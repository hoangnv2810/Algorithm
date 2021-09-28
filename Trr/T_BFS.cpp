#include<bits/stdc++.h>
using namespace std;

int u, a[100][100], chuaxet[100], n, dau[100], cuoi[100], c;
void T_BFS(int a[100][100]){
	queue<int> q;
	q.push(u);
	chuaxet[u] = 1;
	while(q.empty()){
		u = q.front();
		q.pop();
		for(int v = 1; v <= n; v++){
			if(a[u][v] == 1 && chuaxet[v] == 0){
				q.push(v);
				dau[c] = u;
				cuoi[c] = v;
				c++;
				chuaxet[v] = 1;
			}
		}
		
	}
	if(c == n-1){
		cout << "\nCay khung T: ";
		for(int i = 1; i < c; i++){
			if(dau[i] < cuoi[i]){
				cout << "(" << dau[i] << ", " << cuoi[i] << ")";
			} else {
				cout << "(" << cuoi[i] << ", " << dau[i] << ")";
			}
		}
	} else {
		cout << "\nDo thi khong lien thong";
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){

	}
}

