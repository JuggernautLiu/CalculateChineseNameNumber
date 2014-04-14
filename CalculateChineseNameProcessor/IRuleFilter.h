#pragma once
#include <vector>
#include "NameProfile.h"

using namespace std;

class IRuleFilter
{
public:
    IRuleFilter(void);
    virtual ~IRuleFilter(void)=0;
    virtual bool Filter(vector<NameProfile>& nameprofiles)=0;
    virtual bool Initialize()=0;
protected:
    virtual bool IsInitialized()=0;    
};

class FilterAllNameNumberForFiveElements : public IRuleFilter
{
public:
    FilterAllNameNumberForFiveElements(void);
    ~FilterAllNameNumberForFiveElements(void);
    bool Filter(vector<NameProfile>& nameprofiles);
    bool Initialize();
    bool IsInitialized();
private:
    bool isInit;
};

class FilterThreeWordsPhase : public IRuleFilter
{
public:
    FilterThreeWordsPhase(void);
    ~FilterThreeWordsPhase(void)=0;
    bool Filter(vector<NameProfile>& nameprofiles);    
    bool Initialize();
    bool IsInitialized();
private:
    bool isInit;
};

class Filter81GoodNumber : public IRuleFilter
{
public:
    Filter81GoodNumber(void);
    ~Filter81GoodNumber(void)=0;
    bool Filter(vector<NameProfile>& nameprofiles);    
    bool Initialize();
    bool IsInitialized();
private:
    bool isInit;
};