#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string str;
		getline(cin, str);
		stack<string> st;
		stringstream s(str);
		string word;
		while(s >> word){
			st.push(word);
		}
		
		while(!st.empty()){
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
}

