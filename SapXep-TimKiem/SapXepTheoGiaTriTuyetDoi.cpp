#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, val, temp;
		vector<int> a;
		cin >> n >> temp;
		for (int i = 0; i < n; i++) {
			cin >> val;
			a.push_back(val);
		}

		multimap<int, int> mp;
		for (auto x : a) {
			mp.insert(pair<int, int>(abs(x - temp), x));
		}
		

		for (auto x : mp) {
			cout << x.second << " ";
		}
			
		
		cout << endl;
		
	}
}
