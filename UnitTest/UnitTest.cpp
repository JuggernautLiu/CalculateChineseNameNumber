// UnitTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"


int _tmain(int argc, _TCHAR* argv[])
{
	::testing::FLAGS_gtest_output = "xml:"; // output to xml
	::testing::InitGoogleTest(&argc, argv);
    int Ret = RUN_ALL_TESTS();
    return Ret;
}

