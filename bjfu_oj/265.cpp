#include"iostream"
#include"string"
using namespace std;
typedef struct TNode{
	TNode *left,*right;
	char c;
}*biTree;
void initNode(biTree &T){
	T=new TNode;
	T->left=NULL;
	T->right=NULL;
}
int k;
void createTree(biTree &T,string s){
	k++;
	if(s[k]=='0'){
		T=NULL;
	}else{
		initNode(T);
		T->c=s[k];
		createTree(T->left,s);
		createTree(T->right,s);
	}
}
void doubleOrder(biTree &T){
	if(T){
		cout<<T->c;
		doubleOrder(T->left);
		cout<<T->c;
		doubleOrder(T->right);
	}
}
int main(){
	biTree T;
	string s;
	while(1){
		cin>>s;
		if(s=="0"){
			break;
		}
		k=-1;
		createTree(T,s);
		doubleOrder(T);
		cout<<endl;
	}
	return 0;
} 
