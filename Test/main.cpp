#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
	int getNext(int n)
	{
		int next = 0;
		while (n > 0)
		{
			int temp = (n % 10);
			next += temp * temp;
			n /= 10;
		}
		return next;
	}

public:
	bool isHappy(int n)
	{
		int slow = n, fast = n;
		do
		{
			slow = getNext(slow);
			fast = getNext(fast);
			fast = getNext(fast);
		} while (slow != fast);
		return slow == 1;
	}
};

int main(void)
{

	return 0;
}