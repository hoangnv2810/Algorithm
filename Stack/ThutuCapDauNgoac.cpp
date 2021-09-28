#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		stack<int> st;
		int dem = 1;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '('){
				cout << dem << " "; 
				st.push(dem);
				dem++;
			}
			else if(s[i] == ')'){
				cout << st.top() << " ";
				st.pop();
			}
		}
		cout << endl;
	}
}

