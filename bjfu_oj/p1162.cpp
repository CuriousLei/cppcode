
#include"iostream"
#include"queue"
using namespace std;
int n;
int x[4]={0,-1,0,1};
int y[4]={-1,0,1,0};
//广度优先搜索（使用队列） 
void bfs(int map[][31],int flag[][31],int i,int j){
	int m;
	queue <int> q;
	q.push(i);q.push(j);
	while(!q.empty()){
		i=q.front();
		q.pop();
		j=q.front();
		q.pop();
		for(m=0;m<4;m++){
			int i0=i+x[m];
			int j0=j+y[m];
			if(map[i0][j0]==0&&i0>-1&&i0<n&&j0>-1&&j0<n&&!flag[i0][j0]){
				q.push(i0);
				q.push(j0);
				flag[i0][j0]=1;
			}
		}	
	}
}
//深度优先搜索（使用递归） 
void dfs(int map[][31],int flag[][31],int i,int j){
	for(int m=0;m<4;m++){
		int i0=i+x[m];
		int j0=j+y[m];
		if(map[i0][j0]==0&&i0>-1&&i0<n&&j0>-1&&j0<n&&!flag[i0][j0]){
			flag[i0][j0]=1;
			dfs(map,flag,i0,j0); 
		}
	}
} 
int main(){
	int map[31][31];
	int flag[31][31];
	int i,j;
	while(cin>>n){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>map[i][j];
				if(map[i][j]){
					flag[i][j]=1;
				}else{
					flag[i][j]=0;	
				}
			}
		}
		for(i=0,j=0;j<n;j++){
			if(map[i][j]==0){
				flag[i][j]=1;
				dfs(map,flag,i,j);
			}
		}
		for(i=n-1,j=0;j<n;j++){
			if(map[i][j]==0){
				flag[i][j]=1;
				dfs(map,flag,i,j);
			}
		}
		for(j=0,i=0;i<n;i++){
			if(map[i][j]==0){
				flag[i][j]=1;
				dfs(map,flag,i,j);
			}
		}
		for(j=n-1,i=0;i<n;i++){
			if(map[i][j]==0){
				flag[i][j]=1;
				dfs(map,flag,i,j);
			}
		}
		//输出
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j!=n-1){
					if(flag[i][j]){
						cout<<map[i][j]<<" ";
					}else{
						cout<<2<<" ";
					}
					
				}else{
					cout<<map[i][j]<<endl;
				}
			}
		}
	}
}
