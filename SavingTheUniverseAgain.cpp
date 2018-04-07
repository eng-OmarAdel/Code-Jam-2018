#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long calculateDamage(string code)
{
	long long dmg = 0,product=1;
	int flag = 1;
	for (int i = 0; i < code.size(); i++)
	{
		if (code[i] == 'S')
		{
			dmg += product;
		}
		else
			product *= 2;
	}
	return dmg;
}

bool checkPossibility(string code)
{
	int sPos=code.rfind('S');
	
	if (sPos == -1 || sPos == 0)
		return false;
	else
	{
		int cPos=code.find('C');
		if (cPos == -1)
			return false;
		else if (cPos < sPos)
			return true;
		else return false;
	}
}

int calculateHacks(long long sheild, string& code, bool& possible)
{
	bool target=false;
	int hacks=0;
	long long diff = calculateDamage(code) - sheild;
	if (diff <= 0)
	{
		return 0;
	}
	else
	{
		while (!target)
		{
			possible = checkPossibility(code);
			if (!possible)
				break;
			else
			{
				int sPos = code.rfind('S');
				while (code[sPos - 1] == 'S')
					sPos--;
				swap(code[sPos], code[sPos - 1]);
				hacks++;
				if (calculateDamage(code) <= sheild)
					target = true;
			}
		}
		return hacks;
	}
}

int main()
{
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++)
	{
		int numberOfHacks;
		bool possible = true;
		long long sheild;
		string robotCode;

		cin >> sheild >> robotCode;

		numberOfHacks = calculateHacks(sheild, robotCode,possible);

		if(possible)
			cout << "Case #" << i << ": " << numberOfHacks << endl;
		else
			cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
	}
	return 0;
}
