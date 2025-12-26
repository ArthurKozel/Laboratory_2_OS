#include "gtest/gtest.h"
#include "../Core/Utilities/utilities.h"

TEST(Threads, Test_threads_creation)
{
    Processes_arguments Mas;
    Mas.ptr = new int[1] {};
    Mas.size = 1;

    HANDLE min_max = NULL;
    HANDLE average = NULL;
    EXPECT_TRUE(Create_Threads(Mas, min_max, average));
    Wait(min_max, average);
    delete[] Mas.ptr;
}

TEST(Threads, Test_Min_max_thread)
{
   Processes_arguments Mas;
   Mas.ptr = new int[5]{1, -4, 9, 0, -11};
   Mas.size = 5; 
   max_value = 0;
   min_value = 0;

   Min_max((LPVOID)&Mas);
   EXPECT_EQ(max_value, 9); 
   EXPECT_EQ(min_value, -11);  
   delete[] Mas.ptr;
}

TEST(Threads, Test_Average_thread)
{
    Processes_arguments Mas;
    Mas.ptr = new int[5] {1, -4, 9, 0, -11};
    Mas.size = 5;
    average_value = 0;

    Average((LPVOID)&Mas);
    EXPECT_EQ(average_value, -1);
    delete[] Mas.ptr;
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}