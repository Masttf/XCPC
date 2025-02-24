#include <bits/stdc++.h>

#define Max 100005
#define ll long long

using namespace std;

const int mod=1e9+7;

int T,n,m,len,a[Max],id[Max];
int L[500],R[500],num[500][1000],lazy[500];
int ans,cnt,inv;

inline int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ans;
}

inline void down(int p){
	for(int i=L[p];i<=R[p];i++){
		if(i==num[p][a[i]+500])num[p][a[i]+500]=-1;
		a[i]=a[i]+lazy[p];
	}
	lazy[p]=0;
}

inline void up(int p){
	for(int i=L[p];i<=R[p];i++){
		if(a[i]>=-len&&a[i]<=len&&num[p][a[i]+500]==-1)num[p][a[i]+500]=i;
	}
}

inline void change(int l,int r,int k){
	if(l>r)return;
	if(id[l]==id[r]){
		int p=id[l];
		down(p);
		for(int i=l;i<=r;i++)a[i]+=k;
		up(p);
		return;
	}
	int p=id[l];
	down(p);
	for(int i=l;i<=R[p];i++)a[i]+=k;
	up(p);
	
	for(int i=id[l]+1;i<id[r];i++){
		lazy[i]+=k;
	}
	
	p=id[r];
	down(p);
	for(int i=L[p];i<=r;i++)a[i]+=k;
	up(p);
	return;
}

inline int query(int l,int r,int k){
	if(l>r)return -1;
	if(id[l]==id[r]){
		for(int i=l;i<=r;i++){
			if(a[i]+lazy[id[i]]==k)return i;
		}
		return -1;
	}
	int p=id[l];
	for(int i=l;i<=R[p];i++){
		if(a[i]+lazy[id[i]]==k)return i;
	}
	
	for(int i=id[l]+1;i<id[r];i++){
		if(lazy[i]<=-len||lazy[i]>=len){
			down(i);
			up(i);
		}
		if(num[i][k-lazy[i]+500]!=-1)return num[i][k-lazy[i]+500];
	}
	
	p=id[r];
	for(int i=L[p];i<=r;i++){
		if(a[i]+lazy[id[i]]==k)return i;
	}
	return -1;
}

int main(){
	freopen("1.in","r",stdin);
	freopen("3.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	len=300;
	inv=qpow(2,mod-2);
	while(T--){
		cin>>n>>m;
		ans=cnt=0;
		for(int i=1;i<=n;i++){
			a[i]=0;
			id[i]=(i-1)/len+1;
			if(!L[id[i]])L[id[i]]=i;
			R[id[i]]=i;
		}
		for(int i=1;i<=id[n];i++){
			lazy[i]=0;
			for(int j=-len;j<=len;j++){
				num[i][j+500]=-1;
			}
			num[i][500]=L[i];
		}
		for(int i=1;i<=m;i++){
			int l,r;
			cin>>l>>r;
			l++;
			int p=query(l,n,0),q=query(l,n,-1);
//			cout<<p<<"!"<<q<<endl;
			bool flag=1;
			if(p==q&&p==-1){
				change(l,r,1);
				flag=0;
			}else if(p!=-1&&(q==-1||p<q)){
				ans=(ans+n-p)%mod;
				cnt++;
				change(l,p,1);
			}else{
				ans=(ans+n-q+1)%mod;
				cnt--;
				change(l,q,1);
			}
//			cout<<ans<<" "<<cnt<<" "<<flag<<endl;
			if(flag){
				p=query(r+1,n,1);q=query(r+1,n,0);
				if(p==q&&p==-1){
					change(r+1,n,-1);
				}else if(p!=-1&&(q==-1||p<q)){
					ans=(ans-(n-p)+mod)%mod;
					cnt--;
					change(r+1,p,-1);
				}else{
					ans=(ans-(n-q+1)+mod)%mod;
					cnt++;
					change(r+1,q,-1);
				}
			}
//			cout<<ans<<" "<<cnt<<endl;
			cout<<(ans+1ll*cnt*inv%mod)%mod<<'\n';
		}
	}
	return 0;
}
