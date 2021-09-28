#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == ']'){
				string temp;
				while(st.top() != '['){
					temp = st.top() + temp;
					st.pop();
				}		
				st.pop();
				
				int num = 0, he = 1;
				if(st.empty()) num = 1;
				else if(st.top() >= 'a' && st.top() <= 'z') num = 1;
				else 
				while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
					num += (st.top() - '0')*he;
					st.pop();
					he *= 10;
				}
				
				for(int j = 0; j < num; j++){
					for(int k = 0; k < temp.size(); k++){
						st.push(temp[k]);
					}
				}
			} 
			else st.push(s[i]);
		}
		string res = "";
		while(!st.empty()){
			char c = st.top();
			st.pop();
			res.push_back(c);
		}
		reverse(res.begin(), res.end());
		for(int i = 0; i < res.size(); i++) cout << res[i];
		cout << endl;
	}
}
