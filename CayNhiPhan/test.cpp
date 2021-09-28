#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<string> st;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
				string s1 = st.top();
				st.pop();
				string s2 = st.top();
				st.pop();
				string temp = s2 + s[i] + s1;
				st.push(temp);
			} else {
				st.push(string(1, s[i]));
			}
		}
		while(!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}

