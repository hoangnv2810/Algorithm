#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
int main(){
	int t;
	cin >> t;
	while(t--){
			int n;
	cin >> n;
	long long value, res = 0;
	priority_queue<long long, vector<long long>, greater<long long> > q;
	for(int i = 0; i < n; i++){
		cin >> value;
		q.push(value);
	}
    while (q.size() > 1){
            long long first = q.top();
            q.pop();
            long long second = q.top();
            q.pop();
            long long temp = (first+second)%mod;
            q.push(temp);
            res += temp;
            res %= mod;
   			
    }
	cout << res << endl;
	}
}

