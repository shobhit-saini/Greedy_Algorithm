#include<iostream>
#include<math.h>
using namespace std;

void Merge(int *ar,int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = 0;
	int temp[high - low +1];
	while(i <= mid && j <= high)
	{
		if(ar[i] <= ar[j])
		{
			temp[k] = ar[i];
			k++; i++;
		}
		else
		{
			temp[k] = ar[j];
			k++;j++;
		}
	}

	while(i <= mid)
	{
		temp[k] = ar[i];
		k++; i++;
	}
	
	while(j <= high)
	{
		temp[k] = ar[j];
		k++; j++;
	}
	
	for(i = low; i <= high; i++)
	{
		ar[i] = temp[i - low];
	}
	
}
void Mergesort(int *ar, int low, int high)
{
	if(low < high)
	{
		int mid = (low + high)/2;
		Mergesort(ar, low, mid);
		Mergesort(ar, mid + 1, high);
		Merge(ar, low, mid, high);
	}
}
int main()
{
	int N = 0, i = 0, dis = 0;
	cout << "Enter the number of Rat and Holes positions:\n";
	cin >> N;
	int R[N] = {0}, H[N] = {0};
/////////////////////////Position of Rats//////////////////////////
	cout << "Enter the Positions of the Rats:\n";
	for(i = 0; i < N ; i++)
	{
		cin >> R[i];
	}
	
////////////////////////Position of Holes//////////////////////////
	cout << "Enter the postions of the Holes:\n" ;
	for(i = 0; i < N ; i++)
	{
		cin >> H[i];
	}
	
////////////////////////////////////Sort the Rat and Holes array///////////////////////////////////
	Mergesort(R, 0, N-1);
	Mergesort(H, 0, N-1);
		cout << "Enter the Positions of the Rats:\n";
	for(i = 0; i < N ; i++)
	{
		cout<< R[i]<<"\t";
	}
	
		cout << "Enter the postions of the Holes:\n" ;
	for(i = 0; i < N ; i++)
	{
		cout<< H[i]<<"\t";
	}
	int max = 0;
	for(i = 0; i < N; i++)
	{
		dis = abs(R[i] - H[i]);

		if(max < dis)
		{
			max = dis;
		}
	}
	cout << max;
}
