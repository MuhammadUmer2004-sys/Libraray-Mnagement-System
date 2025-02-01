
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct date{
	int d;
	int m;
	int y;
};
struct book
{
	char bookid[10];
	char bookname[30];
	char authorname[30];
	char studentname[30];
	char category[30];
	struct date issuedate;
}
bookinfo;
start();
menu();
add();
search();
view();
category();
edit();
issuebook();
removebook();
headMessage(const char* title);

int main()
{
	start();
	menu();
	
}

headMessage(const char* title)
  {
    system("cls");
    char str[]="Library Management System";
    int i;
    printf("\n\n\n\t\t\t");
	for(i=1;i<=75;i++)
	{
    	printf("%c",4);
	}
	printf("\n\t\t\t");
	for(i=1;i<=75;i++)
	{
	 printf("%c",4);
	}
	printf("\n\t    \t\t");
	for(i=1;i<=75;i++)
	{
	 if(i>=1 && i<13)
	 {
		printf("%c",4);
	}
	else if(i>=13 && i<64)
	{
		printf(" ");
	}
	else{
		printf("%c",4);
	  }
	}
    printf("\n\t\t\t");
	for(i=0;i<12;i++)
	{
		printf("%c",4);
	}
	for(i=0;i<12;i++)
	{
		printf("%c",' ');
	}
	printf("Library Managment System");
	for(i=0;i<15;i++)
	{
		printf("%c",' ');
	}
	for(i=0;i<12;i++)
	{
		printf("%c",4);
	}
	printf("\n\t    \t\t");
	for(i=1;i<=75;i++){
	if(i>=1 && i<13){
		printf("%c",4);
	}
	else if(i>=13 && i<64){
		printf(" ");
	}
	else
	{
		printf("%c",4);
	}
	}
	printf("\n\t\t\t");
	for(i=1;i<=75;i++)
	{
	printf("%c",4);
	}
	printf("\n\t\t\t");
	for(i=1;i<151;i++)
	{
	
	if(i>=1 && i<=75)
	{
	printf("=");
	}
	if(i==76)
	{
		printf("\n\t\t\t\t\t\t\t%s \n\t\t\t",title);
	}
	if(i>=76)
	{
		printf("=");
	}
	}
}
start()
{
    headMessage("PF PROJECT");
    int i;
	printf("\n\n\t\t\t");
	for(i=1;i<=75;i++)
	{
	printf("="); 
	}
	printf("\n\t\t\t");
	printf("=");
	printf("\t\t\t\tWELCOME\t\t\t\t\t  =");
	printf("\n\t\t\t");
	printf("=");
	printf("\t\t\t\t  TO\t\t\t\t\t  =");
	printf("\n\t\t\t");
	printf("=");
	printf("\t\t\t\t LIBRARY\t\t\t\t  =");
	printf("\n\t\t\t");
	printf("=");
	printf("\t\t\t\tMANAGMENT\t\t\t\t  =");
	printf("\n\t\t\t");
	printf("=");
	printf("\t\t\t\t SYSTEM\t\t\t\t\t  =");
	printf("\n\t\t\t");
	for(i=1;i<=75;i++)
	 {
	printf("=");
	}
    printf("\n\n\t\t\t Press Enter to continue.....");
    getch();
}

menu()
{
    system("cls");
    printf("********************************MAIN MENU**************************");
    int choice = 0;
    do
	{
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Books");
        printf("\n\t\t\t2.Search Books");
        printf("\n\t\t\t3.View Book List");
        printf("\n\t\t\t4.View Books By Categories");
        printf("\n\t\t\t5.Edit Book");
        printf("\n\t\t\t6.Delete Book");     
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            search();
            break;
        case 3:
            view();
            break;
        case 4:
            category();
            break;    
        case 5:
        	edit();
        	break;
        case 6:
            removebook();
            break;        
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");    
        }                                            
    }
	while(choice!=0);}

