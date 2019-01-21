#include<bits/stdc++.h>
#include<map>
#include<vector>
#define mp make_pair
using namespace std;
int n,m;
pair<int,int> p[100005]; 
vector<int> v;
map<int,int> ma;
int dp[200005];
map<int,vector<int> > miv;
priority_queue<int>pq;
int main(){
	int i,j;
	cin>>m>>n;
	for(i=0;i<n;++i) cin>>p[i].first>>p[i].second,v.push_back(p[i].first),v.push_back(p[i].second);
	sort(v.begin(),v.end());
	v.push_back(m);
	v.erase(unique(v.begin(),v.end()),v.end());
	for(i=0;i<v.size();++i) ma[v[i]]=i+1;
	for(i=0;i<n;++i) miv[ma[p[i].first]].push_back(ma[p[i].second]);
	cout<<"OK\n";
	for(i=1;i<=v.size();++i){
		vector<int> tv=miv[i];
		sort(tv.begin(),tv.end());
		tv.erase(unique(tv.begin(),tv.end()),tv.end());
		for(j=0;j<tv.size();++j) cout<<tv[j]<<" ";
		cout<<endl;
		miv[i]=tv;
	}
	cout<<"OK\n";
	dp[1]=1;
	int sum=0; 
	cout<<v.size()<<endl;
	for(i=1;i<=v.size();++i){
		sum+=dp[i];
		sum+=dp[i];
		for(j=0;j<miv[i].size();++j) dp[miv[i][j]]+=sum;
		while(pq.size() and (-pq.top())<i){
			sum-=dp[-pq.top()];
			pq.pop();
		}
		pq.push(-i);
	}
	cout<<dp[ma[m]]<<endl;
	return 0;
}
