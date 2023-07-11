#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque <int> dq;
    int n, m, count=0, qcount=0;
    bool front=false;
    cin>>n>>m;
    int * arr=new int[m+1];
    for(int i=0; i<m; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        dq.push_back(i+1);
    }
    
    for(int i=0; i<m;){
    if(arr[i]==dq.front()){
        dq.pop_front();
        i++; 
        front=false;
        n--;
    }
    else {
        while(dq.front()!=arr[i]){
            dq.push_back(dq.front());
            dq.pop_front();
            qcount++;
        }
        if(qcount<n-qcount) front=true;
        while(qcount!=0){
            dq.push_front(dq.back());
            dq.pop_back();
            qcount--;
        }

        if(front){
            while(arr[i]!=dq.front()){
            count++;
            dq.push_back(dq.front());
            dq.pop_front();
            }
        }
        else{
            while(arr[i]!=dq.front()){
            count++;
            dq.push_front(dq.back());
            dq.pop_back();
            }
        }
    }
    }
    cout<<count;
    return 0;
}