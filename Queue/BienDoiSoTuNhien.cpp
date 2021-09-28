#include<iostream>
#include<string>
#include<queue>
#include<set>
using namespace std;

class Node {
public:
	int val, level;
	Node(int val, int level) {
		this->val = val;
		this->level = level;
	}
};

int solutionBFS(int n) {
	queue<Node> q;
	q.push(Node(n, 0));
	set<int> s;
	s.insert(n);
	while (!q.empty()) {
		Node node = q.front();
		q.pop();
		if (node.val == 1) return node.level;
		if (node.val - 1 == 1) return node.level + 1;
		else if (s.find(node.val - 1) == s.end()) {
			q.push(Node(node.val - 1, node.level + 1));
			s.insert(node.val - 1);
		}
		for (int i = 2; i * i <= node.val; i++) {
			if (node.val % i == 0 && s.find(node.val / i) == s.end()) {
				q.push(Node(node.val / i, node.level + 1));
				s.insert(node.val / i);
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << solutionBFS(n);
		cout << endl;
	}
}
