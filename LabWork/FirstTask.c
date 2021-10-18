#include <stdio.h>
#include <math.h>

int factorial (int n);
double sinX(double x);
double Sin2(double x);
double cosX(double x);

int main () {
	double function = 0;
	double a, b, i;
	
	printf("\nEnter a:\n");
	scanf("%lf",&a);
	printf("\nEnter b:\n");
	scanf("%lf",&b);
	
	for (i = a; i <= b; i += 0.1) {
		function += pow(sinX(i), 2) / (1 + pow(cosX(i), 3));
	}
	
	printf("Result: %f\n", function);
	
	return 0;
}

double sinX(double x) {
    int n = 0;
    double sum, temp;
    
	sum = temp = x;
    
	do {
        n += 2;
        temp *= -(x * x) / n / (n + 1);
        sum += temp;
    } while(fabs(temp) > 0.01);
    return sum;
}
 
double cosX(double x) {
    int n = 0;
    double sum, temp;
    
	sum = temp = 1;
    
	do {
        n +=2;
        temp *= -(x * x) / (n - 1) / n;
        sum += temp;
    } while(fabs(temp) > 0.01);
    return sum;
}
