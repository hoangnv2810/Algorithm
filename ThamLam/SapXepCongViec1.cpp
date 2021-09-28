#include<bits/stdc++.h>
using namespace std;

struct solution{
	int first, second;
};

int cmp(solution a, solution b){
	return a.second < b.second;
}
solution a[1000];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i].first;
		}
		for(int i = 0; i < n; i++){
			cin >> a[i].second;
		}
		sort(a, a+n, cmp);
		
		int res = 1;
		int i = 0;
		for(int j = 1; j < n; j++){
			if(a[j].first >= a[i].second){
				res++;
				i = j;
			}
		}
		cout << res << endl;
	}
}

