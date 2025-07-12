#include <bits/stdc++.h>
using namespace std;

const double ERROR = 1e-4;

bool valid_avg(double avg, vector<double> &v, int k){
	int n = v.size();
	auto w = [&](int i){
		return v[i] - avg;
	};
	
	vector<double> p(n+1);
	p.front() = 0;
	for (int i = 1; i <= n; i++) p[i] = p[i-1] + w(i-1);
	double q = 0;
	for (int i = k; i <= n; i++){
		q = min(q,p[i-k]);
		if (p[i]-q >= 0) return true;
	}
	return false;

}

bool solve(){
	int n, k; cin >> n >> k;
	if (!n) return false;

	vector<double> v(n);
	for (auto &x : v) cin >> x;

	double m0 = *min_element(v.begin(),v.end());
	double m1 = *max_element(v.begin(),v.end());
	while (m1-m0 >= ERROR){
		double mid = (m0+m1)/2;
		if (valid_avg(mid,v,k)) m0 = mid;
		else m1 = mid;
	}
	cout << (m0+m1)/2 << '\n';
	return true;
}

int main(){
	while (solve());
	return 0;
}
