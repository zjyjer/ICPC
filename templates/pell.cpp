#include <cstdio>
#include <cmath>
#include <iostream>
#define sqr(x) ((x)*(x))
#define maxn 50
#define UL unsigned long long
using namespace std;
UL A, B, p[maxn], q[maxn], a[maxn], g[maxn], h[maxn];
int main()
{
	int n;
	for(int test = 1; scanf("%d",&n) && n; test++)
	{
		printf("Case %d:", test);
		if(fabs(sqrt(n) - floor(sqrt(n) + 1e-7)) <= 1e-7)
		{
			int a = (int)(floor(sqrt(n) + 1e-7));
			printf("%d %d\n", a, 1);
		}
		else //x^2 - n * y^2 = 1
		{
			p[1] = 1, p[0] = 0;
			q[1] = 0, q[0] = 1;
			a[2] = (int)(floor(sqrt(n) + 1e-7));
			g[1] = 0; h[1] = 1;
			for(int i = 2; i; i++)
			{
				g[i] = -g[i - 1] + a[i] * h[i - 1];
				h[i] = (n - sqr(g[i])) / h[i - 1];
				a[i + 1] = (g[i] + a[2]) / h[i];
				p[i] = a[i] * p[i - 1] + p[i - 2];
				q[i] = a[i] * q[i - 1] + q[i - 2];
				if(sqr((UL)(p[i])) - n * sqr((UL)(q[i])) == 1)
				{
					A = p[i]; B = q[i];
					break;
				}
			}
			cout << A << " " << B << endl;
		}
	}
	return 0;
}
