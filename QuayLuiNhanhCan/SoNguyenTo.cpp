#include<bits/stdc++.h>
using namespace std;
int check[201];
vector<int> prime;
vector<int> v;
vector< vector<int> > res;
int n, s, p;
void sieve(){
	for(int i = 2; i <= s; i++){
		if(!check[i]){
			if(i > p) prime.push_back(i);
			for(int j = i*i; j <= s; j += i){
				check[j] = 1;
			}
		}
	}
}

void Try(int tmpSum, int index){
	if(tmpSum > s || index == prime.size()) return;
	if(tmpSum == s && v.size() == n){
		res.push_back(v);
		return;
	}
	for(int j = index; j < prime.size(); j++){
		if(!check[j] && tmpSum+prime[j] <= s && v.size() < n){
			v.push_back(prime[j]);
			check[j] = 1;
			Try(tmpSum+prime[j], j+1);
			v.pop_back();
			check[j] = 0;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> p >> s;
		sieve();
		memset(check, 0, sizeof(check));
		Try(0, 0);
		
		cout << res.size() << endl;
		for(int i = 0; i < res.size(); i++){
			for(int j = 0; j < res[i].size(); j++){
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
		res.clear();
		v.clear();
		prime.clear();
	}
}

