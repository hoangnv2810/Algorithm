#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		long long i = 0, temp, maxtop = 0, res = 0;
		stack<int> st;
		while(i < n){
			if(st.empty() || a[st.top()] <= a[i]){
				st.push(i++);
			} else {
				temp = st.top();
				st.pop();
				if(st.empty()){
					maxtop = a[temp]*i;
				} else {
					maxtop = a[temp]*(i-1-st.top());
				}
				res = max(maxtop, res);
			}
		}
		while(!st.empty()){
			temp = st.top();
			st.pop();
			if(st.empty()){
				maxtop = a[temp]*i;
			} else {
				maxtop = a[temp]*(i-1-st.top());
			}
			res = max(maxtop, res);
		}
		cout << res << endl;
	}
}

