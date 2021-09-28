#include<bits/stdc++.h>
using namespace std;

// Sap xep doi cho truc tiep
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int count = 1;
	for(int i = 0; i < n; i++){
		bool check = false;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[i]){
				swap(a[i], a[j]);
				check = true;
			}
		}
		if(check){
			cout << "Buoc " << count++ << ": ";
			for(int l = 0; l < n; l++){
				cout << a[l] << " ";
			}
			cout << endl;
		}
	}
}

// Sap xep chon
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int count = 1;
	for(int i = 0; i < n-1; i++){ // NOTE n-1
		int min = i;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[min]) min = j;
		}
		swap(a[min], a[i]);
		cout << "Buoc " << count++ << ": ";
		for(int l = 0; l < n; l++){
			cout << a[l] << " ";
		}
		cout << endl;
	}
}

// Sap Xep Chen
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << "Buoc 0: " << a[0] << endl;
	int count = 1;
	for(int i = 1; i < n; i++){
		int j = i-1;
		int temp = a[i];
		while(j >= 0 && temp < a[j]){
			a[j+1] = a[j];  // note
			j--;
		}
		a[j+1] = temp;
		cout << "Buoc " << count++ << ": ";
		for(int k = 0; k <= i; k++){
			cout << a[k] << " ";
		}
		cout << endl;
	}
}

// Sap Xep Noi Bot
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int count = 1;
	for(int i = 0; i < n; i++){
		bool check = false;
		for(int j = 0; j < n-1; j++){
			if(a[j] > a[j+1]){
				check = true;
				swap(a[j], a[j+1]);
			}
		}
		if(check){
			cout << "Buoc " << count++ << ": ";
			for(int k = 0; k < n; k++){
				cout << a[k] << " ";
			}
			cout << endl;
		}
	}
}

// Sap Xep Xen Ke

// Sep Xep Theo Gia Tri Tuyet Doi
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a;
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			a.push_back(val);
		}
		multimap<int, int> mp;
		for (auto x : a) {
			mp.insert(pair<int, int>(abs(k - x), x));
		}

		for (auto x : mp) {
			cout << x.second << " ";
		}
		cout << endl;
	}
}

// Sap Xep Day Con Lien Tuc
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int l = 0, r = n-1;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n-1; i++){
			if(a[i] > a[i+1]){
				l = i;
				break;
			}
		}
		for(int i = n-1; i > 0; i--){
			if(a[i] < a[i-1]){
				r = i;
				break;
			}
		}
		sort(a+l, a+r+1);
		
		for(int i = 0; i < l; i++){
			if(a[i] > a[l]){
				l = i;
				break;
			}
		}
		
		for(int i = n-1; i > r; i--){
			if(a[i] < a[r]){
				r = i;
				break;
			}
		}
		
		cout << l+1 << " " << r+1 << endl;
	}
}

// Cap So Tong Bang K
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> a;
		for(int i = 0; i < n; i++){
			int val;
			cin >> val;
			a.push_back(val);
		}
		
		map<int, int> mp;
		for(auto x : a){
			mp[x]++;
		}
		int res = 0;
		for(auto x : a){
			res += mp[k-x];
			if(x == k-x){
				res--;
			}
		}
		cout << res/2 << endl;
	}
}

// Sap xep chu so

// Tong Gan Khong Nhat
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int res = a[0]+a[1];
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				if(abs(a[i] + a[j]) < abs(res)){
					res = a[i]+a[j];
				}
			}
		}
		cout << res << endl;
	}
}
// Phan Tu Lon Nhat

// So Lan Xuat Hien

// Tong Cap So Nguyen To
void sieve(int n){
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	for(int i = 2; i <= n; i++){
		if(prime[i]){
			for(int j = i*i; j <= n; j += i){
				prime[j] = false;
			}
		}
	}
	bool check = false;
	for(int i = 2; i <= n; i++){
		if(prime[i] == true && prime[n-i] == true && n-i >= 2){
			check = true;
			cout << i << " " << n-i << endl;
			break;
		}
	}
	if(!check) cout << -1 << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		sieve(n);
	}
}

