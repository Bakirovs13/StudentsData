#include <stdio.h>
#include <stdlib.h>


#define MAX_STUDENTS 100


struct Student{

    int studentID;
    int age;
    float grade;

};

void inputStudentData(struct Student students[], int *numStudents);
void calculateAverageGrade(struct Student students[], int numStudents);
void categorizeStudentsByAge(struct Student students[],int numStudents);
void findBestStudent(struct Student students[],int numStudents);

int main(){

    struct Student students[MAX_STUDENTS];
    int numStudents =0;

    inputStudentData(students,&numStudents);
        printf("-----------------------------");

    calculateAverageGrade(students,numStudents);
        printf("-----------------------------");

    categorizeStudentsByAge(students,numStudents);
        printf("-----------------------------");

    findBestStudent(students,numStudents);



    return 0;
}


void findBestStudent(struct Student students[],int numStudents){
    float maxGrade =-1;
    int bestStudentIndex =-1;

    for(int i =0;i<numStudents;i++){
        if(students[i].grade>maxGrade){
            maxGrade =students[i].grade;
            bestStudentIndex =i;
        }
    }
    printf("The best student : \n");
    printf("Student ID : %d\n ",students[bestStudentIndex].studentID);
    printf("Age : %d\n ",students[bestStudentIndex].age);
    printf("Grade : %d\n",students[bestStudentIndex].grade);
}




void inputStudentData(struct Student students[],int *numStudents){
    printf("the overall number of the students: ");
    scanf("%d", numStudents);

    printf("print data for each student : ");
     for(int i = 0; i< *numStudents ; i++){
        printf("Student %d \n",i+1);
        printf("Student ID: ");
        scanf("%d",&students[i].studentID);
        printf("Student age: \n");
        scanf("%d",&students[i].age);
        printf("Student grade: \n");
        scanf("%d",&students[i].grade);
    }
}

void calculateAverageGrade(struct Student students[], int numStudents){
    float totalGrade =0 ;
    for(int i = 0;i<numStudents; i++){
        totalGrade= totalGrade +students[i].grade;

    }
    float averageGrade = totalGrade/numStudents;
    printf("Average grade of students : %f\n",averageGrade);
}


void categorizeStudentsByAge(struct Student students[],int numStudents){
    int ageCategories[3] = {0};

    for(int i = 0; i<numStudents; i++){
        if(students[i].age >=18 && students[i].age <=25){
            ageCategories[0]++;
        }else if (students[i].age>=26 && students[i].age<=30){
            ageCategories[1]++;
        }else{
            ageCategories[2]++;
        }
    }

    printf("Categorization by age :\n");
    printf("18-25 : %d\n",ageCategories[0]);
    printf("26-30 : %d\n",ageCategories[1]);
    printf("31 and older : %d\n",ageCategories[2]);



}
