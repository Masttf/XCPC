#include <bits/stdc++.h>

#define int long long 
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
using i128 = __int128;

struct point {
	int x, y;
	friend point operator- (point a, point b) {
		return {a.x - b.x, a.y - b.y};
	}
};

int n;
point rp;
int r;

int Cross(point a, point b) {
	return a.x * b.y - a.y * b.x;
}
double Length(point a) {
	return a.x * a.x + a.y * a.y;
}


bool check(point A, point B) {
	point P = rp;
	point AB = B - A, AP = P - A;
	int tmp = Cross(AB, AP);
	i128 tmp1 = (i128)tmp * tmp;
	i128 tmp2 = (i128)r * r * Length(AB);
	if(tmp1 < tmp2) return false;
	return true;
}


void solve (){
	std::cin >> n;
	std::cin >> rp.x >> rp.y >> r;
	std::vector<point> v(n);
	for(int i = 0; i < n; ++i) std::cin >> v[i].x >> v[i].y;
	int x = 1;
	int ans = 0, mx = 0;
	// for(int i = 0; i < n; ++i) {
	// 	if(x == i) {
	// 		ans += Cross(v[x], v[(x + 1) % n]);
	// 		x = (x + 1) % n;
	// 	}
	// 	while(check(v[i], v[(x + 1) % n])) {
	// 		int f1 = Cross(rp - v[i], v[x] - v[i]);
	// 		int f2 = Cross(rp - v[i], v[(x + 1) % n] - v[i]);
	// 		if(f1 > 0)f1 = 1;
	// 		else if(f1 < 0)f1 = -1;
	// 		if(f2 > 0)f2 = 1;
	// 		else if(f2 < 0)f2 = -1;
	// 		if(f1 != f2) break;
	// 		ans += Cross(v[x], v[(x + 1) % n]);
	// 		x = (x + 1) % n;

	// 		int tmp = ans + Cross(v[x], v[i]);
	// 		// if(Cross(rp - v[i], v[x] - v[i]) > 0) tmp = tot - tmp;
	// 		mx = std::max(tmp, mx);
	// 	}
	// 	// dbg(i, x);
	// 	ans -= Cross(v[i], v[(i + 1) % n]);
	// }
	std::reverse(v.begin(), v.end());
	ans = 0;
	x = 0;
	for(int i = 0; i < n; ++i) {
		if(x == i) {
			ans += Cross(v[x], v[(x + 1) % n]);
			x = (x + 1) % n;
		}
		while(check(v[i], v[(x + 1) % n])) {
			int f1 = Cross(rp - v[i], v[x] - v[i]);
			int f2 = Cross(rp - v[i], v[(x + 1) % n] - v[i]);
			if(f1 > 0)f1 = 1;
			else if(f1 < 0)f1 = -1;
			if(f2 > 0)f2 = 1;
			else if(f2 < 0)f2 = -1;
			if(f1 != f2) break;

			ans += Cross(v[x], v[(x + 1) % n]);
			x = (x + 1) % n;
			int tmp = ans + Cross(v[x], v[i]);
			// dbg(tmp);
			mx = std::max(-tmp, mx);
		}
		// dbg(i, x);
		ans -= Cross(v[i], v[(i + 1) % n]);
	}
	std::cout << mx << '\n';
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while(T--) solve();
	return 0;
}