#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		int begin, end;
		vector<int> ke[v+1];
		for(int i = 0; i < e; i++){
			cin >> begin >> end;
			ke[begin].push_back(end);
			ke[end].push_back(begin);
		}
		for(int i = 1; i <= v; i++){
			cout << i << ": ";
			for(int j = 0; j < ke[i].size(); j++){
				cout << ke[i][j] << " ";
			}
			cout << endl;
		}
	}
}

