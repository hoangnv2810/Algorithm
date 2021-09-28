#include<bits/stdc++.h>
using namespace std;

// Luy Thuy
int mod = 1e9+7;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        long long res = 1;
        while(k != 0){
            if(k%2 == 1){
                res = (res*n)%mod;
            }
            n = (n*n)%mod;
            k /= 2;
        }
        cout << res << endl;
    }
}

// Gap Doi Day
long long solution(int n, int k){
	long long len = pow(2, n-1);
	if(len == k) return n;
	if(len < k) return solution(n-1, len - (k-len));
	return solution(n-1, k);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << solution(n, k) << endl;
	}
}

// Dem Day
int mod = 123456789;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		long long k = n-1;
		n = 2;
		long long ans = 1;
		while(k != 0){
			if(k%2 == 1){
				ans = (ans*n)%mod;
			}
			n = (n*n)%mod;
			k /= 2;
		}
		cout << ans << endl;
	}
}

// Day Xau Fibonaci
char solution(long long dp[], long long n, long long k){
	if(n == 1) return 'A';
	if(n == 2) return 'B';
	if(k <= dp[n-2]) return solution(dp, n-2, k);
	else return solution(dp, n-1, k-dp[n-2]); 
}

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, k;
		cin >> n >> k;
		long long dp[n+1];
		dp[1] = 1;
		dp[2] = 1;
		for(int i = 3; i <= n; i++){
			dp[i] = dp[i-1] + dp[i-2];
		}
		cout << solution(dp, n, k) << endl;
	}
}

// Luy Thua Dao

int mod = 1e9+7;
long long reverse(long long n){
	long long k = 0;
	while(n != 0){
		k = k*10 + n%10;
		n /= 10;
	}
	return k;
}
long long solution(long long n, long long k){
	if(k == 0) return 1;
	if(n == 0) return 0;
	if(k % 2 == 0) return (solution(n, k/2)*solution(n,k/2))%mod;
	return (n*((solution(n, k/2)*solution(n, k/2))%mod))%mod;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, k;
		cin >> n;
		k = reverse(n);
		long long ans = 1;
		while(k != 0){
			if(k%2 == 1){
				ans = (ans * n)%mod;
			}
			n = (n*n)%mod;
			k = k/2;
		}
		long long ans = solution(n, k);
		cout << ans << endl;
	}
}

// Day Con Lien Tiep Co Tong Lon Nhat
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int maxsofar = a[0], maxendinghere = a[0];
		for(int i = 1; i < n; i++){
			maxendinghere = max(maxendinghere + a[i], a[i]);
			maxsofar = max(maxsofar, maxendinghere);
		}
		cout << maxsofar << endl;
	}
}

// Tinh Floor(x)
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		vector<long long> v;
		long long x, val;
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			cin >> val;
			v.push_back(val);
		}

		vector<long long>::iterator it;
		it = upper_bound(v.begin(), v.end(), x);
		int res = it - v.begin();
		if (res == 0) {
			cout << -1 << endl;
		} else cout << res << endl;

	}
}
// Phan tu khac nhau

// Dem so 0

// Tim kiem nhi phan

// He co so K
int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		string a, b;
		cin >> k >> a >> b;
		while(a.length() < b.length()) a = "0" + a;
		while(a.length() > b.length()) b = "0" + b;
		int nho = 0;
		string res;
		for(int i = a.length()-1; i >= 0; i--){
			int so = (a[i]-'0') + (b[i]-'0') + nho;
			res = char(so%k + '0') + res;
			nho = so/k;
		}
		if(nho) res = char(nho + '0') + res;
		cout << res << endl;
	}
}
// Sap xep kanguru
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int* a = new int[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int i = n/2-1, j = n-1, res = n;
        sort(a, a+n);
        while(i >= 0 && j >= n/2){
            if(a[j] >= 2*a[i]){
                res--;
                i--, j--;
            } else {
                i--;
            }
        }
        cout << res << endl;
    }
}
// So Fibonaccin thu n
int mod = 1e9+7;
void Mul(long long x[2][2], long long y[2][2], long long a[2][2]){
	long long temp[2][2];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			long long res = 0;
			for(int k = 0; k < 2; k++){
				res += (x[i][k]*y[k][j])%mod;
				res %= mod;
			}
			temp[i][j] = res;
		}
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			a[i][j] = temp[i][j];
		}
	}
}

void Pow(long long a[2][2], long long b[2][2], int n){
	if(n <= 1)  return;
	Pow(a, b, n/2);
	Mul(a, a, a);
	if(n%2 != 0) Mul(a, b, a);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long a[2][2] = {{1,1}, {1,0}}, b[2][2] = {{1,1}, {1,0}};
		Pow(a, b, n-1);
		cout << a[0][0] << endl;
	}
}

// Luy thua ma tran 1
const long long mod = 1e9 + 7;
int n;
long long a[10][10], b[10][10];
void Mul(long long x[10][10], long long y[10][10]) {
	long long temp[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long res = 0;
			for (int k = 0; k < n; k++) {
				res += (x[i][k] * y[k][j]) % mod;
				res %= mod;
			}
			temp[i][j] = res;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = temp[i][j];
		}
	}
}

void Pow(int n) {
	if (n <= 1) return;
	Pow(n / 2);
	Mul(a, a);
	if (n % 2 != 0) Mul(a, b);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				b[i][j] = a[i][j];
			}
		}
		Pow(k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
}
// Tich Da Thuc
struct X{
	int hs, mu;
};

int main(){
	int t;
	cin >> t;
	while(t--){
		int m, n;
		cin >> m >> n;
		X a[m], b[n];
		for(int i = 0; i < m; i++){
			cin >> a[i].hs;
			a[i].mu = i;
		}
		for(int i = 0; i < n; i++){
			cin >> b[i].hs;
			b[i].mu = i;
		}
		
		vector< vector<X> > res;
		for(int i = 0; i < m; i++){
			vector<X> temp;
			for(int j = 0; j < n; j++){
				temp.push_back({a[i].hs*b[j].hs, a[i].mu+b[j].mu});
			}
			res.push_back(temp);
		}
		
		int mu = 0;
		while(mu < m+n-1){
			int hs = 0;
			for(int i = 0; i < res.size(); i++){
				for(int j = 0; j < res[i].size(); j++){
					if(res[i][j].mu == mu) hs += res[i][j].hs; 
				}
			}
			cout << hs << " ";
			mu++;
		}
		cout << endl;
	}
}

// Tich hai so nhi phan
