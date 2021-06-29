/* Program to print numbers in given range */
#include<iostream>
#define ERROR -1
using namespace std;

class Range
{
public:
	int iStart, iEnd;
	Range()
	{
		iStart = 0;
		iEnd = 0;
	}

	void DisplayInRange(int, int);
	void DisplayEvenInRange(int, int);
	int  AdditionInRange(int, int);
	int  EvenAdditionInRange(int, int);
	void DisplayInRangeRev(int, int);
};
void Range::DisplayInRange(int iStart, int iEnd)
{
	if(iStart > iEnd)
		printf("Invalid Range\n");
	for (int i = iStart; i <= iEnd; i++)
	{
		cout << i << " ";
	}
}

void Range::DisplayInRangeRev(int iStart, int iEnd)
{
	if(iStart > iEnd)
		printf("Invalid Range\n");
	for (int i = iEnd; i >= iStart; i--)
	{
		cout << i << " ";
	}
}

int Range::AdditionInRange(int iStart, int iEnd)
{
	int iSum = 0;
	if(iStart < 0 || iEnd < 0 || iStart > iEnd)
	{
		printf("Invalid Range");
		return ERROR;
	}
	for(int i = iStart; i <= iEnd; i++)
	{
		iSum = iSum + i;
	}
	return iSum;
}

int Range::EvenAdditionInRange(int iStart, int iEnd)
{
	int iSum = 0;
	if(iStart < 0 || iEnd < 0 || iStart > iEnd)
	{
		printf("Invalid Range");
		return ERROR;
	}
	for(int i = iStart; i <= iEnd; i++)
	{
		if(i % 2 == 0)
			iSum = iSum + i;
	}
	return iSum;
}

void Range::DisplayEvenInRange(int iStart, int iEnd)
{
	if(iStart > iEnd)
		printf("Invalid Range\n");
	for (int i = iStart; i <= iEnd; i++)
	{
		if(i % 2 == 0)
			cout << i << " ";
	}
}

int main()
{
	int iStart = 0, iEnd = 0, iRet = 0;
	cout << "Enter the start\n";
	cin >> iStart;
	cout << "Enter the end\n";
	cin >> iEnd;

	Range rObj;
	cout << "\nNumbers in Given Range\n";
	rObj.DisplayInRange(iStart, iEnd);
	cout << endl;
	cout << "-------------------------------------------------\n";

	cout << "\nNumbers in Given Range Reverse\n";
	rObj.DisplayInRangeRev(iStart, iEnd);
	cout << endl;
	cout << "-------------------------------------------------\n";

	iRet = rObj.AdditionInRange(iStart, iEnd);
	cout << endl;
	if(iRet != ERROR)
		cout << "\nAddition of numbers in given range is " << iRet<<endl;
	cout << "-------------------------------------------------\n";

	iRet = rObj.EvenAdditionInRange(iStart, iEnd);
	cout << endl;
	if(iRet != ERROR)
		cout << "\nAddition of Even numbers in given range is " << iRet<<endl;
	cout << "-------------------------------------------------\n";

	cout << "\nEven numbers in Given Range\n";
	rObj.DisplayEvenInRange(iStart, iEnd);
	cout << endl;
	cout << "-------------------------------------------------\n";
	return 0;
}