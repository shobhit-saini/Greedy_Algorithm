#include<iostream>
using namespace std;
struct activity
{
	string job_id;
	int start_time;
	int finish_time;
};
void Merge(struct activity *ar, int low, int mid, int high)
{
	int i = low;
	int j = mid+1;
	int k = 0;
	struct activity temp[high - low + 1];
	while(i <= mid && j<= high)
	{
		if(ar[i].finish_time <= ar[j].finish_time)
		{
			temp[k].finish_time = ar[i].finish_time;
			temp[k].start_time = ar[i].start_time;
			temp[k].job_id = ar[i].job_id;
			k++;
			i++;
		}
		else
		{
			temp[k].finish_time = ar[j].finish_time;
			temp[k].start_time = ar[j].start_time;
			temp[k].job_id = ar[j].job_id;
			k++;
			j++;
		}
	}
	
	while(i <= mid)
	{
		temp[k].finish_time = ar[i].finish_time;
		temp[k].start_time = ar[i].start_time;
		temp[k].job_id = ar[i].job_id;
		k++;
		i++;
	}
	
	while(j <= high)
	{
		temp[k].finish_time = ar[j].finish_time;
		temp[k].start_time = ar[j].start_time;
		temp[k].job_id = ar[j].job_id;
		k++;
		j++;
	}
	
	for(i = low; i <= high; i++)
	{
		ar[i].finish_time = temp[i - low].finish_time;
		ar[i].start_time = temp[i - low].start_time;
		ar[i].job_id = temp[i - low].job_id;
	}
}
void Mergesort(struct activity *ar, int low, int high)
{
	int mid = 0;
	if(low < high)
	{
		mid = low + (high - low)/2 ;
		Mergesort(ar, low, mid);
		Mergesort(ar, mid+1, high);
		Merge(ar, low, mid, high);
	}
}

int main()
{
	int N = 0, i = 0, j = 0;
	cout<<"Enter the no. of the activity:";
	cin>> N;
	struct activity ar[N];
	for(i = 0; i < N; i++)
	{
		cin >> ar[i].job_id >> ar[i].start_time >> ar[i].finish_time;
	}
	Mergesort(ar, 0, N-1);

	cout << "Job sequence is:\n" << ar[0].job_id << "\t";
	j = 0;
	for(i = 1; i < N; i++)
	{
		if(ar[j].finish_time <= ar[i].start_time)
		{
			cout<< ar[i].job_id << "\t";
			j=i;
		}
	}
}
