#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, * a;
		cin >> n;
		a = new int[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		int l = 0, r = n-1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				l = i;
				break;
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			if (a[i] < a[i - 1]) {
				r = i;
				break;
			}
		}

		sort(a + l, a + r + 1);
		for (int i = 0; i < l; i++) {
			if (a[i] > a[l]) {
				l = i;
				break;
			}
		}
		for (int i = n-1; i > r; i--) {
			if (a[i] < a[r]) {
				r = i;
				break;
			}
		}
		cout << l+1 << " " << r+1 << endl;
	}
}