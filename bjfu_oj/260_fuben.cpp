#include"iostream"
using namespace std;
bool vInList(int c,int *list){
	int k=0;
	for(int i=0;list[i];i++){
		if(list[i]==c){
			k++;
		}
	}
	if(k>1){
		return true;
	}else{
		return false;
	}
}
bool existRepeate(int **data,int *list,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(vInList(data[i][j],list)){
				return true;
			}
		}
	}
	return false;
}
int main(){
	int **data,m,n,*list;
	while(1){
		cin>>m>>n;
		if(m==0&&n==0){
			break;
		}
		data=new int*[m];
		list=new int[m*n];
		int k=0;
		for(int i=0;i<m;i++){
			data[i]=new int[n];
			for(int j=0;j<n;j++){
				cin>>data[i][j];
				list[k]=data[i][j];
				k++;
			}
		}
		if(existRepeate(data,list,m,n)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
