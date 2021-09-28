#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n, *a, *b;
		map<int, int> mp;
		vector<int> v;
		cin >> m >> n;
		a = new int[m];
		b = new int[n];
		for (int i = 0; i < m; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			mp[b[i]]++;
		}

		for (auto x : mp) {
			if (x.second >= 1) cout << x.first << " ";
		}
		cout << endl;
		for (auto x : mp) {
			if (x.second > 1) cout << x.first << " ";
		}
		
		cout << endl;

	}
}

