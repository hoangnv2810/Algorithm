#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n+1][n+1];
	vector<int> ke[n+1];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j]) ke[i].push_back(j+1);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < ke[i].size(); j++){
			cout << ke[i][j] << " ";
		}
		cout << endl;
	}
}

