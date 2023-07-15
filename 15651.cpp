#include <iostream>
using namespace std;
int n, m;
int arr[9]={0,};
bool visited[9]={0,};
void recursion(int len){
    if(len==m){
        for(int i=0; i<m; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=1; i<=n; i++){
        
            visited[i]=true;
            arr[len]=i;
            recursion(len+1);
            visited[i]=false;
        
    }
}

int main(){
    cin>>n>>m;
    recursion(0);
    return 0;
}