#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	queue<int> q;
	cin.ignore();
	while(t--){
		string s;
		cin >> s;
		if(s == "PUSH"){
			int val;
			cin >> val;
			q.push(val);
		} else if(s == "PRINTFRONT"){
			if(q.empty()){
				cout << "NONE" << endl;
			} else {
				cout << q.front() << endl;
			}
		} else {
			if(!q.empty()) q.pop();
		}
	}
}

