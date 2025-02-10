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
struct manacher{
	string res;
	vector<int>p;
	manacher(string s){
		res="^";
		for(auto x:s){
			res+='#';
			res+=x;
		}
		res+="#&";
		p.resize(res.size()+1);
	}
	pair<int,int> get(){
		int len=res.size();
		int c=0,r=0;
		int max_len=0;
		int start=-1;
		for(int i=1;i<len;i++){
			if(i<=r){
				p[i]=min(p[2*c-i],r-i);
			}
			while(res[i-p[i]-1]==res[i+p[i]+1])p[i]++;
			if(i+p[i]>r){
				c=i;
				r=i+p[i];
			}
			if(p[i]>max_len){
				max_len=p[i];
				start=(i-p[i])/2;
			}
			// (i-p[i])/2是回文起始点,字符串从0开始
		}
		return {start,max_len};
	}
	bool check(int l,int r){
		int len=(r-l+1);
		int center=(l+r)/2;
		center=center*2+2;
		if(len%2==0)center++;
		return p[center]>=len;
	}
};
void solve(){
	int n,m;cin>>n>>m;
	string s,t;cin>>s>>t;
	manacher res(s);
	res.get();
	int ans=0;
	vector<int>nt(m+1);
	nt[0]=-1;
	for(int i=1,j=-1;i<m;i++){
		while(j!=-1&&t[i]!=t[j+1])j=nt[j];
		if(t[i]==t[j+1])j++;
		nt[i]=j;
	}
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=i,k=-1;j<n;j++){
			while(k!=-1&&s[j]!=t[k+1])k=nt[k];
			if(s[j]==t[k+1])k++;
			if(k==m-1){
				cnt++;
				k=nt[k];
			}
			if((j-i+1)%2==1&&res.check(i,j)){
				//dbg(i,j,cnt);
				ans+=cnt;
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}