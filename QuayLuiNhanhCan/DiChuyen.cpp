#include<bits/stdc++.h>
using namespace std;
int flag = 0, n, a[100][100];
vector<string> res;


void Try(int i, int j, string s){
	if(i == 0 && j == 0 && a[i][j] == 0) return;
	if(i == n-1 && j == n-1 && a[n-1][n-1] == 1) {
		res.push_back(s);
		flag = 1;
		return;
	}
	if(i < n-1 && a[i+1][j] == 1) Try(i+1, j, s+"D");
	if(j < n-1 && a[i][j+1] == 1) Try(i, j+1, s+"R");
	if(i > n-1 || j > n-1 || j < n-1 && i < n-1 && a[i+1][j] == 0 && a[i][j+1] == 0) return;
}

int main(){
	int t; 
	cin >> t;
	while(t--){
		string s = "";
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		Try(0, 0, s);
		if(flag == 0) cout << -1;
		else {
			sort(res.begin(), res.end());
			for(int i = 0; i < res.size(); i++){
				cout << res[i] << " ";
			}
		}
		res.clear();
		flag = 0;
		cout << endl;
	}
}

