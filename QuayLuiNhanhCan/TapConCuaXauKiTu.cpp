#include<bits/stdc++.h>
using namespace std;

// vector<string> v;
// void Try(string s){
// 	if(s.size() == 0) return;
// 	int check = 0;
// 	for(int i = 0; i < v.size(); i++){
// 		if(v[i] == s) check = 1;
// 	}
// 	if(check == 0){
// 		v.push_back(s);
// 		for(int i = 0; i < s.length(); i++){
// 			string temp = s;
// 			temp.erase(i, 1);
// 			Try(temp);
// 		}
// 	}
// }

// int main(){
// 	int t;
// 	cin >> t;
// 	while(t--){
// 		int n;
// 		cin >> n;
// 		string s;
// 		cin >> s;
// 		Try(s);
// 		// sort(v.begin(), v.end());
// 		for(int i = 0; i < v.size(); i++){
// 			cout << v[i] << " ";
// 		}
// 		v.clear();
// 		cout << endl;
// 	}
// }

set<string> st;
void Try(string s) {
	if (s.size() == 0) return;

	if (st.find(s) == st.end()) {
		st.insert(s);
		for (int i = 0; i < s.size(); i++) {
			string t = s;
			t.erase(i, 1);
			Try(t);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		Try(s);
		for (auto x : st) {
			cout << x << " ";
		}
		st.clear();
		cout << endl;
	}
}