#include<bits/stdc++.h>
#define int long long
using namespace std;
int sum=0;
multiset<int,greater<int> >m1;
multiset<int,greater<int> >m3;
multiset<int>m4;
multiset<pair<int,int>>q;
int res=0;
int len=0;
void add(){
	if(m1.empty()&&m3.size()==1)return ;
	if(m1.empty()){
		int tem=*m3.begin();
		m3.erase(tem);
		m4.insert(tem);
		res+=tem;
		q.insert({tem,0});
	}else if(m3.size()==1){
		int tem=*m1.begin();
		m1.erase(tem);
		res+=tem;
		q.insert({tem,1});
	}else{
		int tem1=*m1.begin();
		int tem2=*m3.begin();
		if(tem1>=tem2){
			res+=tem1;
			q.insert({tem1,1});
			m1.erase(tem1);
		}else{
			res+=tem2;
			q.insert({tem2,0});
			m3.erase(tem2);
			m4.insert(tem2);
		}
	}
}
void del(){
	pair<int,int>root=*q.begin();
	res-=root.first;
	q.erase(root);
	if(root.second==0){
		m4.erase(root.first);
		m3.insert(root.first);
	}else{
		m1.insert(root.first);
	}
	return ;
}
void updata(){
	if(q.empty())return ;
	if(m1.empty()&&m3.size()==1)return ;
	pair<int,int>root=*q.begin();
	if(m1.empty()){
		int tem=*m3.begin();
		if(root.first>=tem)return ;
		else{
			del();
			res+=tem;
			q.insert({tem,0});
			m3.erase(tem);
			m4.insert(tem);
		}
	}else if(m3.size()==1){
		int tem=*m1.begin();
		if(root.first>=tem)return ;
		else{
			del();
			res+=tem;
			q.insert({tem,1});
			m1.erase(tem);
		}
	}else{
		int tem1=*m1.begin();
		int tem2=*m3.begin();
		int mx=max(tem1,tem2);
		if(root.first>=mx)return ;
		if(mx==tem1){
			del();
			res+=tem1;
			q.insert({tem1,1});
			m1.erase(tem1);
		}else{
			del();
			res+=tem2;
			q.insert({tem2,0});
			m3.erase(tem2);
			m4.insert(tem2);
		}
	}
}
void solve(){
	int n;cin>>n;
	for(int k=1;k<=n;k++){
		int tp,d;cin>>tp>>d;
//		if(k==40)cout<<tp<<d<<'\n';
		sum+=d;
		if(d>0){
			if(tp==0)m1.insert(d);
			else m3.insert(d),len++;
		}else{
			d=-d;
			if(tp==0){
				if(m1.count(d)){
					m1.erase(d);
				}else{
					res-=d;
					q.erase({d,1});
				}
			}else{
				len--;
				if(m3.count(d)){
					m3.erase(d);
					if(m3.empty()&&!m4.empty()){
						int tem=*m4.begin();
						res-=tem;
						q.erase({tem,0});
						m3.insert(tem);
						m4.erase(tem);
					}
					if(q.size()>len)del();
				}else{
					res-=d;
					m4.erase(d);
					q.erase({d,0});
				}
			}
		}
		if(q.size()<len)add();
		else if(q.size()==len)updata();
		cout<<sum+res<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
/*
  41
  1 83723419
  1 -83723419
  1 43688531
  0 107306488
  0 -107306488
  1 741108574
  1 -741108574
  1 22459404
  1 -43688531
  1 -22459404
  0 348791796
  0 -348791796
  1 599443414
  1 -599443414
  0 124587329
  1 95720501
  0 -124587329
  1 514657693
  1 -514657693
  1 -95720501
  0 367146977
  0 -367146977
  0 913300866
  0 788937177
  0 -788937177
  1 807916218
  1 -807916218
  0 -913300866
  0 901311455
  0 -901311455
  0 180039378
  1 547750560
  0 -180039378
  1 -547750560
  1 981295007
  1 -981295007
  1 392151481
  1 -392151481
  1 701238294
  1 439832625
  1 -439832625
  
  83723419
  0
  43688531
  258301507
  43688531
  1525905679
  43688531
  109836466
  22459404
  0
  348791796
  0
  599443414
  0
  124587329
  344895159
  95720501
  1125035887
  95720501
  0
  367146977
  0
  913300866
  1702238043
  913300866
  2634517950
  913300866
  0
  901311455
  0
  180039378
  907829316
  547750560
  0
  981295007
  0
  392151481
  0
  701238294
  1842309213
  701238294
 */
