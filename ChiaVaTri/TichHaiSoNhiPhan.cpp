#include<iostream>
#include<string>
using namespace std;

long long converBinary(string s){
    long long base = 1, num = 0;
    for(int i = s.length()-1; i >= 0; i--){
        num += (s[i]-'0')*base;
        base *= 2;
    }
    return num;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        cout << converBinary(a)*converBinary(b) << endl;
    }
}