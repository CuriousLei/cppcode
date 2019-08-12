//Ackermann函数的递归求值
#include"iostream"
using namespace std;
int ackermann(int m,int n){
	if(m==0){
		cout<<n+1<<endl;
		return n+1;
	}else if(n==0){
		return ackermann(m-1,1);
	}else{
		return ackermann(m-1,ackermann(m,n-1));
	}
}
int main (){
	int m,n;
	while(1){
		cin>>m>>n;
		if(m==0&&n==0){
			break;
		}
		cout<<ackermann(m,n)<<endl;
	}
	return 0;
}
