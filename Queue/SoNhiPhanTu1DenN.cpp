#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		queue<string> q;
		q.push("1");
		while(n--){
			string s = q.front();
			q.pop();
			cout << s << " ";
			q.push(s+"0");
			q.push(s+"1");
		}
		cout << endl;
	}
}

