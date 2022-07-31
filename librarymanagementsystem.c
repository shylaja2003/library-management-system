#include<stdio.h>
#include<string.h>
void scanbookdetail();
void view_all_books_library();
void add_book_details();
void search_book();
void search_book_by_name();
int k,c,i,na,bn,an,g,flag=0;
struct details{
char bookname[100];
char authorname[100];
int bookcode;
char forbranch[100];
int noofbooks;
}r;
FILE *shy;
main()
{
do
{
printf("\n*LIBRARY MANAGEMENT SYSTEM*\n");
printf("\n1.scanbookdetail\n");
printf("\n2.view book details\n");
printf("\n3.add book details\n");
printf("\n4.search book\n");
printf("\n5.search book by name\n");
printf("\n0.EXIT\n");
printf("\nenter your option:");
scanf("%d",&c);
switch(c)
{
case 1:scanbookdetail();
break;
case 2:view_all_books_library();
break;
case 3:add_book_details();
break;
case 4:search_book();
break;
case 5:search_book_by_name();
break;
default:
printf("\n***INVALID OPTION,PLEASE ENTER RIGHT OPTION\n");
}
printf("\nenter 9 to continue");
scanf("%d",&k);
}while(k==9);
}
void scanbookdetail()
{
shy=fopen("books.txt","r");
printf("\nbook name\tauthor name\tbook code\tfor branch\t noof books\n");
while(fscanf(shy,"\n%s%s%d%s%d",r.bookname,r.authorname,&r.bookcode,r.forbranch,&r.noofbooks)!=EOF);
fprintf(stdout,"\n%s\t\t%s\t\t%d\t\t%s\t\t%d",r.bookname,r.authorname,r.bookcode,r.forbranch,r.noofbooks);
fclose(shy);
}
void view_all_books_library()
{
shy=fopen("books.txt","r");
printf("\nbook name\tauthor name\tbook code\tfor branch\t noof books\n");
while(fscanf(shy,"%s%s%d%s%d",r.bookname,r.authorname,&r.bookcode,r.forbranch,&r.noofbooks)!=EOF)
{
printf("\n");
fprintf(stdout,"\n%s\t\t%s\t\t%d\t\t%s\t\t%d",r.bookname,r.authorname,r.bookcode,r.forbranch,r.noofbooks);
}
fclose(shy);
}
void add_book_details()
{
FILE *shy;
shy=fopen("books.txt","a");
printf("\nbook name\tauthor name\tbook code\tfor branch\tno of books\n");
fscanf(stdin,"\n%s%s%d%s%d",r.bookname,r.authorname,&r.bookcode,r.forbranch,&r.noofbooks);
fprintf(shy,"\n%s %s %d %s %d",r.bookname,r.authorname,r.bookcode,r.forbranch,r.noofbooks);
fclose(shy);
}
void search_book()
{
shy=fopen("books.txt","r");
printf("\nenter book code to search");
scanf("%d",&g);
while(fscanf(shy,"%s%s%d%s%d",r.bookname,r.authorname,&r.bookcode,r.forbranch,&r.noofbooks)!=EOF)
{
if(g==r.bookcode)
{
printf("\n%s %s %d %s %d",r.bookname,r.authorname,r.bookcode,r.forbranch,r.noofbooks);
flag=1;
break;
}
 }
if(flag==1)
{
printf("\nrecord found");
}
else
{
printf("\nrecord not found");
}
fclose(shy);
}
void search_book_by_name()
{
char an[20];
int flag=0,x;
shy=fopen("books.txt","r");
printf("\nenter author name\n");
scanf("%s",an);
// strcmp(an,r.authorname)
while(fscanf(shy,"%s%s%d%s%d",r.bookname,r.authorname,&r.bookcode,r.forbranch,&r.noofbooks)!=EOF)
{
x=strcmp(an,r.authorname);
if(x==0)
{
printf("\n%s %s %d %s %d",r.bookname,r.authorname,r.bookcode,r.forbranch,r.noofbooks);
flag=1;
break;
}
 }
if(flag==1)
{
	
printf("\nrecord found");
}
else
{
printf("\nrecord not found");
}
fclose(shy);
}
