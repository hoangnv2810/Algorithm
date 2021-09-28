#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<int> st;
		// int flag[100];
		// memset(flag, 0, sizeof(flag));

		for(int i = 0; i < s.length(); i++){
			if(s[i] == '('){
				st.push(i);
			} else if(s[i] == ')'){
				int top = st.top();
				st.pop();
				if(top == 0) continue;
				if(s[top-1] == '+') continue;
				if(s[top-1] == '-'){
					// if(s[top+1] == '+' || s[top+1] == '-') flag[top-1] = 1;
					for(int j = top; j <= i; j++){
						if(s[j] == '+') s[j] = '-';
						else if(s[j] == '-') s[j] = '+';
					}
				}
			}
		}
		for(int i = 0; i < s.length(); i++){
			if(s[i] != '(' && s[i] != ')' && flag[i] != 1) cout << s[i];
		}
		cout << endl;
	}
}
