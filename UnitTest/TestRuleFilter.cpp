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

    vector<NameProfile> vec;
    bool bfilter = filter.Filter(vec);
    ASSERT_TRUE(bok);
}