#include<bits/stdc++.h>
using namespace std;

int check(int v, vector<int> ke[1001]){
	int deg = 0;
	for(int i = 1; i <= v; i++){
		if(ke[i].size()%2 == 1){
			deg++;
		}
	}
	if(deg == 0) return 2;
	else if(deg == 2) return 1;
	else return 0;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		vector<int> ke[v+1];
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		
		cout << check(v, ke) << endl; 
	}
}

