#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
struct Node {
	int val;
	int level;
};

int solutionBFS(int x, int y) {
	int visit[MAX];
	memset(visit, 0, sizeof(visit));
	queue<Node> q;
	Node nd;
	nd.val = x;
	nd.level = 0;
	q.push(nd);
	visit[x] = 1;
	while (q.front().val != y) {
		Node n = q.front();
		q.pop();
		
		if (n.val*2 < MAX && n.val*2 > 0 && visit[n.val*2] == 0) {
			nd.val = n.val*2;
			nd.level = n.level+1;
			visit[n.val*2] = 1;
			q.push(nd);
		}
		if (n.val-1 > 0  && n.val-1 < MAX && visit[n.val-1] == 0) {
			nd.val = n.val-1;
			nd.level = n.level+1;
			visit[n.val-1] = 1;
			q.push(nd);
		}
	}
	return q.front().level;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int s, t;
		cin >> s >> t;
		cout << solutionBFS(s, t);
		cout << endl;
	}
}
