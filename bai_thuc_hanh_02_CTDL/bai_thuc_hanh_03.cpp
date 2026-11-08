#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct sinhVien {
	char ten[50];
	int ma;
	float diem1;
	float diem2;
	float diem3;
};
typedef struct sinhVien sinhVien;

void nhap(sinhVien* x, int n) {
	for(int i = 0; i < n; i++) {
		printf("Nhap ten sinh vien [%d]: ", i + 1);
		gets(x[i].ten);
		printf("Nhap ma sinh vien [%d]: ", i + 1);
		scanf("%d", &x[i].ma);
		printf("Nhap diem toan sinh vien [%d]: ", i + 1);
		scanf("%f", &x[i].diem1);
		printf("Nhap diem ly sinh vien [%d]: ", i + 1);
		scanf("%f", &x[i].diem2);
		printf("Nhap diem hoa sinh vien [%d]: ", i + 1);
		scanf("%f", &x[i].diem3);
		getchar();
	}
}
void in(sinhVien* x, int n) {
	printf("Danh sach sinh vien: \n");
	for(int i = 0; i < n; i++) {
		printf("%s %d %.2f %.2f %.2f\n", x[i].ten, x[i].ma, x[i].diem1, x[i].diem2, x[i].diem3);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	getchar();
	if(n <= 0) {
		printf("So sinh vien phai lon hon 0");
		return 1;
	}
	sinhVien* x = (sinhVien* )malloc(n * sizeof(sinhVien));
	if (x == NULL) {
		printf("cap phat that bai!!!\n");
		return 1;
	}
	nhap(x, n);
	in(x, n);
	free(x);
}
