#include"iostream"
using namespace std;
void countSort(int list[],int n){
	int e,*cList,m;
	cList=new int[n];
	for(int i=0;i<n;i++){
		e=list[i];
		m=0;
		for(int j=0;j<n;j++){
			if(list[j]<e){
				m++;
			}
		}
		cList[m]=e;
	}
	for(int i=0;i<n;i++){
		cout<<cList[i];
		if(i==n-1){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
}
int main(){
	int n,*list;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		list=new int[n];
		for(int i=0;i<n;i++){
			cin>>list[i];
		}
		countSort(list,n);
	}
	return 0;
}
