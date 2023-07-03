#include <iostream>
#include <queue>
using namespace std;
 
int findmaxindex(int * arr, int n, int index){ 
    int i, max=0,a, cnt=0;
    i=index;

    while(cnt<n){
        cnt++;
        if(arr[i]==-1) {i=(i+1)%n; continue;}
        if(max<arr[i]){
        max=arr[i];
        a=i;
        i=(i+1)%n;
        }
        else i=(i+1)%n;

    }
    return a;
}

int main(){
    int number, n, m, maxindex, count, index;
    bool done=false;
    cin>>number;
    int tmp;

    for(int i=0; i<number; i++){
        count=0; done=false;

        index=0;
        queue <int> q;

        cin>>n>>m;
        int * importance=new int[n+1];

        for(int j=0; j<n; j++){ 
            q.push(j);
        }
        for(int j=0; j<n; j++){
            cin>>importance[j];
        }

        while(1){ 

            while(1){
                maxindex=findmaxindex(importance, n, index);

                if(index!=maxindex && importance[maxindex]!=importance[index]){
                    if(importance[index]==-1) { index=(index+1)%n; continue;}
                    q.push(q.front());
                    q.pop();
                    index=(index+1)%n;
                }
                
                else{
                    count++;
                    if(m==q.front()){
                        done=true;
                        cout<<count<<"\n";
                        break;
                    }
                    importance[index]=-1;
                    index=(index+1)%n;
                    q.pop();

                    break;
                }
                
            }
            if(done){
            break;
            }

        }
    }
    return 0;
}