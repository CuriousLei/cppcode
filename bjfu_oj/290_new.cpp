#include"iostream"
using namespace std;
typedef struct node{
	node *llink,*rlink;
	int data;
	int count;
}*biTree;
void initNode(biTree &T){
	T=new node;
	T->llink=NULL;
	T->rlink=NULL;
	T->count=0;
}
void createTree(biTree &T,int data){
	if(T==NULL){
		initNode(T);
		T->data=data;
	}else{
		if(data>=T->data){
			createTree(T->rlink,data); 
		}else{
			createTree(T->llink,data);
		}
	}
}
void find(biTree &T,int k){
	biTree p=T,e;
	while(p){
		if(k==p->data){
			p->count++;
			break;
		}else{
			if(k>T->data){
				p=p->rlink;
			}else{
				p=p->llink;
			}
		}
	}
	if(p==NULL){
		
		p=T;
		while(p){
			e=p;
			if(k>=p->data){
				p=p->rlink;
			}else{
				p=p->llink;
			}
		}
		initNode(p);
		p->data=k;
		if(k>=e->data){
			e->rlink=p;
		}else{
			e->llink=p;
		}
	}
}
int flag1,flag2;
void output(biTree T){
	if(T){
		output(T->llink);
		if(flag1==1){
			cout<<T->data;
			flag1--;
		}else{
			cout<<" "<<T->data;
		}
		
		output(T->rlink);
	}
}
void outputCount(biTree T){
	if(T){
		outputCount(T->llink);
		if(flag2==1){
			cout<<T->count;
			flag2--;
		}else{
			cout<<" "<<T->count;
		}
		outputCount(T->rlink);
	}
}
int main(){
	biTree T;
	int n,k;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		T=NULL;
		for(int i=0;i<n;i++){
			cin>>k;
			createTree(T,k);
		}
		cin>>k;
		find(T,k);
		flag1=1;flag2=1;
		output(T);
		cout<<endl;
		outputCount(T);
		cout<<endl;
	}
	return 0;
}
