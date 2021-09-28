#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int vs[501][501], a[501][501], m, n;

class Node {
public:
	int x, y;
	Node(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

void solutionBFS(int row, int col) {
	int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	queue<Node> q;
	q.push(Node(row, col));
	while (!q.empty()) {
		Node node = q.front();
		q.pop();
		row = node.x;
		col = node.y;
		vs[row][col] = 1;
		for (int i = 0; i < 8; i++) {
			row += dx[i];
			col += dy[i];
			if (row >= 1 && row <= m && col >= 1 && col <= n && a[row][col] && !vs[row][col]) {
				q.push(Node(row, col));
			}
			row -= dx[i];
			col -= dy[i];
		}
	}
}

int countIslands(int m, int n) {
	int k = 0;
	memset(vs, 0, sizeof(vs));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] && !vs[i][j]) {
				solutionBFS(i, j);
				k++;
			}
		}
	}
	return k;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		cout << countIslands(m, n) << endl;
	}
}
