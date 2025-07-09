#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int N; cin >> N;
		priority_queue<int> l;
		priority_queue<int,vector<int>,greater<int>> r;
		int num = 1;
		int x; cin >> x; l.push(x);
		for (int i = 1; i < N; i++){
			cin >> x;
			int m = l.top();
			if (x <= m) l.push(x);
			else{
				num++;
				r.push(x);
			} 

			if (r.size()>l.size()){
				l.push(r.top()); r.pop();
			}
			else if (l.size()-r.size() >= 2){
				r.push(l.top()); l.pop();
			}
		}
		cout << num << '\n';
	}
	return 0;
}