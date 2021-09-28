#include<bits/stdc++.h>
using namespace std;
int vs[1001][1001], a[1001][1001], m, n;

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

int countFishPounds(int m, int n){
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

int main() {
	cin >> m >> n;
	char b[m + 1][n + 1];
	memset(vs, false, sizeof(vs));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> b[i][j];
			if (b[i][j] == 'W') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	cout << countFishPounds(m, n) << endl;
}

