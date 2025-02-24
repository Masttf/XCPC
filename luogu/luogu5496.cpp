#include<bits/stdc++.h>
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
struct PAM{
	static constexpr int Asz = 26;
	int n, tot, last;
	string s;
	struct node{
		int cnt, len, fail;
		array<int, Asz> nex;
		node() : cnt(0), len(0), fail(0), nex{} {}
	};
	vector<node> tr;
	PAM(int m){
		tr.assign(m + 1, node());
		tot = 1;
		n = 0;
		last = 0;
		s = " ";
		tr[0].fail = 1; //偶根
		tr[1].len = -1; //奇根
	}
	int get_fail(int x){
		while(x && s[n - tr[x].len + 1] != s[n]) x = tr[x].fail;
		// dbg(x);
		return x;
	}
	void insert(char c){
		s += c;
		n++;
		int p = get_fail(last);
		dbg(p);
		if(!tr[p].nex[c - 'a']){
			tr[++tot].len = tr[p].len + 2;
			tr[tot].fail = tr[get_fail(tr[p].fail)].nex[c - 'a'];
			tr[tot].cnt = tr[tr[tot].fail].cnt + 1;
			tr[p].nex[c - 'a'] = tot;
		}
		last = tot;
	}
};
void solve(){
    string s; cin >> s;
    PAM pam(s.size());
    dbg("???");
    for(auto x : s){
    	pam.insert(x);
    	int suf = pam.tot;
    	cout << pam.tr[suf].cnt << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}