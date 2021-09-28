#include<bits/stdc++.h>
using namespace std;

int result(int a, int b, int c, int d){
	int temp = max(a, b);
	int temp2 = max(c, d);
	return max(temp, temp2); 
}

int main(){
	int *a, n;
	cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	int max2 = a[n-1]*a[n-2];
	int max3 = a[n-1]*a[n-2]*a[n-3];
	int min2 = a[0]*a[1];
	int min3 = a[0]*a[1]*a[n-1];
	cout << result(max2, max3, min2, min3);
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
		sort(a, a+n);
		long long num1 = 0, num2 = 0;
		for(int i = 0; i < n; i++){
			if(i % 2 == 0) num1 = num1*10 + a[i];
			else {
				num2 = num2*10 + a[i];
			}
		}
		cout << num1 + num2;
		
		cout << endl;
	}
}
