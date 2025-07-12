#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve(){
    ll n; cin >> n;
    if (!n) return false;
    ll l = 1, r = n, a = 0;
    while (l < r){
        ll mid = (l+r)/2+1;
        cout << "? " << mid*(1LL<<a) << endl;
        string s; cin >> s;
        if (s == "SI"){
            a++; l = mid;
        } else r = mid-1LL;
        //cout << '(' << l << ' ' << r << ")\n";
    }
    cout << "=> " << l << endl;
    return true;
}

int main(){
    while (solve()) ;
    return 0;
}

