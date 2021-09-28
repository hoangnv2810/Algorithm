#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		vector<int> ke[v+1];
		int begin, end;
		for(int i = 0; i < e; i++){
			cin >> begin >> end;
			ke[begin].push_back(end);
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

