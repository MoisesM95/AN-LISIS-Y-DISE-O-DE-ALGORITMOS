#include <stdio.h>
#include <stdlib.h>


int trap(int* height, int n) {
    if (n <= 2) return 0; 

    int *leftMax = (int*)malloc(n * sizeof(int));   
    int *rightMax = (int*)malloc(n * sizeof(int));  
    int waterTrapped = 0;

    
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = (height[i] > leftMax[i-1]) ? height[i] : leftMax[i-1];
    }

    
    rightMax[n-1] = height[n-1];
    for (int i = n-2; i >= 0; i--) {
        rightMax[i] = (height[i] > rightMax[i+1]) ? height[i] : rightMax[i+1];
    }

    
    for (int i = 0; i < n; i++) {
        
        waterTrapped += (leftMax[i] < rightMax[i] ? leftMax[i] : rightMax[i]) - height[i];
    }

    free(leftMax);  
    free(rightMax); 

    return waterTrapped;
}

int main() {
    
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(height) / sizeof(height[0]);

    int result = trap(height, n);
    printf("El agua atrapada es: %d\n", result);

    return 0;
}
