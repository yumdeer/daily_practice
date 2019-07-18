#include <stdio.h>
#include <math.h>
void main()
{
    int l,r,m,k,n;
	//int a = 1;

    scanf_s("%d",&l);
    scanf_s("%d",&r);
    scanf_s("%d",&k);

	n=k;

	if(l<k&&k<r)
	{
		printf("%d\n",1);
		for(k;l<k&&k<r;k=n*k)
		{
			printf("%d\n",k);
		}
	}
	else
	printf("-1");

}