#include <windows.h>
#include <stdio.h>
#include <conio.h>
void gotoxy(int x, int y);
void GotoXY(int x,int y);
struct coordinate
{
    int x;
    int y;
    int direction;
};
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}
void load()
{
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("Yukleniyor...");
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",177);
    }
    printf("\n\n\t\tYuklenme Tamamlandi...Baslamak Icin Bir Tusa Basiniz\n\n");
    getch();
}

int birli (int m){

      switch(m){

        case 1:
            printf("A'B'C'");break;
        case 2:
            printf("A'B'C");break;
        case 3:
            printf("A'BC'");break;
        case 4:
            printf("A'BC'");break;
        case 5:
            printf("AB'C'");break;
        case 6:
            printf("AB'C");break;
        case 7:
            printf("ABC");break;
        case 8:
            printf("ABC'");break;
      }
    return 0;
}

int ikili(int m,int h){

    if((m==1) && (h==2) ) {
        printf("A'B'");return 1;
    }
    else if((m==1) && (h==5) ) {
        printf("B'C'");return 1;
    }
    else if((m==1) && (h==4) ) {
        printf("A'C'");return 1;
    }
    else if((m==2) && (h==3) ) {
        printf("AC'");return 1;
    }
    else if((m==2) && (h==6) ) {
        printf("B'C");return 1;
    }
    else if((m==3) && (h==7) ) {
        printf("BC");return 1;
    }
    else if((m==4) && (h==8) ) {
        printf("BC'");return 1;
    }
    else if((m==5) && (h==8) ) {
        printf("ABC'");return 1;
    }
    else if((m==6) && (h==7) ) {
        printf("AC'");return 1;
    }
    else{
        birli(m);
        printf(" + ");
        birli(h);
    }
}

int dortlu(int m, int h, int z, int k){

    if( (m==1) && (h==2) && (z==3) && (k==4) )
printf("A'");
    else if( (m==5) && (h==6) && (z==7) && (k==8) )
printf("A");
    else if( (m==1) && (h==2) && (z==5) && (k==6) )
printf("B'");
    else if( (m==3) && (h==4) && (z==7) && (k==8) )
printf("B");
    else if( (m==1) && (h==3) && (z==5) && (k==7) ) {
ikili(m,z);printf(" + ");ikili(h,k);
}
    else if( (m==2) && (h==4) && (z==6) && (k==8) ) {
ikili(m,z);printf(" + ");ikili(h,k);
}
    else if( (m==1) && (h==3) && (z==7) && (k==8) ) {
ikili(m,k);printf(" + ");ikili(h,z);
}
    else if( (m==1) && (h==3) && (z==5) && (k==7) ) {
ikili(m,z);printf(" + ");ikili(h,k);
}
    else {
ikili(m,h);printf(" + ");ikili(z,k);
}
}
int bitis(int value[]){
    int toplam=0, i, m[8], n=0;

    for(i=1;i<8;i++){
        if(value[i]==1){
            toplam++;
            n++;
            m[n]=i;
        }
    }
    switch(toplam){
        case 0:
             printf("Tum degerler 0(sifir) olamaz!");break;
        case 1:
            birli(m[1]);break;
        case 2:
            ikili(m[1],m[2]);break;
        case 3:
            ikili(m[1],m[2]);printf(" = ");birli(m[3]);break;
        case 4:
            dortlu(m[1],m[2],m[3],m[4]);break;
        case 5:
            dortlu(m[1],m[2],m[3],m[4]);printf(" + ");birli(m[5]);break;
        case 6:
            dortlu(m[1],m[2],m[3],m[4]);printf(" + ");ikili(m[5],m[6]);break;
        case 7:
            dortlu(m[1],m[2],m[3],m[4]);printf(" + ");ikili(m[5],m[6]);printf(" + ");birli(m[1]);break;
        case 8:
             printf("B' + B");break;
    }
}
int main(){
    load();
    system("cls");
    int y, i, mod_y, index[8];
    printf("\t\t\t\t\tKARNAUGH HARITASI HESAPLAYICI");
printf("\n");
printf("\n");
     printf("DURUMLARI LUTFEN SADECE 1 VEYA 0 OLARAK GIRINIZ.  \n");
     printf("\n");

    for (y=0;y<8;y++){
        printf(" %d=> ",y);
        scanf("%d",&index[y]);
    }
   printf("\t\t\t Karnough Haritasý \n\n\t");
    printf(" \tA / BC \t00\t01\t11\t10\n");
   printf("\t___________________________________________________\n\t\t");

    for(i=1;i<=8;i++){
        mod_y=i%4;

        if(i==1){
    int temp1;
    temp1=index[2];
    index[2]=index[3];
    index[3]=temp1;
            printf("   0\t");
        }
        else if(i==5) {

            printf("   1\t");
        }

        printf("%d\t",index[i-1]);
       if (mod_y==0){

    int temp;
    temp=index[7];
    index[7]=index[6];
    index[6]=temp;

            printf("\n\t___________________________________________________\n\t\t");
        }
    }
    printf("\n f(A,B,C)= ");
    bitis(index);

    printf("\n");
printf("\n\n\n\n\n\n\t\t\t\t\t\t...M.MOLLA...");
getch();
}//M.MOLLA
