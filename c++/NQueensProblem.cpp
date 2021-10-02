#include <iostream>
#include <vector>
using namespace std;

class MultiQueens
{
private:
	vector<int> queen_vec;
	int solve;

	//Check whether the current position of the k-th queen is possible
	bool Check(int k)
	{
		for (int i = 0; i < k; i++)
		{
			if (abs(queen_vec[i] - queen_vec[k]) == abs(i - k) || queen_vec[i] == queen_vec[k])
				return false;
		}
		return true;
	}

	//Print queen position  
	void print_queens()
	{
		std::cout << "Solution " << solve << endl;
		for (int i = 0; i < queen_vec.size(); i++)
		{
			cout << "Queen " << i+1 << " at position (" << i << "," << queen_vec[i] << ")" << endl;
		}
		cout << endl;
	}

	//Recursive backtracking function
	void MultiQueensSolve(const int queen_num, const int k)
	{
		for (int i = 0; i < queen_num; i++) {
			queen_vec[k] = i;
			if (Check(k)) {
				if (k <= queen_num - 1)
				{
					if (k == queen_num - 1)
					{ 
						solve++;
						print_queens();
					}
					else
					{
						MultiQueensSolve(queen_num, k + 1);
					}
				}
			}

		}
	}

public:
	void operator()(const int queen_num)
	{
		solve = 0;
		queen_vec.resize(queen_num);
		MultiQueensSolve(queen_num, 0);
	}
};

int main()
{
	int N;
	cout << "Enter number of queens" << endl;
	cin >> N;
	cout << endl;
	MultiQueens()(N);
}