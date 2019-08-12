#include"iostream"
using namespace std;
typedef struct{
	int value;	
}node;
typedef struct{
	node *elem;
	int length;
}sqList;
void initList(sqList &list){
	list.elem=new node[10000];
	list.length=0;
}
void deleteNode(sqList &list,int m){
	for(int i=0;i<list.length;i++){
		if(list.elem[i].value==m){
			for(int j=i;j<list.length-1;j++){
				list.elem[j]=list.elem[j+1];
			}
			list.length--;
			i--;
		}
	}
}
void output(sqList list){
	for(int i=0;i<list.length;i++){
		cout<<list.elem[i].value;
		if(i==list.length-1){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
}
int main(){
	sqList list;
	int n,m;
	cin>>n;
	while(n!=0){
		initList(list);
		for(int i=0;i<n;i++){
			cin>>list.elem[i].value;
			list.length++;
		}
		cin>>m;
		deleteNode(list,m);
		output(list);
		cin>>n;
	}
	return 0;
}
