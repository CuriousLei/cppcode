#include"iostream"
#include"algorithm"
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int n,*list,*A,*B,i,*l0,a,b;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		list=new int[n];
		l0=new int[n];
		for(i=0;i<n;i++){
			cin>>list[i];
			l0[i]=list[i];
		}
		A=new int[n/2];
		B=new int[n-n/2];
		sort(list,list+n,cmp);
		a=0,b=0;
		for(int j=0;j<n;j++){
			for(i=0;i<n/2;i++){
				if(list[i]==l0[j]){
					A[a]=l0[j];
					a++;
					break;
				}
			}
			for(i=n/2;i<n;i++){
				if(list[i]==l0[j]){
					B[b]=l0[j];	
					b++;
					break;
				}
			}
		}

		
		for(i=0;i<n/2;i++){
			cout<<A[i];
			if(i==n/2-1){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
		for(i=0;i<n-n/2;i++){
			cout<<B[i];
			if(i==n-n/2-1){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
	}
	return 0;
}
