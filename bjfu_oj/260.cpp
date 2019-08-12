#include"iostream"
using namespace std;
typedef struct{
	int *col;
	int length;
}Row;
typedef struct{
	Row *row;
}data;
bool ifInList(int v,Row list){
	int k=0;
	for(int i=0;i<list.length;i++){
		if(list.col[i]==v){
			k++;
		}
	}
	if(k>1){
		return true;
	}
	return false;
}
bool ifRepeat(data L,int m,int n,Row list){
	int v;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			v=L.row[i].col[j];
			if(ifInList(v,list)){
				return true;
			}
		}
	}
	return false;
}
int main(){
	int m,n;
	data L;
	while(1){
		cin>>m>>n;
		if(m==0&&n==0){
			break;
		}
		L.row=new Row[m];
		Row list;
		list.col=new int[m*n];
		int k=0;
		for(int i=0;i<m;i++){
			L.row[i].col=new int[n];
			for(int j=0;j<n;j++){
				cin>>L.row[i].col[j];
				list.col[k]=L.row[i].col[j];
				k++;
			}
		}
		list.length=k;
		if(ifRepeat(L,m,n,list)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
