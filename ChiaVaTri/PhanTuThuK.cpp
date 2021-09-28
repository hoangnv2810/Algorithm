// Cho hai mảng đã được sắp xếp A[], B[] gồm M, N phần tử theo thứ tự và số K. Nhiệm vụ của bạn là tìm phần tử ở vị trí số K sau khi trộn hai mảng để nhận được một mảng được sắp xếp.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int *a, *b, m, n, k;
		cin >> m >> n >> k;
		a = new int[m];
		b = new int[n];
		vector<int> v;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
			v.push_back(a[i]);
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			v.push_back(b[i]);
		}

		sort(v.begin(), v.end());

		cout << v[k-1] << endl;

	}
}