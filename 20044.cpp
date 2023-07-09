#include <iostream>
using namespace std;

int main(){
    int n, tmp, summin;
    cin>>n;
    int *arr=new int[2*n+1];
    int *min=new int[n+1];
    for(int i=0; i<2*n; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<2*n-1; i++){
        for(int j=i+1; j<2*n; j++){
            if(arr[i]>arr[j]){
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }

    for(int i=0; i<n; i++){
        min[i]=arr[i]+arr[2*n-i-1];
    }
    
    summin=min[0];

    for(int i=0; i<n; i++){
        if(summin>min[i]) summin=min[i];
    }
    

    cout<<summin;
    return 0;
}