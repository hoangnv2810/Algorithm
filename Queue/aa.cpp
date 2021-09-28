#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int solutionBFS(int s, int t){
	queue<int> q;
	q.push(s);
	queue<int> c;
	c.push(0);
	int visited[MAX] = {};
	visited[s] = 1;
	while(q.front() != t){
		int y = q.front(); q.pop();
		int x = c.front(); c.pop();
		if(y-1 > 0 && y-1 < MAX && visited[y-1] == 0){
			q.push(y-1);
			c.push(x+1);
			visited[y-1] = 1;
		}
		if(y*2 > 0 && y*2 < MAX && visited[y*2] == 0){
			q.push(y*2);
			c.push(x+1);
			visited[y*2] = 1;
		}
	}
	return c.front();
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int s, t;
		cin >> s >> t;
		cout << solutionBFS(s, t);
		cout << endl;
	}
}
