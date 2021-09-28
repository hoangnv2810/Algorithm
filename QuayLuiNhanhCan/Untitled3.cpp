#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > res;
int a[100], b[100], n, k;
void Try(int i){
	for(int j = 0; j <= 1; j++){
		b[i] = j;
		if(i == n){
			int sum = 0;
			for(int k = 1; k <= n; k++){
				if(b[k] == 1) sum += a[k];
			}
			if(sum == k){
				vector<int> temp;
				for(int k = 1; k <= n; k++){
					if(b[k] == 1)temp.push_back(a[k]);
				}
				res.push_back(temp);
			}
		} else {
			Try(i+1);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a+1, a+n+1);
		Try(1);
		if(res.size() != 0){
			sort(res.begin(), res.end());
			for(int i = 0; i < res.size(); i++){
				cout << "[";
				for(int j = 0; j < res[i].size()-1; j++){
					cout << res[i][j] << " ";
				}
				cout << res[i][res[i].size()-1] << "] ";
			}
		} else {
			cout << -1;
		}
		res.clear();
		cout << endl;
	}
}
