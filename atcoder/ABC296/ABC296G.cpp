#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
struct node{
	vector<int>f=vector<int>(3);
	bool operator <(const node &y)const{
		return f<y.f;
	}
};
int shuji(node p,node q,node r){
	int x=q.f[0]-p.f[0];
	int y=q.f[1]-p.f[1];
	int xx=r.f[0]-p.f[0];
	int yy=r.f[1]-p.f[1];
	return x*xx+y*yy;
}
int inji(node p,node q,node r){
	int x=q.f[0]-p.f[0];
	int y=q.f[1]-p.f[1];
	int xx=r.f[0]-p.f[0];
	int yy=r.f[1]-p.f[1];
	return x*yy-xx*y;
}
int check(node p,node q,node r){
	int c=inji(p,q,r);
	if(c)return c>0?2:0;
	int t1=shuji(p,q,r);
	int t2=shuji(p,q,q);
	return 0<=t1&&t1<=t2;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	vector<node>a(n);
	for(int i=0;i<n;i++)cin>>a[i].f[0]>>a[i].f[1],a[i].f[2]=~i;
	int q;cin>>q;
	vector<node>qq=a;
	vector<int>ans(q);
	for(int i=0;i<q;i++){
		int x,y;cin>>x>>y;
		node temp;
		temp.f[0]=x;
		temp.f[1]=y;
		temp.f[2]=i;
		qq.push_back(temp);
	}
	sort(qq.begin(),qq.end());
	int u=-1,s=-1;
	for(int i=0;i<n+q;i++){
		int t=qq[i].f[2];
		if(t<0){
			t=~t;
			if(u==-1){
				u=t;
				s=t;
			}else{
				if((u-1+n)%n==t)u=t;
				if((s+1)%n==t)s=t;
			}
		}else{
			if(u==-1){
				ans[t]=3;
			}else{
				int t1=check(a[(u-1+n)%n],a[u],qq[i]);
				int t2=check(a[s],a[(s+1)%n],qq[i]);
				if(t1==1||t2==1){
					ans[t]=1;
				}else if(t1&&t2)ans[t]=2;
				else ans[t]=3;
			}
		}
	}
	for(int i=0;i<q;i++){
		if(ans[i]==1)cout<<"ON\n";
		else if(ans[i]==2)cout<<"IN\n";
		else cout<<"OUT\n";
	}
	return 0;
}
