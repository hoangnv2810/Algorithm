#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int d;
		string s;
		cin >> d >> s;
		map<char, int> mp;
		int max = 0;
		for(int i = 0; i < s.length(); i++){
			mp[s[i]]++;
			if(mp[s[i]] > max) max = mp[s[i]]; 
		}	
		
		if(s.length() - max >= (max-1)*(d-1)) cout << 1;
		else cout << -1;
		cout << endl;
		
	}
}