//add books in our data base
add()
{
    int i;
	system("cls");
    printf("********************************ADD SECTION**************************");
    FILE *fp;
	fp = fopen("record.bin","ab+");
	if(fp == NULL)
	{
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }		
	headMessage("ADD BOOKS");
	printf("\n\n\t\t\tENTER BOOK DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    
	printf("\n\t\t\tBook ID NO: ");
    fflush(stdin);
    gets(bookinfo.bookid);
    while(1)
    {
    	for(i=0;i<strlen(bookinfo.bookid);i++){
   		if(bookinfo.bookid[i]>='0' && bookinfo.bookid[i]<='9'){
   		 	break;	
		}
   		}
   		if(i<strlen(bookinfo.bookid)){
   		break;	
		}
		else {
			printf("Please Enter book ID in numbers\n ");
			printf("\n\t\t\tBook ID NO: ");
    		gets(bookinfo.bookid);
			fflush(stdin);
			continue;   
		}	
	}
	    
    printf("\n\t\t\tBook Name: ");
    gets(bookinfo.bookname);
	fflush(stdin);    	
	while(1)
    {
    	for(i=0;i<strlen(bookinfo.bookname);i++){
   		if(bookinfo.bookname[i]>='0' && bookinfo.bookname[i]<='9'){
   		 	break;	
		}
   		}
   		if(i<strlen(bookinfo.bookname)){
   			printf("Please Enter book name in only alphabet \n ");
			printf("\n\t\t\tBook name : ");
    		gets(bookinfo.bookname);
			fflush(stdin);	
		}
		else {
			break;   
		}	
	}    
	printf("\n\t\t\tAuthor Name: ");
	gets(bookinfo.authorname);
	fflush(stdin);       
	while(1)
    {
    	for(i=0;i<strlen(bookinfo.authorname);i++){
   		if(bookinfo.authorname[i]>='0' && bookinfo.authorname[i]<='9'){
   		 	break;	
		}
   		}
   		if(i<strlen(bookinfo.authorname)){
   			printf("Please Enter author name in only alphabet \n ");
			printf("\n\t\t\tBook Author Name: ");
    		gets(bookinfo.authorname);
			fflush(stdin);	
		}
		else {
			break;   
		}	
	}
	 
	printf("\n\t\t\tStudent Name: ");
	gets(bookinfo.studentname);
	fflush(stdin);	
	while(1)
    {
    	for(i=0;i<strlen(bookinfo.studentname);i++){
   		if(bookinfo.studentname[i]>='0' && bookinfo.studentname[i]<='9'){
   		 	break;	
		}
   		}
   		if(i<strlen(bookinfo.studentname)){
   			printf("Please Enter Student name in only alphabet \n ");
			printf("\n\t\t\tStudent name: ");
    		gets(bookinfo.studentname);
			fflush(stdin);	
		}
		else {
			break;   
		}	
	}
	
	printf("\n\t\t\tCategory Name: ");
	gets(bookinfo.category);
	fflush(stdin);
	while(1)
	    {
    	for(i=0;i<strlen(bookinfo.category);i++){
   		if(bookinfo.category[i]>='0' && bookinfo.category[i]<='9'){
   		 	break;	
		}
   		}
   		if(i<strlen(bookinfo.category)){
   			printf("Please Enter category name in only alphabet \n ");
			printf("\n\t\t\tcategory name: ");
    		gets(bookinfo.category);
			fflush(stdin);	
		}
		else {
			break;   
		}	
	}
	
	printf("\n\t\t\tEnter date(dd): ");
	scanf("%d",&bookinfo.issuedate.d);
	fflush(stdin);   
    
	printf("\n\t\t\tEnter month(mm): ");
	scanf("%d",&bookinfo.issuedate.m);
	fflush(stdin);
        
	printf("\n\t\t\tEnter year(yyyy): ");
	scanf("%d",&bookinfo.issuedate.y);
	fflush(stdin);
    
	fwrite(&bookinfo, sizeof(bookinfo), 1, fp);	     
    fclose(fp); 	
}

//To find books from library

search()
{
    system("cls");
    printf("********************************SEARCH SECTION**************************");
    int found=1;
    char searchbook[30];
    FILE *fp;
	fp = fopen("record.bin","rb");
    if(fp == NULL){
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    
    headMessage("SEARCH BOOKS");
    
    fflush(stdin);
    printf("\n\n\t\t\tEnter Book Name to search: ");    
    gets(searchbook);
    rewind(fp);
    while(fread(&bookinfo, sizeof(bookinfo), 1, fp)==1)
    {
		if(strcmp(bookinfo.bookname, searchbook)==0)
		
        {
            printf("\n\t\t\tBook ID = %s\n",bookinfo.bookid);
        	printf("\t\t\tBook Name = %s\n",bookinfo.bookname);
        	printf("\t\t\tAuthor Name = %s\n",bookinfo.authorname);
        	printf("\t\t\tStudent Name = %s\n",bookinfo.studentname);
        	printf("\t\t\tCategory = %s\n",bookinfo.category);
        	printf("\t\t\tIssue date(day/month/year) =  %d/%d/%d\n",bookinfo.issuedate.d,
        	bookinfo.issuedate.m, bookinfo.issuedate.y);
        	found = 0;
            break;
        }
    }
     
    if(found==1)
	{
        printf("\n\t\t\tNo Record");
    }
    
    fclose(fp);
    printf("\n\n\n\t\t\tPress Enter to go to main menu.....");
    getchar();	
 }
//View data from data base file
view()
{
    system("cls");
    printf("********************************VIEW SECTION**************************");
	int found = 0;
	int count = 1;
	headMessage("BOOKS DETAILS");
	FILE *fp = fopen("record.bin","rb");
	if(fp == NULL){
     	printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
	rewind(fp);
    while(fread(&bookinfo, sizeof(bookinfo), 1, fp)==1)
    {
        printf("\n\t\t\tBook Count = %d\n\n",count);
        printf("\t\t\tBook ID = %s\n",bookinfo.bookid);
        printf("\t\t\tBook Name = %s\n",bookinfo.bookname);
        printf("\t\t\tAuthor Name = %s\n",bookinfo.authorname);
        printf("\t\t\tStudent Name = %s\n",bookinfo.studentname);
        printf("\t\t\tCategory = %s\n",bookinfo.category);
        printf("\t\t\tIssue date(day/month/year) =  (%d/%d/%d)\n\n",bookinfo.issuedate.d,
        		bookinfo.issuedate.m, bookinfo.issuedate.y);
        found = 1;
        count++;
    }
    fclose(fp);
    if(found==0)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();	
}

//This function work like compartment

category()
{
    system("cls");
    printf("********************************CATEGORY SECTION**************************");
	int found = 0;
	int count = 1;
	char cat[30];
	headMessage("BOOKS DETAILS BY CATEGORY");
	FILE *fp = fopen("record.bin","rb");
	if(fp == NULL){
     	printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    fflush(stdin);
    printf("\n\n\t\t\tEnter category to search: ");    
    gets(cat);
	rewind(fp);
    while(fread(&bookinfo, sizeof(bookinfo), 1, fp)==1)
    {
    	if(strcmp(bookinfo.category, cat)==0)
        {
        printf("\n\t\t\tBook Count = %d\n\n",count);
        printf("\t\t\tBook ID = %d\n",bookinfo.bookid);
        printf("\t\t\tBook Name = %s\n",bookinfo.bookname);
        printf("\t\t\tAuthor Name = %s\n",bookinfo.authorname);
        printf("\t\t\tStudent Name = %s\n",bookinfo.studentname);
        printf("\t\t\tCategory = %s\n",bookinfo.category);
        printf("\t\t\tIssue date(day/month/year) =  (%d/%d/%d)\n\n",bookinfo.issuedate.d,
        		bookinfo.issuedate.m, bookinfo.issuedate.y);
        found = 1;
        count++;
    	}
    }
    fclose(fp);
    if(found==0)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}


//remove books from our library
removebook()
{
    system("cls");
    printf("********************************REMOVE BOOK SECTION**************************");
    int found = 0;
    int deleteid[30];
    char bookName[30] = {0};
    FILE *fp = NULL;
    FILE *fp1 = NULL;
    int status = 0;
    headMessage("Delete Books Details");
    fp = fopen("record.bin","rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fp1 = fopen("recycle.bin","wb");
    if(fp1 == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }
    printf("\n\t\t\tEnter Book ID NO. for delete:");
    scanf("%s",deleteid);
    fflush(stdin);
    
    while(fread(&bookinfo, sizeof(bookinfo), 1, fp))
    {
    	int check=strcmp(bookinfo.bookid,deleteid);
        if(check==0)					
        {
            found = 1;
        }
        else
        {
        	fwrite(&bookinfo,sizeof(bookinfo), 1, fp1);            
        }
    }
    if(found==1)
	{	
        printf("\n\t\t\tRecord deleted successfully.....");
    }
    else
	{
		printf("\n\t\t\tNo Record Found.....");        
    }    
    fclose(fp);
    fclose(fp1);
    remove("record.bin");
    rename("recycle.bin","record.bin");
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    getchar();
}
//Edit file

edit(){
    int found=1,i;
    char editbook[30];
    FILE *fp;
	fp = fopen("record.bin","rb+");
    if(fp == NULL){
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("EDIT BOOKS");
    
    fflush(stdin);
    printf("\n\n\t\t\tEnter Book Name to edit: ");    
    gets(editbook);
    rewind(fp);
    while(fread(&bookinfo, sizeof(bookinfo), 1, fp)==1)
    {
		if(strcmp(bookinfo.bookname, editbook)==0)
        {
        	printf("\t\t\tPrevious Book ID = %s\n",bookinfo.bookid);
        	printf("\t\t\tPrevious Book Name = %s\n",bookinfo.bookname);
        	printf("\t\t\tPrevious Author Name = %s\n",bookinfo.authorname);
        	printf("\t\t\tPrevious Student Name = %s\n",bookinfo.studentname);
        	printf("\t\t\tPrevious Category = %s\n",bookinfo.category);
        	printf("\t\t\tPrevious Issue date(day/month/year) =  (%d/%d/%d)\n\n",bookinfo.issuedate.d,bookinfo.issuedate.m, bookinfo.issuedate.y);
        	printf("\n\t\t\tBook ID NO: ");
    	gets(bookinfo.bookid);
    	fflush(stdin);
    	while(1)
    	{
    		for(i=0;i<strlen(bookinfo.bookid);i++){
   			if(bookinfo.bookid[i]>='0' && bookinfo.bookid[i]<='9'){
   			 	break;	
			}
   			}
   			if(i<strlen(bookinfo.bookid)){
   			break;	
			}
		else {
			printf("Please Enter book ID in numbers\n ");
			printf("\n\t\t\tBook ID NO: ");
    		gets(bookinfo.bookid);
			fflush(stdin);
			continue;   
		}	
		}
		    
    	printf("\n\t\t\tBook Name: ");
    	gets(bookinfo.bookname);
		fflush(stdin);    	
		while(1)
    	{
    		for(i=0;i<strlen(bookinfo.bookname);i++){
   				if(bookinfo.bookname[i]>='0' && bookinfo.bookname[i]<='9'){
   			 	break;	
			}
   			}
   			if(i<strlen(bookinfo.bookname)){
   				printf("Please Enter book name in only alphabet \n ");
				printf("\n\t\t\tBook name : ");
    			gets(bookinfo.bookname);
				fflush(stdin);	
			}
			else {
				break;   
			}	
		}    
		printf("\n\t\t\tAuthor Name: ");
		gets(bookinfo.authorname);
		fflush(stdin);       
		while(1)
   		{
    		for(i=0;i<strlen(bookinfo.authorname);i++){
   			if(bookinfo.authorname[i]>='0' && bookinfo.authorname[i]<='9'){
   		 		break;	
			}
   		}
   		if(i<strlen(bookinfo.authorname)){
   			printf("Please Enter author name in only alphabet \n ");
			printf("\n\t\t\tBook Author Name: ");
    		gets(bookinfo.authorname);
			fflush(stdin);	
		}
		else {
			break;   
		}	
		}
	 
		printf("\n\t\t\tStudent Name: ");
		gets(bookinfo.studentname);
		fflush(stdin);	
		while(1)
    	{
    		for(i=0;i<strlen(bookinfo.studentname);i++){
   			if(bookinfo.studentname[i]>='0' && bookinfo.studentname[i]<='9'){
   			 	break;	
			}
   			}
   			if(i<strlen(bookinfo.studentname)){
   				printf("Please Enter Student name in only alphabet \n ");
				printf("\n\t\t\tStudent name: ");
    			gets(bookinfo.studentname);
				fflush(stdin);	
			}
			else {
				break;   
			}		
		}
	
		printf("\n\t\t\tCategory Name: ");
		gets(bookinfo.category);
		fflush(stdin);
		while(1)
		    {
    		for(i=0;i<strlen(bookinfo.category);i++){
   			if(bookinfo.category[i]>='0' && bookinfo.category[i]<='9'){
   			 	break;	
			}
   			}
   		if(i<strlen(bookinfo.category)){
   			printf("Please Enter category name in only alphabet \n ");
			printf("\n\t\t\tcategory name: ");
    		gets(bookinfo.category);
			fflush(stdin);	
		}
		else {
			break;   
		}	
		}
	
		printf("\n\t\t\tEnter date(dd): ");
		scanf("%d",&bookinfo.issuedate.d);
		fflush(stdin);   
    	
		printf("\n\t\t\tEnter month(mm): ");
		scanf("%d",&bookinfo.issuedate.m);
		fflush(stdin);
        
		printf("\n\t\t\tEnter year(yyyy): ");
		scanf("%d",&bookinfo.issuedate.y);
		fflush(stdin);	
	
		fseek(fp,-sizeof(bookinfo),SEEK_CUR);
		fwrite(&bookinfo,sizeof(bookinfo), 1, fp);
        found = 0;
        break;
        }
    }
    if(found==1){
        printf("\n\t\t\tNo Such Record");
    }
    else
	{
    	printf("Record Edited Successfully.....");
	}
    fclose(fp);
    printf("\n\n\n\t\t\tPress Enter to go to main menu.....");
    getchar();	
}

// IT WAS OUR HONOUR TO PRESENT THIS PROJECT TO YOU IN THE FIRST SEMESTER, THANK YOU FOR MAKING US CAPABLE SO THAT WE CAN DO THIS//



