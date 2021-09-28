#include<iostream>
using namespace std;
int find(int n, int* in, int x) {
	for (int i = 0; i < n; i++) {
		if (x == in[i]) {
			return i;
		}
	}
	return -1;
}

void postorder(int n, int* in, int* pre) {
	int root = find(n, in, pre[0]);
	if (root != 0) {
		postorder(root, in, pre + 1);
	}
	if (root != n - 1) {
		postorder(n - root - 1, in + root + 1, pre + root + 1);
	}
	cout << pre[0] << " ";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int* in = new int[n];
		int* pre = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> in[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> pre[i];
		}
		postorder(n, in, pre);
		cout << endl;
	}
}
