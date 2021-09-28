#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, sum, val;
		vector<int> a;
		cin >> n >> sum;
		for (int i = 0; i < n; i++) {
			cin >> val;
			a.push_back(val);
		}

		map<int, int> mp;
		for (auto x : a) {
			mp[x]++;
		}

		int res = 0;
		for (auto x : a) {
			res += mp[sum - x];
			if (x == sum - x) {
				res--;
			}
		}
		
		cout << res/2 << endl;
	}
}