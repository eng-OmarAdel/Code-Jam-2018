#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void troubleSort(vector<unsigned int>& v, int size)
{
	for (auto itOuter = 0; itOuter < size-2; itOuter++)
	{
		for (auto itEven = 0; itEven < size-1; itEven +=2)
		{
			if (v[itEven] > v[itEven +2])
				swap(v[itEven], v[itEven +2]);
		}
		for (auto itOdd = 1; itOdd < size - 2 ; itOdd += 2)
		{
			if (v[itOdd] > v[itOdd + 2])
				swap(v[itOdd], v[itOdd + 2]);
		}
	}
}

int compare(vector<unsigned int> v1, vector<unsigned int> v2)
{
	int i,flag=1;
	for (i = 0; i < v1.size(); i++)
	{
		if (v1[i] > v2[i])
		{
			break;
			flag = 0;
		}
	}
	if (flag == 1) return -1;
	return i;
}

int main()
{
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++)
	{
		unsigned int numberOfValues;
		cin >> numberOfValues;
		vector<unsigned int>values(numberOfValues);
		for (int i = 0; i < numberOfValues; i++)
			cin >> values[i];
		vector<unsigned int> troubleValues = values;
		troubleSort(troubleValues, numberOfValues);
		sort(values.begin(), values.end());
		int index = compare(troubleValues, values);
		if (index == -1)
			cout << "Case #" << i << ": " << "OK" << endl;
		else
			cout << "Case #" << i << ": " << index << endl;
	}
	return 0;
}
