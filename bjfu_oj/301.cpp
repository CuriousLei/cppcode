#include"iostream"
using namespace std;

int main(){
	int n,*list,p,*buf,i;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		list=new int[n];
		for(i=0;i<n;i++){
			cin>>list[i];
		}
		cin>>p;
		p=p%n;
		buf=new int[p];
		for(i=0;i<p;i++){
			buf[i]=list[i];
		}
		for(i=0;i<n-p;i++){
			list[i]=list[i+p];
		}
		for(;i<n;i++){
			list[i]=buf[i-n+p];
		}
		for(i=0;i<n;i++){
			cout<<list[i];
			if(i==n-1){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
	}
	return 0;
}
