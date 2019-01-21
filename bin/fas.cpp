#include<bits/stdc++.h>
#include<map>
#include<vector>
#define mp make_pair
using namespace std;
const int mod=1000000007; 
int n,m;
pair<int,int> p[100005]; 
vector<int> v;
map<int,int> ma;
int dp[200005];
map<int,vector<int> > miv;
inline bool cmp(pair<int,int>a,pair<int,int>b){
	if(a.second!=b.second) return a.second<b.second;
	return a.first<b.first;
}
int rr[444444];
inline void add(int pos,int val){
	pos+=222222;
	while(pos){
		rr[pos]+=val;
		if(rr[pos]>=mod) rr[pos]-=mod;
		pos>>=1;
	}
}
inline int sum(int a1,int a2){
	a1+=222222;
	a2+=222222;
	int res(0);
	while(a1<=a2){
		if(a1&1){
			res+=rr[a1];
			if(res>=mod) res-=mod;
		}
		if(!(a2&1)){
			res+=rr[a2];
			if(res>=mod) res-=mod;
		}
		a1=(a1+1)>>1;
		a2=(a2-1)>>1;
	}
	return res;
}
int main(){
	int i,j;
	cin>>m>>n;
	for(i=0;i<n;++i) cin>>p[i].first>>p[i].second,v.push_back(p[i].first),v.push_back(p[i].second);
	v.push_back(m);
	v.push_back(0);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(i=0;i<v.size();++i) ma[v[i]]=i;
	for(i=0;i<n;++i) p[i].first=ma[p[i].first],p[i].second=ma[p[i].second];
	sort(p,p+n,cmp);
	add(0,1);
	for(i=0;i<n;++i) add(p[i].second,sum(p[i].first,p[i].second-1));
	cout<<sum(v.size()-1,v.size()-1)<<endl; 
	return 0;
}
