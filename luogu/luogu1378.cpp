#include<bits/stdc++.h>
using namespace std;
int xa,ya,xb,yb,n;
struct node{
	int x,y;
}res[10];
bool vis[10];
vector<int>track;
vector<double>cr(10);
double ans,sum;
const double PI=3.1415926;
double js(int m){
	int x=track[m];
	double f1=min(res[x].x-xa,xb-res[x].x);
	double f2=min(res[x].y-ya,yb-res[x].y);
	double r=min(f1,f2);
	for(int i=0;i<m;i++){
		int t=track[i];
		double kk=sqrt((res[t].x-res[x].x)*(res[t].x-res[x].x)+(res[t].y-res[x].y)*(res[t].y-res[x].y));
		double dis=kk-cr[i];
		r=min(dis,r);
	}
	r=max(r,0.0);
	cr[m]=r;
	return PI*r*r;
}
void dfs(){
	if(track.size()==n){//拿到全排列
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			track.push_back(i);
			double temp=js(track.size()-1);
			sum+=temp;
			dfs();
			vis[i]=0;
			track.pop_back();
			sum-=temp;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;cin>>xa>>ya>>xb>>yb;
	for(int i=1;i<=n;i++){
		cin>>res[i].x>>res[i].y;
	}
	int l=ya+yb,l2=xa+xb;
	xa=min(xa,xb),xb=l2-xa;
	ya=min(ya,yb),yb=l-ya;
	dfs();
	double ares=(xb-xa)*(yb-ya);
	int final=ares-ans+0.5;
	cout<<final;
	return 0;
}
