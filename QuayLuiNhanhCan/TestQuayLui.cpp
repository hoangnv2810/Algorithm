#include<bits/stdc++.h>
using namespace std;

// Day So 1
void print(int a[100], int n){
	cout << "[";
	for(int i = 0; i < n-1; i++){
		cout << a[i] << " ";
	}
	cout << a[n-1] << "]" << endl;
}

void Try(int a[100], int n){
	if(n == 1) return;
	else {
		int temp[n-1];
		for(int i = 0; i < n-1; i++){
			temp[i] = a[i] + a[i+1];
		}
		print(temp, n-1);
		Try(temp, n-1);
	}
	
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		print(a, n);
		Try(a, n);
	}
}

// Day So 2
void print(int a[], int n){
	cout << "[";
	for(int i = 0; i < n-1; i++){
		cout << a[i] << " ";
	}
	cout << a[n-1] << "]" << endl;
}

void Try(int a[], int n){
	if(n == 1) return;
	else {
		int temp[n-1];
		for(int i = 0; i < n-1; i++){
			temp[i] = a[i] + a[i+1];
		}
		Try(temp, n-1);
		print(temp, n-1);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		
		Try(a, n);
		print(a, n);
	}
}

// Hoan Vi Xau Ky Tu
int a[100], n, vs[100];
void Try(int i){
	for(int j = 1; j <= n; j++){
		if(vs[j] == 0){
			a[i] = j;
			vs[j] = 1;
			if(i == n){
				for(int l = 1; l <= n; l++){
					cout << char(a[l]+64);
				}
				cout << endl;
			} else {
				Try(i+1);
			}
			vs[j] = 0;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		n = s.length();
		Try(1);
	}
}

// Di Chuyen Trong Me Cung 1
int n, a[100][100], flag;
vector<string> res;
void Try(int i, int j, string s){
	if(i == 0 && j == 0 && a[i][j] == 0) return;
	if(i == n-1 && j == n-1 && a[i][j] == 1){
		res.push_back(s);
		flag = 1;
		return;
	}
	if(i < n-1 && j <= n-1 && a[i+1][j] == 1) Try(i+1, j, s+"D");
	if(i <= n-1 && j < n-1 && a[i][j+1] == 1) Try(i, j+1, s+"R");
	if(i > n-1 || j > n-1 || i < n-1 && j < n-1 && a[i+1][j] == 0 && a[i][j+1] == 0) return;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		string s;
		Try(0, 0, "");
	
		if(!flag){
			cout << -1 << endl;
		} else {
			sort(res.begin(), res.end());
			for(int i = 0; i < res.size(); i++){
				cout << res[i] << " ";
			}
			cout << endl;
		}
		flag = 0;
		res.clear();
	}
}

// Day Con Tong Bang K
int b[100], n, k, a[100];
vector< vector<int> > res;
void Try(int i){
	for(int j = 0; j <= 1; j++){
		b[i] = j;
		if(i == n){
			int sum = 0;
			for(int l = 1; l <= n; l++){
				if(b[l]) sum += a[l];
			}
			
			if(sum == k){
				vector<int> temp;
				for(int l = 1; l <= n; l++){
					if(b[l]) temp.push_back(a[l]);
				}	
				res.push_back(temp);
			}
		} else {
			Try(i+1);
		}
	}
}


int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1, a+n+1);
		Try(1);
		sort(res.begin(), res.end());
		for(int i = 0; i < res.size(); i++){
			cout << "[";
			for(int j = 0; j < res[i].size()-1; j++){
				cout << res[i][j] << " ";
			}
			cout << res[i][res[i].size()-1] << "] ";
		}
		cout << endl;
		res.clear();
	}
}

// Tap Con Bang Nhau
int solution(int a[], int n, int sum){
	if(sum != 0 && n == 0) return 0;
	if(sum == 0) return 1;
	if(sum < a[n-1]) return solution(a, n-1, sum);
	else return solution(a, n-1, sum) || solution(a, n-1, sum-a[n-1]);
}

int solution(int a[], int n, int sum){
	int dp[n+1][sum+1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			if(j == 0) dp[i][j] = 1;
			else if(j < a[i-1]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j] || dp[j-a[i-1]];
		}
	}
	return dp[n][sum];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n], sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		
		if(sum %2 == 0 && (solution(a, n, sum/2))){
			cout <<  "YES";
		} else cout << "NO";
		cout << endl;
		
	}
}

// Di Chuyen Trong Ma Tran
int a[100][100], n, m, res = 0;
void Try(int i, int j){
	if(i == m-1 && j == n-1){
		res++;
		return;
	}
	if(i < m-1) Try(i+1, j);
	if(j < n-1) Try(i, j+1);
	if(i > m-1 || j > n-1) return;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> m >> n;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		Try(0, 0);
		cout << res << endl;
		res = 0;
	}
}

