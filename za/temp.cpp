#include<bits/stdc++.h>
#define int long long
using namespace std;

#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}

const int mod = 998244353;

template <const int M, class T>
struct Matrix{
    T m[M][M];
    int row, col;
    Matrix(){
        row = 0;
        col = 0;
    }
    Matrix(int n){
        row = col = n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)m[i][j] = 1;
                else m[i][j] = 0;
            }
        }
    }
    Matrix(int r, int c){
        row = r;
        col = c;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                m[i][j] = 0;
            }
        }
    }
    Matrix(vector<vector<T>> a){
        row = a.size();
        col = a[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                m[i][j] = a[i][j];
            }
        }
    }
    Matrix operator * (const Matrix &y) const {
        Matrix res(row, y.col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < y.col; j++){
                for(int k = 0; k < col; k++){
                    res.m[i][j] += m[i][k] * y.m[k][j] % mod;
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
    Matrix qmi (long long b){
        Matrix res(row);
        Matrix a = *this;
        while(b){
            if(b & 1) res = res * a;
            b >>= 1;
            a = a * a;
        }
        return res;
    }
};
using matrix = Matrix<3,int>;

matrix m(3,1);
matrix m0(3,3);
matrix m1(3,3);
matrix m2(3,3);

void init() {
    m.m[2][0] = 1;
    m0.m[0][0] = 1;
    m0.m[0][1] = 1;
    m0.m[0][2] = 1;
    m0.m[1][1] = 1;
    m0.m[2][2] = 1;
    m1.m[0][0] = 1;
    m1.m[1][0] = 1;
    m1.m[1][1] = 1;
    m1.m[1][2] = 1;
    m1.m[2][2] = 1;
    m2.m[0][0] = 1;
    m2.m[0][1] = 1;
    m2.m[0][2] = 1;
    m2.m[1][0] = 1;
    m2.m[1][1] = 1;
    m2.m[1][2] = 1;
    m2.m[2][2] = 1;
}

const int maxn = 1e5 + 5;
// matrix a[maxn << 2];
// int tt[maxn << 2][3][3];
// struct SegmentTree {
// #define ls(p) (p << 1)
// #define rs(p) (p << 1 | 1)
//     matrix v[maxn << 2];
//     void update(int p) {
//         v[p] = v[ls(p)] * v[rs(p)];
//     }
//     void build(int p,int l,int r) {
//         if (l == r) {
//             v[p] = a[l];
//             return ;
//         }
//         int mid = (l + r) >> 1;
//         build(ls(p), l, mid);
//         build(rs(p), mid + 1, r);
//         update(p);
//     }
//     void modify(int p,int l,int r,int w,const matrix &g) {
//         if (l == r) {
//             v[p] = g;
//             return ;
//         }
//         int mid = (l + r) >> 1;
//         if (mid >= w) modify(ls(p),l,mid,w,g);
//         else modify(rs(p),mid + 1,r,w,g);
//         update(p); 
//     }
//     matrix query(int p,int l,int r,int L,int R) {
//         matrix res(3);
//         if (L <= l && R >= r) {
//             return v[p];
//         }
//         int mid = (l + r) >> 1;
//         if (L <= mid) res = res * query(ls(p),l,mid,L,R);
//         if (R > mid) res = res * query(rs(p),mid + 1,r,L,R);
//         return res;
//     }
// };

void solve(){
    init();
    int n,q; cin >> n >> q;
    // SegmentTree tr;
    string s;cin >> s;
    for (int i = 0;i < n;i++) {
        if (s[i] == '1') {
            a[i + 1] = m1;
        }
        else if (s[i] == '0') {
            a[i + 1] = m0;
        }
        else a[i + 1] = m2;
    }
    // tr.build(1,1,n);
    while (q--) {
        int x;cin >> x;
        char c;cin >> c;
        if (c == '0') {
            a[x] = m0;
        }
        else if (c == '1') {
            a[x] = m1;
        }
        else a[x] = m2;
        // tr.modify(1,1,n,x,a[x]);
        // matrix ans = tr.query(1,1,n,1,n);
        // ans = ans * m;
        // cout << (ans.m[0][0] + ans.m[1][0]) % mod << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
