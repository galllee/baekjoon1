#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int *arrN, int number, int N)
{
    int start = 0;
    int end = N;
    int mid;

    while (end >= start)
    {
        mid = (start + end) / 2;
        if (number == arrN[mid])
            return (1);
        else if (number < arrN[mid])
            end = mid - 1;
        else if (number > arrN[mid])
            start = mid + 1;
    }
    return (0);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    int M;
    int tmp;
    int *arrN;
    int *arrM;

    cin >> N;
    arrN = new int[N + 1];
    for(int i = 0; i < N; i++)
        cin >> arrN[i];
    cin >> M;
    arrM = new int[M + 1];
    for(int i = 0; i < M; i++)
        cin >> arrM[i];

    sort(arrN, arrN + N);

    for (int i = 0; i < M; i++)
        cout << BinarySearch(arrN, arrM[i], N - 1) << "\n";
    
    return (0);
}