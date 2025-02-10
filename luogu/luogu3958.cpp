#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	double x,y,z;
}res[1005];
double js(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
int f[1005],xia[1005],shang[1005],c1,c2;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void unit(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb)return ;
	f[fa]=fb;
	return ;
}
void solve(){
	c1=1,c2=2;
	int n,h;
	double r;
	cin>>n>>h>>r;
	for(int i=1;i<=n;i++)cin>>res[i].x>>res[i].y>>res[i].z,f[i]=i,res[i].id=i;;
	for(int i=1;i<=n;i++){
		if(res[i].z-r<=0)xia[c1++]=res[i].id;
		if(res[i].z+r>=h)shang[c2++]=res[i].id;
		for(int j=1;j<=n;j++){
			if(js(res[i],res[j])<=2*r){
				unit(res[i].id,res[j].id);
			}
		}
	}
	for(int i=1;i<=n;i++)find(i);
	int flag=0;
	for(int i=1;i<c1;i++){
		for(int j=1;j<c2;j++){
			if(f[xia[i]]==f[shang[j]])flag=1;
		}
	}
	if(flag)cout<<"Yes"<<'\n';
	else cout<<"No"<<'\n';
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
