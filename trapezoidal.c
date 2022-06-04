/*This is the quitessential trapezoidal rule for numerical integration*/

#include <stdio.h>

void main(){
    
    int n;
    float a, b;
    printf("Enter the number of subintervals: ");
    scanf("%d", &n);

    float fvalues[n+1];
    printf("Enter lower bound and its image in function: ");
    scanf("%f%f", &a, &fvalues[0]);
    printf("Enter upper bound and its image in function: ");
    scanf("%f%f", &b, &fvalues[n]);

    float h=(b-a)/n;

    for(int i=1; i<n; i++){
        printf("Enter f(x) at x=%0.3f: ", a+h*i);
        scanf("%f", &fvalues[i]);
    }

    float sum=0;
    for(int i=0; i<n; i++){
        sum+= ((fvalues[i]+fvalues[i+1])/2)*h;
    }
    printf("%f", sum);
}