#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<int> st;
		int count = 1;
		st.push(count);
		for(int i = 0; i < s.length(); i++){
			if(s[i] == 'D'){
				st.push(++count);
			} else {
				while(!st.empty()){
					cout << st.top();
					st.pop();
				}
				st.push(++count);
			}
		}
		while(!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}

