#include<bits/stdc++.h>
using namespace std;

inline void work() {
	set<pair<int,int> > st;
	int mx = 2e9, pos = 2e9, last = -1;
	bool ok = true;
	int n, m;
	cin >> n >> m;
	while(m--) {
		int op, p, q;
		cin >> op;
		if (op == 1) {
			if (!ok) puts("bad");
			else if (last != -1) {
				auto ptr = st.lower_bound({last, 0});
				if ((prev(ptr) -> first) == (ptr -> first) - 1) printf("%d\n", (ptr -> first));
				else printf("%d\n", (prev(ptr) -> first) + 1);
			} else {
				if (st.size() == 0) puts("0");
				else {
					auto ptr = *st.begin();
					printf("%d\n", (ptr.first + ptr.second + 1) % 2);
				}
			}
		} else if (op == 2) {
			if (!ok) puts("bad");
			else if (mx == 2e9) puts("inf");
			else printf("%d\n", mx);
		} else {
			cin >> p >> q;
			if (abs(p - 1) > q) {ok = false; continue;}
			if (p > 1) pos = min(pos, q);
			if (p > 1) mx = min(mx, q - abs(p - 1));
			st.insert({q, p});
			auto ptr = st.find({q, p});
			if (ptr != st.begin() && next(ptr) != st.end() && last == (next(ptr) -> first)) last = -1;
			if (ptr != st.begin()) {
				auto pre = *prev(ptr);
				if ((pre.first + pre.second) % 2 != (p + q) % 2) last = max(last, q);
				if (abs(pre.second - p) > abs(pre.first - q)) {ok = false; continue;}
			}
			if (next(ptr) != st.end()) {
				auto nxt = *next(ptr);
				if ((nxt.first + nxt.second) % 2 != (p + q) % 2) last = max(last, nxt.first);
				if (abs(nxt.second - p) > abs(nxt.first - q)) {ok = false; continue;}
			}
			if (last > pos) {ok = false; continue;}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) work();
	return 0;
}