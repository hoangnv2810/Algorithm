#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int m, n;
		vector<int> v;
		cin >> m >> n; 
		int a[m], b[n];
		for(int i = 0; i < m; i++){
			cin >> a[i];
			v.push_back(a[i]);
		} 
		for(int i = 0; i < n; i++){
			cin >> b[i];
			v.push_back(b[i]);
		}
		sort(v.begin(), v.end());
		for(auto x : v){
			cout << x << " ";
		}
		cout << endl;
		
	}
}

