//
// Created by pcx on 8/13/2022.
//

#include "u_fileManipulateModule.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "studentsManagementSoftware/dataStorage/filePath.h"
#include "u_fileManipulateModule.h"
#include "studentsManagementSoftware/u_dataBufferModule/u_dataBufferModule.h"

#define ARR_MAX 30

typedef struct {
	char temp[10];
}Temp;

void file_saveProp2File(const char* filePath, char* ptr_src) {

	FILE* fp = fopen(filePath, "a");
	char temp[30];

	memset(temp, '\0', ARR_MAX);
	strcpy(temp, ptr_src);
	strcat(temp, "\n");

	if (NULL != fp) {
		fputs(temp, fp);
		fclose(fp);
	}
}
/*brief: save ONE property to a file
*para  : (const char *filePath) choosing which property to be saved ( Path name in saveFile() )
*para  : (char *ptr_src) pointer to property
*NOTE  : this function used in saveFile()
*NOTE  : this function write "\n" separately ( Ex: string "ABC" is written, this function
*        write '\n' to file, our string is NOT "ABC\n" )
*/
void Student_refreshArr(Temp Arr[]) {
	for (unsigned int index = 0; index < ARR_MAX; index++) {
		memset(Arr[index], '\0', ARR_MAX);
	}
}
/*brief: Clear garbage value in Student Array
*para  : (Student Arr[]) array of type Student
*/
void file_saveFile(list_T* mainBuffer) {

	unsigned int u4_totalStudent;
	u4_totalStudent = list_size(mainBuffer);
	Temp tempArr[ARR_MAX];
	if (0<u4_totalStudent) {
		/*-----------------------Name--------------------------*/
		remove(filePath_name);
		for (unsigned int index = 0; index < u4_totalStudent; index++) {
			file_saveProp2File(filePath_name, list_goToPos(mainBuffer, index)->data.fullName);
		}
		/*--------------------Year-of-birth---------------------*/
		Student_refreshArr(tempArr);
		for (unsigned int index = 0; index < u4_totalStudent; index++) {
			sprintf(tempArr[index].temp, "%d", list_goToPos(mainBuffer, index)->data.birthYear);
		}

		remove(filePath_yob);
		for (unsigned int index = 0; index < u4_totalStudent; index++) {
			file_saveProp2File(filePath_yob, tempArr[index].temp);
		}
		/*-----------------------Home-town-----------------------*/
		remove(filePath_pob);
		for (unsigned int index = 0; index < u4_totalStudent; index++) {
			file_saveProp2File(filePath_pob, list_goToPos(mainBuffer, index)->data.homeTown);
		}
		/*-------------------------Majors-------------------------*/
		remove(filePath_faculty);
		for (unsigned int index = 0; index < u4_totalStudent; index++) {
			file_saveProp2File(filePath_faculty, list_goToPos(mainBuffer, index)->data.majors);
		}
		/*------------------------Department----------------------*/
		remove(filePath_department);
		for (unsigned int index = 0; index < u4_totalStudent; index++) {
			file_saveProp2File(filePath_department, list_goToPos(mainBuffer, index)->data.department);
		}
		/*--------------------Entrance-Score-----------------------*/
		Student_refreshArr(tempArr);
		for (unsigned int index = 0; index < u4_totalStudent; index++) {
			sprintf(tempArr[index].temp, "%d", list_goToPos(mainBuffer, index)->data.entryScores);
		}

		remove(filePath_entrance_s);
		for (unsigned int index = 0; index < u4_totalStudent; index++) {
			file_saveProp2File(filePath_entrance_s, tempArr[index].temp);
		}
		/*-------------------------GPA--------------------------*/
		Student_refreshArr(tempArr);
		for (unsigned int index = 0; index < u4_totalStudent; index++) {
			sprintf(tempArr[index].temp, "%d", list_goToPos(mainBuffer, index)->data.cumulativeScore);
		}

		remove(filePath_gpa);
		for (unsigned int index = 0; index < u4_totalStudent; index++) {
			file_saveProp2File(filePath_gpa, tempArr[index].temp);
		}
	}
	else {
		printf("There is no student to save\n");
	}
}
/*brief: Using this function to write all struct array Student to file
*para  : (list_T* mainBuffer) Buffer to get data to save
*note  : number of students CHECKED
*/
void file_read_aProp(const char* filePath, char* ptr_dst, unsigned int u4_index) {
	int line = 0;
	int sizeread = 0;
	int skip = 0;
	int flag = 0;
	FILE* fp = fopen(filePath, "r");
	if (NULL != fp) {
		while (line < u4_index) {
			char c = fgetc(fp);
			if (c < -1) {
				continue;
			}
			else {
				if ('\n' != c) {
					skip++;
				}
				else {
					line++;
				}
			}
		}
		while (0 == flag) {
			char c = fgetc(fp);

			if ('\n' == c) {
				flag = 1;
			}
			else {
				sizeread++;
//				printf("|%c|, %d\n", c, sizeread);
			}
		}

		fseek(fp, (skip + u4_index * 2), SEEK_SET);
		fread(ptr_dst, sizeread, 1, fp);
		*(ptr_dst + sizeread) = '\0';
		fclose(fp);
	}
}
/*brief: Read a property in Student struct
*para  : (const char *filePath) choosing which Property to be saved ( Path name in read_a_Student() )
*para  : (char *ptr_dst) pointer to the Property to be read
*para  : (unsigned int u4_index) index in each Property array 
*NOTE  : this function used in read_aStudent()
*/
void file_read_aStudent(studentInputBuffer_T *studentReadBuffer, unsigned int u4_index) {
	char temp[ARR_MAX];
	/*-----------------------Name---------------------------*/

	file_read_aProp(filePath_name, studentReadBuffer->fullName, u4_index);
	printf("%s\n", studentReadBuffer->fullName);
	/*--------------------Year-of-birth----------------------*/

	memset(temp, '\0', ARR_MAX);
	file_read_aProp(filePath_yob, temp, u4_index);
	studentReadBuffer->birthYear = atoi(temp);
	printf("%d\n", studentReadBuffer->birthYear);
	/*-----------------------Home-town------------------------*/

	file_read_aProp(filePath_pob, studentReadBuffer->homeTown, u4_index);
	printf("%s\n", studentReadBuffer->homeTown);
	/*-------------------------Majors-------------------------*/

	file_read_aProp(filePath_faculty, studentReadBuffer->majors, u4_index);
	printf("%s\n", studentReadBuffer->majors);
	/*------------------------Department----------------------*/

	file_read_aProp(filePath_department, studentReadBuffer->department, u4_index);
	printf("%s\n", studentReadBuffer->department);
	/*--------------------Entrance-Score-----------------------*/

	memset(temp, '\0', ARR_MAX);
	file_read_aProp(filePath_entrance_s, temp,u4_index);
	studentReadBuffer->entryScores = atoi(temp);
	printf("%d\n", studentReadBuffer->entryScores);
	/*----------------------------GPA---------------------------*/
	memset(temp, '\0', ARR_MAX);
	file_read_aProp(filePath_gpa, temp, u4_index);
	studentReadBuffer->cumulativeScore = atoi(temp);
	printf("%d\n", studentReadBuffer->cumulativeScore);

}
/*brief: Read a Student with full Properties
*para  : (studentInputBuffer_T *studentReadBuffer) passing a result array to get the read data at u4_index-th position
*para  : (unsigned int u4_index) read u4_index-th element in Student array
*NOTE  : HAS NOT included number of students checking
*NOTE  : Should check number of students BEFORE using this function
*/
