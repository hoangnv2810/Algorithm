#include<bits/stdc++.h>
using namespace std;
int used[100], a[100][100], b[100], n, sum;
vector<int> res;
void Try(int i){
	for(int j = 1; j <= n; j++){
		if(used[j] == 0){
			b[i] = j;
			used[j] = 1;
			if(i == n){
				int temp = 0;
				for(int l = 1; l <= n; l++){
					temp += a[l][b[l]];
				}
				if(temp == sum) {
					for(int l = 1; l <= n; l++){
						res.push_back(b[l]);
					}	
				}
				
			} else {
				Try(i+1);	
			}
			used[j] = 0;
		}
	}
}

int main(){
	cin >> n >> sum;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	Try(1);
	cout << res.size()/n << endl;
	for(int i = 0; i < res.size(); i++){
		if(i%n == 0 && i != 0) cout << endl;
		cout << res[i] << " ";
	}
	cout << endl;
	
}

