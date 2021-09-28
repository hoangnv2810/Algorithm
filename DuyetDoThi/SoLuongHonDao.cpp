#include<bits/stdc++.h>
using namespace std;
int vs[501][501];
int a[501][501], m, n;

void DFS(int row, int col){
	int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
	vs[row][col] = 1;
	for(int i = 0; i < 8; i++){
		row += dx[i];
		col += dy[i];
		if(row >= 1 && row <= m && col >= 1 && col <= n && !vs[row][col] && a[row][col]){
			DFS(row, col);
		}
		row -= dx[i];
		col -= dy[i];
	}
}

int countIslands(int m, int n){
	memset(vs, 0, sizeof(vs));
	int k = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] && !vs[i][j]){
				DFS(i, j);
				k++;
			}
		}
	}
	return k;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> m >> n;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
			}
		}
		cout << countIslands(m, n) << endl;
	}
}
