#include<bits/stdc++.h>
using namespace std;

// Day ngoac dung dai nhat
int main(){
	int t;
	cin >> t;
	while(t--){
		string exp;
		cin >> exp;
		stack<int> st;
		st.push(-1);
		int res = 0;
		for(int i = 0; i < exp.length(); i++){
			if(exp[i] == '('){
				st.push(i);
			} else {
				st.pop();
				if(!st.empty()) res = max(res, i - st.top());
				else {
					st.push(i);
				}
			}
		}
		cout << res << endl;
	}
}

// Ngan xep 1
int main() {
	stack<int> s;
	string input;
	while (cin >> input) {
		if (input == "push") {
			int val;
			cin >> val;
			s.push(val);
		}
		else if (input == "pop") {
			s.pop();
		}
		else {
			if (s.empty()) cout << "empty";
			else {
				vector<int> temp;
				while (!s.empty()) {
					temp.push_back(s.top());
					s.pop();
				}
				reverse(temp.begin(), temp.end());
				for (auto x : temp) {
					cout << x << " ";
					s.push(x);
				}
			}
			cout << endl;
		}

	}
}


// Ngan xep 2
int main() {
	stack<int> s;
	int t;
	cin >> t;
	while (t--) {
		string input;
		cin >> input;
		if (input == "PUSH") {
			int val;
			cin >> val;
			s.push(val);
		}
		else if (input == "POP") {
			if (!s.empty()) s.pop();
		}
		else {
			if (s.empty()) cout << "NONE";
			else {
				cout << s.top();
			}
			cout << endl;
		}
	}
}


// Kiem tra bieu thuc so hoc
int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		int check;
		for(int i = 0; i < s.length(); i++){
			if(s[i] != ')'){
				st.push(s[i]);
			} else {
				char top = st.top();
				st.pop();
				check = 1;
				while(!st.empty() && top != '('){
					if(top == '+' || top == '-' || top == '*' || top == '/'){
						check = 0;
					}
					top = st.top();
					st.pop();
				}
				if(check){
					break;
				}
			}
		}
		if(check){
			cout << "Yes";
		} else {
			cout << "No";
		}
		cout << endl;
	}
}

// Dem so ngoac doi chieu
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == ')'){
				if(!st.empty() && st.top() == '('){
					st.pop();
					continue;
				}
			}
			st.push(s[i]);
		}
		int res = 0;
		while(!st.empty()){
			char a = st.top();
			st.pop();
			char b = st.top();
			st.pop();
			if(a != b) res++;
			res++;
		}
		cout << res << endl;
	}
}

// Bien doi tien to - trung to
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<string> st;
		for(int i = s.length()-1; i >= 0; i--){
			if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
				string a = st.top();
				st.pop();
				string b = st.top();
				st.pop();
				string temp = '(' + a + s[i] + b + ')';
				st.push(temp);
			}
			else st.push(string(1, s[i]));
		}
		while(!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}

// Bien doi tien to - hau to
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<string> st;
		for(int i = s.length()-1; i >= 0; i--){
			if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
				string a = st.top();
				st.pop();
				string b = st.top();
				st.pop();
				string temp = a + b + s[i];
				st.push(temp);
			} else {
				st.push(string(1, s[i]));
			}
		}
		while(!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}

// Tinh gia tri bieu thuc hau to
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<int> st;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				int temp;
				if(s[i] == '+') temp = a+b;
				else if(s[i] == '-') temp = b-a;
				else if(s[i] == '*') temp = a*b;
				else temp = b/a;
				st.push(temp);			
			} else {
				st.push((s[i]-'0'));
			}
		}
		cout << st.top() << endl;
	}
}

// Tinh gia tri bieu thuc tien to
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        stack<int> st;
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int temp;
                if(s[i] == '+') temp = a+b;
                else if(s[i] == '-') temp = a-b;
                else if(s[i] == '*') temp = a*b;
                else temp = a/b;
                st.push(temp);
            } else {
                st.push(s[i]-'0');
            }
        }
        cout << st.top() << endl;
    }
}

// Phan Tu Ben Phai Dau Tien Lon Hon
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n], res[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		stack<int> st;
		for(int i = n-1; i >= 0; i--){
			if(!st.empty() && a[i] >= a[st.top()]){
				st.pop();
			}
			if(!st.empty()){
				res[i] = a[st.top()];
			} else {
				res[i] = -1;
			}
			st.push(i);
		}
		for(int i = 0; i < n; i++) cout << res[i] << " ";
		cout << endl;
	}
}

// Dao tu
int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string str;
		getline(cin, str);
		stack<string> st;
		stringstream s(str);
		string word;
		while(s >> word){
			st.push(word);
		}
		
		while(!st.empty()){
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
}
// Hinh chu nhat lon nhat
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		stack<int> st;
		int i = 0, maxtop = 0, res = 0;
		while(i < n){
			if(st.empty() || a[i] >= a[st.top()]){
				st.push(i++);
			} else {
				int temp = st.top();
				st.pop();
				if(st.empty()){
					maxtop = a[temp]*i;
				} else {
					maxtop = a[temp]*(i-1-st.top());
				}
				res = max(res, maxtop);
				
			}
		}	
		while(!st.empty()){
			int temp = st.top();
			st.pop();
			if(st.empty()){
				maxtop = a[temp]*i;
			} else {
				maxtop = a[temp]*(i-1-st.top());
			}
			res = max(res, maxtop);
		}
		cout << res << endl;
	}
}

