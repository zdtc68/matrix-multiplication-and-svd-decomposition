#include <math.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "matrixmul.h"
#define random(x)(rand()%x)
int main()
{
	int a,b,c,d,i=1,j,m,n,t;
	while(i)
	{
		i=0;
		printf("first length=\n");
		scanf("%d",&a);
		printf("first width=\n");
		scanf("%d",&b);
		printf("second length=\n");
		scanf("%d",&c);
		printf("second length=\n");
		scanf("%d",&d);
		if (b!=c)
		{
			printf("size wrong, input again\n");
			i=1;
		}
	}
	int **x,**y,**z;
	float **x1,**y1,**z1;
	x=(int **)malloc(a*sizeof(int *));
	y=(int **)malloc(c*sizeof(int *));
	z=(int **)malloc(a*sizeof(int *));
	x1=(float **)malloc(a*sizeof(float *));
	y1=(float **)malloc(c*sizeof(float *));
	z1=(float **)malloc(a*sizeof(float *));
	for(i=0;i<a;i++)
	{
		x[i]=(int *)malloc(b*sizeof(int));
		z[i]=(int *)malloc(d*sizeof(int));
		x1[i]=(float *)malloc(b*sizeof(float));
		z1[i]=(float *)malloc(d*sizeof(float));
	}
	for(i=0;i<c;i++)
	{
		y[i]=(int *)malloc(d*sizeof(int));
		y1[i]=(float *)malloc(d*sizeof(float));
	}
	//float x1[a][b],y1[c][d], z1[a][d];
	//z1=(float*)malloc(a*d*sizeof(float));
	for (i=0;i<a;i++)
		for (j=0;j<b;j++)
		{
			x[i][j]=random(200)-100;
			x1[i][j]=(float)(x[i][j]);
		}
	for (i=0;i<c;i++)
		for (j=0;j<d;j++)
		{
			y[i][j]=random(200)-100;
			y1[i][j]=(float)(y[i][j]);
		}
	for (i=0;i<a;i++)
		for (j=0;j<d;j++) 
		{
			m=0;
			for (t=0;t<b;t++)
			{
				n=x[i][t]*y[t][j];
				m=m+n;
			}
			z[i][j]=m;
		}
	if (a>c)m=a;
	else m=c;
	for (i=0;i<m;i++)
	{
		for (j=0;j<b;j++)
		{
			if (i<a)
			{
				printf("%6d",x[i][j]);
			}
			else printf("      ");
		}
		if (i==(int)(m/2))printf("   * ");
		else printf("     ");
		for (j=0;j<d;j++)
		{
			if (i<c)
			{
				printf("%6d",y[i][j]);
			}
			else printf("      ");
		}
		if (i==(int)(m/2))printf("   = ");
		else printf("     ");
		for (j=0;j<d;j++)
		{
			if (i<a)
			{
				printf("%7d",z[i][j]);
			}
		}
		printf("\n");
	}




	matrixmul(a,b,d,x1,y1,z1);
	for(i=0;i<a;i++)
	{
		for(j=0;j<d;j++)
		{
			printf("%7.1f  ",z1[i][j]);
		}
		printf("\n");
	}
	//free(z1);
	for(i=0;i<c;i++)
	{
		free(y1[i]);
		free(y[i]);
	}
	for(i=0;i<a;i++)
	{
		free(z1[i]);
		free(x1[i]);
		free(z[i]);
		free(x[i]);
	}
	free(z1);
	free(y1);
	free(x1);
	free(z);
	free(y);
	free(x);
}
