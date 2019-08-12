#include"iostream"
using namespace std;
int main(){
	int n,low,high,mid,k;
	int a[]={-90,-32,12,16,24,36,45,59,98,120};
	while(cin>>n){
		k=0;
		low=0;
		high=9;
		while(high>=low){
			mid=(low+high)/2;
			if(a[mid]==n){
				cout<<"第"<<mid+1<<"个元素为"<<n<<",比较次数为"<<k+1<<endl;
				break;
			}else if(a[mid]>n){
				high=mid-1;
			}else{
				low=mid+1;
			}
			k++;
		}
		if(high<low){
			cout<<"查找失败，比较次数为"<<k<<endl;
		}
	}
	return 0;
} 
