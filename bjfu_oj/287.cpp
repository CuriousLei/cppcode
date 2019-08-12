#include"iostream"
using namespace std;
void binarySearch(int data[],int k,int low,int high){
	if(low>high){
		cout<<"NO"<<endl;
	}else{
		int mid=(low+high)/2;
		if(data[mid]==k){
			cout<<"YES"<<endl;
		}else if(k<data[mid]){
			binarySearch(data,k,low,mid-1);
		}else{
			binarySearch(data,k,mid+1,high);
		}	
	}
}
int main(){
	int n,*data,k;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		data=new int[n];
		for(int i=0;i<n;i++){
			cin>>data[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				if(data[j]>data[j+1]){
					k=data[j];
					data[j]=data[j+1];
					data[j+1]=k;
				}
			}
		}
		cin>>k;
		binarySearch(data,k,0,n);
	}
	return 0; 
} 
