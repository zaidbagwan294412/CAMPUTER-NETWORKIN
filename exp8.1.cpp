#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int a,b,c,d;
	cout<<"Enter the IP address : ";
	cin>>a>>b>>c>>d;
	cout<<"The Ip Adress is     : "<<a<<"."<<b<<"."<<c<<"."<<d<<endl;
	int mask[4];
	int n;
	if(a>=0&&a<=127)
	{
		cout<<"The IP Adress Belong to the Class A "<<endl;
		mask[1]=255,mask[2]=0,mask[3]=0,mask[4]=0;
		n=8;
		
		
	}
	else if(a>=128&&a<=191) {
		cout<<"The IP Adress Belong to the Class B "<<endl;
		mask[1]=255,mask[2]=255,mask[3]=0,mask[4]=0;
		n=16;
	}
	else if(a>=192&&a<=223) {
		cout<<"The IP Adress Belong to the Class C "<<endl;
		mask[1]=255,mask[2]=255,mask[3]=255,mask[4]=0;
	    n=24;
    }
else{
	cout<<"Invalid IP adress!!1 OR it Belong to Class D or E"<<endl;
}
cout<<"The No. of adresses : "<<pow(2,32-n)<<endl;
int ip[4]={a,b,c,d};
int f[4];
int l[4];
for(int i=0;i<4;i++)
{
f[i]=ip[i]&mask[i];
l[i]=ip[i] | (255^mask[i]);
	
}

	cout<<"The First Adress is : "<<f[1]<<"."<<f[2]<<"."<<f[3]<<"."<<f[4]<<endl;
	cout<<"The last Adress is : "<<l[1]<<"."<<l[2]<<"."<<l[3]<<"."<<l[4]<<endl;
	


 return 0;
}
