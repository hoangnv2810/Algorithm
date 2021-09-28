#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector< vector<char> > res;

int solution(int a[100], int n, int k) {
	int dem = 0, check = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) dem++;
		else dem = 0;
		if (dem == k) check++;
		else if (dem > k) return 0;
	}
	return (check == 1);
}

void sinh(int i, int n, int a[100], int k) {
	for (int j = 0; j <= 1; j++) {
		a[i] = j;
		if (i == n) {
			if (solution(a, n, k) == 1) {
				vector<char> x;
				for (int i = 1; i <= n; i++) {
					if (a[i]) x.push_back(a[i] + 64);
					else x.push_back(a[i] + 66);
				}
				res.push_back(x);
			}
		}
		else {
			sinh(i + 1, n, a, k);
		}
	}
}

void result() {
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for (auto x : res) {
		for (auto y : x) cout << y;
		cout << endl;
	}
}

int main() {
	int n, a[100], k;
	cin >> n >> k;
	sinh(1, n, a, k);
	result();
}
