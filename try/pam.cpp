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
    static constexpr int ASIZE = 26;
    struct Node{
        int len;
        int fail;
        int cnt; //以它结尾的回文子串个数
        array<int, ASIZE> nex;
        Node() : len(0), fail(0), cnt(0), nex{} {}
    };
    vector<Node> tr;
    vector<int> res;
    int suff;
    string s;
    PAM() {
        init();
    }
    void init(){
        tr.assign(2, Node());
        tr[0].len = 0; //偶根
        tr[0].fail = 1;
        tr[1].len = -1; //奇根
        tr[1].fail = 0;
        suff = 0;
        s.clear();
        res.clear();
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
        tr.emplace_back();
        return tr.size() - 1;
    }
    int getFail(int x){
        int pos = s.size() - 1;
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
    bool add(char c){
        s += c;
        int let = c - 'a';
        int cur = getFail(suff);
        if(tr[cur].nex[let]){
            suff = tr[cur].nex[let];
            res.push_back(suff);
            return false;
        }
        int num = newNode();
        suff = num;
        res.push_back(suff);
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
    int run(){
        vector<int> f(tr.size());
        for(auto v : res){
            f[v]++; // 在s中的出现次数
        }
        vector<vector<int>> adj(tr.size());
        for(int i = 2; i < tr.size(); i++){
            adj[tr[i].fail].push_back(i);
        }
        int ans = 0;
        auto dfs = [&](auto self, int x) -> void{
            for(auto y : adj[x]){
                self(self, y);
                f[x] += f[y];
            }
            ans = max(ans, tr[x].len * f[x]);
        };
        dfs(dfs, 0);// fail只会连到偶根
        // 倒序遍历就是拓扑序
        // for(int i = tr.size() - 1; i >= 2; i--){
        //     // dbg(i, tr[i].fail);
        //     f[tr[i].fail] += f[i];
        // }
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
    string s; cin >> s;
    PAM pam;
    int n = s.size();
    for(auto x : s)pam.add(x);
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