#include"iostream"
using namespace std;
bool find(int *L,int v,int low,int high){
	if(low!=high){
		int mid=(low+high)/2;
		if(L[mid]>v){
			find(L,v,low,mid-1);
		}else if(L[mid]<v){
			find(L,v,mid+1,high);
		}else{
			return true;
		}
	}else{
		return false;
	}

}
int main(){
	int n,*L,v;
	
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		L=new int[n];
		for(int i=0;i<n;i++){
			cin>>L[i];
		}
		cin>>v;
		if(find(L,v,0,n-1)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}
