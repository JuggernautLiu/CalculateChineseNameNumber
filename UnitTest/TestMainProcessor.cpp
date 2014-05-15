#pragma once
#include "StdAfx.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MainProcessor.h"

using namespace std;
class TestMainProcessor : public ::testing::Test
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

TEST_F(TestMainProcessor,RUN)
{
	MainProcessor processor;
	vector<NameProfile> nameprofiles;
	int lastname = 7;
	int lackelement = IRuleFilter::Enum_Elements::Water;
	processor.Run(nameprofiles,lastname,lackelement);

	NameProfile expectedNameProfile(15);
	expectedNameProfile.Set_name1_num(10);
	expectedNameProfile.Set_name2_num(6);
	expectedNameProfile.FinishSetting();

	vector<NameProfile>::iterator it;
	it = find(nameprofiles.begin(),nameprofiles.end(),expectedNameProfile);

	if(it != nameprofiles.end()){
		//found it.
		EXPECT_TRUE(true);
	}
	else{
		// Does not exist.
		EXPECT_TRUE(false);
	}

}