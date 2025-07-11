#include <bits/stdc++.h>
using namespace std;


int main() {
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) v[i] = i;
		int m; cin >> m;
		while (m--){
			int x,y; cin >> x >> y;
			x--; y--;
			swap(v[x],v[y]);
		}
		for (int i = 0; i < n; i++){
			if (i) putchar(' ');
			cout << v[i]+1;
		}
		putchar('\n');
	}
	return 0;
}
