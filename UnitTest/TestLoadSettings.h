#pragma once
#include "gtest/gtest.h"
#include "ILoadSettings.h"

class TestLoadSettings : public ::testing::Test
{
public:
	TestLoadSettings(void);
	virtual ~TestLoadSettings(void);
	virtual void SetUp();
	virtual void TearDown();
};

