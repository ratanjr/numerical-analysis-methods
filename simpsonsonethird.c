/*This is Simpson's 1/3rd rule for numerical integration*/

#include <stdio.h>

void main(){
    int n;
    float a, b;

    do{
        printf("Enter an even number of subintervals: ");
        scanf("%d", &n);
    }while(n%2!=0);

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
    sum+=fvalues[0]+fvalues[n];
    for(int i=1; i<n; i++){
        if(i%2==0)
        sum+=2*fvalues[i];
        else
        sum+=4*fvalues[i];
    }
    sum*=h/3;
    printf("%f", sum);    
}