//首先多源最短路径floyd
//然后考虑牧场与牧区使用并查集
//然后考虑把两个牧场相连，这个新牧场的直径可能是A的直径，B的直径，i在A牧场中的最长的路径+ij+j在B牧场中的最长路径
#include<bits/stdc++.h>
using namespace std;
const int inf=999999999;
struct node{
	double x,y;
}res[155];
string t[155];
int f[155],n;
double d[155][155],ml[155],ff[155];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void unit(int a,int b){
	int f1=find(a),f2=find(b);
	if(f1==f2)return ;
	f[f1]=f2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>res[i].x>>res[i].y,f[i]=i;
	for(int i=1;i<=n;i++)cin>>t[i];
	for(int i=1;i<=n;i++){//建图
		for(int j=0;j<n;j++){
			if(t[i][j]=='1'){
				double l=sqrt((res[i].x-res[j+1].x)*(res[i].x-res[j+1].x)+(res[i].y-res[j+1].y)*(res[i].y-res[j+1].y));
				unit(i,j+1);
				d[i][j+1]=l;
			}else{
				if(i==j+1)d[i][j+1]=0;
				else d[i][j+1]=inf;
			}
		}
	}
	for(int k=1;k<=n;k++){//floyd
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][k]+d[k][j]<d[i][j])d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
	for(int i=1;i<=n;i++)find(i);
	for(int i=1;i<=n;i++){//找出该牧场的直径以及这个点在这个牧场中的最长路径
		for(int j=1;j<=n;j++){
			if(f[i]==f[j]){//属于同一个牧场
				ml[i]=max(ml[i],d[i][j]);
				ff[f[i]]=max(ff[f[i]],ml[i]);//算出牧场直径
			}
		}
	}
	double ans=inf;
	for(int i=1;i<=n;i++){//枚举
		for(int j=1;j<=n;j++){
			if(f[i]!=f[j]){//如果不是一个牧场
				ans=min(ans,max(max(ml[i]+ml[j]+sqrt((res[i].x-res[j].x)*(res[i].x-res[j].x)+(res[i].y-res[j].y)*(res[i].y-res[j].y)),ff[f[i]]),ff[f[j]]));
			}
		}
	}
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
}
