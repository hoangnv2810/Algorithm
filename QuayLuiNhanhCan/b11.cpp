#include<bits/stdc++.h>
using namespace std;
int a[100][100], used[100], b[100];
vector<int> v;
vector< vector<int> > res;
void sulution(int k, int n){
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += a[i][b[i]];
	}
	if(sum == k){
		for(int i = 1; i <= n; i++){
			v.push_back(a[i][b[i]]);
		}
		res.push_back(v);
	}
}

void Try(int i, int n, int k){
	for(int j = 1; j <= n; j++){
		if(used[j] == 0){
			b[i] = j;
			used[j] = 1;
			if(i == n){
				for(int l = 1; l <= n; l++){
					cout << b[i];
				}
				cout << endl;
			} else {
				Try(i+1, n, k);
			}
			used[j] = 0;
		}
	}
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
//		for(int i = 1; i <= n; i++){
//			for(int j = 1; j <= n; j++){
//				cin >> a[i][j];
//			}
//		}
		Try(1, n, k);
//		cout << res.size() << endl;
	}
}