// Sap Xep Quan Hau 1
int n, hang[11], cot[11], cheox[11], cheoy[11], res = 0;
void Try(int i){
	for(int j = 1; j <= n; j++){
		if(hang[j] == 0 && cot [j] == 0 && cheox[i+j-1] == 0 && cheoy[i-j+n] == 0){
			hang[j] = cot[j] = cheox[i+j-1] = cheoy[i-j+n] = 1;
			if(i == n){
				res++;
			} else {
				Try(i+1);
			}
			hang[j] = cot[j] = cheox[i+j-1] = cheoy[i-j+n] = 0;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		memset(hang, 0, sizeof(hang));
		memset(cot, 0, sizeof(cot));
		memset(cheox, 0, sizeof(cheox));
		memset(cheoy, 0, sizeof(cheoy));
		Try(1);
		cout << res << endl;
		res = 0;
	}
}

// Di Chuyen Trong Me Cung 2
int a[100][100], n;
vector<string> res;
bool vs[100][100];
void Try(int i, int j, string s){
	if(i == 0 && j == 0 && a[i][j] == 0 || a[n-1][n-1] == 0) return;
	if(i == n-1 && j == n-1 && a[i][j] == 1) {
		res.push_back(s);
		return;
	}
	if(i < n-1 && a[i+1][j] == 1 && !vs[i+1][j]) {
		vs[i][j] = true;
		Try(i+1, j, s+"D");
		vs[i][j] = false;
	}
	if(j < n-1 && a[i][j+1] == 1 && !vs[i][j+1]) {
		vs[i][j] = true;
		Try(i, j+1, s+"R");	
		vs[i][j] = false;
	} 
	if(i > 0 && a[i-1][j] == 1 && !vs[i-1][j]) {
		vs[i][j] = true;
		Try(i-1, j, s+"U");
		vs[i][j] = false;
	}
	if(j > 0 && a[i][j-1] == 1 && !vs[i][j-1]) {
		vs[i][j] = true;
		Try(i, j-1, s+"L");
		vs[i][j] = false;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		Try(0, 0, "");
		if(res.size() ==0) cout << -1;
		else {
			sort(res.begin(), res.end());
			for(int i = 0; i < res.size(); i++){
				cout << res[i] << " ";
			}
		}
		cout << endl;
		res.clear();
	}
}


//Doi Cho Cac Chu So
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		for(int i = 0; i < s.length(); i++){
			char max = s[s.length()-1];
			int index = s.length()-1;
			for(int j = s.length()-2; j > i; j--){
				if(max < s[j]){
					max = s[j];
					index = j;
				}
			}
			if(max > s[i]){
				swap(s[index], s[i]);
				n--;
			}
		}
		for(int i = 0; i < s.length(); i++){
			cout << s[i];
		}
		cout << endl;
	}
}

// So Nguyen To
int n, s, p, check[100];
vector<int> v, prime;
vector< vector<int> > res;
void sieve(){
	for(int i = 2; i <= s; i++){
		if(!check[i]){
			if(i > p) prime.push_back(i);
			for(int j = i*i; j <= s; j += i){
				check[j] = 1;
			}
		}
	}
}

