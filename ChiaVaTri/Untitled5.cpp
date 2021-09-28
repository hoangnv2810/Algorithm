#include<bits/stdc++.h>
using namespace std;

int solution(int a[], int l, int r){
	int mid = (l+r)/2;
	if(l <= r){
		if(a[mid] != 0 && a[mid-1] == 0) return mid-1;
		if(a[mid] == 0 && a[mid+1] != 0) return mid;
		if(a[mid] == 0 && a[mid+1] == 0) return solution(a, mid+1, r);
		if(a[mid] != 0) return solution(a, l, mid-1);
	}
	else {
		return -1;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cout << solution(a, 0, n-1) << endl;
	}
}

