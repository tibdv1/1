#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>

struct tiemchung{
	char hoten[50];
	char cccd[15];
	char sdt[15];
	float nhietdo;
	int ha1, ha2;
};
void nhap(tiemchung danhsach[], int *size)
{
	int a,i;
	for(i=0;i<=200;i++)
	{
	  fflush(stdin);printf("Nhap tiep(1) \t Dung(0)\n");scanf("%d",&a);
	  if (a==1){
	  fflush(stdin);printf("\nNhap ten: ");gets(danhsach[i].hoten);
	  fflush(stdin);printf("\nNhap cccd: ");gets(danhsach[i].cccd);
	  fflush(stdin);printf("\nNhap sdt: ");gets(danhsach[i].sdt);
	  fflush(stdin); printf("\nNhap nhietdo: ");scanf("%f",&danhsach[i].nhietdo); 
	  fflush(stdin);printf("\nNhap chi so ha1 va ha2:");scanf("%d%d",&danhsach[i].ha1,&danhsach[i].ha2);}
	  else break;
	}
	*size = i-1;
}
void xuat(tiemchung danhsach[],int n)
{
	printf("STT\tHo ten\t\t\tCCCD\t\t\tSDT\n ");
	printf("-------------------------------------");
	for(int i=0;i<=n;i++)
		printf("\n%d\t%s\t\t%s\t\t%s",i+1,danhsach[i].hoten,danhsach[i].cccd,danhsach[i].sdt);
}
int ktrnhietdo(float nhietdo)
{
	if (nhietdo<=38&&nhietdo>=36.8)
	return 1;
	else return 0;
}
int ktrhuyetap(int ha1, int ha2)
{
	if (ha1>100&&ha1<3007&ha2>79&&ha2<89)
	return 1;
	else return 0;
}
void tiem(tiemchung danhsach[],int n)
{
	printf("\nSTT\tHo ten\t\t\tCCCD\t\t\tSDT\n ");
	printf("-------------------------------------");
	for(int i=0;i<=n;i++)
	{
		if (ktrnhietdo(danhsach[i].nhietdo)==1&&ktrhuyetap(danhsach[i].ha1,danhsach[i].ha2)==1)
		printf("\n%d\t%s\t\t%s\t\t%s",i,danhsach[i].hoten,danhsach[i].cccd,danhsach[i].sdt);
	}
}
void search(tiemchung danhsach[], int n)
{
	char a[100];
	fflush(stdin);printf("\nNhap sdt: ");gets(a);
	for (int i=0;i<=n;i++)
	{
		if (strcmp(danhsach[i].sdt,a)==0)
		{printf("\n%s\t\t%s\t\t%s\t%f\t%d\t%d",danhsach[i].hoten,danhsach[i].cccd,danhsach[i].sdt,danhsach[i].nhietdo,danhsach[i].ha1,danhsach[i].ha2);break;}
		else {printf("khong tim thay SDT trong danh sach! ");break;}
	} 
}

int main()
{
    tiemchung a[100];int n,t;
    for(;;)
	{
	printf("\nMenu:\n+1:Nhap thong tin nguoi den tiem\n+2danh sach du dieu kien tiem\n+3:Tra cuu theo SDT\n+4:thoat chuong trinh\n");
	scanf("%d",&t);
 	if (t==1) {nhap(a,&n);xuat(a,n);}
 	else if (t==2) {tiem(a,n);}
 	else if (t==3) {search(a,n);}
 	else if (t==4) {break;} 
 	}
}