void Try(int tmpSum, int index){
	if(tmpSum > s || index == prime.size()) return;
	if(tmpSum == s && v.size() == n){
		res.push_back(v);
		return;
	}
	for(int j = index; j < prime.size(); j++){
		if(!check[j] && tmpSum+prime[j] <= s && v.size()+1 <= n){  // NOTE j = index;
			check[j] = 1;
			v.push_back(prime[j]);
			Try(tmpSum+prime[j], j+1);
			check[j] = 0;
			v.pop_back();
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> p >> s;
		sieve();
		memset(check, 0, sizeof(check));
		Try(0, 0);
		cout << res.size() << endl;
		for(int i = 0; i < res.size(); i++){
			for(int j = 0; j < res[i].size(); j++){
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
		
		res.clear();
		v.clear();
		prime.clear();
	}
}

// Sap Xep Quan Hau 2
int a[100], b[100][100], hang[100], cot[100], cheox[100], cheoy[100], n, ans;
void Try(int i){
	for(int j = 1; j <= n; j++){
		if(hang[j] == 0 && cot[j] == 0 && cheox[i+j-1] == 0 && cheoy[i-j+n] == 0){
			a[i] = j;
			hang[j] = cot[j] = cheox[i+j-1] = cheoy[i-j+n] = 1;
			if(i == n){
				int sum = 0;
				for(int l = 1; l <= n; l++){
					sum += b[l][a[l]];
				}
				ans = max(ans, sum);
			} else {
				Try(i+1);
			}
			hang[j] = cot[j] = cheox[i+j-1] = cheoy[i-j+n] = 0;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		n = 8;
		memset(hang, 0, sizeof(hang));
		memset(cot, 0, sizeof(cot));
		memset(cheox, 0, sizeof(cheox));
		memset(cheoy, 0, sizeof(cheoy));
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin >> b[i][j];
			}
		}
		Try(1);
		cout << ans << endl;
		ans = 0;
	}
}

//Phan Tich So 2
vector< vector<int> > res;
vector<int> v;
void Try(int i, int n){
	if(n == 0){
		res.push_back(v);
	}
	for(int j = i; j <= n; j++){
		v.push_back(j);
		Try(j, n-j); // NOTE
		v.pop_back();
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		Try(1, n);
		cout << res.size() << endl;
		for(int i = 0; i < res.size(); i++){
			sort(res[i].begin(), res[i].end(), greater<int>());
		}
		sort(res.rbegin(), res.rend());
		for(int i = 0; i < res.size(); i++){
			cout << "(";
			for(int j = 0; j < res[i].size()-1; j++){
				cout << res[i][j] << " ";
			}
			cout << res[i][res[i].size()-1] << ")";
			cout << " ";
		}
		res.clear();
		v.clear();
		cout << endl;
	}
}

// To Hop So Co Tong Bang K
int n, k, a[100];
vector< vector<int> > res;
vector<int> v;
void Try(int i, int k){
	if(k == 0) {
		res.push_back(v);
		return;
	}
	if(k < 0) return;
	for(int j = i; j < n; j++){
		v.push_back(a[j]);
		Try(j, k-a[j]);
		v.pop_back();
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> a[i];
		Try(0, k);
		
		for(int i = 0; i < res.size(); i++){
			sort(res[i].begin(), res[i].end());
		}
		
		sort(res.begin(), res.end());
		if(res.size() == 0) cout << -1;
		else {
			cout << res.size() << " ";
			for(int i = 0; i < res.size(); i++){
				cout << "{";
				for(int j = 0; j < res[i].size()-1; j++){
					cout << res[i][j] << " ";
				}
				cout << res[i][res[i].size()-1] << "} ";
			}
		}
		res.clear();
		v.clear();
		cout << endl;
	}
}

// Tap Con Cua Xau Ky Tu
set<string> st;
void Try(string s){
	if(s.size() == 0){
		return;
	}
	if(st.find(s) == st.end()){
		st.insert(s);
		for(int j = 0; j < s.length(); j++){
			string temp = s;
			temp.erase(j, 1);
			Try(temp);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		Try(s);
		for(auto x: st){
			cout << x << " ";
		}
		st.clear();
		cout << endl;
	}
}

// Bien Doi Ve 1
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int dp[n+1], res = 0;
		dp[1] = 0;
		for(int i = 2; i <= n; i++){
			res = dp[i-1];
			if(n%2 == 0) res = min(res, dp[i/2]);
			if(n%3 == 0) res = min(res, dp[i/3]);
			dp[i] = 1 + res;
		}
		cout << dp[n] << endl;
	}
}

//Chia Mang
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k, sum = 0;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
		} 
		
		int check = 0;
		if(sum % k == 0){
			sum /= k;
		} else check = 1;
		for(int i = 0; i < n; i++){
			if(a[i] > sum) check = 1;
		}
		if(check) cout << 0;
		else cout << 1;
		cout << endl;
		
	}
}

// To Hop So Co Tong Bang X
int n, k, a[100];
vector<int> v;
vector< vector<int> > res;

void Try(int i, int sum){
	if(sum == 0) {
		res.push_back(v);
		return;
	} 
	if(sum < 0) return;
	for(int j = i; j < n; j++){
		v.push_back(a[j]);
		Try(j, sum - a[j]);
		v.pop_back();
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> a[i];
		Try(0, k);
		
		for(int i = 0; i < res.size(); i++){
			sort(res[i].begin(), res[i].end());
		}
		for(int i = 0; i < res.size(); i++){
			cout << "[";
			for(int j = 0; j < res[i].size()-1; j++){
				cout << res[i][j] << " ";
			}
			cout << res[i][res[i].size()-1] << "]";
		}
		cout << endl;
		res.clear();
		v.clear();
	}
}

// Nguoi Du Lich
int a[16][16], x[16], vs[16], sum = 0, res = INT_MAX, minA = INT_MAX, n;
void Try(int i){
	if(sum + (n-i+1)*minA >= res) return ;
	for(int j = 1; j <= n; j++){
		if(!vs[j]){
			x[i] = j;
			vs[j] = 1;
			sum += a[x[i-1]][j];
			if(i == n){
				res = min(res,sum + a[x[n]][x[1]]);
			} else {
				Try(i+1);
			}
			vs[j] = 0;
			sum -= a[x[i-1]][j];
		}
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] != 0){
				minA = min(minA, a[i][j]);
			}
		}
	}
	vs[1] = 1;
	x[1] = 1;
	Try(2);
	cout << res << endl;
}

