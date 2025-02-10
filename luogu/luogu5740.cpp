#include<bits/stdc++.h>
using namespace std;
struct student{
	string name;
	int chinese;
	int math;
	int english;
	int id;
	int count;
}s[1000000];
bool cmp(student x,student y){
	if(x.count!=y.count)return x.count>y.count;
	else return x.id<y.id;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].name>>s[i].chinese>>s[i].math>>s[i].english;
		s[i].id=i;
		s[i].count=s[i].chinese+s[i].math+s[i].english;		
	}
	sort(s+1,s+1+n,cmp);
	cout<<s[1].name<<' '<<s[1].chinese<<' '<<s[1].math<<' '<<s[1].english;
	return 0;
}
