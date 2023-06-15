#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <cmath>
using namespace std;

int lastRemaining(int, int);

int main()
{

    cout<<lastRemaining(5,3);
    return 0;
}

/**
 * 约瑟夫环
*/
int lastRemaining(int n, int m)
{
    int x=0;
    for(int i=2;i<=n;i++)
    {
        x=(x+m)%i;
    }
    return x;
}

