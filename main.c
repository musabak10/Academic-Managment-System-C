#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
 char courseName[50];
 char courseCode[10];
 int credit;
 int midtermGrade;
 int finalGrade;
 float average;
} Course;
typedef struct {
 char name[50];
 int studentNo;
 Course *courses; 
 int courseCount; 
 float overallAverage;
} Student;
void initStudent(Student *stu, char *name, int no);
void addCourse(Student *stu, char *name, char *code, int credit); 
void deleteCourse(Student *stu, char *code);
void freeSystem(Student *stu); 
void enterGrades(Student *stu, char *code, int midterm, int final);
void calculateOverallAverage(Student *stu); 
void updateCourse(Student *stu, char *code, char *newName, int newCredit);
int searchCourse(Student *stu, char *code);
void findHighestGradeCourse(Student stu); 
void listFailedCourses(Student stu); 
void printReportCard(Student stu);
void creditLoadReport(Student stu);
void sortCoursesAlphabebetically(Student *stu);
void updateStudentInfo(Student *stu, char *newName, int newNo);
void copyCourses(Student *target, Student source); 
int findStudent(Student *stu,char *name,int n);
int main(){
    int choice,exit,st,i,credit,midterm,final,index,indexsource,no;
    char name[50],code[10];
    Student *stu;
    exit=0;
	printf("\n");
    printf("********************************************************\n");
    printf("*                                                      *\n");
    printf("*                                                      *\n");
    printf("*            YILDIZ TECHNICAL UNIVERSITY               *\n");
    printf("*                                                      *\n"); 
    printf("*                                                      *\n");
    printf("*            Academic Management System                *\n");
    printf("*                                                      *\n");
    printf("*                                                      *\n");
    printf("*               Welcome to the System                  *\n");
    printf("*                                                      *\n");
    printf("********************************************************\n");
    printf("\n\n\n\n");
    printf("HOW MANY STUDENTS WOULD YOU LIKE TO IDENTIFY?\n");
    printf("YOUR ANSWER:");
    scanf("%d",&st);
    stu=(Student*)malloc(sizeof(Student)*st);
	if(stu==NULL){
		printf("MEMORY ALLOCATION FAILED");
		exit=1;
	}
	while(exit==0){
    printf("?WHAT DO YOU WANT TO DO?\n");
    printf("\n0:EXIT");
	printf("\n1:ADD STUDENT");
    printf("\n2:ADD COURSE");
    printf("\n3:DELETE COURSE");
    printf("\n4:ENTER GRADES");
    printf("\n5:CALCULATE OVERALL AVERAGE");
    printf("\n6:UPDATE COURSE");
    printf("\n7:SEARCH COURSE");
    printf("\n8:COURSE WITH HIGHEST GRADE");
    printf("\n9:LIST FAILED COURSES");
    printf("\n10:PRINT REPORT CARD");
    printf("\n11:TOTAL CREDIT LOAD");
    printf("\n12:SORT COURSES ALPHABETICALLY");
    printf("\n13:UPDATE STUDENT INFO");
    printf("\n14:COPY COURSES TO ANOTHER STUDENT\n");
    printf("\n------YOUR CHOICE:");
	scanf("%d",&choice);
	if(choice==0){
		exit=1;
		for(i=0;i<st;i++){
			freeSystem((stu+i));
		}
		free(stu);
	}else if(choice==1){
		for(i=0;i<st;i++){
			printf("\nNAME:");
			scanf(" %[^\n]",name);
			
			printf("\nNO:");
			scanf("%d",&no);
			initStudent((stu+i),name,no);
		}
	}else if(choice==2){
            printf("\nSTUDENT'S NAME:");
		    scanf(" %[^\n]", name);
		    index=findStudent(stu,name,st);
		    if(index==-1){
		    	printf("\nSTUDENT CAN NOT FOUND");
			}else{
			printf("\nCOURSE NAME:\n");
			scanf(" %[^\n]", name);
			printf("\nCODE:");
		    scanf(" %[^\n]",code);
		    printf("\nCREDIT:");
		    scanf("%d",&credit);
			addCourse((stu+index),name,code,credit); 
			}
	
	}else if(choice==3){
		printf("\nSTUDENT'S NAME:");
		scanf(" %[^\n]", name);
		index=findStudent(stu,name,st);
		if(index==-1){
		    printf("STUDENT CAN NOT FOUND");
		}else{
            printf("\nCODE:");
		    scanf(" %[^\n]",code);
		    deleteCourse((stu+index),code);
		}

	}else if(choice==4){
		printf("\nSTUDENT'S NAME:");
		scanf(" %[^\n]", name);
		index=findStudent(stu,name,st);
		if(index==-1){
		    printf("STUDENT CAN NOT FOUND");
		}else{
            printf("\nCODE:");
	        scanf(" %[^\n]",code);
		    printf("\nMIDTERM:");
	        scanf("%d",&midterm);
	        printf("\nFINAL:");
	        scanf("%d",&final);
		    enterGrades((stu+index),code,midterm,final);
		}

  	}else if(choice==5){
		for(i=0;i<st;i++){
			calculateOverallAverage((stu+i));
		}
	}else if(choice==6){
		printf("\nSTUDENT'S NAME:");
		scanf(" %[^\n]", name);
		index=findStudent(stu,name,st);
		if(index==-1){
		    printf("STUDENT CAN NOT FOUND");
		}else{
		printf("\nCODE:");
	    scanf(" %[^\n]",code);
	    printf("\nNEW NAME:");
	    scanf(" %[^\n]", name);
	    printf("\nNEW CREDIT:");
	    scanf("%d",&credit);
		updateCourse((stu+index),code,name,credit);
		}
    }else if(choice==7){
		printf("\nSTUDENT'S NAME:");
		scanf(" %[^\n]", name);
		index=findStudent(stu,name,st);
		if(index==-1){
		    printf("STUDENT CAN NOT FOUND");
		}else{
            printf("\nCODE:");
	        scanf(" %[^\n]",code);
		    index=searchCourse((stu+index),code);
		    printf("\nCOURSE'S INDEX:%d\n",index);
		}
    }else if(choice==8){
		printf("\nSTUDENT'S NAME:");
		scanf(" %[^\n]", name);
		index=findStudent(stu,name,st);
		if(index==-1){
		    printf("STUDENT CAN NOT FOUND");
		}else{
           	findHighestGradeCourse(stu[index]);
		}

	}else if(choice==9){
		printf("\nSTUDENT'S NAME:");
		scanf(" %[^\n]", name);
		index=findStudent(stu,name,st);
		if(index==-1){
		    printf("STUDENT CAN NOT FOUND");
		}else{
            listFailedCourses(stu[index]);
		}
	}else if(choice==10){
		printf("\nSTUDENT'S NAME:");
		scanf(" %[^\n]", name);
		index=findStudent(stu,name,st);
		if(index==-1){
		   	printf("STUDENT CAN NOT FOUND");
		}else{
           	printReportCard(stu[index]);
		}
	}else if(choice==11){
		printf("\nSTUDENT'S NAME:");
		scanf(" %[^\n]", name);
		index=findStudent(stu,name,st);
			if(index==-1){
		    	printf("STUDENT CAN NOT FOUND");
			}else{
                creditLoadReport(stu[index]);
			}

	}else if(choice==12){
		printf("\nSTUDENT'S NAME:");
		scanf(" %[^\n]", name);
		index=findStudent(stu,name,st);
		if(index==-1){
		    printf("STUDENT CAN NOT FOUND");
		}else{
            sortCoursesAlphabetically((stu+index));
			}	
	}else if(choice==13){
		printf("\nSTUDENT'S NAME:");
		scanf(" %[^\n]", name);
		index=findStudent(stu,name,st);
		if(index==-1){
		    printf("STUDENT CAN NOT FOUND");
		}else{
       	printf("\nNEW NAME:");
		scanf(" %[^\n]", name);
		printf("\nNEW NO:");
		scanf("%d",&no);
		updateStudentInfo((stu+index),name,no);
		}
	}else if(choice==14){
		printf("\nTARGET STUDENT'S NAME:");
		scanf(" %[^\n]", name);
		index=findStudent(stu,name,st);
		if(index==-1){
		    printf("STUDENT CAN NOT FOUND");
		}else{
        printf("\nSOURCE STUDENT'S NAME:");
		scanf(" %[^\n]", name);
		indexsource=findStudent(stu,name,st);
		copyCourses((stu+index),stu[indexsource]);
		}

	}
    
	}
    return 0;
}
void initStudent(Student *stu, char *name, int no){
	stu->studentNo=no;
	strcpy(stu->name,name);
	stu->courses=NULL;
	stu->courseCount=0;
	stu->overallAverage = 0;
}
void addCourse(Student *stu, char *name, char *code, int credit){
	stu->courseCount++;
	Course *temp=realloc(stu->courses,sizeof(Course)*stu->courseCount);
	if (temp != NULL) {
    stu->courses = temp;
    strcpy(stu->courses[stu->courseCount-1].courseName,name);
	strcpy(stu->courses[stu->courseCount-1].courseCode,code);
	stu->courses[stu->courseCount-1].credit=credit;
    } else {
    printf("Memory allocation failed!\n");
	}
}
void deleteCourse(Student *stu, char *code){
	int i,delete;
	delete=-1;
	for(i=0;i<stu->courseCount;i++){
		if(!strcmp(stu->courses[i].courseCode,code)){
			delete=i;
		}
	}
    if(delete==-1){
    	printf("\nCourse Not Found\n");
	}else{
		for(i=delete;i<stu->courseCount-1;i++){
		stu->courses[i]=stu->courses[i+1];
	}
    stu->courseCount--;
    if (stu->courseCount == 0) {
            free(stu->courses);
            stu->courses = NULL; 
    }else{
   	Course *temp=realloc(stu->courses,sizeof(Course)*stu->courseCount);
	if (temp != NULL){
		stu->courses=temp;
	}else {
    printf("\nMemory allocation failed!\n");
	}
   	}
	}
}

