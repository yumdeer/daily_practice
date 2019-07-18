#include <stdio.h>
#include <iostream>
#include <deque>
#include <iterator>
//#include <allocators>
#include <algorithm>

using namespace std;
int a[1000010], ans = 0;
void f(int n)
{
	if (n <= 2) ans += a[n];
	else if (n == 3) ans += a[1] + a[2] + a[3];
	else
	{
		ans += a[n] + a[1];
		ans += min(2 * a[2], a[n - 1] + a[1]);
		f(n - 2);
	}
}

int main()
{
	int bridge[100];
	int i, n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	f(n);
	printf("%d", ans);
	return 0;
}

