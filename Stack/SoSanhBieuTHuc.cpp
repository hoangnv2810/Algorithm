#include<bits/stdc++.h>
using namespace std;

string solution(string s){
	stack<int> st;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '(') st.push(i);
			else if(s[i] == ')'){
				int top = st.top();
				st.pop();
				if(top == 0) continue;
				else if(s[top-1] == '+') continue;
				else if(s[top-1] == '-'){
					for(int j = top; j <= i; j++){
						if(s[j] == '+') s[j] = '-';
						else if(s[j] == '-') s[j] = '+'; 
					}
				} 
			}
		}
		string res;
		for(int i = 0; i < s.length(); i++){
			if(s[i] != ')' && s[i] != '(') res = res + s[i];
		}
		return res;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s, s1;
		cin >> s >> s1;
		string res = solution(s);
		string res1 = solution(s1);
		if(res == res1) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
