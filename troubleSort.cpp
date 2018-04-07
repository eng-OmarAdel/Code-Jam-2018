#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void troubleSort(vector<long long>::iterator it1, vector<long long>::iterator it2)
{
	int even = 1, odd = 2;
	if ((it2 - it1) % 2 == 0)
		swap(even, odd);
	for (auto itOuter = it1; itOuter != it2 - 2; itOuter++)
	{
		for (auto itEven = it1; itEven != it2 - even; itEven += 2)
		{
			if ((*itEven) > (*(itEven + 2)))
				swap(*itEven, *(itEven + 2));
		}
		for (auto itOdd = it1 + 1; itOdd != it2 - odd; itOdd += 2)
		{
			if ((*itOdd) > (*(itOdd + 2)))
				swap(*itOdd, *(itOdd + 2));
		}
	}
}

int compare(vector<long long> v1, vector<long long> v2)
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
		int numberOfValues;
		cin >> numberOfValues;
		vector<long long>values(numberOfValues);
		for (int i = 0; i < numberOfValues; i++)
			cin >> values[i];
		vector<long long> troubleValues = values;
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
