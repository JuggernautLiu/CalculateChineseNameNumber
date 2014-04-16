#pragma once
#include <vector>
#include "NameProfile.h"

using namespace std;

class IRuleFilter
{
public:
	enum Enum_Elements
	{
		Wood=0,
		Fire=1,
		Earth=2,
		Gold=3,
		Water=4
	};
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
	void SetLackOfElement(int element);
private:
    bool isInit;
	int lackofelement;
	int modNumber1;
	int modNumber2;
};

class FilterThreeWordsPhase : public IRuleFilter
{
public:
    FilterThreeWordsPhase(void);
    ~FilterThreeWordsPhase(void);
    bool Filter(vector<NameProfile>& nameprofiles);    
    bool Initialize();
    bool IsInitialized();
private:
    bool isInit;
	int GetPhase(int mod);
	bool IsAdjacent(int lhs, int rhs);
};

class Filter81GoodNumber : public IRuleFilter
{
public:
    Filter81GoodNumber(void);
    ~Filter81GoodNumber(void);
    bool Filter(vector<NameProfile>& nameprofiles);    
    bool Initialize();
    bool IsInitialized();
private:
    bool isInit;
	vector<int> good81Numbers;
	bool CreateGood81Numbers();
};