#include <iostream>
using namespace std;

int main()
{
	int cost[20][20], i, j, u, v, s[20], k, distance[20], minimum, n, num;
	cout << "Enter number of vertices" << endl;
	cin >> n;
	cout << "Enter adjacency matrix" << endl;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			cin >> cost[i][j];


	cout << "Choose source vertex" << endl;
	cin >> v;
	for (i = 1; i <= n; i++)
	{
		s[i] = 0;
		distance[i] = cost[v][i];
	}

	s[v] = 1;
	distance[v] = 0;
	for (num = 2; num < n; num++)
	{
		minimum = 999;
		for (k = 1; k <= n; k++)
		{
			if (s[k] == 0 && distance[k] < minimum)
			{
				minimum = distance[k];
				u = k;
			}
		}
		s[u] = 1;

		for (k = 1; k <= n; k++)
			if ((s[k] == 0) && (distance[k] > distance[u] + cost[u][k]))
				distance[k] = distance[u] + cost[u][k];
	}

	for (i = 1; i <= n; i++)
		cout << v << "---->" << i << " cost = " << distance[i] << endl;

	return 0;
}