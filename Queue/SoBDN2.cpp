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
		string res;
		while(!q.empty()){
			res = q.front();
			q.pop();
			int temp = 0;
			for(int i = 0; i < res.length(); i++){
				temp = temp*10 + (res[i]-'0');
				temp %= n;
			}
			if(temp == 0) break;
			q.push(res+"0");
			q.push(res+"1");
		}
		
		cout << res << endl;
	}
}

