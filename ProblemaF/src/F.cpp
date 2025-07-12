#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int f, ff, mf; cin >> f >> ff >> mf;
		if (f*ff%mf) cout << "IMPOSIBLE\n";
		else cout << f*ff/mf << "\n";
	}
	return 0;
}