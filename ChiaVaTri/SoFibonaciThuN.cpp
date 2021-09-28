#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

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

void Pow(long long a[2][2], long long b[2][2], int k){
    if(k <= 1) return;
    Pow(a, b, k/2);
    Mul(a, a, a);
    if(k%2 != 0) Mul(a, b, a);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long a[2][2] = {{1,1},{1,0}}, b[2][2] = {{1,1},{1,0}};
        Pow(a, b, n-1);
        cout << a[0][0] << endl;
    }
        
}