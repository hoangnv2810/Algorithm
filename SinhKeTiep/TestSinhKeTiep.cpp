#include<bits/stdc++.h>
using namespace std;


// Phan Tich So 1
....
void print(int a[], int &k) {
	for (int i = 1; i <= k; i++) {
		if (i == 1) cout << "(";
		cout << a[i];
		if (i < k) cout << " ";
		else cout << ") ";
	}
}

void sinh(int a[], int& k, int& check) {
	int i = k;
	while (i > 0 && a[i] == 1) i--;
	if (i < 1) check = 0;
	else {
		int kc = k - i + 1;
		a[i]--;
		k = i + kc / a[i];
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[i];
		}
		if(kc%a[i]){
			a[++k] = kc%a[i];
		}

	}

}

// Xau Nhi Phan Ke Tiep
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int i = s.length()-1;
		while(i >= 0 && s[i] == '1'){
			s[i] = '0';
			i--;
		}
		s[i] = '1';
		for(int i = 0; i < s.length(); i++) cout << s[i];
		cout << endl;
	}
}

//Tap Con Ke Tiep
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[k];
		for(int i = 1; i <= k; i++) cin >> a[i];
		
		int i = k;
		while(i > 0 && a[i] == n-k+i) i--;
		if(i == 0) {
			for(int i = 1; i <= k; i++){
				cout << i << " ";
			}
			cout << endl;
		}
		else {
			a[i]+=1;
			for(int j = i+1; j <= k; j++) a[j] = a[j-1]+1;
			for(int i = 1; i <= k; i++){
				cout << a[i] << " ";
			}
			cout << endl;
		}
	}
}

//Hoan Vi Ke Tiep
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n+1];
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		int i = n-1;
		while(a[i] > a[i+1]) i--;
		if(i == 0){
			for(int i = n; i >= 1; i--){
				cout << a[i] << " ";
			}
			cout << endl;
		} else {
			int j;
			for(j = n; j > i; j--){
				if(a[j] > a[i]) break;
			}
			swap(a[i], a[j]);
			sort(a+i+1, a+n+1);
			for(int i = 1; i <= n; i++) cout << a[i] << " ";
			cout << endl;
		}
	}
}

// Xau AB Co Do Dai N
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			a[i] = 0;
		}
		
		while(1){
			for(int i = 0; i < n; i++) cout << (char)(a[i]+65);
			cout << " ";
			int i = n-1;
			while(i >= 0 && a[i] == 1){
				a[i] = 0;
				i--;
			}
			if(i < 0) break;
			else {
				a[i] = 1;
			}
		}
		cout << endl;
	}
}

// Sinh To Hop
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[k];
		for(int i = 0; i < k; i++) a[i] = i+1;
		
		while(1){
			for(int i = 0; i < k; i++){
				cout << a[i];
			}
			cout << " ";
			int i = k-1;
			while(i >= 0 && a[i] == n-k+i+1) i--;
			if(i < 0) break;
			else {
				a[i] += 1;
				for(int j = i+1; j < k; j++) a[j] = a[j-1]+1;
			}
		}
		cout << endl;
	}
}

// Sinh Hoan Vi

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) a[i] = i+1;
		while(1){
			for(int i = 0; i < n; i++) cout << a[i];
			cout << " ";
			int i = n-2;
			while(a[i] > a[i+1]) i--;
			if(i < 0) break;
			else {
				int j;
				for(j = n-1; j > i; j--){
					if(a[j] > a[i]) break;
				}
				swap(a[i], a[j]);
				sort(a+i+1, a+n);
			}
		}
		cout << endl;
	}
}

// Hoan Vi Nguoc
int cmp(int a, int b){
	return a > b;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) a[i] = n-i;
		while(1){
			for(int i = 0; i < n; i++) cout << a[i];
			cout << " ";
			int i = n-2;
			while(a[i] < a[i+1]) i--;
			if(i < 0) break;
			else {
				int j;
				for(j = n-1; j > i; j--){
					if(a[j] < a[i]) break;
				}
				swap(a[j], a[i]);
				sort(a+i+1, a+n, cmp);
			}
		}
		cout << endl;
	}
}

//Xau Nhi Phan Co K Bit 1
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++) a[i] = 0;
		while(1){
			string temp = "";
			int sum = 0;
			for(int i = 0; i < n; i++) {
				sum += a[i];
				temp += char(a[i]+'0');
			}
			if(sum == k) cout << temp << " ";
			int i = n-1;
			while(i >= 0 && a[i] == 1){
				a[i] = 0;
				i--;
			}
			if(i < 0) break;
			else a[i] = 1;
		}
		cout << endl;
	}
}

