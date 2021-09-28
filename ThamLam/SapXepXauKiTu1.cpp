#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		map<char, int> mp;
		int max = 0;
		for(int i = 0; i < s.length(); i++){
			mp[s[i]]++;
			if(mp[s[i]] > max) max = mp[s[i]]; 
		}		
		if((s.length()%2 == 0) && max <= s.length()-max) cout << 1;
		else if((s.length()%2 == 1) && max <= (s.length()/2+1)) cout << 1;
		else cout << -1;
		cout << endl;
	}
}

