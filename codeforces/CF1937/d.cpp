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
const int Max=1e18;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1];
		if(s[i]=='>')pre[i]++;
	}
	vector<int>p1(n+1),p2(n+1);
	for(int i=1;i<=n;i++){
		p1[i]=p1[i-1];
		p2[i]=p2[i-1];
		if(s[i]=='>'){
			p1[i]=i;
		}else if(s[i]=='<')p2[i]=i;
	}
	vector<int>s1(n+5),s2(n+5);
	for(int i=n;i>=1;i--){
		s1[i]=s1[i+1];
		s2[i]=s2[i+1];
		if(s[i]=='>'){
			s1[i]=i;
		}else if(s[i]=='<')s2[i]=i;
	}
	vector<int>psum1(n+1),psum2(n+1);
	for(int i=1;i<=n;i++){
		int d1=pre[i-1];
		int d2=i-1-d1;
		psum1[i]=psum1[i-1]+d1*2;
		psum2[i]=psum2[i-1]+d2*2;
	}
	vector<int>ssum1(n+5),ssum2(n+5);
	for(int i=n;i>=1;i--){
		int d1=pre[n]-pre[i];
		int d2=n-i-d1;
		ssum1[i]=ssum1[i+1]+d1*2;
		ssum2[i]=ssum2[i+1]+d2*2;
	}
	vector<int>ans(n+1);
	// for(int i=1;i<=n;i++){
	// 	dbg(i,p1[i],p2[i],s1[i],s2[i]);
	// 	dbg(psum1[i],psum2[i]);
	// 	dbg(ssum1[i],ssum2[i]);
	// }
	for(int i=1;i<=n;i++){
		if(s[i]=='<'){
			int d1=pre[i];
			int d2=n-i+1-pre[n]+pre[i-1];
			if(d1>=d2){//出口在右
				int l=1,r=i;
				int res=-1;
				while(l<=r){
					int mid=(l+r)>>1;
					int k=pre[i]-pre[mid-1];
					if(k>=d2)res=mid,l=mid+1;
					else r=mid-1;
				}
				ans[i]=ssum2[i]+n-i+1+psum1[i]-psum1[res-1]-(pre[res-1]*2*(i-res+1));
			}else{
				int l=i,r=n;
				int res=-1;
				while(l<=r){
					int mid=(l+r)>>1;
					int k=mid-i+1-pre[mid]+pre[i-1];
					if(k>=d1+1)res=mid,r=mid-1;
					else l=mid+1;
				}
				int dd=n-res-pre[n]+pre[res];
				ans[i]=psum1[i]+i+ssum2[i]-ssum2[res+1]-(dd*2*(res-i+1));
			}
		}else{
			int d1=pre[i];
			int d2=n-i+1-pre[n]+pre[i-1];
			if(d2>=d1){//出口在左
				int l=i,r=n;
				int res=-1;
				while(l<=r){
					int mid=(l+r)>>1;
					int k=mid-i+1-pre[mid]+pre[i-1];
					if(k>=d1)res=mid,r=mid-1;
					else l=mid+1;
				}
				int dd=n-res-pre[n]+pre[res];
				ans[i]=psum1[i]+i+ssum2[i]-ssum2[res+1]-(dd*2*(res-i+1));
			}else{
				int l=1,r=i;
				int res=-1;
				while(l<=r){
					int mid=(l+r)>>1;
					int k=pre[i]-pre[mid-1];
					if(k>=d2+1)res=mid,l=mid+1;
					else r=mid-1;
				}
				ans[i]=ssum2[i]+n-i+1+psum1[i]-psum1[res-1]-(pre[res-1]*2*(i-res+1));
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}