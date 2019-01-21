#ifdef openg
inline void rd(){
	mt19937 mt;
	for(int i=0;i<1982473;++i) mt(); 
	cout<<"请输入你要读的档的名字(英文)\n";
	string s,t;
	cin>>s;
	cout<<"密码：";
	cin>>t;
	ifstream out;
	out.open((s+".LGWS_is_jvruo").c_str());
	string pd;
	out>>pd;
	if(pd!=t){
		cout<<"Wrong Password!!!\n";
		return;
	}
	out>>player.level>>player.exp>>player.ishh>>player.isqj>>player.money>>openmh>>opencp>>kswj;
	for(int i=0;i<player.level+player.exp+player.ishh+player.isqj+player.ishh+openmh+opencp+kswj;++i) mt(),mt(),mt();
	for(int i=0;i<6;++i){
		out>>player.a[i];
		for(int j=0;j<player.a[i];++j) mt(),mt(),mt(),mt(),mt();
	}
	for(int i=0;i<6;++i){
		out>>player.add[i];
		for(int j=0;j<player.add[i];++j) mt(),mt();
	}
	long long ipd;
	out>>ipd;
	if(mt()!=ipd){
		cout<<"Do you change the file???\n";
		return;
	}
	out.close();
	cout<<"\n\t\t\t\t\tOK\n";
}
#endif
