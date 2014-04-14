#pragma once
#include "StdAfx.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "IDataProducer.h"
#include "NameProfile.h"

using namespace std;
class TestDataProducer : public ::testing::Test
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

class TestDataProducerByCount : public TestDataProducer
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

TEST_F(TestDataProducerByCount,ProduceNameProfiles)
{
    DataProducerByCount producer;
    NameProfileCfg cfg;
    cfg.lastname_num = 15;
    cfg.limit_maxNumber = 5;
    cfg.limit_minNumber = 1;
    producer.SetNameProfileCfg(cfg);
    
    vector<NameProfile> vec;
    bool isok = producer.ProduceNameProfiles(vec);
    ASSERT_TRUE(isok);

    int expectvec_count = 25;
    EXPECT_EQ(expectvec_count,vec.size());
}