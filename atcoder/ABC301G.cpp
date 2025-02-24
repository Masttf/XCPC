#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=55;
int x[maxn],y[maxn],z[maxn];
vector<vector<int>>res;
int val[maxn*maxn];
bool js(vector<int>xx,vector<int>yy){
	int res=0;
	for(int i=0;i<3;i++){
		res+=xx[i]*yy[i];
	}
	return res==0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i]>>z[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(x[i]<x[j]){
				vector<int>tem;
				int x1=x[j]-x[i];
				int dd=x1;
				int y1=y[j]-y[i];
				dd=__gcd(abs(y1),dd);
				int z1=z[j]-z[i];
				dd=__gcd(abs(z1),dd);
				tem.push_back(x1/dd);
				tem.push_back(y1/dd);
				tem.push_back(z1/dd);
				tem.push_back(x[i]);
				tem.push_back(y[i]);
				tem.push_back(z[i]);
				int flag=1;
				for(int k=0;k<(int)res.size();k++){
					int ok=1;
					for(int d=0;d<3;d++){
						if(res[k][d]!=tem[d])ok=0;
					}
					if(ok){
						int k1=0,k2=0,k3=0;
						if((res[k][3]-tem[3])%tem[0]==0)k1=(res[k][3]-tem[3])/tem[0];
						else ok=0;
						if(tem[1]==0){
							if(res[k][4]==tem[4])k2=k1;
							else ok=0;
						}else{
							if((res[k][4]-tem[4])%tem[1]==0)k2=(res[k][4]-tem[4])/tem[1];
							else ok=0;
						}
						if(tem[2]==0){
							if(res[k][5]==tem[5])k3=k1;
							else ok=0;
						}else{
							if((res[k][5]-tem[5])%tem[2]==0)k3=(res[k][5]-tem[5])/tem[2];
							else ok=0;
						}
						if(ok&&k1==k2&&k2==k3)flag=0;
					}
				}
				if(flag)res.push_back(tem);
			}
		}
	}
	int len=res.size();
	for(int i=0;i<len;i++){
		int cnt=-1;
		for(int j=1;j<=n;j++){
			int k1=0,k2=0,k3=0,ok=1;
			if((x[j]-res[i][3])%res[i][0]==0){
				k1=(x[j]-res[i][3])/res[i][0];
			}else ok=0;
			if(res[i][1]==0){
				if(y[j]==res[i][4])k2=k1;
				else ok=0;
			}else{
				if((y[j]-res[i][4])%res[i][1]==0){
					k2=(y[j]-res[i][4])/res[i][1];
				}else ok=0;
			}
			if(res[i][2]==0){
				if(z[j]==res[i][5])k3=k1;
				else ok=0;
			}else{
				if((z[j]-res[i][5])%res[i][2]==0){
					k3=(z[j]-res[i][5])/res[i][2];
				}else ok=0;
			}
			if(ok&&k1==k2&&k2==k3)cnt++;
		}
		val[i]=cnt;
	}
	int ans=0;
	for(int i=0;i<len;i++)ans=max(ans,val[i]);
	map<vector<double>,set<int>>m;
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(i==j)continue;
			int flag=1;
			for(int k=3;k<=5;k++){
				if(res[i][k]!=res[j][k])flag=0;
			}
			if(flag)continue;
			vector<int>tem;
			tem.push_back(res[i][1]*res[j][2]-res[i][2]*res[j][1]);
			tem.push_back(res[i][2]*res[j][0]-res[i][0]*res[j][2]);
			tem.push_back(res[i][0]*res[j][1]-res[i][1]*res[j][0]);
			if(tem[0]==0&&tem[0]==tem[1]&&tem[1]==tem[2])continue;
			vector<int>tem2;
			tem2.push_back(res[i][3]-res[j][3]);
			tem2.push_back(res[i][4]-res[j][4]);
			tem2.push_back(res[i][5]-res[j][5]);
			if(js(tem,tem2)){
				int d1=(res[i][5]-res[j][5])*res[j][1]-res[j][2]*(res[i][4]-res[j][4]);
				int d2=res[i][1]*res[j][2]-res[i][2]*res[j][1];
				if(!d1||!d2){
					d1=(res[i][3]-res[j][3])*res[j][1]-res[j][0]*(res[i][4]-res[j][4]);
					d2=(res[i][1]*res[j][0]-res[i][0]*res[j][1]);
					if(!d1||!d2){
						d1=(res[i][3]-res[j][3])*res[j][2]-res[j][0]*(res[i][5]-res[j][5]);
						d2=(res[i][2]*res[j][0]-res[i][0]*res[j][2]);
					}
				}
				double t=res[i][3]+res[i][0]*1.0*d1/d2;
				if(t<0){
					double t2=res[i][4]+res[i][1]*1.0*d1/d2;
					double t3=res[i][5]+res[i][2]*1.0*d1/d2;
					vector<double>l;
					l.push_back(t);
					l.push_back(t2);
					l.push_back(t3);
					m[l].insert(i);
					m[l].insert(j);
				}
			}
		}
	}
	for(auto it=m.begin();it!=m.end();it++){
		int a=0;
		for(auto x=it->second.begin();x!=it->second.end();x++){
			a+=val[*x];
		}
		ans=max(ans,a);
	}
	cout<<n-ans;
	return 0;
}
