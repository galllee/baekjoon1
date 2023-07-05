#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k, a, count=0;
    cin>>n>>k;
    queue <int> q;
    for(int i=0; i<n; i++){
        q.push(i+1);
    }
    cout<<"<";
    while(1){
        count++;
        if(count%k==0){
            cout<<q.front();
            q.pop();
            if(q.empty()) break;
            cout<<", ";
        }
        else{
        q.push(q.front());
        q.pop();
        }
    }
    cout<<">";
    return 0;
}