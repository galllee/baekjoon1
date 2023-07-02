#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n, a;
    cin>>n;
    string s;
    deque <int> dq;
    for(int i=0; i<n; i++){
        cin>>s;
        if(s.compare("push_front")==0){
            cin>>a;
            dq.push_front(a);
        }
        else if(s.compare("push_back")==0){
            cin>>a;
            dq.push_back(a);
        }
        else if(s.compare("pop_front")==0){
            if(dq.empty()) cout<<-1<<"\n";
            else {cout<<dq.front()<<"\n"; dq.pop_front();}
        }
        else if(s.compare("pop_back")==0){
            if(dq.empty()) cout<<-1<<"\n";
            else {cout<<dq.back()<<"\n"; dq.pop_back();}
        }
        else if(s.compare("size")==0){
            cout<<dq.size()<<"\n";
        }
        else if(s.compare("empty")==0){
            cout<<dq.empty()<<"\n";
        }
        else if(s.compare("front")==0){
            if(dq.empty()) cout<<-1<<"\n";
            else cout<<dq.front()<<"\n";
        }
        else if(s.compare("back")==0){
            if(dq.empty()) cout<<-1<<"\n";
            else cout<<dq.back()<<"\n";
        }
    }
    return 0;
}