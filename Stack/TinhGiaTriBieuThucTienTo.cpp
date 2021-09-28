#include<bits/stc++.h>
using namespace std;

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
                if(a[i] == '+') temp = a+b;
                else if(a[i] == '-') temp = a-b;
                else if(a[i] == '*') temp = a*b;
                else temp = a/b;
                st.push(temp);
            } else {
                st.push(s[i]-'0');
            }
        }
        cout << st.top() << endl;
    }
}