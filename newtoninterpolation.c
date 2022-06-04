/*Polynomial interpolation using Newtons's forward and backward differernce.
Note that this method is valid for evenly spaced datapoints.*/

#include <stdio.h>
#include <math.h>

float forward(float p[][2], int n1, int a1){
    if(n1>0){
        return forward(p, n1-1, a1+1) - forward(p, n1-1, a1);
    }   
    else return p[a1][1]; 
}
float backward(float p[][2], int n1, int a1){
    if(n1>0){
        return backward(p, n1-1, a1) - backward(p, n1-1, a1-1);
    }   
    else return p[a1][1]; 
}

int factorial(int a){
    if(a>1)
    return factorial(a-1)*a;
    else
    return 1;
}

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

    float h = points[1][0]-points[0][0];
    float sum=0;

    if(fabs(x-points[0][0])<fabs(x-points[n-1][0])){
        float g=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                g*= x-points[j][0];
            }
            sum+= (forward(points, i, 0)/factorial(i)*(pow(h, i)))*g;
            g=1;
        }
    }
    else{
        float g=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                g*= x-points[n-1-j][0];
            }
            sum+= (backward(points, i, n-1)/factorial(i)*(pow(h, i)))*g;
            g=1;
        }
    }
    printf("%f", sum);
}