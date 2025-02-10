#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
struct node{
	int l,r,val;
}aa[maxn],bb[maxn];
vector<pair<int,int>>a[2*maxn],b[2*maxn];
int c[2*maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int l,n1,n2;cin>>l>>n1>>n2;
	int p=1;
	int k=0;
	for(int i=1;i<=n1;i++){
		int x,y;cin>>x>>y;
		aa[i].val=x;
		aa[i].l=p;
		aa[i].r=p+y-1;
		c[++k]=x;
		p+=y;
	}
	p=1;
	for(int i=1;i<=n2;i++){
		int x,y;cin>>x>>y;
		bb[i].val=x;
		bb[i].l=p;
		bb[i].r=p+y-1;
		c[++k]=x;
		p+=y;
	}
	sort(c+1,c+1+k);
	int len=unique(c+1,c+1+k)-c;
	int mx=0;
	for(int i=1;i<=n1;i++){
		int t=lower_bound(c+1,c+len,aa[i].val)-c;
		mx=max(t,mx);
		a[t].push_back({aa[i].l,aa[i].r});
	}
	for(int i=1;i<=n2;i++){
		int t=lower_bound(c+1,c+len,bb[i].val)-c;
		mx=max(mx,t);
		b[t].push_back({bb[i].l,bb[i].r});
	}
	int ans=0;
	for(int i=1;i<=mx;i++){
		int sz1=a[i].size();
		int sz2=b[i].size();
		int s1=0,s2=0;
		while(s1<sz1&&s2<sz2){
			int l1=a[i][s1].first;
			int r1=a[i][s1].second;
			int l2=b[i][s2].first;
			int r2=b[i][s2].second;
			if(r1>=r2){
				ans+=max(0LL,min(r2,r1)-max(l1,l2)+1);
				s2++;
			}else{
				ans+=max(0LL,min(r2,r1)-max(l1,l2)+1);
				s1++;
			}
		}
	}
	cout<<ans;
	return 0;
}
