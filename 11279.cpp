#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, less<int>> pq;
    int n;
    cin>>n;
    int *arr=new int[n+1];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        if(arr[i]!=0) pq.push(arr[i]);
        else{
            if(!pq.empty()){
            cout<<pq.top()<<"\n";
            pq.pop();
            }
            else cout<<0<<"\n";
        }
    }
    return 0;
}