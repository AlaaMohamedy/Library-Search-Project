#include <iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bookdata
{
int id;
char name[50];
int quantity;
};
int sizeoffile(int i);
void add(struct bookdata book[],int *z);
void del(struct bookdata book[],int *z);
int linearsearch(struct bookdata book[],int z,int i,int n);
int binarysearch(struct bookdata b[],int z,int low,int high,char key[],int x);
void sortedbooks(struct bookdata book[],int *z);
void printing(struct bookdata book[],int *z);
int main()
{
int i;
i=sizeoffile(0);
int z=i+1;
struct bookdata book[z];struct bookdata book2[z];char ch,ch2,c='y';int n,p;
int y=0;char key[50];struct bookdata b[z];
FILE*fptr=fopen("the file.txt","r");{
for(int i=0;i<z;i++)
{
fscanf(fptr,"%d",&book[i].id);fscanf(fptr,"%[^:]%*c",book[i].name);
fscanf(fptr,"%d",&book[i].quantity);
}
}fclose(fptr);
while(c=='y'||c=='Y')
{
printf("the menu of options:\na:add new book\nb:delete book by id\n");
printf("c:search for book by id\nd:search for book by name\n");
printf("e:print books sorted by name\nf:print books unsorted\n");
printf("enter the option tha you want from that menu:");
scanf(" %c",&ch);
if(ch=='a'||ch=='A')
{
add(book,&z);
printf("the book is added\n");

printf("Do you want another option choose y for yes,n for no");
scanf(" %c",&ch2);
if(ch2=='y'||ch2=='Y')
{
system("cls");
c=ch2;
}
else
{
c=ch2;
printf("bye bye");
}
}
else if(ch=='b'||ch=='B')
{
del(book,&z);
printf("the book is deleted\n");
printf("Do you want another option choose\y for yes,n for no:");
scanf(" %c",&ch2);
if(ch2=='y'||ch2=='Y')
{
system("cls");
c=ch2;
}
else
{
c=ch2;
printf("bye bye");
}
}
else if(ch=='c'||ch=='C')
{
printf("enter the id of book for searching about it");scanf("%d",&n);
y=linearsearch(book,z,0,n);
if(y==z)
{
printf("the book is not found\n");
}
printf("Do you want another option choose(y for yes,n for no");
scanf(" %c",&ch2);
if(ch2=='y'||ch2=='Y')
{
system("cls");
c=ch2;
}
else
{
c=ch2;
printf("bye bye");
}
}
else if(ch=='d'||ch=='D')

{
for(int i=0;i<z;i++)
{
b[i]=book[i];
}
printf("enter the name of book for searching about it\n");fflush(stdin);gets(key);
int p=binarysearch(b,z,0,z-1,key,50);
if(p!=-1)
{
printf("the book is exist :\n it's name :%s\nit's id :%d\n",b[p].name,b[p].id);
printf("it's quantity :%d\n",b[p].quantity);
}
else
printf("the book is not found\n");
printf("Do you want another option choose(y for yes,n for no)");
scanf(" %c",&ch2);
if(ch2=='y'||ch2=='Y')
{
system("cls");
c=ch2;
}
else
{
c=ch2;
printf("bye bye");
}
}
else if(ch=='e'||ch=='E')
{
sortedbooks(book,&z);
printf("Do you want another option choose(y for yes,n for no)");
scanf(" %c",&ch2);
if(ch2=='y'||ch2=='Y')
{
system("cls");
c=ch2;
}
else
{
c=ch2;
printf("bye bye");
}
}
else if(ch=='f'||ch=='F')
{
printing(book,&z);
printf("Do you want another option choose(y for yes,n for no)");
scanf(" %c",&ch2);
if(ch2=='y'||ch2=='Y')
{
system("cls");
c=ch2;

}
else
{
c=ch2;
printf("bye bye");
}
}
}
return 0;
}
int sizeoffile(int i)
{
FILE*fptr=fopen("the file.txt","r");
if(!feof(fptr))
{
for(char s=getc(fptr);s!=EOF;s=getc(fptr))
{
if(s=='\n')
{
i++;
}
}
}fclose(fptr);return i;
}
/////////////////////////////////
void add(struct bookdata book[],int*z)
{
*z=*z+1;
FILE*fptr=fopen("the file.txt","a");
if(fptr!=NULL)
{
printf("enter id for the book:");scanf("%d",&book[*z].id);

fprintf(fptr,"\n%d",book[*z].id);
printf("enter the name of book:");
fflush(stdin);gets(book[*z].name);
fprintf(fptr,"%s:",book[*z].name);
printf("enter the quantity of books:");scanf("%d",&book[*z].quantity);
fprintf(fptr,"%d",book[*z].quantity);//*z=*z+1;
}fclose(fptr);
}
/////////////////////////////////////////
void del(struct bookdata book[],int *z)
{
int n;int y=*z;
FILE*fptr=fopen("the file.txt","w");
if(fptr!=NULL)
{
printf("enter the id of book that you want to delete:");
scanf("%d",&n);
for(int i=0;i<*z;i++)
{
if(n==book[i].id)
{
for(int j=i;j<y;j++)
{
book[j]=book[j+1];
}
}
}*z=*z-1;
for(int i=0;i<*z;i++)
{
fprintf(fptr,"%d%s:%d",book[i].id,book[i].name,book[i].quantity);
if(i<*z-1)
fprintf(fptr,"\n");
}
}fclose(fptr);
}
////////////////////////////////////
int linearsearch(struct bookdata book[],int z,int i,int n)
{
int counter=0;
if(i<z)
{
if(n==book[i].id)
{
printf("the book is exist\nit's id:%d\n",book[i].id);
printf("it's name:%s\nit's quantity:%d\n",book[i].name,book[i].quantity);
return counter;
}
else
{
counter++;
linearsearch(book,z,i+=1,n);
}
}
}
////////////////////////////////
int binarysearch(struct bookdata b[],int z,int low,int high,char key[],int x)

