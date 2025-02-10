#include<bits/stdc++.h>
#define int long long
using namespace std;
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
constexpr int Max=1e18;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>x(n+1),val(n+1);
	vector<int>pos;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>val[i];
		pos.push_back(x[i]);
		pos.push_back(x[i]+1);
		pos.push_back(x[i]+val[i]);
		pos.push_back(x[i]-val[i]);
	}
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	auto get = [&](int x)->int{
		return lower_bound(pos.begin(),pos.end(),x)-pos.begin()+1;
	};
	int N=pos.size();
	vector<int>b(N+5);
	vector<int>c(N+5);
	for(int i=1;i<=n;i++){
		int l=get(x[i]-val[i]);
		int r=get(x[i]+val[i]);
		b[l]+=val[i]-x[i];
		b[get(x[i])+1]-=val[i]-x[i];
		c[l]++;
		c[get(x[i])+1]--;
		b[get(x[i]+1)]+=val[i]+x[i];
		b[r+1]-=val[i]+x[i];
		c[get(x[i]+1)]--;
		c[r+1]++;
	}
	vector<int>h(N+5);
	for(int i=1;i<=N;i++){
		b[i]+=b[i-1];
		c[i]+=c[i-1];
		h[i]=b[i]+c[i]*pos[i-1];
		//dbg(pos[i-1], h[i]);
	}
	vector hMax(3,vector<int>(N*4));
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l == r){
			hMax[0][p] = h[l];
			hMax[1][p] = h[l] + pos[l - 1];
			hMax[2][p] = h[l] - pos[l - 1];
			return ;
		}
		int mid = (l + r)>>1;
		self(self, l, mid, p<<1);
		self(self, mid+1, r, p<<1|1);
		hMax[0][p] = max(hMax[0][p<<1], hMax[0][p<<1|1]);
		hMax[1][p] = max(hMax[1][p<<1], hMax[1][p<<1|1]);
		hMax[2][p] = max(hMax[2][p<<1], hMax[2][p<<1|1]);
	};
	auto get_Max = [&](auto self,int l,int r,int x,int y,int ty,int p)->int{
		if(x<=l&&r<=y)return hMax[ty][p];
		int mid = (l + r)>>1;
		int res = -Max;
		if(x <= mid)res = max(res, self(self, l, mid, x, y, ty, p<<1));
		if(y > mid)res = max(res, self(self, mid + 1, r, x, y, ty, p<<1|1));
		return res;
	};
	bulid(bulid, 1, N, 1);
	for(int i=1;i<=n;i++){
		int l = get(x[i]-val[i]);
		int r = get(x[i]+val[i]);
		int mx = 0;
		if(l - 1 > 1)
			mx = max(mx, get_Max(get_Max, 1, N, 1, l-1, 0, 1));
		if(r + 1 < N)
			mx = max(mx, get_Max(get_Max, 1, N, r+1, N, 0, 1));
		//dbg(mx);
		mx = max(mx, get_Max(get_Max, 1, N, l, get(x[i]), 2, 1) - (val[i] - x[i]));
		//dbg(mx);
		mx = max(mx, get_Max(get_Max, 1, N, get(x[i] + 1), r, 1, 1) - (val[i] + x[i]));

		if(mx <= m)cout<<1;
		else cout<<0;
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}