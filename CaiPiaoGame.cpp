#ifdef openg
struct cp{
	cp(){}
	int money=100;
	int t=0;
	int tt=-1;
	int v;
	int d;
	void borrow()
	{
	    if(tt!=-1)
	    {
	        cout<<"�����ڲ��ܽ�Ǯ"<<endl;
	        return;
	    }
	    cout<<"��Ҫ�����Ǯ��"<<endl;
	    cin>>v;
	    if (d==1||d==2)
	    {
	        if (v>1000) cout<<"�㲻�ܽ���ô��Ǯ��"<<endl,cout<<"��Ҫ�����Ǯ��"<<endl,cin>>v;
	        if (v<=1000) money+=v,cout<<"10���Ժ���Ҫ��"<<2*v<<"��Ԫ"<<endl;
	        return;
	    }
	    else
	    {
	        if (v>100) cout<<"�㲻�ܽ���ô��Ǯ��"<<endl,cout<<"��Ҫ�����Ǯ��"<<endl,cin>>v;
	        if (v<=100) money+=v,cout<<"10���Ժ���Ҫ��"<<2*v<<"��Ԫ"<<endl;
	        return;
	    }
	}
	bool pay()
	{
	    cout<<"������Ҫ�� "<<2*v<<endl;
	    money-=2*v;
	    tt=-1;
	    v=0;
	    if(money<=0) return false;
	    else return true;
	}
	Player main(Player a)
	{
		Colorset(11);
		money=a.money;
	    cout<<"��ӭ������Ʊ���磡"<<endl<<endl<<"��ܰ��ʾ������Ϸ������ʹ��С����������Ӣ����ĸ�������ַ�����Ϸ����˵�����⣩��"<<endl<<"�������Ը���"<<endl<<endl;
//	    cout<<"��ѡ���Ѷ�(������ż���):"<<endl<<"1:����"<<" "<<"2:��"<<" "<<"3:��ͨ"<<" "<<"4:�е�"<<" "<<"5:����"<<endl;
	    d=4;
	    bool flag=true;
	    srand(time(0));
	    int n,p;
	    char c[4];
	    if (d==1)
	    {
	        cout<<"ÿ�Ų�Ʊ �����Ϊ1��Ԫ�����ۼ�Ϊ5��Ԫ�����������"<<endl<<"С����10��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���10,000��Ԫ"<<endl;
	        cout<<"����100��Ԫ������׬�˳���10,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ�����Ʋ��ˡ�"<<endl;
	        cout<<"��������Ǯ�����1,000��Ԫ����������룬��0��"<<endl<<"���ס���������ʮ���Ժ�����볥��������"<<endl;
	        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
	    }
	    if (d==2)
	    {
	        cout<<"ÿ�Ų�Ʊ �����Ϊ2��Ԫ�����ۼ�Ϊ3��Ԫ�����������"<<endl<<"С����5��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���10,000��Ԫ"<<endl;
	        cout<<"����100��Ԫ������׬�˳���10,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ�����Ʋ��ˡ�"<<endl;
	        cout<<"��������Ǯ�����1,000��Ԫ����������룬�밴0��"<<endl<<"���ס���������ʮ���Ժ�����볥��������"<<endl;
	        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
	    }
	    if (d==3)
	    {
	        cout<<"ÿ�Ų�Ʊ �ۼ�2��Ԫ�����������"<<endl<<"С����5��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���10,000��Ԫ"<<endl;
	        cout<<"����100��Ԫ������׬�˳���10,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ�����Ʋ��ˡ�"<<endl;
	        cout<<"��������Ǯ�����100��Ԫ����������룬�밴0��"<<endl<<"���ס���������ʮ���Ժ�����볥��������"<<endl;
	        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
	    }
	    if (d==4)
	    {
	        cout<<"ÿ�Ų�Ʊ �ۼ�3��Ԫ�����������"<<endl<<"С����5��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���10,000��Ԫ"<<endl;
	        cout<<"����100��Ԫ������׬�˳���100,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ�����Ʋ��ˡ�"<<endl;
	        cout<<"��������Ǯ�����100��Ԫ����������룬�밴0��"<<endl<<"���ס��������������Ժ�����볥��������"<<endl;
	        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
	    }
	    if (d==5)
	    {
	        cout<<"ÿ�Ų�Ʊ �����Ϊ5��Ԫ�����ۼ�Ϊ2��Ԫ�����������"<<endl<<"С����5��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���5,000��Ԫ"<<endl;
	        cout<<"����100��Ԫ������׬�˳���100,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ������Ʋ��ˡ�"<<endl;
	        cout<<"��������Ǯ�����100��Ԫ����������룬�밴0��"<<endl<<"���ס��������������Ժ�����볥��������"<<endl;
	        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
	    }
	    cin>>c;
	    if(c[0]=='b'||c[0]=='B')
	    {
	        while(money>0)
	        {
	            if (d==1||d==2||d==3) if(money>=10000)
	                {
	                    cout<<"�㷢����! "<<endl;
	                    cout<<"�㻨�� "<<t<<"��"<<endl;
	                    system("pause");
	                    a.money=money;
	                    return a;
	                }
	            if (d==4||d==5) if(money>=100000)
	                {
	                    cout<<"�㷢����! "<<endl;
	                    cout<<"�㻨�� "<<t<<"��"<<endl;
	                    system("pause");
	                    a.money=money;
	                    return a;
	                }
	            t++;
	            cout<<"��Ҫ����Ʊ������-1����ս������"<<" "<<"����$"<<money<<endl;
	            cin>>n;
	            if(n==-1){
	            	a.money=money;
	            	return a;
				}
	            if(n==0)
	            {
	                if (d=4)
	                {
	                    borrow();
	                    tt=t+7;
	                }
	                if (d=5)
	                {
	                    borrow();
	                    tt=t+5;
	                }
	                else
	                {
	                    borrow();
	                    tt=t+10;
	                }
	            }
	            if(t==tt)
	            {
	                flag=pay();
	            }
	            if(t==tt-1) cout<<"[����]����������컹Ǯ��"<<endl;
	            if(flag==false)
	            {
	                cout<<"�㲻�ܳ�������Ǯ��"<<endl;
	                cout<<"���Ʋ��ˡ�"<<endl;
	                cout<<"��������"<<t<<"�졣"<<endl;
	                a.money=money;
	                system("pause");
	                return a;
	            }
	            flag=true;
	            if(n<0)
	            {
	                cout<<"��Ϊ��Υ����������ϵͳǿ��ֹͣ�������Ϸ"<<endl;
	                system("pause");
	            }
	            if (d==1) money=money-n;
	            if (d==2||d==3) money=money-n*2;
	            if (d==4) money=money-n*3;
	            if (d==5) money=money-n*5;
	            if(money<0)
	            {
	                cout<<"���Ʋ��ˡ�"<<endl;
	                cout<<"��������"<<t<<"��"<<endl;
	                system("pause");
	                a.money=money;
	                return a;
	            }
	            for(int i=0; i<n; i++)
	            {
	                p=rand()%12000;
	                if(p==0)
	                {
	                    int q=0;
	                    q=rand()%4;
	                    if(q==1)
	                    {
	                        cout<<"�����˽ܿ˺���"<<endl;
	                        if (d==5) money+=5000;
	                        else money+=10000;
	                    }
	                }
	                else if(p>=1&&p<=8)
	                {
	                    int g=0;
	                    g=rand()%2;
	                    if(g==0)
	                    {
	                        cout<<"�����˾޶�� "<<endl;
	                        money+=1000;
	                    }
	                }
	                else if(p>=9&&p<=99)
	                {
	                    cout<<"�����˴󽱣�"<<endl;
	                    money+=100;
	                }
	                else if((p>=100&&p<=399)||(p>1500&&p<=1600))
	                {
	                    cout<<"�������м佱��"<<endl;
	                    money+=20;
	                }
	                else if(p>=400&&p<=1500)
	                {
	                    cout<<"������С����"<<endl;
	                    if (d==1) money+=10;
	                    else money+=5;
	                }
	            }
	            if(money<=0)
	            {
	                cout<<"���Ʋ��ˡ�"<<endl;
	                cout<<"��������"<<t<<"�졣"<<endl;
	                system("pause");
	                a.money=money;
	                return a;
	            }
	        }
	    }
	    if(c[0]=='s'||c[0]=='S')
	    {
	        if (d==1)
	        {
	            cout<<"����$"<<money<<endl;
	            cout<<"����븶25��Ԫ��һ���̵ꡣ "<<endl;
	            cout<<"��ֻ����ͬ��������Ʊ��Ϊ���Ǯ�� "<<endl;
	            money-=25;
	        }
	        if (d==2)
	        {
	            cout<<"����$"<<money<<endl;
	            cout<<"����븶35��Ԫ��һ���̵ꡣ "<<endl;
	            cout<<"��ֻ����ͬ��������Ʊ��Ϊ���Ǯ�� "<<endl;
	            money-=35;
	        }
	        if (d==3||d==4)
	        {
	            cout<<"����$"<<money<<endl;
	            cout<<"����븶50��Ԫ��һ���̵ꡣ "<<endl;
	            cout<<"��ֻ����ͬ��������Ʊ��Ϊ���Ǯ�� "<<endl;
	            money-=50;
	        }
	        if (d==5)
	        {
	            cout<<"����$"<<money<<endl;
	            cout<<"����븶60��Ԫ��һ���̵ꡣ "<<endl;
	            cout<<"��ֻ����ͬ��������Ʊ��Ϊ���Ǯ�� "<<endl;
	            money-=60;
	        }
	        cout<<"����$"<<money<<endl;
	        while(money>0)
	        {
	            if (d==1||d==2||d==3) if(money>=10000)
	                    if (d==4||d==5) if(money>=100000)
	                        {
	                            cout<<"�㷢����!"<<endl;
	                            cout<<"�㻨��"<<t<<"�졣"<<endl;
	                            system("pause");
	                            a.money=money;
	                            return a;
	                        }
	            t++;
	            cout<<"��Ҫ������Ʊ�� ����-1����ս����½"<<" "<<"����$"<<money<<endl;
	            cin>>n;
	            if(n==-1){
	            	a.money=money;
	            	return a;
				}
	            if(n==0)
	            {
	                borrow();
	                tt=t+10;
	            }
	            if(t==tt) bool flag=pay();
	            if(flag==false)
	            {
	                cout<<"�㲻�ܳ�������Ǯ��"<<endl;
	                cout<<"���Ʋ��ˣ�"<<endl;
	                cout<<"��������"<<t<<" �졣"<<endl;
	                system("pause");
	                a.money=money;
	                return a;
	            }
	            if(n<0 || n>money)
	            {
	                cout<<"ע��"<<endl;
	                cout<<"���Ʋ��ˣ�"<<endl;
	                cout<<"��������"<<t<<" ��"<<endl;
	                system("pause");
	                a.money=money;
	                return a;
	            }
	            if (d=1) money=money+n*5;
	            if (d=2) money=money+n*3;
	            else money=money+n*2;
	            if(money<0)
	            {
	                cout<<"���Ʋ��ˣ�"<<endl;
	                cout<<"��������"<<t<<" ��"<<endl;
	                system("pause");
	                a.money=money;
	                return a;
	            }
	            for(int i=0; i<n; i++)
	            {
	                p=rand()%12000;
	                if(p==0)
	                {
	                    int y;
	                    y=rand()%4;
	                    if(y==1)
	                    {
	                        cout<<"��ʧȥ�˽ܿ˺���"<<endl;
	                        if (d==5) money-=5000;
	                        else money-=10000;
	                    }
	                }
	                else if(p>=1&&p<=8)
	                {
	                    cout<<"��ʧȥ�˾޶��"<<endl;
	                    money-=1000;
	                }
	                else if(p>=15&&p<=50)
	                {
	                    cout<<"��ʧȥ�˴󽱣�"<<endl;
	                    money-=100;
	                }
	                else if(p>=61&&p<=360)
	                {
	                    cout<<"��ʧȥ���н���"<<endl;
	                    money-=20;
	                }
	                else if(p>=401&&p<=1500)
	                {
	                    cout<<"��ʧȥ��С����"<<endl;
	                    money-=5;
	                }
	            }
	        }
	    }
	    if(money<=0)
	    {
	        cout<<"���Ʋ��ˡ�"<<endl;
	        cout<<"��������"<<t<<"�졣"<<endl;
	        system("pause");
	        a.money=money;
	        return a;
	    }
	}
}cip;
#endif
