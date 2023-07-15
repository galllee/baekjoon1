#include <iostream>
using namespace std;
int n, m;
int arr[9]={0,};
bool visited[9]={0,};
void recursion(int len, int j){
    if(len==m){
        for(int i=0; i<m; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=j; i<=n; i++){

            visited[i]=true;
            arr[len]=i;
            recursion(len+1, i);
            visited[i]=false;
        }
    
}

int main(){
    cin>>n>>m;
    recursion(0, 1);
    return 0;
}