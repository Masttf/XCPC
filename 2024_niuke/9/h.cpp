#include <bits/stdc++.h>
using namespace std;
void solve();
#define int long long
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)
 
void err() {
    cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
class Point {
   public:
    int x, y;
    Point() {}
    Point(int xx, int yy) : x(xx), y(yy) {}
    friend bool operator<(const Point& a, const Point& b) {
        return a.x != b.x ? a.x < b.x : a.y < b.y;
    }
    friend Point operator+(const Point& a, const Point& b) {
        return Point(a.x + b.x, a.y + b.y);
    }
    friend Point operator-(const Point& a, const Point& b) {
        return Point(a.x - b.x, a.y - b.y);
    }
    friend Point operator*(const Point& a, double k) {
        return Point(a.x * k, a.y * k);
    }
    // friend double operator* (const Point &a, const Point &b) { return Dot(a,
    // b); }
    friend Point operator/(const Point& a, double b) {
        return Point(a.x / b, a.y / b);
    }
    // friend double operator^ (const Point &a, const Point &b) { return
    // Cross(a, b); }
    bool operator==(const Point& other) const {
        return x == other.x and y == other.y;
    }
    bool operator!=(const Point& other) const { return !operator==(other); }
    static int dis(Point a, Point b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
};
constexpr int maxn = 1e6 + 5;
int n, m;
struct node{
    int x,y;
}p[maxn],ch[maxn];


int dis(node a,node b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int cross(node p0,node p1,node p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int cmp(node a,node b){//排序，对于x，y坐标
    return (a.x!=b.x) ? (a.x<b.x):(a.y<b.y);
}

void andrew(){//先右到左遍历找凸包，在左到右找
    sort(p,p+n,cmp);
    for(int i=0;i<n;++i){
        while(m>1&&cross(ch[m-2],ch[m-1],p[i])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;--i){
        while(m>k&&cross(ch[m-2],ch[m-1],p[i])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
}

int rotating_calipers(){//旋转卡壳同上
    int j=1,ans=0;
    for(int i=0;i<m;++i){
        while(cross(ch[i],ch[i+1],ch[j])<cross(ch[i],ch[i+1],ch[j+1])) j=(j+1)%m;
        ans=max(ans,max(dis(ch[i],ch[j]),dis(ch[i+1],ch[j])));
    }
    return ans;
}
constexpr double Pi = 3.141592653589793238462643383279502884L;
void solve() {
    int N, M;
    std::cin >> N;
    std::vector<Point> a(N);
    for (int i = 0; i < N; ++i) std::cin >> a[i].x >> a[i].y;
    std::cin >> M;
    std::vector<Point> b(M);
    n = M;
    m = 0;
    for (int i = 0; i < M; ++i){
        std::cin >> b[i].x >> b[i].y;
        p[i] = {b[i].x, b[i].y}; 
    }
    //andrew();
    double mx = sqrt(rotating_calipers());
    double ans = 0;
    a.push_back(a.front());
    for (int i = 1; i <= N; ++i) ans += std::sqrt(Point::dis(a[i], a[i - 1]));
    ans += Pi * 2 * mx;
    std::cout << std::fixed << std::setprecision(10) << ans << '\n';
}