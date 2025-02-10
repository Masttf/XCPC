#include<bits/stdc++.h>
// #define int long long
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
template<const int T>
struct ModInt {
	const static int mod = T;
	int x;
	ModInt(int x = 0) : x(x % mod) {}
	// ModInt(long long x) : x(int(x % mod)) {} 
	int val() { return x; }
	ModInt operator + (const ModInt &a) const { 
		int x0 = x + a.x;
		return ModInt(x0 < mod ? x0 : x0 - mod); 
	}
	ModInt operator - (const ModInt &a) const {
		int x0 = x - a.x;
		return ModInt(x0 < 0 ? x0 + mod : x0);
	}
	ModInt operator * (const ModInt &a) const {
		return ModInt(1LL * x * a.x % mod);
	}
	ModInt operator / (const ModInt &a) const {
		return *this * a.inv();
	}
	bool operator == (const ModInt &a) const {
		return x == a.x;
	}
	bool operator != (const ModInt &a) const {
		return x != a.x;
	}
	void operator += (const ModInt &a) {
		x += a.x;
		if (x >= mod) x -= mod;
	}
	void operator -= (const ModInt &a) {
		x -= a.x;
		if (x < 0) x += mod;
	}
	void operator *= (const ModInt &a) {
		x = 1LL * x * a.x % mod;
	}			
	void operator /= (const ModInt &a) {
		*this = *this / a;
	}
	friend ModInt operator + (int y, const ModInt &a){
		int x0 = y + a.x;
		return ModInt(x0 < mod ? x0 : x0 - mod);
	}
	friend ModInt operator - (int y, const ModInt &a){
		int x0 = y - a.x;
		return ModInt(x0 < 0 ? x0 + mod : x0);
	}			
	friend ModInt operator * (int y, const ModInt &a){
		return ModInt(1LL * y * a.x % mod);
	}
	friend ModInt operator / (int y, const ModInt &a){
		return ModInt(y) / a;
	}
	friend ostream &operator<<(ostream &os, const ModInt &a) {
		return os << a.x;
	}
	friend istream &operator>>(istream &is, ModInt &t){
		return is >> t.x;
	}						
				
	ModInt pow(long long n) const {
	ModInt res(1), mul(x);
		while(n){
			if (n & 1) res *= mul;
			mul *= mul;
			n >>= 1;
		}
		return res;
	}
				
	ModInt inv() const {
		int a = x, b = mod, u = 1, v = 0;
		while (b) {
			int t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		if (u < 0) u += mod;
		return u;
	}
				
};
constexpr int mod = 998244353;
using mint = ModInt<mod>;
static constexpr int ASIZE = 10;
struct Node{
    int len;
    int fail;
    int cnt; //以它结尾的回文子串个数
    array<int, ASIZE> nex;
    Node() : len(0), fail(0), cnt(0), nex{} {}
};
constexpr int maxn = 1e7;
mint f1[maxn], f2[maxn];
Node tr[maxn];
int flag = 0;
struct PAM{
    int suff;
    string s;
    int tot;
    int pos;
    PAM(string &S) {
        init(S);
    }
    void init(string &S){
    	s = S;
        tr[0].len = 0; //偶根
        tr[0].fail = 1;
        tr[1].len = -1; //奇根
        tr[1].fail = 0;
        suff = 0;
        tot = 1;
        pos = -1;
        /*
        你0、1一个是偶数空，一个是奇数空
        怎么跳fail都匹配不上，但是它 会在奇数根1下面挂上，表示单独的字符C。
        fail[0]=1 让0指向1，就实现了增添新的单独字符的功能。
        跳fail的本质过程是判断能不能加入新的位
        不能在单个字符周围加入新的字符形成长度为3的新回文串
        不代表不能在“0空”位置形成 aa,bb,ccaa,bb,cc这样长度为2的回文串。
        */
    }
    int newNode(){
    	tot++;
        return tot; 
    }
    int getFail(int x){
        int cur = x, curlen = 0;
        while(true){
            curlen = tr[cur].len;
            if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]){
                break;
            }
            cur = tr[cur].fail;
        }
        return cur;
    }
    bool add(int i){
    	pos++;
        int let = s[i] - '0';
        int cur = getFail(suff);
        if(tr[cur].nex[let]){
            suff = tr[cur].nex[let];
            if(!flag)f1[suff] += 1;
            f2[suff] += 1; 
            return false;
        }
        int num = newNode();
        suff = num;
        if(!flag)f1[suff] += 1;
        f2[suff] += 1; 
        tr[num].fail = tr[getFail(tr[cur].fail)].nex[let];
        tr[cur].nex[let] = num;
        tr[num].len = tr[cur].len + 2;
        tr[num].cnt = tr[tr[num].fail].cnt + 1;
        return true;
        /*
        1.如果i从0开始，i−len[x]−1可能出现负数，特判一下。
        2.求新点的fail时是getfail(fail[pos])如果写成了getfail(pos)自己会被当成是自己的最长回文后缀，fail指向自己会导致程序死循环。
        3.求新点的fail必须在建立新点之前！
        否则考虑 要建立奇数根下的点时(abbbc)，他们fail[i]=0,getfail(fail[pos])会跳到1(0匹配的话不会再1下建点)，如果1下已经建立它的点，fail也会指向他自己导致程序卡死
        */
    }
    mint run(){
        // for(int i = 2; i <= tot; i++){
        //     adj[tr[i].fail].push_back(i);
        // }
        // mint ans = 0;
        // auto dfs = [&](auto self, int x) -> void{
        //     for(auto y : adj[x]){
        //         self(self, y);
        //         f1[x] += f1[y];
        //         f2[x] += f2[y];
        //     }
        //     if(tr[x].len * 2 > s.size())return ;
        //     ans += tr[x].len * (f2[x] - f1[x]) * (f2[x] - f1[x]);
        // };
        // dfs(dfs, 0);// fail只会连到偶根
        mint ans = 0;
        for(int i = tot; i >= 2; i--){
        	// dbg(i, tr[i].fail);
        	f1[tr[i].fail] += f1[i];
        	f2[tr[i].fail] += f2[i];
        	if(tr[i].len * 2 > s.size())continue;
        	ans += tr[i].len * (f2[i] - f1[i]) * (f2[i] - f1[i]);
        }
        return ans;
    }
    /*
    时间复杂度O(n),这棵树的节点个数-2就是本质不同的回文串个数
    首先建立的节点数是O(n)的
    其次因为每次执行while循环的时候cur的深度会-1
    而cur的深度总共增加了n次(for循环中)
    所以while的执行次数也是O(n)的
    */
};
void solve(){
	int n; cin >> n;
	string s; cin >> s;
	string temp = s + s;
	PAM pam(temp);
	for(int i = 0; i < n; i++)pam.add(i);
	flag ^= 1;
	for(int i = n; i < 2 * n; i++)pam.add(i);
	cout << pam.run() << '\n';
	
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}