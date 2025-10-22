#include <iostream>
using namespace std;

int main()
{

    int N;
    int M;
    cin >> N;
    cin >> M;
    int l1 = N + 1;
    int l2 = M + 1;

    int NOR = (l1 * (l1 - 1)*l2*(l2 - 1))/4;
    cout << NOR << endl;
    return 0;
}