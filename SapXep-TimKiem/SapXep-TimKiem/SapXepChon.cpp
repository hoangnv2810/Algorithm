#include<bits/stdc++.h>
using namespace std;

int main(){
	int *a, n;
	cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int count = 0;
	for(int i = 0; i < n-1; i++){
		int min = i;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[min]) min = j;
		}
		
		// if(min != i){
		swap(a[min], a[i]);
		cout << "Buoc " << ++count << ": ";
		for(int k = 0; k < n; k++) cout << a[k] << " ";
		cout << endl;
		// }
	}
}
