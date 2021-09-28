#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[100];
vector<int> v;
vector< vector<int> > res;

void Try(int i, int sum) {
	if (sum == 0) {
		res.push_back(v);
		return;
	}
	if (sum < 0) return;
	for (int j = i; j < n; j++) {
		v.push_back(a[j]);
		Try(j, sum - a[j]);
		v.pop_back();
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int sum;
		cin >> n >> sum;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		Try(0, sum);
		for(int i = 0; i < res.size(); i++){
			sort(res[i].begin(), res[i].end());
		}
		sort(res.begin(), res.end());
		if(res.size() == 0) cout << -1;
		else {
			cout << res.size() << " ";
			for (int i = 0; i < res.size(); i++) {
				cout << "{";
				for (int j = 0; j < res[i].size()-1; j++) {
					cout << res[i][j] << " ";
				}
				cout << res[i][res[i].size()-1];
				cout << "} ";
			}
		}
		v.clear();
		res.clear();
		cout << endl;
	}
}


