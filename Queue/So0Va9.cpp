#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		queue<string> q;
		q.push("9");
		string s;
		while(!q.empty()){
			s = q.front();
			q.pop();
			long long temp = 0;
			for(int i = 0; i < s.length(); i++){
				temp = temp*10 + (s[i]-'0');
			}
			if(temp%n == 0) break;
			q.push(s+"0");
			q.push(s+"9");
		}
		cout << s << endl;
	}
}

