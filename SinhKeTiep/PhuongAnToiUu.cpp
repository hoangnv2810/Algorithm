#include<bits/stdc++.h>
using namespace std;

struct tui{
	int kl;
	int gt;
};
int b[100];
int n, w, c = INT_MIN;
vector<int> res;
tui a[100];
void result(){
	int weight = 0, giatri = 0;
	for(int i = 1; i <= n; i++){
		if(b[i]){
			weight += a[i].kl;
			giatri += a[i].gt;
		}
	}
	if(weight <= w && giatri > c){
		c = giatri;
		res.clear();
		for(int i = 1; i <= n; i++){
			res.push_back(b[i]);
		}
	}
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		b[i] = j;
		if(i == n){
			result();
		} else {
			Try(i+1);
		}
	}
}

int main(){
	cin >> n >> w;
	for(int i = 1; i <= n; i++){
		cin >> a[i].gt;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i].kl;
	}
	Try(1);
	cout << c << endl;
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;

}

