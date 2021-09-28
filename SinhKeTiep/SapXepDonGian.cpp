#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int *a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int min = INT_MAX, index = -1;
		for(int i = 0; i < n; i++){
			if(a[i] < min){
				min = a[i];
				index = i;
			}
		}
		int res = index;
		int minpre = *min_element(a, a+index);
		for(int i = index+1; i < n; i++){
			if(a[i] > minpre) res++;
		}
		cout << res << endl;
	}
}

