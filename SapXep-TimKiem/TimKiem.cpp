#include<iostream>
#include<algorithm>
using namespace std;

int binary_search(int a[], int l, int r, int x) {
	if (l <= r) {
		int mid = (r-l) / 2 + l;
		if (a[mid] == x) return 1;
		if (a[mid] > x) return binary_search(a, l, mid - 1, x);
		else return binary_search(a, mid + 1, r, x);

	}
	return -1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, * a, x;
		cin >> n >> x;
		a = new int[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		cout << binary_search(a, 0, n - 1, x) << endl;
	}
}