// Thuat Toan Sinh
int n, a[100];
void Result(){
	for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			int flag = 0;
			if(i%2){
				for(int i = 1; i <= n/2+1; i++){
					if(a[i] == a[n-i+1]) flag++;
				}
			} else {
				for(int i = 1; i <= n/2; i++){
					if(a[i] == a[n-i+1]) flag++;
				}
			}
			if(n%2 == 1 && flag == n/2+1 || n%2 == 0 && flag == n/2){
				Result();
			}
		} else {
			Try(i+1);
		}
	}
}

int main(){
	cin >> n;
	Try(1);
}

// Tong Day Con = K
int a[100], b[100], n, k, res;
void Result(){
	for(int i = 1; i <= n; i++){
		if(a[i]) cout << b[i-1] << " ";
	}
	cout << endl;
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			int sum = 0;
			for(int i = 1; i <= n; i++){
				if(a[i]) sum += b[i-1];
			}
			if(sum == k){
				Result();
				res++;
			}
		} else {
			Try(i+1);
		}
	}
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	Try(1);
	cout << res << endl;
}

// Ha Ha Ha
int a[100], n;
void Result(){
	if(a[1] == 1 && a[n] == 0){
		int flag = 0;
		for(int i = 1; i <= n-1; i++){
			if(a[i] == 1 && a[i+1] == 1){
				flag = 1;
			}
		}
		
		if(!flag){
			for(int i = 1; i <= n; i++){
				if(a[i]) cout << (char)(a[i]+71);
				else cout << (char)(a[i]+65);
			}
			cout << endl;
		}
		
	}
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			Result();
		} else {
			Try(i+1);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		Try(1);
		
	}
}

// Xau Nhi Phan Truoc
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int nho = 0;
		for(int i = s.length()-1; i >= 0; i--){
			int temp = 0;
			if(i == s.length()-1) temp = (s[i]-'0')-1-nho;
			else temp = (s[i]-'0') - nho;
			if(temp < 0){
				temp += 2;
				nho = 1;
			} else {
				nho = 0;
			}
			s[i] = (temp+'0');
		}
		for(int i = 0; i < s.length(); i++) cout << s[i];
		cout << endl;
	}
	
}

// Dat Ten
int n, k, a[100];
void Try(int i){
	for(int j = a[i-1]+1; j <= n-k+i; j++){
		a[i] = j;
		if(i == k){
			for(int l = 1; l <= k; l++){
				cout << (char)(a[l]+64);
			}
			cout << endl;
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
		Try(1);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a[100], k = 1, check = 1;
		cin >> n;
		a[k] = n;
		while(check){
			print(a, k);
			sinh(a, k, check);
		}
		cout << endl;
	}
}
// Ma Gray 1
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<string> a;
		a.push_back("0");
		a.push_back("1");
		for(int i = 2; i < pow(2, n); i *= 2){
			for(int j = i-1; j >= 0; j--){
				a.push_back(a[j]);
			}
			for(int j = 0; j < i; j++){
				a[j] = "0" + a[j];
			}
			for(int j = i; j < 2*i; j++){
				a[j] = "1" + a[j];
			}
		}
		for(int i = 0; i < a.size(); i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
}

// Ma Gray3
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		cout << s[0];
		for(int i = 1; i < s.length(); i++){
			if(s[i] != s[i-1]) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
}

// Ma Gray 2
int main(){
	int t;
	cin >> t;
	while(t--){
		string s, res;
		cin >> s;
		res += s[0];
		for(int i = 1; i < s.length(); i++){
			if(res[res.length()-1] != s[i]) res += "1";
			else res += "0";
		}
		cout << res;
		cout << endl;
	}

}

// Xau AB Dac Biet
int a[100], n, k;
int solution(){
	int dem = 0, check = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0){
			dem++;
		} else dem = 0;
		if(dem > k) return 0;
		else if(dem == k) check++; 
	}
	if(check == 1){
		return 1;
	}
	return 0;
}
vector<string> res;
void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			if(solution()){
				string temp;
				for(int l = 1; l <= n; l++){
					temp += char(a[l]+65);
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
		Try(1);
		cout << res.size() << endl;
		for(int i = 0; i < res.size(); i++){
			cout << res[i] << endl;
		}
	}
}

// Tap Quan Su
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n+1], b[n+1];
		for(int i = 1; i <= k; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		
		int i = k;
		while(i >= 0 && a[i] == n-k+i) i--;
		if(i < 0){
			cout << k << endl;
		}
		else {
			a[i] += 1;
			for(int j = i+1; j <= k; j++){
				a[j] = a[j-1]+1;
			}
			int res = 0;
			for(int i = 1; i <= k; i++){
				for(int j = 1; j <= k; j++){
					if(a[i] == b[j]) res++;
				}
			}
			cout << k-res << endl;	
		}
	}
}

