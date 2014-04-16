#pragma once
#include "StdAfx.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "IRuleFilter.h"
#include "NameProfile.h"

using namespace std;

class TestRuleFilter : public ::testing::Test
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
    };
    virtual void TearDown(){
    };
};

class TestFilterAllNameNumberForFiveElements : public TestRuleFilter
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
    };
    virtual void TearDown(){
    };
};

class TestFilter81GoodNumber : public TestRuleFilter
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
    };
    virtual void TearDown(){
    };
};

class TestFilterThreeWordsPhase : public TestRuleFilter
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
    };
    virtual void TearDown(){
    };
};

TEST_F(TestFilterAllNameNumberForFiveElements,Initialize)
{
    FilterAllNameNumberForFiveElements filter;
    bool isok = filter.Initialize();
    ASSERT_TRUE(isok);
}

TEST_F(TestFilterAllNameNumberForFiveElements,Filter)
{
    FilterAllNameNumberForFiveElements filter;
    bool bok = filter.Initialize();
    ASSERT_TRUE(bok);

	filter.SetLackOfElement(IRuleFilter::Enum_Elements::Wood);
    vector<NameProfile> profileList;
	// add data
	NameProfile temp1(15);
    temp1.Set_name1_num(10);
	temp1.Set_name2_num(6);
	temp1.FinishSetting();

	NameProfile temp2(10);
	temp2.Set_name1_num(10);
	temp2.Set_name2_num(6);
	temp2.FinishSetting();

	NameProfile temp3(10);
	temp3.Set_name1_num(1);
	temp3.Set_name2_num(10);
	temp3.FinishSetting();

	profileList.push_back(temp1);
	profileList.push_back(temp2);
	profileList.push_back(temp3);
    bool bfilter = filter.Filter(profileList);
    ASSERT_TRUE(bok);

	NameProfile expectedNameProfile(15);
	expectedNameProfile.Set_name1_num(10);
	expectedNameProfile.Set_name2_num(6);
	expectedNameProfile.FinishSetting();

	vector<NameProfile>::iterator it;
	it = find(profileList.begin(),profileList.end(),expectedNameProfile);

	if(it != profileList.end()){
		//found it.
		EXPECT_TRUE(true);
	}
	else{
		// Does not exist.
		EXPECT_TRUE(false);
	}
}

TEST_F(TestFilter81GoodNumber,Filter)
{
	Filter81GoodNumber filter;
    bool bok = filter.Initialize();
    ASSERT_TRUE(bok);
	
    vector<NameProfile> profileList;
	// add data
	NameProfile temp1(15);
    temp1.Set_name1_num(10);
	temp1.Set_name2_num(6);
	temp1.FinishSetting();

	NameProfile temp2(10);
	temp2.Set_name1_num(10);
	temp2.Set_name2_num(6);
	temp2.FinishSetting();

	NameProfile temp3(10);
	temp3.Set_name1_num(3);
	temp3.Set_name2_num(13);
	temp3.FinishSetting();

	profileList.push_back(temp1);
	profileList.push_back(temp2);
	profileList.push_back(temp3);
    bool bfilter = filter.Filter(profileList);
    ASSERT_TRUE(bok);

	NameProfile expectedNameProfile(15);
	expectedNameProfile.Set_name1_num(10);
	expectedNameProfile.Set_name2_num(6);
	expectedNameProfile.FinishSetting();

	vector<NameProfile>::iterator it;
	it = find(profileList.begin(),profileList.end(),expectedNameProfile);

	if(it != profileList.end()){
		//found it.
		EXPECT_TRUE(true);
	}
	else{
		// Does not exist.
		EXPECT_TRUE(false);
	}
}

TEST_F(TestFilterThreeWordsPhase,Filter)
{
	FilterThreeWordsPhase filter;
    bool bok = filter.Initialize();
    ASSERT_TRUE(bok);
	
    vector<NameProfile> profileList;
	// add data
	NameProfile temp1(15);
    temp1.Set_name1_num(10);
	temp1.Set_name2_num(6);
	temp1.FinishSetting();

	NameProfile temp2(10);
	temp2.Set_name1_num(10);
	temp2.Set_name2_num(6);
	temp2.FinishSetting();

	NameProfile temp3(10);
	temp3.Set_name1_num(9);
	temp3.Set_name2_num(2);
	temp3.FinishSetting();

	profileList.push_back(temp1);
	profileList.push_back(temp2);
	profileList.push_back(temp3);
    bool bfilter = filter.Filter(profileList);
    ASSERT_TRUE(bok);

	vector<NameProfile> expectedVec;
	NameProfile expectedNameProfile(15);
	expectedNameProfile.Set_name1_num(10);
	expectedNameProfile.Set_name2_num(6);
	expectedNameProfile.FinishSetting();

	NameProfile expectedNameProfile2(10);
	expectedNameProfile2.Set_name1_num(9);
	expectedNameProfile2.Set_name2_num(2);
	expectedNameProfile2.FinishSetting();

	expectedVec.push_back(expectedNameProfile);
	expectedVec.push_back(expectedNameProfile2);

	vector<NameProfile>::iterator it;
	vector<NameProfile>::iterator expectedIt;
	for(expectedIt = expectedVec.begin() ; expectedIt != expectedVec.end(); ++expectedIt){
		it = find(profileList.begin(),profileList.end(),*expectedIt);
		if(it != profileList.end()){
		    //found it.
		    EXPECT_TRUE(true);
	    }
	    else{
		    // Does not exist.
		    EXPECT_TRUE(false);
	    }
	}	
}