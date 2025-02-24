#include<bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define int long long
#define pii pair<int,int>
//#define endl "\n"
#define dbg(x...) do{cout<<#x<<" -> ";err(x);}while(0)

void err() { cout << '\n'; }

template<class T, class... Ts>
void err(T arg, Ts... args) {
    cout << arg << ' ';
    err(args...);

}

const long double PI=acosl(-1);
int r, s, h, ans1, ans2, ans3;
double mn = 1e18;

void solve() {
	cin >> r >> s >> h;
	int y = 2*PI*r/(s * h);
	double m1 = 2*PI*r/(s * h) - y;
	m1 = min(m1, 1.0 - m1);
	for(int n1 = 2; n1 <= 1000; n1++) {
		for(int n2 = n1*2; n2 <= 1000; n2 += n1) {
			for(int n3 = n2*2; n3 <= 1000; n3 += n2) {
				int k1 = n3/n1, k2 = n3/n2;
				double dt = abs(k1-k2+1 - m1*n3);
				if(dt < mn) {
					mn = dt;
					ans1 = n1, ans2 = n2, ans3 = n3;
				}
			}
		}
	}
	
	cout << ans1 << " " << ans2 << " " << ans3 << "\n";
}

signed main() {
    IOS;
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
/*
dpijk <- dp(i - 1) j - ai k
dpijk <- dp(i - 1) j k - ai
bitset
dpij | dp(i - 1) j << ai
dpij | dp(i - 1) j - ai
*/