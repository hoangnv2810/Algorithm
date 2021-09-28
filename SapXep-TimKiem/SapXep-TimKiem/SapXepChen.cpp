#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, *a;
	cin >> n;
	a = new int [n];
	for(int i = 0; i < n; i++) cin >> a[i];
	
	int count = 0;
	cout << "Buoc 0: " << a[0] << endl;
	for(int i = 1; i < n; i++){
		int j = i - 1;
		int temp = a[i];
		while(j >= 0 && a[j] > temp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
		cout << "Buoc " << ++count << ": ";
		for(int k = 0; k <= i; k++){
			cout << a[k] << " ";
		}
		cout << endl;
	}
}
