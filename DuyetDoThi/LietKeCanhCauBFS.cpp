#include<bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
bool vs[1001];
struct edge {
	int start;
	int end;
};

void BFS(int u) {
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		vs[u] = true;
		for (int i = 0; i < ke[u].size(); i++) {
			if (!vs[ke[u][i]]) {
				q.push(ke[u][i]);
				vs[ke[u][i]] = true;
			}
		}
	}
}

int tplt(int v) {
	int k = 0;
	for (int i = 1; i <= v; i++) {
		if (!vs[i]) {
			k++;
			BFS(i);
		}
	}
	return k;
}

vector<edge> res;
void canhCau(int canh, int k, int v, int e, vector<edge> temp) {
	memset(vs, false, sizeof(vs));
	for (int i = 0; i <= v; i++) {
		ke[i].clear();
	}
	for (int i = 0; i < e; i++) {
		if (i != canh) {
			ke[temp[i].start].push_back(temp[i].end);
			ke[temp[i].end].push_back(temp[i].start);
		}
	}

	int count = tplt(v);
	if (count > k) {
		edge eg;
		if (temp[canh].start > temp[canh].end) {
			eg.start = temp[canh].end;
			eg.end = temp[canh].start;
			res.push_back(eg);
		}
		else {
			eg.start = temp[canh].start;
			eg.end = temp[canh].end;
			res.push_back(eg);
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		memset(vs, false, sizeof(vs));
		for (int i = 0; i <= v; i++) {
			ke[i].clear();
		}
		res.clear();
		vector<edge> temp;
		
		for (int i = 0; i < e; i++) {
			int dau, cuoi;
			cin >> dau >> cuoi;
			edge t = { dau, cuoi };
			temp.push_back(t);
			ke[dau].push_back(cuoi);
			ke[cuoi].push_back(dau);
		}
		int k = tplt(v);
		for (int i = 0; i < e; i++) {
			canhCau(i, k, v, e, temp);
		}
		//sort(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++) {
			cout << res[i].start << " " << res[i].end << " ";
		}
		cout << endl;

	}
}

