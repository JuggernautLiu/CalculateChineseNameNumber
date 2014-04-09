#include "stdafx.h"
#include "TestLoadSettings.h"

using namespace std;

TestLoadSettings::TestLoadSettings(void)
{
}


TestLoadSettings::~TestLoadSettings(void)
{
}

void TestLoadSettings::SetUp()
{
}

void TestLoadSettings::TearDown()
{
}

TEST(TEST_LoadSettings,TEST_LoadSettings_LoadSettings)
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
