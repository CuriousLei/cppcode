#include"iostream"
using namespace std;
typedef struct TNode{
	TNode *lchild,*rchild;
	int data;
}*biTree;
void initNode(biTree &T){
	T=new TNode;
	T->lchild=NULL;
	T->rchild=NULL;
}
void createTree(biTree &T,int v){
	if(!T){
		initNode(T);
		T->data=v;
	}else if(v<T->data){
		createTree(T->lchild,v);
	}else if(v>=T->data){
		createTree(T->rchild,v);
	} 
}
int flag=1;
void find(biTree T,int v){
	if(T){
		find(T->lchild,v);
		if(T->data>=v&&flag==0){
			cout<<" "<<T->data;
		}else if(T->data>=v&&flag==1){
			cout<<T->data;
			flag=0;
		}
		find(T->rchild,v);
	}
}
int main(){
	biTree T;
	int n,v;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		T=NULL;
		for(int i=0;i<n;i++){
			cin>>v;
			createTree(T,v);
		}
		cin>>v;
		find(T,v);
		cout<<endl;
		flag=1;
	}
	return 0;
}
