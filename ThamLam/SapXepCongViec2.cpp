#include<bits/stdc++.h>
using namespace std;

struct job{
	int jobId;
	int deadline;
	int profit;
};

int cmp(job a, job b){
	return a.profit > b.profit;
}

void solution(job a[1000], int n){
	bool check[1000];
	memset(check, true, sizeof(check));
	int res = 0, count = 0;
	for(int i = 0; i < n; i++){
		for(int j = min(n-1, a[i].deadline-1); j >= 0; j--){
			if(check[j]){
				res += a[i].profit;
				check[j] = false;
				count++;
				break;
			}
		}
	}
	cout << count << " " << res << endl;;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		job a[1000];
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i].jobId >> a[i].deadline >> a[i].profit;
		}
		sort(a, a+n, cmp);
		solution(a, n);
	}
}

