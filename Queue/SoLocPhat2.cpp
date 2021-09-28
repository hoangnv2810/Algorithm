#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		queue<string> q;
		q.push("6");
		q.push("8");
		vector<string> v;
		while(!q.empty()){
			string s1 = q.front();
			q.pop();
			string s2 = q.front();
			q.pop();
			if(s1.length() <= n) v.push_back(s1);
			if(s2.length() <= n) v.push_back(s2);
			if(s1.length() > n|| s2.length() > n) break;
			q.push(s1+"6");
			q.push(s1+"8");
			q.push(s2+"6");
			q.push(s2+"8");
		}
		cout << v.size() << endl;
		for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
		cout << endl;
	}
}

