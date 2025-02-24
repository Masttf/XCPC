#include<bits/stdc++.h>
using namespace std;
int chang[10],cnt1=1,cnt2=1;
pair<int,int>huang[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		double h,d,vx,vy,t;cin>>h>>d>>vx>>vy>>t;
		int go=h;
		int n;cin>>n;
		for(int i=1;i<=n;i++)cin>>chang[i];
		sort(chang+1,chang+1+n);
		int m;cin>>m;
		for(int i=1;i<=m;i++)cin>>huang[i].first>>huang[i].second;
		sort(huang+1,huang+1+m);
		int flag=1;
		for(int i=0;i<d;i++){
			if(h<0){
				flag=0;break;
			}
			if(i==chang[cnt1]&&cnt1<=n){
				h=go;
				cnt1++;
			}
			if(i==huang[cnt2].first&&cnt2<=m){
				if(h>=huang[cnt2].second){
					if((h-vy*2*t)<huang[cnt2].second-vy*t){
						h=huang[cnt2].second-vy*t;
						i=i+vx*2*t;
					}
				}
				cnt2++;
			}
			h-=vy/vx;
		}
		if(flag)cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
	return 0;
}
