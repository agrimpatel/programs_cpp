#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            count+=(n-i+1)*(m-j+1);
        }
    }
    
    cout << count;
    return 0;
}