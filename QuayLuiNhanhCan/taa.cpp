#include<bits/stdc++.h>
using namespace std;
int a[10][10], flag, n;
vector<string> res;
bool vs[10][10];
void Try(int i, int j, string s){
	if(a[1][1] == 0 || a[n][n] == 0) return;
	if(i == n && j == n && a[i][j] == 1){
		res.push_back(s);
	}
	if(i != n && a[i+1][j] == 1 && !vs[i+1][j]) {
		vs[i][j] = true;
		Try(i+1, j, s+"D");
		vs[i][j] = false;
	}
	if(j != n && a[i][j+1] == 1 && !vs[i][j+1]) {
		vs[i][j] = true;
		Try(i, j+1, s+"R");
		vs[i][j] = false;
	}
	if(i != 1 && a[i-1][j] == 1 && !vs[i-1][j]) {
		vs[i][j] = true;
		Try(i-1, j, s+"U");
		vs[i][j] = false;
	}
	if(j != 1 && a[i][j-1] == 1 && !vs[i][j-1]) {
		vs[i][j] = true;
		Try(i, j-1, s+"L");
		vs[i][j] = false;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
				vs[i][j] = false;
			}
		}
		
		Try(1, 1, "");
		if(res.size() == 0) cout << -1;
		else {
			sort(res.begin(), res.end());
			for(int i = 0; i < res.size(); i++){
				cout << res[i] << " ";
			}
		}
		res.clear();
		cout << endl;
	}
}

