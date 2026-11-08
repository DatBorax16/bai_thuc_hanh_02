#include <stdio.h>
#include <stdlib.h>
void nhap(float* a, int n) {
    for(int i = 0; i < n; i++) {
    	scanf("%f", a + i);
	}
}
void in(float* a, int n) {
	for(int i = 0; i < n; i++) {
		printf("a[%d] = %f\n", i, a[i]);
	}
}
	
int main() {
    int n; 
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    if(n <= 0) {
    	printf("So phan tu phai lon hon 0!");
    	return 1;
	}
	float* a = (float* )malloc(n * sizeof(float));
	if (a == NULL) {
		printf("cap phat that bai!!!\n");
		return 1;
	}
	nhap(a,n);
	printf("Mang vua nhap: \n");
	in(a, n);
	free(a);
	a = NULL;
    return 0;
}