// Bien doi trung to hau to
int priority(char c){
	if(c =='^') return 3;
	else if(c == '*' || c == '/') return 2;
	else if(c == '+' || c == '-') return 1;
	else return 0;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '('){
				st.push(s[i]);
			} else if (s[i] == ')'){
				while(!st.empty() && st.top() != '('){
					cout << st.top();
					st.pop();
				}
				st.pop();
			} else if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^'){
				while(!s.empty() && priority(s[i]) <= priority(st.top())){
					cout << st.top();
					st.pop();
				}
				st.push(s[i]);
			} else cout << s[i];
		}
		while(!st.empty()){
			if(st.top() != '(') cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}

// Bien doi hau to tien to
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<string> st;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
				string a = st.top();
				st.pop();
				string b = st.top();
				st.pop();
				string tmp = s[i] + b + a;
				st.push(tmp);
			} else {
				st.push(string(1, s[i]));
			}
		}
		while(!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}

//Bien doi hau to trung to
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<string> st;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
				string a = st.top();
				st.pop();
				string b= st.top();
				st.pop();
				string tmp = '(' + b + s[i] + a + ')';
				st.push(tmp);
			} else {
				st.push(string(1, s[i]));
			}
		}
		while(!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}

// Bieu thuc tang giam
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<int> st;
		st.push(1);
		int count = 1;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == 'D'){
				st.push(++count);
			} else {
				while(!st.empty()){
					cout << st.top();
					st.pop();
				}
				st.push(++count);
			}
		}
		while(!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}

// Phan tu ben phai nho hon
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n], next[n], small[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		stack<int> st;
		for(int i = n-1; i >= 0; i--){
			while(!st.empty() && a[i] >= a[st.top()]){
				st.pop();
			}
			if(!st.empty()){
				next[i] = st.top();
			} else {
				next[i] = -1;
			}
			st.push(i);
		}
		
		while(!st.empty()) st.pop();
		
		for(int i = n-1; i >= 0; i--){
			while(!st.empty() && a[i] <= a[st.top()]){
				st.pop();
			} 
			if(!st.empty()){
				small[i] = st.top();
			} else {
				small[i] = -1;
			}
			st.push(i);
		}
		for(int i = 0; i < n; i++){
			if(next[i] != -1 && small[next[i]] != -1){
				cout << a[small[next[i]]] << " ";
			} else {
				cout << -1 << " ";
			}
			
		}
		cout << endl;
	}
}

// Giai ma xau ki tu
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == ']'){
				string tmp;
				while(!st.empty() && st.top() != '['){
					tmp = st.top() + tmp;
					st.pop();
				}
				st.pop();
				
				int num = 0, base = 1;
				if(st.empty() || (st.top() >= 'a' && st.top() <= 'z')) num = 1;
				else {
					while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
						num += (st.top()-'0')*base;
						base *= 10;
						st.pop();
					}
				}
				
				for(int j = 0; j < num; j++){
					for(int k = 0; k < tmp.size(); k++){
						st.push(tmp[k]);
					}
				}
			} else {
				st.push(s[i]);
			}
		}
		string res;
		while(!st.empty()){
			res.push_back(st.top());
			st.pop();
		}
		reverse(res.begin(), res.end());
		for(int i = 0; i < res.size(); i++){
			cout << res[i];
		}
		cout << endl;
	}
}

// Nhip Chung Khoan
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		stack<int> st;
		st.push(0);
		int res[n];
		res[0] = 1;
		for(int i = 1; i < n; i++){
			while(!st.empty() && a[i] >= a[st.top()]){
				st.pop();
			}
			if(!st.empty()){
				res[i] = i - st.top();
			} else {
				res[i] = i+1;
			}
			st.push(i);
		}
		for(int i = 0; i < n; i++){
			cout << res[i] << " ";
		}
		cout << endl;
	}
}

// Bieu thuc dung dai nhat
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		int res = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '('){
				st.push(s[i]);
			} else {
				if(!st.empty()){
					st.pop();
					res += 2;
				}
			}
		}
		cout << res << endl;
	}
}

// Bieu thuc tuong duong
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<int> st;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '('){
				st.push(i);
			} else if(s[i] == ')') {
				int top = st.top();
				st.pop();
				if(top == 0) continue;
				if(s[top-1] == '+') continue;
				if(s[top-1] == '-'){
					for(int j = top; j <= i; j++){
						if(s[j] == '+') s[j] = '-';
						else if(s[j] == '-') s[j] = '+'; //note else if
					}
				}
			}
		}
		for(int i = 0; i < s.size(); i++){
			if(s[i] != '(' && s[i] != ')') cout << s[i];
		}
		cout << endl;
	}
}

// So sanh bieu thuc

// Phan tu co so lan xuat hien nhieu hon ben phai

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		map<int, int> mp;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		vector<int> res;
		for(int i = 0; i < n; i++){
			int check = 0, temp;
			for(int j = i+1; j < n; j++){
				if(mp[a[j]] > mp[a[i]]){
					check = 1;
					temp = a[j];
					break;
				}
			}
			if(check == 1) res.push_back(temp);
			else if(i == n-1) res.push_back(-1);
			else res.push_back(-1);
			
		}
		for(int i = 0; i < res.size(); i++){
			cout << res[i] << " ";
		}
		cout << endl;
		
	}
}
