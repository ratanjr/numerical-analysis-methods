/*Polynomial interpolation using Lagrange's method*/

#include <stdio.h>
#include <math.h>


void main(){
    int n; float x;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    float points[n][2];

    for(int i=0; i<n; i++){
        printf("Enter x_%d and f(x_%d): ", i, i);
        scanf("%f%f", &points[i][0], &points[i][1]);
    }
    printf("Enter x: ");
    scanf("%f", &x);

    float sum=0, p1=1, p2=1;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j!=i){
                p1*=(x-points[j][0]);
                p2*=(points[i][0]-points[j][0]);
            }
        }
        sum+=(p1*points[i][1])/p2;
        p1=p2=1;
    }
    printf("%f", sum);
}