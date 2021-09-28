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
		int *next = new int[n];
		int *small = new int[n];
		stack<int> s;
		for(int i = n-1; i >= 0; i--){
			while(!s.empty() && a[s.top()] <= a[i]){
				s.pop();
			} 
			if(!s.empty()){
				next[i] = s.top();
			} else {
				next[i] = -1;
			} 
			s.push(i);
		}		
		while(!s.empty()) s.pop();
		for(int i = n-1; i >= 0; i--){
			while(!s.empty() && a[s.top()] >= a[i]) s.pop();
			if(!s.empty()) small[i] = s.top();
			else small[i] = -1;
			s.push(i);
		}
		for(int i = 0; i < n; i++){
			if(next[i] != -1 && small[next[i]] != -1) cout << a[small[next[i]]] << " ";
			else cout << -1 << " ";
		}
		cout << endl;
	}
}
