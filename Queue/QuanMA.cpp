#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

class cell {
public:
	int x, y, level;
	cell(int x, int y, int level) {
		this->x = x;
		this->y = y;
		this->level = level;
	}
};

int KnightBFS(int startX, int startY, int endX, int endY) {
	int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	queue<cell> q;
	q.push(cell(startX, startY, 0));
	int visited[9][9];
	memset(visited, 0, sizeof(visited));
	visited[startX][startY] = 1;
	while (!q.empty()) {
		cell c = q.front();
		q.pop();

		if (c.x == endX && c.y == endY) return c.level;
		for (int i = 0; i < 8; i++) {
			int x = c.x + dx[i];
			int y = c.y + dy[i];
			if (x >= 1 && x <= 8 && y >= 1 && y <= 8 && visited[x][y] == 0) {
				q.push(cell(x, y, c.level + 1));
				visited[x][y] = 1;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string x, y;
		cin >> x >> y;
		int startX, startY;
		startX = (int)x[0] - 96;
		startY = (x[1] - '0');
		int endX, endY;
		endX = (int)y[0] - 96;
		endY = (y[1] - '0');
		cout << KnightBFS(startX, startY, endX, endY);
		cout << endl;
	}
}
