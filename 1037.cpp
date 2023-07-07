#include <iostream>
using namespace std;

int main(){
    int number, tmp;
    cin>>number;
    int * arr=new int[number+1];
    arr[number]={0};
    for(int i=0; i<number; i++){
        cin>>arr[i];
    }

    for(int i=0; arr[i]!=0; i++){
        for(int j=i+1; arr[j]!=0; j++){
            if(arr[i]>arr[j]){
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
    cout<<arr[0]*arr[number-1];
    return 0;
}