#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 2000
#define MAX_T 2000

vector<int> solved[MAX_N];
int points[MAX_T];
int score[MAX_N];
bool poiLess(int x, int y)
{
    if (score[x] > score[y])
        return true;
    else if (score[x] == score[y])
    {
        if (solved[x].size() > solved[y].size())
            return true;
        else if (solved[x].size() == solved[y].size())
            return x < y;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    int n, t, p;

    scanf("%d %d %d", &n, &t, &p);
    assert(1 <= n && n <= MAX_N);
    assert(1 <= t && t <= MAX_T);
    assert(1 <= p && p <= n);

    p--;

    memset(points, 0, sizeof(points));
    for (int i = 0; i < n; i++)
    {
        solved[i].reserve(n);
        int x;
        for (int j = 0; j < t; j++)
        {
            scanf("%d", &x);
            if (x == 1)
                solved[i].push_back(j);
            else
                points[j]++;
        }
    }

    vector<int> sortedIds;
    sortedIds.reserve(n);
    for (int i = 0; i < n; i++)
    {
        score[i] = 0;
        for (unsigned int j = 0; j < solved[i].size(); j++)
            score[i] += points[solved[i][j]];
        sortedIds.push_back(i);
    }

    sort(sortedIds.begin(), sortedIds.end(), poiLess);
    for (int i = 0; i < n; i++)
        if (sortedIds[i] == p)
        {
            cout << score[p] << " " << (i + 1) << endl;
            return 0;
        }
    assert(false);

    return 0;
}
