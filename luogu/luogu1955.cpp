#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
struct node{
	int x,y,e;
	bool operator <(const node &y)const{
		return e>y.e;
	}
}res[maxn];
int f[2*maxn],b[3*maxn];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void unit(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb)return ;
	f[fa]=fb;
	return ;
}
void solve(){
	int cnt=1;
	int n;cin>>n;
	for(int i=1;i<=2*n;i++)f[i]=i;
	for(int i=1;i<=n;i++){
		cin>>res[i].x>>res[i].y>>res[i].e;
		b[cnt++]=res[i].x;
		b[cnt++]=res[i].y;
	}
	sort(b+1,b+cnt);
	int le=unique(b+1,b+cnt)-b;//去重最后一个元素的下一个元素下标
	for(int i=1;i<=n;i++){
		res[i].x=lower_bound(b+1,b+le,res[i].x)-b;
		res[i].y=lower_bound(b+1,b+le,res[i].y)-b;
	}
	sort(res+1,res+1+n);
	int flag=1;
	for(int i=1;i<=n;i++){
		if(res[i].e==1){
			unit(res[i].x,res[i].y);
		}else{
			if(find(res[i].x)==find(res[i].y)){
				flag=0;
				break;
			}
		}
	}
	if(flag)cout<<"YES"<<'\n';
	else cout<<"NO"<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
