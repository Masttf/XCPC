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


using Pii = pair<int, int>;

int T, problem;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 4>> v;
    vector<pair<char, string>> input(problem + 1);
    for(int i = 1; i <= problem; ++i) {
        char op;
        cin >> op;
        input[i].first = op;
        if(op == '+') {
            string s;
            cin >> s;
            input[i].second = s;
            int cnt, time;

            int flag = -1;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '/'){
                    flag = j;
                    break;
                }
            }
            cnt = 0, time = 0;
            for(int j = 0; j < flag; j++){
                cnt = cnt * 10 + s[j] - '0';
            }
            for(int j = flag + 1; j < s.size(); j++){
                time = time * 10 + s[j] - '0';
            }


            --n;
            m -= time + (cnt - 1) * 20;
        } else if(op == '-') {
            string s;
            cin >> s;
            input[i].second = s;
        } else if(op == '.') continue;
        else {
            int cnt, wa;
            cin >> cnt >> wa;
            input[i].second = to_string(wa);
            v.push_back({i, cnt, wa - cnt, -1});
        }
    }
    if(m < 0 || (v.size() == 0 and m != 0) || n < 0) {
        cout << "No\n";
        return ;
    }
    auto vv = v;
    for(int i = 0; i < (1 << v.size()); ++i) {
        v = vv;
        bitset<13> bit(i);
        if(bit.count() != n) continue;
        int cm = m;
        for(int j = 0; j < v.size(); ++j) {
            if(!bit[j]) continue;
            cm -= v[j][2] * 20 + 240;
        }
        if(cm < 0) {
            continue;
        }
        for(int j = 0; j < v.size(); ++j) {
            if(!bit[j]) {
                continue;
            }
            if(cm == 0) {
                v[j][1] = 1;
                v[j][3] = 240;
                continue;
            }
            if(cm <= 59 + 20 * (v[j][1] - 1)) {
                int num = min(cm / 20, v[j][1] - 1);
                cm -= num * 20;
                v[j][1] = num + 1;
                v[j][3] = cm + 240;
                cm = 0;
            }else {
                cm -= 59 + 20 * (v[j][1] - 1);
                v[j][3] = 299;
            }
        }
        if(cm == 0) goto COUT;
    }
    cout << "No\n";
    return ;
    COUT:;
    reverse(v.begin(), v.end());
    cout << "Yes\n";
    for(int i = 1; i <= problem; ++i) {
        char op = input[i].first;
        string s = input[i].second;
        if(op == '+' || op == '-') cout << op << ' ' << s << '\n';
        else if(op == '.') cout << op << '\n';
        else {
            if(v.back()[3] == -1) {
                cout << "- " << v.back()[1] + v.back()[2] << '\n';
            } else {
                cout << "+ " << v.back()[1] + v.back()[2] << "/" << v.back()[3] << '\n';
            }
            v.pop_back();
        }
    }
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T >> problem;
    for(int i = 1; i <= T; ++i) solve();


    return 0;
}

/*
1 13
7 951
+ 1/6
? 3 4
+ 4/183
- 2
+ 3/217
.
.
.
+ 2/29
+ 1/91
.
+ 1/22
.


*/

/*
6 2
1 100
.
? 3 4
2 100
+ 1/1
+ 1/2
0 0
- 5
- 6
2 480
? 100 100
? 100 100
2 480
? 99 100
? 100 100
1 2000
? 100 100
? 100 100


*/