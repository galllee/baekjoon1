#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, less<int>> max;
    priority_queue<int, vector<int>, greater<int>> min;
    int n;
    cin>>n;
    int *arr=new int[n+1];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        if(arr[i]!=0) {
            if(arr[i]<0) max.push(arr[i]); 
            else min.push(arr[i]);
        }
        else{
            if(!min.empty() && !max.empty()){
                if(abs(max.top())==abs(min.top())){
                    cout<<max.top()<<"\n";
                    max.pop();
                }
                else if(abs(max.top())>abs(min.top())){
                    cout<<min.top()<<"\n";
                    min.pop();
                }
                else if(abs(max.top())<abs(min.top())){
                    cout<<max.top()<<"\n";
                    max.pop();
                }
            }
            else if(min.empty()&&!max.empty()){
                cout<<max.top()<<"\n";
                max.pop();
            }
            else if(!min.empty()&&max.empty()){
                cout<<min.top()<<"\n";
                min.pop();
            }
            else if(min.empty()&&max.empty()) cout<<0<<"\n";
        }
    }
    return 0;
}