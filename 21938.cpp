#include <iostream>
using namespace std;
int obj[1001][1001];
int n, m;
class Pos{
    int row, col;
    public:
    Pos(int r=0, int c=0) {row=r; col=c;}
    Pos Up() {return Pos(row-1, col);}
    Pos Down(){return Pos(row+1, col);}
    Pos Left(){return Pos(row, col-1);}
    Pos Right(){return Pos(row, col+1);}
    bool Invalid(){
        return(row<0||row>=n||col<0||col>=m||obj[row][col]==0);
    }
    void Visit(){obj[row][col]=0;}
};

bool DepthFirstSearch(Pos p){
    if(p.Invalid()) return false;
    p.Visit();
    DepthFirstSearch(p.Up());
    DepthFirstSearch(p.Down());
    DepthFirstSearch(p.Left());
    DepthFirstSearch(p.Right());
    return true;
}

int main(){
    int t, count=0, k;
    cin>>n>>m;
    int** arr=new int*[n+1];
    for(int i=0; i<n; i++)
        arr[i]=new int[m*3+1];
    for(int i=0; i<n; i++){
        for(int j=0; j<m*3; j++){
            cin>>arr[i][j];
        }
    }
    
    cin>>t;


    for(int i=0; i<n; i++){
        for(int j=0; j<m*3; j+=3){
            obj[i][j/3]=(arr[i][j]+arr[i][j+1]+arr[i][j+2])/3;
            if(obj[i][j/3]>=t) obj[i][j/3]=255;
            else obj[i][j/3]=0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            count+=DepthFirstSearch(Pos(i, j));
        }
    }
    cout<<count;
    return 0;
}