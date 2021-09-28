#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		map<int, int> mp;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		vector<int> res;
		for(int i = 0; i < n; i++){
			int check = 0, temp;
			for(int j = i+1; j < n; j++){
				if(mp[a[j]] > mp[a[i]]){
					check = 1;
					temp = a[j];
					break;
				}
			}
			if(check == 1) res.push_back(temp);
			else if(i == n-1) res.push_back(-1);
			else res.push_back(-1);
			
		}
		for(int i = 0; i < res.size(); i++){
			cout << res[i] << " ";
		}
		cout << endl;
		
	}
}