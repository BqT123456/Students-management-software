//
// Created by pcx on 8/13/2022.
//

#ifndef STUDENTS_MANAGEMENT_SOFTWARE_U_FILEMANIPULATEMODULE_H
#define STUDENTS_MANAGEMENT_SOFTWARE_U_FILEMANIPULATEMODULE_H
#include <stdio.h>
#include "studentsManagementSoftware/u_dataStruct.h"
#include "studentsManagementSoftware/u_dataBufferModule/u_dataBufferModule.h"
#include "studentsManagementSoftware/dataStorage/filePath.h"

void fileM_loadData(list_T *buffer);
void fileM_saveData(list_T *buffer);

void writeStringToFileDat(char *theString);

void saveProp2File(const char* filePath, char* ptr);
void saveFile(list_T* mainBuffer);

//void read_a_Prop(const char* filePath, char* ptr_dst, int skip, int sizeread, int line);
//void read_a_Student(Student rlt[], int k, ARR_SIZE size[], Student student[]);


#endif // STUDENTS_MANAGEMENT_SOFTWARE_U_FILEMANIPULATEMODULE_H
