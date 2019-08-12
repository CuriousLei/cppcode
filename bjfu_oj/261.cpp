#include"iostream"
#include"queue"
using namespace std;

int main(){
	int n,*L;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		L=new int[n];
		for(int i=0;i<n;i++){
			cin>>L[i];
		}
		queue <int> A;
		queue <int> B;
		for(int i=0;i<n;i++){
			if(L[i]>0){
				A.push(L[i]);
			}else{
				B.push(L[i]);
			}
		}
		int k=0;
		while(!A.empty()){
			L[k]=A.front();
			k++;
			A.pop();
		}
		while(!B.empty()){
			L[k]=B.front();
			k++;
			B.pop();
		}
		for(int i=0;i<n;i++){
			cout<<L[i];
			if(i==n-1){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
	}
	return 0;
}
