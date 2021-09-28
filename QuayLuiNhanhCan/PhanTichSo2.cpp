#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
vector< vector<int> > res;

void Try(int i, int n) {
	if (n == 0) {
		res.push_back(v);
	}
		
	for (int j = i; j <= n; j++) {
		v.push_back(j);
		Try(j, n - j);
		v.pop_back();
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		Try(1, n);
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			sort(res[i].begin(), res[i].end(), greater<int>());
		}
		sort(res.begin(), res.end());
		for (int i = res.size()-1; i >= 0; i--) {
			cout << "(";
			for(int j = 0; j < res[i].size()-1; j++){
				cout << res[i][j] << " ";
			}
			cout << res[i][res[i].size()-1]; 
			cout << ") ";
		}
		res.clear();
		v.clear();
		cout << endl;
	}
}

