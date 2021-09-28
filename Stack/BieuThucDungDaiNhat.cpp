#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		int res = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == ')'){
				if(!st.empty()){
					st.pop();
					res += 2;
				}
			} else st.push(s[i]);
		}
		cout << res << endl;
	}
}
