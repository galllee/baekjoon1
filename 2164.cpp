#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    queue <int> q;
    cin>>n;
    for(int i=0; i<n; i++){
        q.push(i+1);
    }
    while(!q.empty()){
        if(q.size()==1)
        break;
        q.pop();
        if(q.size()==1)
        break;
        q.push(q.front());
        q.pop();
    }
    cout<<q.front();
    return 0;
}