#include <stdio.h>
#include <math.h>
#include <cblas.h>
#include <lapacke.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "svd.h"
#include "matrixmul.h"
#define random(x)(rand()%x)
float main()
{
	srand((int)time(0));
	int i,j,x,y,z,t;
	printf("the number of rows=\n");
	scanf("%d",&x);
	printf("the number of columns=\n");
	scanf("%d",&y);
	if(x>y)
		z=y;
	else
		z=x;

	float **a,**u,**v,**s,**P,**Q;
	a=(float **)malloc(x*sizeof(float *));
	u=(float **)malloc(x*sizeof(float *));
	v=(float **)malloc(y*sizeof(float *));
	s=(float **)malloc(x*sizeof(float *));
	P=(float **)malloc(x*sizeof(float *));
	Q=(float **)malloc(x*sizeof(float *));
	for(i=0;i<x;i++)
	{
		a[i]=(float *)malloc(y*sizeof(float));
		u[i]=(float *)malloc(x*sizeof(float));
		s[i]=(float *)malloc(y*sizeof(float));
		P[i]=(float *)malloc(y*sizeof(float));
		Q[i]=(float *)malloc(y*sizeof(float));
	}
	for(i=0;i<y;i++)
		v[i]=(float *)malloc(y*sizeof(float));
	printf("the matrix=\n");
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			a[i][j]=(float)random(200)-100;
			printf("%5d  ",(int)(a[i][j]));
		}
		printf("\n");
		}
	svd(x,y,a,u,s,v);
	printf("S=\n");
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
				printf("%6.3f  ",s[i][j]);
		printf("\n");
	}
	printf("\nU=\n");
	for(i=0;i<x;i++)
	{
		for(j=0;j<x;j++)
			printf("%6.3f  ",u[i][j]);
		printf("\n");
	}
	printf("V=\n");
	for(i=0;i<y;i++)
	{
		for(j=0;j<y;j++)
			printf("%6.3f  ",v[i][j]);
		printf("\n");
	}
	matrixmul(x,x,y,u,s,P);
	matrixmul(x,y,y,P,v,Q);
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
			printf("%6.0f  ",Q[i][j]);
		printf("\n");
	}
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			a[i][j]=Q[i][j];
	free(a);
	free(u);
	free(s);
	free(v);
	free(P);
	free(Q);
}
