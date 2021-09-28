#include<bits/stdc++.h>
using namespace std;

void solution(string s){
	map<char, int> mp;
	int max = 0;
	for(int i = 0; i < s.length(); i++){
		mp[s[i]]++;
		if(mp[s[i]] > max) max = mp[s[i]];
	}
	int n = s.length();
	if(n%2 == 0 && max <= n-max) cout << 1;
	else if(n%2 == 1 && max <= (n/2)+1) cout << 1;
	else cout << -1;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		solution(s);
		cout << endl;
	}
}

