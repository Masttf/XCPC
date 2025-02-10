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
                    res.m[i][j] += m[i][k] * y.m[k][j];
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
using matrix = Matrix<5, int>;
void solve(){
    matrix a({{1, 5, 0, 0, 0}, {0, 13, 0, 0, 0}, {2, 6, 9, 0 ,0}, {3, 7, 0, 11, 0}, {4, 8, 10, 12, 13}});
    matrix b({{1, 5, 0, 0, 0}, {0, 13, 0, 0, 0}, {2, 6, 9, 0 ,0}, {3, 7, 0, 11, 0}, {4, 8, 10, 12, 13}});
    for(int i = 0; i < 5; i++){
    	for(int j = 0; j < 5; j++){
    		if(a.m[i][j] == 0)continue;
    		dbg(a.m[i][j] - 1);
    		for(int k = 0; k < 5; k++){
    			int d = a.m[i][k] * b.m[k][j];
    			if(d != 0){
    				cout << a.m[i][k] - 1 << ' ' << b.m[k][j] - 1<< endl;
    				//dbg(a.m[i][k] - 1, b.m[k][j] -1);
    			}
    			
    		}
    	}
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}