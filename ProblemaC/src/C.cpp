#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


bool solve(){
    int n; cin >> n;
    if (!n) return false;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<pair<ll,ll>>> adj(a[0]);
    for (int i = 0; i < a[0]; i++) for (auto x : a){
        adj[i].push_back({(i+x)%a[0],x});
    }
    /*
    for (int i = 0; i < a[0]; i++){
        cout << i << ": ";
        for (auto x : adj[i]) cout << "(" << x.first << "," << x.second << ") ";
        putchar('\n');
    }
    */
    // Dijkstra
    vector<ll> distance(a[0],LONG_LONG_MAX);
    vector<bool> processed(a[0],false);

    priority_queue<pair<ll,ll>> q;
    distance[0] = 0;
    q.push({0,0});
    while (!q.empty()){
        ll a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]){
            ll b = u.first, w = u.second;
            if (distance[a]+w < distance[b]){
                distance[b] = distance[a]+w;
                q.push({-distance[b],b});
            }
        }
    }
    //for (auto x : distance) cout << x << '\n';
    ll res = *max_element(distance.begin(),distance.end());
    if (res == LONG_LONG_MAX) cout << "INFINITO\n";
    else cout << res - a[0] << '\n';

    return true;
}

int main(){
    while (solve());
    return 0;
}