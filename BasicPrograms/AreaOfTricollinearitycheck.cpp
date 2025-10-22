#include <iostream>
#include <vector>
using namespace std;

bool collinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    return area == 0;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> coordinates(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coordinates[i].first >> coordinates[i].second;
    }

    bool found = false;

    for (int i = 0; i < n && !found; i++)
    {
        for (int j = i + 1; j < n && !found; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (collinear(coordinates[i].first, coordinates[i].second,
                              coordinates[j].first, coordinates[j].second,
                              coordinates[k].first, coordinates[k].second))
                {
                    cout << "Collinear" << endl;
                    found = true;
                    break;
                }
            }
        }
    }

    if (!found)
    {
        cout << "Not collinear" << endl;
    }

    return 0;
}
