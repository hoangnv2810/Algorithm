#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	deque<int> dq;
	while(t--){
		string s;
		cin >> s;
		if(s == "PUSHBACK"){
			int val;
			cin >> val;
			dq.push_back(val);
		} else if(s == "PUSHFRONT"){
			int val;
			cin >> val;
			dq.push_front(val);
		} else if(s == "PRINTBACK"){
			if(!dq.empty()) cout << dq.back() << endl;
			else cout << "NONE" << endl;
		} else if(s == "PRINTFRONT"){
			if(!dq.empty()) cout << dq.front() << endl;
			else cout << "NONE" << endl;
		} else if(s == "POPFRONT"){
			if(!dq.empty()) dq.pop_front();
		} else {
			if(!dq.empty()) dq.pop_back();
		}
	}
}

