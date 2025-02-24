#include<bits/stdc++.h>
#define int long long
using namespace std;
int res[10000];
bool pd(int x){
	if((x%4==0 && x%100!=0 )||x%400==0)return true;
	return false;
}
int mon(int year,int a){
	int flag=pd(year);
	switch(a){
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:{
			return 31;
			break;
		}
		case 4:case 6:case 9:case 11:{
			return 30;
			break;
		}
		case 2:return 28+flag;
	}
}
int qiu(int y1,int m1,int d1,int y2,int m2,int d2){
	int ans=0;
	string a="";
	int temp=y1;
	vector<int>v;
	while(temp){
		v.push_back(temp%10);
		temp/=10;
	}
	for(int i=3;i>=0;i--)a+=v[i]+'0';
	if((a[0]=='2'&&a[1]=='0'&&a[2]=='2')||(a[1]=='2'&&a[2]=='0'&&a[3]=='2')){
		if(m1!=m2){
			ans+=d2;
			ans+=mon(y1,m1)-d1+1;
		}else{
			ans+=d2-d1+1;
		}
		for(int i=m1+1;i<m2;i++){
			ans+=mon(y1,i);
		}
	}else if(a[3]=='2'){
		if(m1<2&&m2>2){
			ans+=mon(y1,2);
		}else if(m1==2&&m2==2){
			ans+=d2-d1+1;
		}else if(m1==2){
			ans+=mon(y1,2)-d1+1;
		}else if(m2==2) ans+=d2;
		if(m1<12&&m2==12&&d2>=2)++ans;
		else if(m1==12&&m2==12&&d1<=2&&d2>=2)++ans;
	}else{
		if(m1<2&&m2>2)++ans;//二月 
		else if(m1<2&&m2==2&&d2>=2)++ans;
		else if(m1==2&&d1<=2&&m2>2)++ans;
		else if(m1==2&&d1<=2&&m2==2&&d2>=2)++ans;
		if(m1<12&&m2==12&&d2>=2)++ans;//十二 
		else if(m1==12&&m2==12&&d1<=2&&d2>=2)++ans;
	}
	//cout<<y1<<' '<<ans<<'\n';
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	int y1,d1,m1,y2,d2,m2;
	for(int i=2000;i<=9999;i++){
		res[i]+=res[i-1];
		string a="";
		int temp=i;
		vector<int>v;
		while(temp){
			v.push_back(temp%10);
			temp/=10;
		}
		for(int j=3;j>=0;j--)a+=v[j]+'0';
		if((a[0]=='2'&&a[1]=='0'&&a[2]=='2')||(a[1]=='2'&&a[2]=='0'&&a[3]=='2'))res[i]+=365+pd(i);
		else if(a[3]=='2')res[i]+=29+pd(i);
		else res[i]+=2;
	}
	while(t--){
		int ans=0;
		cin>>y1>>m1>>d1>>y2>>m2>>d2;
		if(y1==y2){
			ans=qiu(y1,m1,d1,y2,m2,d2);
		}else{
			ans+=qiu(y1,m1,d1,y1,12,31);
			ans+=qiu(y2,1,1,y2,m2,d2);
			ans+=res[y2-1]-res[y1];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
