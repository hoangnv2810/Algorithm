#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int* res = new int[n];
		stack<int> st;
		st.push(0);
		res[0] = 1;
		for(int i = 1; i < n; i++){
			while(!st.empty() && a[st.top()] <= a[i]) st.pop();
			if(!st.empty()) res[i] = i - st.top();
			else res[i] = i+1;
			st.push(i);
		}
		for(int i = 0; i < n; i++) cout << res[i] << " ";
		
		cout << endl;
	}
}
