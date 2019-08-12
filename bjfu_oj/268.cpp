#include"iostream"
#include"string"
using namespace std;
typedef struct Tnode{
	Tnode *left,*right;
	char v;
}*biTree;
void initNode(biTree &T){
	T=new Tnode;
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
		T->v=s[k];
		createTree(T->left,s);
		createTree(T->right,s);
	}
}
char buf[100];
//深度优先算法 ,遍历至叶子节点时逆序输出路径 
void getPath(biTree T,int n){
	if(T){
		buf[n]=T->v;
		if(T->left==NULL&&T->right==NULL){
			for(int i=0;i<n+1;i++){
				cout<<buf[n-i];
			}
			cout<<endl;
		}else{
			getPath(T->left,n+1);
			getPath(T->right,n+1);
		}
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
		getPath(T,0);
	}
	return 0;
}
