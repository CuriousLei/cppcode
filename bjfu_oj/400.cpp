#include"iostream"
using namespace std;
typedef struct{
	int l,r;
	int id;
}listNode;
typedef struct{
	listNode *list;
	int len;
}sqList;
int num;
void traverse(sqList &L,int l,int r,int id){
	int i,k=0;
	for(i=0;i<L.len;i++){
		if(l>=L.list[i].l&&l<L.list[i].r||r>L.list[i].l&&r<=L.list[i].r){
			k++;
		}
	}
	if(k<num){
		L.list[i].l=l;
		L.list[i].r=r;
		L.list[i].id=id;
		L.len++;
	}
}
void output(sqList L){
	for(int i=0;i<L.len;i++){
		cout<<L.list[i].id;
		if(i==L.len-1){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
}
int main(){
	int q,l,r,i;
	sqList L;
	cin>>num>>q;
	L.list =new listNode[q];
	L.len=0;
	for(i=0;i<q;i++){
		cin>>l>>r;
		traverse(L,l,r,i+1);
	}
	output(L);
	return 0;
}
