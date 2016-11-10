#include <iostream>
#include <vector>

using namespace std;
void mergeArea(vector<int>& vec, int left, int mid, int right)
{
	//make another vector for temporary hold.
	vector<int> tempVec;
	tempVec.reserve(vec.size());

	int leftIndex = left;
	int rightIndex = mid + 1;
	int currentIndex = left;

	while ((leftIndex <= mid) && (rightIndex <= right))
	{
		if (vec[leftIndex] <= vec[rightIndex])
			tempVec[currentIndex] = vec[leftIndex++];
		else
			tempVec[currentIndex] = vec[rightIndex++];
		currentIndex++;
	}

	if (leftIndex > mid)
	{
		for (int i = rightIndex; i <= right; i++)
		{
			tempVec[currentIndex] = vec[i];
			currentIndex++;
		}
	}
	else
	{
		for (int i = leftIndex; i <= mid; i++)
		{
			tempVec[currentIndex] =  vec[i];
			currentIndex++;
		}
	}

	//copy temp to origin
	for(int i = left; i <= right; i++)
	{
		vec[i] = tempVec[i];
	}
}

void mergeS(vector<int>& vec, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		mergeS(vec, left, mid);
		mergeS(vec, mid + 1, right);

		mergeArea(vec, left, mid, right);
	}
}

int main()
{
	vector<int> vec = { 7, 5,3,4,6, 2, 10, 1 };

	mergeS(vec, 0, vec.size() - 1 );

	vector<int>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;


	return 0;
}
