#include<bits/stdc++.h>
#include "Data.cpp"
using namespace std;
struct Monster{
	int a[6];
	Monster(){}
	inline void init(int level){
		for(int i=0;i<level;++i) a[i]=max(mmin[level-1][i],rand()%mmax[level-1][i]); 
	}
	inline bool die(int level){
		for(int i=0;i<level;++i) if(a[i]!=0) return 0;
		return 1;
	}
};
