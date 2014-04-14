#pragma once
#include "StdAfx.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "NameProfile.h"

class TestNameProfile : public ::testing::Test
{
protected:
    // Per-test-case set-up.
    // Called before the first test in this test case.
    // Can be omitted if not needed.
    static void SetUpTestCase() {
    }
    // Per-test-case tear-down.
    // Called after the last test in this test case.
    // Can be omitted if not needed.
    static void TearDownTestCase() {
    }

    virtual void SetUp(){
        NameProfile::limit_maxNumber = 22;
        NameProfile::limit_minNumber = 1;
    };
    virtual void TearDown(){        
    };
};

TEST_F(TestNameProfile,LIMIT_Number)
{
    NameProfile nameprofile;
    int expectedlimit_max = 22;
    int expectedlimit_min = 1;

    EXPECT_EQ(expectedlimit_max,NameProfile::limit_maxNumber);
    EXPECT_EQ(expectedlimit_min,NameProfile::limit_minNumber);
    RecordProperty("expectedlimit_max",NameProfile::limit_maxNumber);
    RecordProperty("expectedlimit_min",NameProfile::limit_minNumber);

    int lastnamenum = 15;
    NameProfile nameprofile2(lastnamenum);
    EXPECT_EQ(expectedlimit_max,NameProfile::limit_maxNumber);
    EXPECT_EQ(expectedlimit_max,NameProfile::limit_maxNumber);
}

TEST_F(TestNameProfile,LIMIT_Number_Modify)
{
    NameProfile nameprofile;
    int expectedlimit_max = 25;
    int expectedlimit_min = 2;

    NameProfile::limit_maxNumber = 25;
    NameProfile::limit_minNumber = 2;

    EXPECT_EQ(expectedlimit_max,NameProfile::limit_maxNumber);
    EXPECT_EQ(expectedlimit_max,NameProfile::limit_maxNumber);    
}

TEST_F(TestNameProfile,SETGETNumber)
{
    int expectedLast = 15;
    int expectedName1 = 10;
    int expectedName2 = 6;

    NameProfile nameprofile;
    nameprofile.Set_lastname_num(15);
    nameprofile.Set_name1_num(10);
    nameprofile.Set_name2_num(6);   

    EXPECT_EQ(expectedLast,nameprofile.Get_lastname_num());
    EXPECT_EQ(expectedName1,nameprofile.Get_name1_num());
    EXPECT_EQ(expectedName2,nameprofile.Get_name2_num());

    NameProfile nameprofile2(15);
    nameprofile2.Set_name1_num(10);
    nameprofile2.Set_name2_num(6);

    EXPECT_EQ(expectedLast,nameprofile2.Get_lastname_num());
    EXPECT_EQ(expectedName1,nameprofile2.Get_name1_num());
    EXPECT_EQ(expectedName2,nameprofile2.Get_name2_num());    
}

TEST_F(TestNameProfile,SETGETNumberBoundary)
{
    int expectedLast = 22;
    int expectedName1 = 22;
    int expectedName2 = 1;

    NameProfile nameprofile(23);
    nameprofile.Set_name1_num(23);
    nameprofile.Set_name2_num(0);

    EXPECT_EQ(expectedLast,nameprofile.Get_lastname_num());
    EXPECT_EQ(expectedName1,nameprofile.Get_name1_num());
    EXPECT_EQ(expectedName2,nameprofile.Get_name2_num());
}

TEST_F(TestNameProfile,FinishSetting)
{   
    int expectedsum = 31;

    NameProfile nameprofile(15);
    nameprofile.Set_name1_num(10);
    nameprofile.Set_name2_num(6);

    bool isfinish = nameprofile.FinishSetting();
    int sum = nameprofile.Get_sum_num();
    
    EXPECT_TRUE(isfinish);
    EXPECT_EQ(expectedsum,sum);
}
