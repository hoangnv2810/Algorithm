#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, *a;
        cin >> n;
        a = new int[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int dp1[n], dp2[n];
        for(int i = 0; i < n; i++){
            dp1[i] = a[i];
            for(int j = 0; j < i; j++){
                if(a[i] > a[j]) dp1[i] = max(dp1[i], dp1[j] + a[i]); 
            }
        }
        for(int i = n-1; i >= 0; i--){
            dp2[i] = a[i];
            for(int j = n-1; j > i; j--){
                if(a[i] > a[j]) dp2[i] = max(dp2[i], dp2[j] + a[i]);
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, dp1[i]+dp2[i]-a[i]);
        }
        cout << res << endl;
    }
}