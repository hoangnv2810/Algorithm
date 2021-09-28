#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void generateGrayarr(int n)
{
	if (n <= 0)
		return;

	vector<string> arr;

	arr.push_back("0");
	arr.push_back("1");

	int i, j;
	for (i = 2; i < pow(2, n); i = 2*i)
	{
		for (j = i-1 ; j >= 0 ; j--)
			arr.push_back(arr[j]);

		for (j = 0 ; j < i ; j++)
			arr[j] = "0" + arr[j];

		for (j = i ; j < 2*i ; j++)
			arr[j] = "1" + arr[j];
	}

	for (i = 0 ; i < arr.size() ; i++ )
		cout << arr[i] << endl;
}

int main()
{
	generateGrayarr(3);
	return 0;
}

