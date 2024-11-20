#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], n, ans;
int b[10][10];
int t[6];
int Nai_Long(int *arr)
{
	int c = 0, j = 0;
	for (int i = 0; i < 5; i++)
	{
		c += pow(10, 4 - i) * arr[i];
	}
	return c;
}
void launch_Genshin_Impact(int m)
{
	int temp = 0;
	for (int i = 0; i < 5; i++)
	{
		t[i] = b[m][i];
	}
	for (int i = 0; i < 5; i++)
	{
		temp = t[i];
		for (int j = 1; j <= 9; j++)
		{
			t[i]++;
			if (t[i] > 9)
				t[i] %= 10;
			a[Nai_Long(t)]++;
		}
		t[i] = temp;
	}
	int temp1 = 0;
	for (int i = 1; i < 5; i++)
	{
		temp = t[i - 1];
		temp1 = t[i];
		for (int j = 1; j <= 9; j++)
		{
			t[i]++;
			if (t[i] > 9)
				t[i] %= 10;
			t[i - 1]++;
			if (t[i - 1] > 9)
				t[i - 1] %= 10;
			a[Nai_Long(t)]++;
		}
		t[i - 1] = temp;
		t[i] = temp1;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> b[i][j];
		}
		launch_Genshin_Impact(i);
	}
	for (int i = 0; i < 1e5; i++)
	{
		if (a[i] == n)
			ans++;
	}
	cout << ans;

	return 0;
}