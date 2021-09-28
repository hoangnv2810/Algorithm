#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		queue<int> q;
		while(n--){
			int key;
			cin >> key;
			if(key == 1){
				cout << q.size();
				cout << endl;
			} else if(key == 2){
				if(q.empty()) cout << "YES";
				else cout << "NO";
				cout << endl;
			} else if(key == 3){
				int val;
				cin >> val;
				q.push(val);
			} else if(key == 4){
				if(!q.empty()) q.pop();
			} else if(key == 5){
				if(q.empty()) cout << -1;
				else cout << q.front();
				cout << endl;
			} else {
				if(q.empty()) cout << -1;
				else cout << q.back();
				cout << endl;
			}
		}
		cout << endl;
	}
}

