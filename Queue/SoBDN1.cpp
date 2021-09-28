#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int index = s.length();
		for(int i = 0; i < s.length(); i++){
			if(s[i] >= '2'){
				index = i;
				break;
			}
		}
		for(int i = index; i < s.length(); i++) 
			s[i] = '1';
		
		int base = 1; 
		long long res = 0;
		for(int i = s.length()-1; i >= 0; i--){
			res += (s[i]-'0')*base;
			base*=2;
		}
		cout << res << endl;
	}
}

