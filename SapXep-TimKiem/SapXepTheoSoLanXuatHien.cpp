#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, val;
		vector<int> a;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> val;
			a.push_back(val);
		}

		map<int, int> mp;
		for (auto x : a) {
			mp[x]++;
		}

		vector<pair<int, int>> vt(mp.begin(), mp.end());

		for (int i = 0; i < vt.size(); i++) {
			for (int j = i + 1; j < vt.size(); j++) {
				if (vt[i].second < vt[j].second) {
					swap(vt[i], vt[j]);
				}
				else if (vt[i].second == vt[j].second) {
					if (vt[i].first > vt[j].first) {
						swap(vt[i], vt[j]);
					}
				}
			}
		}

		for (auto x : vt) {
			while (x.second--) cout << x.first << " ";
		}
		cout << endl;
		
	}
}
