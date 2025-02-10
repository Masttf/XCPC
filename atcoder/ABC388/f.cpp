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
constexpr int inf = 1e18;
template <const int M, class T>
struct Matrix{
    T m[M][M];
    int row, col;
    Matrix(){
        row = 0;
        col = 0;
    }
    Matrix(int n){ //单位矩阵
        row = col = n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)m[i][j] = 0;
                else m[i][j] = -inf;
            }
        }
    }
    Matrix(int r, int c){
        row = r;
        col = c;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                m[i][j] = -inf;
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
	                res.m[i][j] = max(res.m[i][j], m[i][k] + y.m[k][j]);
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
  	void pf(){
  		for(int i = 0; i < row; i++){
  			for(int j = 0; j < col; j++){
  				cout << m[i][j] << ' ';
  			}
  			cout << endl;
  		}
  	}
  	friend ostream &operator<<(ostream &os, const Matrix &a) {
		for(int i = 0; i < a.row; i++){
			for(int j = 0; j < a.col; j++){
				os << a.m[i][j] << ' ';
			}
			os << '\n';
		}
		return os;
	}
};
using matrix = Matrix<20, int>;
void solve(){
    int n, m, A, B; cin >> n >> m >> A >> B;
    vector<pair<int, int>> a(m);
    for(auto &[l, r] : a){
    	cin >> l >> r;
    }
    for(auto [l, r] : a){
    	if((l <= n && n <= r) || (r - l + 1 > B)){
    		cout << "No\n";
    		return ;
    	}
    }
    matrix b(B, B);
    for(int i = 0; i < B - 1; i++){
    	b.m[i + 1][i] = 0;
    }
    for(int i = A - 1; i < B; i++){
    	b.m[0][i] = 0;
    }
    matrix dp(1, B);
    for(int i = 0; i < B; i++){
    	dp.m[0][i] = 0;
    }
    dp.m[0][0] = 1;
    int now = 1;
    for(auto [l, r] : a){
    	int d = l - now;
    	dp = dp * b.qmi(d);
    	for(int j = l; j <= r; j++){
    		dp.m[0][0] = 0;
    		dp = dp * b;
    	}
    	now = r + 1;
    }
    int d = n - now;
    dp = dp * b.qmi(d);
    if(dp.m[0][0] == 1){
    	cout << "Yes\n";
    }else cout << "No\n";
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
/*
区间范围 max 20
m * 20 4e5

dpi 表示 i是否可达
dpi -> dp(i+A, i+B)

*/