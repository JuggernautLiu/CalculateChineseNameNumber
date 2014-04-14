#pragma once
#include "StdAfx.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ILoadSettings.h"

class TestLoadSettings : public ::testing::Test
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


TEST_F(TestLoadSettings,TEST_LoadSettings_LoadSettings)
{
	LoadSettingsFromINI setting;
	
	string key1 = "MaxofNameNumber";
	string key2 = "MinofNameNumber";
	string expectedvalue1 = "22";
	string expectedvalue2 = "1";

	bool isok = setting.LoadSettings();
	
	EXPECT_EQ(true,isok);
	EXPECT_EQ(expectedvalue1,setting.settings[key1]);
	EXPECT_EQ(expectedvalue2,setting.settings[key2]);
}
