#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
using namespace std;

bool isFascinating(int);
int nums_size(int);
int main()
{
	isFascinating(100);
	return 0;
}

bool isFascinating(int n)
{
	int arr[][9] = {{1, 2, 3, 4, 5, 6, 7, 8, 9}, {0, 0, 0, 0, 0, 0, 0, 0, 0}};
	int a = 2 * n, b = 3 * n;
	if (nums_size(n) + nums_size(a) + nums_size(b) > 9)
		return false;
	int size = sizeof(arr) / sizeof(int), col = sizeof(arr[0]) / sizeof(int);
	while (n != 0 || a != 0 || b != 0)
	{
		while (n != 0)
		{
			for (int i = 0; i < col; i++)
			{
				int c = n % 10;
				if (c == arr[0][i] && arr[1][i] > 0)
					return false;
				else if (c == arr[0][i])
				{
					arr[1][i]++;
					n = n / 10;
					break;
				}
				else if(i==col-1)
				{
					return false;
				}
			}
		}
		while (a != 0)
		{
			for (int i = 0; i < col; i++)
			{
				int c = a % 10;
				if (c == arr[0][i] && arr[1][0] > 0)
					return false;
				else if (c == arr[0][i])
				{
					arr[1][i]++;
					a = a / 10;
					break;
				}
				else if(i==col-1)
				{
					return false;
				}
			}
		}
		while (b != 0)
		{
			for (int i = 0; i < col; i++)
			{
				int c = b % 10;
				if (c == arr[0][i] && arr[1][0] > 0)
					return false;
				else if (c == arr[0][i])
				{
					arr[1][i]++;
					b = b / 10;
					break;
				}
				else if(i==col-1)
				{
					return false;
				}
			}
		}
	}
	return true;
}
int nums_size(int nums)
{
	int size = 0;
	while (nums > 0)
	{
		nums /= 10;
		size++;
	}
	return size;
}