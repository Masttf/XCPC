#include<bits/stdc++.h>
using namespace std;
struct student{
	string name;
	int final;
	int grade;
	string xue;
	string xi;
	int count;
	int sum;
	int id;
}res[105];
bool cmp(student x,student y){
	if(x.sum!=y.sum)return x.sum>y.sum;
	else return x.id<y.id;
}
int main(){
	int n;cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>res[i].name>>res[i].final>>res[i].grade>>res[i].xue>>res[i].xi>>res[i].count;
		res[i].id=i;
		int s=0;
		if(res[i].final>80&&res[i].count>=1)s+=8000;
		if(res[i].final>85&&res[i].grade>80)s+=4000;
		if(res[i].final>90)s+=2000;
		if(res[i].final>85&&res[i].xi=="Y")s+=1000;
		if(res[i].grade>80&&res[i].xue=="Y")s+=850;
		res[i].sum=s;
		cnt+=s;
	}
	sort(res+1,res+1+n,cmp);
	cout<<res[1].name<<'\n'<<res[1].sum<<'\n'<<cnt;
	return 0;
}