// Hoan Vi Tiep Theo Cua Chuoi So 
int main(){
	int t;
	cin >> t;
	while(t--){
		string a;
		int stt;
		cin >> stt >> a;
		
		int i = a.length()-2;
		while(a[i] >= a[i+1]) i--;
		if(i < 0){
			cout << stt << " " << "BIGGEST" << endl;
		} else {
			int j;
			for(j = a.length()-1; j > i; j--){
				if(a[j] > a[i]) break;
			}
			swap(a[i], a[j]);
			sort(a.begin()+i+1, a.end());
			for(int i = 0; i < a.length(); i++) cout << a[i];
			cout << endl;
		}
	}
}

// Chon So Tu Ma Tran Vuong Cap N
int a[100][100], n,  vs[100], b[100], sum;
vector<int> res;
void Try(int i){
	for(int j = 1; j <= n; j++){
		if(vs[j] == 0){
			b[i] = j;
			vs[j] = 1;
			if(i == n){
				int temp = 0;
				for(int l = 1; l <= n; l++){
					temp += a[l][b[l]];
				}
				if(temp == sum){
					for(int l = 1; l <= n; l++){
						res.push_back(b[l]);
					}	
				}
			} else {
				Try(i+1);
			}
			vs[j] = 0;
		}
		
	}
}

int main(){
	cin >> n >> sum;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	Try(1);
	cout << res.size()/n << endl;
	for(int i = 0; i < res.size(); i++){
		if(i % n == 0 && i != 0) cout << endl;
		cout << res[i] << " ";
	}
}

//Tim Boi So
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		queue<string> q;
		string s;
		q.push("9");
		while(!q.empty()){
			s = q.front();
			q.pop();
			long long temp = 0;
			for(int i = 0; i < s.length(); i++){
				temp = 10*temp + (s[i]-'0');
			}
			if(temp%n == 0){
				break;
			}
			q.push(s+"0");
			q.push(s+"9");
		}
		cout << s << endl;
	}
}

// Tap Hop
int n, k, s, a[100], res;
void Try(int i){
	for(int j = a[i-1]+1; j <= n-k+i; j++){
		a[i] = j;
		if(i == k){
			long long sum = 0;
			for(int l = 1; l <= k; l++){
				sum += a[l];
			}
			if(sum == s) res++;
		} else {
			Try(i+1);
		}
	}
}

int main(){
	while(1){
		cin >> n >> k >> s;
		if(n == 0 && k == 0 && s == 0) break;
		Try(1);
		cout << res << endl;
		res = 0;
	}
}

// Phuong An Toi Uu
struct tui{
	int kg, gt;
};
tui a[100];
int b[100], n, w, c = INT_MIN;
vector<int> res;
void Result(){
	int kl = 0, gt = 0;
	for(int i = 1; i <= n; i++){
		if(b[i]){
			gt += a[i].gt;
			kl += a[i].kg;
		}
	}
	if(kl <= w && gt > c){
		c = gt;
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
			Result();
		} else {
			Try(i+1);
		}
	}
}

int main(){
	cin >> n >> w;
	for(int i = 1; i <= n; i++) cin >> a[i].gt;	
	for(int i = 1; i <= n; i++) cin >> a[i].kg;
	
	Try(1);
	cout << c << endl;
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
}

// Day Con Tang Dang Bac K
int a[100], n, k, b[100], res;

int Result(){
	for(int i = 1; i < k; i++){
		if(b[a[i]] > b[a[i+1]]) return 0;
	}	
	return 1;
}

void Try(int i){
	for(int j = a[i-1]+1; j <= n-k+i; j++){
		a[i] = j;
		if(i == k){
			if(Result()){
				res++;			
			}
		} else{
			Try(i+1);
		}
	}
}
int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> b[i];
	Try(1);
	cout << res;
	res = 0;
}

//Tap Con Lien Ke Phia Truoc
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 1; i <= k; i++){
			cin >> a[i];
		}
		int check = 1;
		for(int i = 1; i <= k; i++){
			if(a[i] != i){
				check = 0;
				break;
			}
		}
		if(check){
			for(int i = 1; i <= k; i++){
				cout << n-k+i << " ";
			}
			cout << endl;
		} else {
			int i = k; 
			while(i > 1 && a[i] == a[i-1]+1){
				i--;
			}
			a[i]--;
			for(int j = i+1; j <= k; j++){
				a[j] = n-k+j;
			}
			for(int i = 1; i <= k; i++) cout << a[i] << " ";
			cout << endl;
		}
	}
}