{
int result;int counter=0;char s2[50];char s3[50];int y,middle;
for(int pass=1;pass<z;pass++)
{
for(int i=0;i<z-pass;i++)
{
result=strcmp(b[i].name,b[i+1].name);
if(result>0)
{
strcpy(s3,b[i].name);
strcpy(b[i].name,b[i+1].name);
strcpy(b[i+1].name,s3);
x=b[i].id;
b[i].id=b[i+1].id;
b[i+1].id=x;
y=b[i].quantity;
b[i].quantity=b[i+1].quantity;
b[i+1].quantity=y;
}
}
}
while(low<=high)
{
middle=(low+high)/2;
if(strcmp(key,b[middle].name)==0){
return middle;counter++;}
else if(strcmp(b[middle].name,key)>0)
high=middle-1;
else
low=middle+1;
}
if(counter==0);
return -1;
}
////////////////////////////////
void sortedbooks(struct bookdata book[],int *z)
{
struct bookdata book2[*z];int result;char s3[50];int x;int y;
for(int i=0;i<*z;i++)

{
book2[i]=book[i];
}
for(int pass=1;pass<*z;pass++)
{
for(int i=0;i<*z-pass;i++)
{
result=strcmp(book2[i].name,book2[i+1].name);
if(result>0)
{
strcpy(s3,book2[i].name);
strcpy(book2[i].name,book2[i+1].name);
strcpy(book2[i+1].name,s3);
x=book2[i].id;
book2[i].id=book2[i+1].id;
book2[i+1].id=x;
y=book2[i].quantity;
book2[i].quantity=book2[i+1].quantity;
book2[i+1].quantity=y;
}
}
}
printf("all sorted books:\n");
for(int i=0;i<*z;i++)
{
printf("id:%d\tname:%s\tquantity:%d\n",book2[i].id,book2[i].name,book2[i].quantity);
}
}
////////////////////////////////////
void printing(struct bookdata book[],int*z)
{
printf("all books :\n");
for(int i=0;i<*z;i++)
{
printf("id:%d\tname:%s\tquantity:%d\n",book[i].id,book[i].name,book[i].quantity);
}
}

