#include"iostream"
using namespace std;
typedef struct TNode{
	TNode *llink,*rlink;
	int data,count;
}*biTree;
void initNode(biTree &T){
	T=new TNode;
	T->llink=NULL;
	T->rlink=NULL;
	T->count=0;
}
void insert(biTree &T,int v){
	
	if(T){
		if(v>=T->data){
			insert(T->rlink,v);
		}else{
			insert(T->llink,v);
		}
	}else{
		initNode(T);
		T->data=v;
	}
}
void insertAndSearch(biTree T,int v){
	biTree p=T,e;
	while(p){
		e=p;
		if(v==p->data){
			p->count++;
			break;
		}else if(v>p->data){
			p=p->rlink;
		}else{
			p=p->llink;
		}
	}
	if(!p){
		initNode(p);
		p->data=v;
		if(v<e->data){
			e->llink=p;
		}else{
			e->rlink=p;
		}
	}
}
int flag1,flag2;
void inOrderTraverse(biTree T){
	if(T){
		inOrderTraverse(T->llink);
		if(flag1==1){
			cout<<T->data;
			flag1++;
		}else{
			cout<<" "<<T->data;
		}
		
		inOrderTraverse(T->rlink);
	}
}
void inOrderTraverseCount(biTree T){
	if(T){
		inOrderTraverseCount(T->llink);
		if(flag2==1){
			cout<<T->count;
			flag2++;
		}else{
			cout<<" "<<T->count;
		}
		inOrderTraverseCount(T->rlink);
	}
}
int main(){
	int n,v;
	biTree T;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		T=NULL;
		for(int i=0;i<n;i++){
			cin>>v;
			insert(T,v);
		}
		cin>>v;
		flag1=1;
		flag2=1;
		insertAndSearch(T,v);
		inOrderTraverse(T);
		cout<<endl;
		inOrderTraverseCount(T);
		cout<<endl;
	}
	return 0;
}
