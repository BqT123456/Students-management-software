

/*
 * Created on Wed Aug 17 2022
 *
 *
 */


#include "main.h"


student_T studentTestData[10];
list_T mainBuffer;
list_T sreachBuffer;

// JUST a Test Function
void init()
{

   studentTestData[0].fullName = "Bich Tuyen";
   studentTestData[1].fullName = "Viet Nga";
   studentTestData[2].fullName = "Thu Trinh";
   studentTestData[3].fullName = "Kim Thoai";
   studentTestData[4].fullName = "Thanh Sang";

   studentTestData[0].cumulativeScore = 32;
   studentTestData[1].cumulativeScore = 133;
   studentTestData[2].cumulativeScore = 24;
   studentTestData[3].cumulativeScore = 234;
   studentTestData[4].cumulativeScore = 4;

   studentTestData[0].homeTown = "Long An";
   studentTestData[1].homeTown = "Hai Phong";
   studentTestData[2].homeTown = "HCM";
   studentTestData[3].homeTown = "Ha Noi";
   studentTestData[4].homeTown = "Bac Can";

   studentTestData[0].department = "[BT].department";
   studentTestData[1].department = "[VN].department";
   studentTestData[2].department = "[TT].department";
   studentTestData[3].department = "[KT].department";
   studentTestData[4].department = "[TS].department";

   studentTestData[0].majors = "[BT].majors";
   studentTestData[1].majors = "[VN].majors";
   studentTestData[2].majors = "[TT].majors";
   studentTestData[3].majors = "[KT].majors";
   studentTestData[4].majors = "[TS].majors";

   studentTestData[0].entryScores = 23;
   studentTestData[1].entryScores = 22;
   studentTestData[2].entryScores = 2;
   studentTestData[3].entryScores = 43;
   studentTestData[4].entryScores = 12;

   studentTestData[0].birthYear = 2003;
   studentTestData[1].birthYear = 1997;
   studentTestData[2].birthYear = 1996;
   studentTestData[3].birthYear = 2005;
   studentTestData[4].birthYear = 2009;

   list_initList(&mainBuffer, 0);
   list_initList(&sreachBuffer, 0);

   for (int i = 0; i <= 4; i++)
   {
      add_addStudentData(&mainBuffer, &studentTestData[i]);
   }
}
student_T temp;

int main()
{
   init();

 // menu_mainMenu(&mainBuffer, &sreachBuffer);
   
 
   /*---------------------Save--------------------*/
   
   file_saveFile(&mainBuffer);
   
   /*---------------------Read--------------------*/
   
   unsigned int u4_totalStudent;
   u4_totalStudent = list_size(&mainBuffer);
   studentInputBuffer_T studentReadBuffer;

   if (0 < u4_totalStudent){
       for (unsigned int index = 0; index < u4_totalStudent; index++) {
           file_read_aStudent(&studentReadBuffer, index);
           temp = input_allocateData(&studentReadBuffer);
           list_pushFront(&mainBuffer, temp);
       }
   }
   else {
       printf("There is no student to read\n");
   }

   return 0;
}

