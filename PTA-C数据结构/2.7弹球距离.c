#include<stdio.h>
#define TOL 1e-2

double dist(double h, double p);

int main()
{
	double h, p, d;
	scanf("%lf %lf",&h, &p);
	d = dist(h, p);
	printf("%.6f\n",d);
	return 0;
}

double dist(double h, double p)
{
	double x = h;
	h = p*h; 
	while(h>=TOL)
	{
		x+=2*h;
		h = p*h; 
	}
	return x;
}
