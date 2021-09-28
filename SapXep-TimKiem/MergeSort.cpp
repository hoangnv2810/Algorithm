#include<bits/stdc++.h>
using namespace std;

void Merge(int a[], int left, int mid, int right){
	int i = left;
	int j = mid+1;
	int k = 0;
	int n = right-left+1;
	int *b = new int[n];
	while((i < mid+1) && (j < right+1)){
		if(a[i] < a[j]) b[k++] = a[i++];
		else b[k++] = a[j++]; 	
	}
	while(i < mid+1){
		b[k++] = a[i++];
	}
	while(j < right+1){
		b[k++] = a[j++];
	}
	for(k = 0; k < n; k++){
		a[left++] = b[k];
	}
	delete [] b;
}

void MergeSort(int a[], int left, int right){
	if(left < right){
		int mid = (left+right)/2;
		MergeSort(a, left, mid);
		MergeSort(a, mid+1, right);
		Merge(a, left, mid, right);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		MergeSort(a, 0, n-1);
		for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
	}
}

