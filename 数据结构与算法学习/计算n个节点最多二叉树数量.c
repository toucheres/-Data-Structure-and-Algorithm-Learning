#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

//int main()
//{
//	while (1)
//	{
//		int n = 0;
//		scanf("%d", &n);
//		long long int dp[n + 1];
//		memset(dp, 0, sizeof(dp));
//		dp[0] = dp[1] = 1;
//		for (int i = 2; i <= n; ++i)
//		{
//			dp[i] = 0;
//			for (int j = 0; j < i; ++j)
//			{
//				dp[i] += dp[j] * dp[i - j - 1];
//			}
//		}
//		printf("%lld\n", dp[n]);
//	}
//	//¿¨ÌØÀ¼Êý
//	//Cn = (2n)!/(n!*(n+1)!)
//}