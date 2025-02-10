#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int f[maxn*10];
vector<int>p;
struct node{
	int l,r,a,b;
	bool operator <(const node&y)const{
		return b<y.b;
	}
}res[maxn];
int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
int get(int x){
	return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
}
void solve(){
	int n;cin>>n;
	p.clear();
	for(int i=1;i<=n;i++){
		cin>>res[i].l>>res[i].r>>res[i].a>>res[i].b;
		p.push_back(res[i].l);
		p.push_back(res[i].r);
		p.push_back(res[i].a);
		p.push_back(res[i].b);
	}
	int q;cin>>q;
	vector<int>qu(1+q);
	for(int i=1;i<=q;i++){
		cin>>qu[i];
		p.push_back(qu[i]);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	sort(res+1,res+1+n);
	int len=p.size();
	for(int i=1;i<=len;i++)f[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=get(res[i].l);j<=get(res[i].b);j++){
			j=find(j);
			f[j]=get(res[i].b);
		}
	}
	for(int i=1;i<=q;i++){
		int po=get(qu[i]);
		cout<<p[find(po)-1]<<' ';
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