// Merge sort ...

// Tich Lon Nhat - Nho Nhat
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, m, *a, *b;
		cin >> n >> m;
		a = new long long [n];
		b = new long long [m];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < m; i++) cin >> b[i];
		sort(a, a+n);
		sort(b, b+m);
		long long res = a[n-1]*b[0];
		cout << res << endl;
	}
}
// Tron Hai Day

// Bo Sung Phan Tu
int main(){
	int t;
	cin >> t;
	while(t--){
		int *a, n;
		cin >> n;
		a = new int[n];
		map<int, bool> mp;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]] = true;
		}
		sort(a, a+n);
		long long res = 0;
		for(long long i = a[0]; i <= a[n-1]; i++){
			if(mp[i] == false) res++;
		}
		cout << res << endl;
	}
}
// Sap Xep theo so lan xuat hien
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, val;
		vector<int> a;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> val;
			a.push_back(val);
		}

		map<int, int> mp;
		for (auto x : a) {
			mp[x]++;
		}

		vector<pair<int, int>> vt(mp.begin(), mp.end());

		for (int i = 0; i < vt.size(); i++) {
			for (int j = i + 1; j < vt.size(); j++) {
				if (vt[i].second < vt[j].second) {
					swap(vt[i], vt[j]);
				}
				else if (vt[i].second == vt[j].second) {
					if (vt[i].first > vt[j].first) {
						swap(vt[i], vt[j]);
					}
				}
			}
		}

		for (auto x : vt) {
			while (x.second--) cout << x.first << " ";
		}
		cout << endl;
		
	}
}
// Tim kiem
int binary_search(int a[], int l, int r, int x) {
	if (l <= r) {
		int mid = (r-l) / 2 + l;
		if (a[mid] == x) return 1;
		if (a[mid] > x) return binary_search(a, l, mid - 1, x);
		else return binary_search(a, mid + 1, r, x);

	}
	return -1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, * a, x;
		cin >> n >> x;
		a = new int[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		cout << binary_search(a, 0, n - 1, x) << endl;
	}
}
// Tim kiem trong day sap xep vong
int binary_search(int a[], int l, int r, int x) {
	if (l <= r) {
		int mid = (r-l) / 2 + l;
		if (a[mid] == x) return mid+1;
		if (a[mid] > x) return binary_search(a, l, mid - 1, x);
		else return binary_search(a, mid + 1, r, x);

	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, * a, x;
		cin >> n >> x;
		a = new int[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		int max, index = 0;
		max = a[index];
		for (int i = 1; i < n; i++) {
			if(max < a[i]){
				max = a[i];
				index = i;
			}
		}
		
		if(binary_search(a, 0, index, x) || binary_search(a, index+1, n-1, x)){
			if(binary_search(a, 0, index, x))
				cout << binary_search(a, 0, index, x);
			if(binary_search(a, index+1, n-1, x))
				cout << binary_search(a, index+1, n-1, x);
		} 
		else {
			cout << -1;
		}
		cout << endl;
	}
}
// So nho nhat va nho thu hai

// Xoa du lieu trong DSLK don

// Giao cua ba day so
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int* a = new int[n];
		int* b = new int[m];
		int* c = new int[k];
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < k; i++) {
			cin >> c[i];
		}
		
		int i = 0, j = 0, l = 0, check = 0;
		while(i < n && j < m && l < k){
			if (a[i] == b[j] && a[i] == c[l]) {
				cout << a[i] << " ";
				i++, j++, l++;
				check = 1;
			}
			else if (a[i] < b[j]) i++;
			else if (b[j] < c[l]) j++;
			else l++;
		}
		if (!check) cout << "-1";
		cout << endl;


	}
}
