#include"iostream"
using namespace std;
typedef struct node{
	node *left,*right;
	int weight;	
}*biTree;
void initNode(biTree &T){
	T=new node;
	T->left=NULL;
	T->right=NULL;
}
void createTree(biTree &T){
	int v;
	cin>>v;
	if(v!=0){
		initNode(T);
		T->weight=v;
		createTree(T->left);
		createTree(T->right);
	}else{
		T=NULL;
	}
}
int traverse(biTree T,int i){
	if(T){
		if(T->left==NULL&&T->right==NULL){
			return T->weight*i;
		}else{
			return traverse(T->left,i+1)+traverse(T->right,i+1);
		}
	}else{
		return 0;
	}
}
int main(){
	int v;
	while(1){
		biTree T;
		createTree(T);
		if(T==NULL){
			break;
		}
		cout<<traverse(T,0)<<endl;
	}
	return 0;
}
