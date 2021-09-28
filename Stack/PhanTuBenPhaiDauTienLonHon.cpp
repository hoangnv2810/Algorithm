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
		int *res = new int[n];
		
		stack<int> s;
		for(int i = n-1; i >= 0; i--){
			while(!s.empty() && a[s.top()] <= a[i]){
				s.pop();
			} 
			if(!s.empty()){
				res[i] = a[s.top()];
			} else {
				res[i] = -1;
			} 
			s.push(i);
		}		
		for(int i = 0; i < n; i++){
			cout << res[i] << " ";
		}
		cout << endl;
	}
}
