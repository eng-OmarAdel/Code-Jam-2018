#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void troubleSort(vector<unsigned int>::iterator it1, vector<unsigned int>::iterator it2)
{
	for (auto itOuter = it1; itOuter != it2-2; itOuter++)
	{
		for (auto itEven = it1; itEven != it2-1; itEven +=2)
		{
			if ((*itEven) > (*(itEven +2)))
				swap(*itEven, *(itEven +2));
		}
		for (auto itOdd = it1+1; itOdd != it2 - 2 ; itOdd += 2)
		{
			if ((*itOdd) > (*(itOdd + 2)))
				swap(*itOdd, *(itOdd + 2));
		}
	}
}

int compare(vector<unsigned int> v1, vector<unsigned int> v2)
{
	if (v1 == v2)
		return -1;
	int i;
	for (i = 0; i < v1.size(); i++)
	{
		if (v1[i] > v2[i])
			break;
	}
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
		troubleSort(troubleValues.begin(), troubleValues.end());
		sort(values.begin(), values.end());
		int index = compare(troubleValues, values);
		if (index == -1)
			cout << "Case #" << i << ": " << "OK" << endl;
		else
			cout << "Case #" << i << ": " << index << endl;
	}
	return 0;
}