void freeSystem(Student *stu){
	free(stu->courses);
}
void enterGrades(Student *stu, char *code, int midterm, int final){
	int i;
	for(i=0;i<stu->courseCount;i++){
		if(!strcmp(stu->courses[i].courseCode,code)){
		   stu->courses[i].midtermGrade=midterm;
		   stu->courses[i].finalGrade=final;
		   stu->courses[i].average=(float)(midterm*0.4)+(float)(final*0.6);
		}
	}
}
void calculateOverallAverage(Student *stu){
	int i,totalCredit,sum;
	totalCredit=0;
	sum=0;
	for(i=0;i<stu->courseCount;i++){
		sum+=(float)(stu->courses[i].average*stu->courses[i].credit);
		totalCredit+=stu->courses[i].credit;
	}
	if(totalCredit > 0){
		stu->overallAverage = (float)sum / (float)totalCredit;
	}else{
		stu->overallAverage = 0;
	}
        
	
}
void updateCourse(Student *stu, char *code, char *newName, int newCredit){
	int i,index;
	index=-1;
	for(i=0;i<stu->courseCount;i++){
		if(!strcmp(stu->courses[i].courseCode,code)){
			index=i;
		}
	}
	if(index==-1){
		printf("\nCOURSE COULD NOT BE FOUND!!!\n");
	}else{
	    strcpy(stu->courses[index].courseName,newName);
		stu->courses[index].credit=newCredit;	
	}
	calculateOverallAverage(stu);
}
int searchCourse(Student *stu, char *code){
	int i,index;
	index=-1;
	for(i=0;i<stu->courseCount;i++){
		if(!strcmp(stu->courses[i].courseCode,code)){
			index=i;
		}		
	}
	return index;
}
void findHighestGradeCourse(Student stu){
	int i,index;
	float max;
	max=-1;
	index=-1;
	for(i=0;i<stu.courseCount;i++){
		if(stu.courses[i].average>max){
			max=stu.courses[i].average;
			index=i;
		}
	}
	printf("\nCOURSE FOUND AT INDEX:%d",index);
	printf("\nHIGHEST GRADE COURSE:%s\n",stu.courses[index].courseName);
	printf("\nCOURSE AVERAGE:%.2f\nMIDTERM:%d\nFINAL:%d\n",stu.courses[index].average,stu.courses[index].midtermGrade,stu.courses[index].finalGrade);
}
void listFailedCourses(Student stu){
	int i;
	printf("\nFAILED COURSES:\n ");
	for(i=0;i<stu.courseCount;i++){
		if(stu.courses[i].average<50){
		   printf("\n%s--%s\n",stu.courses[i].courseCode,stu.courses[i].courseName);
		}
	}
}
void printReportCard(Student stu){
	int i;
	calculateOverallAverage(&stu);
	printf("\nStudent Name:%s\n",stu.name);
	printf("\nStudent No:%d\n",stu.studentNo);
	printf("\nCourses:\n");
	for(i=0;i<stu.courseCount;i++){
		printf("-----------------------------------------------------------------");
		printf("\nCourse Name:%s\nCode:%s\nCredit:%d\nMidterm:%d\nFinal:%d\nAverage:%f\n",stu.courses[i].courseName,stu.courses[i].courseCode,stu.courses[i].credit,stu.courses[i].midtermGrade,stu.courses[i].finalGrade,stu.courses[i].average);
       	}
    printf("-----------------------------------------------------------------");
    printf("\nOverall Average:%f\n",stu.overallAverage);
    printf("\nCourse Count:%d\n",stu.courseCount);
}
void creditLoadReport(Student stu){
	int i,total;
	total=0;
	for(i=0;i<stu.courseCount;i++){
	    total=stu.courses[i].credit+total;	
	}
	printf("\nTotal Credit:%d",total);
}
void sortCoursesAlphabetically(Student *stu){
	int i,j;
	Course temp;
	for(i = 0; i < stu->courseCount - 1; i++)
    {
        for(j = i + 1; j < stu->courseCount; j++)
        {
            if(strcmp(stu->courses[i].courseName,
                      stu->courses[j].courseName) > 0)
            {
                Course temp = stu->courses[i];
                stu->courses[i] = stu->courses[j];
                stu->courses[j] = temp;
            }
        }
    }
}
void updateStudentInfo(Student *stu, char *newName, int newNo){
	stu->studentNo=newNo;
	strcpy(stu->name,newName);
}
void copyCourses(Student *target, Student source){
	int i;
	Course *temp=malloc(sizeof(Course)*source.courseCount);
	if(temp!=NULL){
		target->courses=temp;
	for(i = 0; i < source.courseCount; i++){
    target->courses[i] = source.courses[i];
	}
	target->courseCount = source.courseCount;
	}else{
		printf("\nMemory allocation failed!\n");
	}
}
int findStudent(Student *stu,char *name,int n){
	int i,index;
	index=-1;
	for(i=0;i<n;i++){
		if(!strcmp(stu[i].name,name)){
			index=i;
		}
	}
	return index;
}










