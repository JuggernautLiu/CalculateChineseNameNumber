#include "stdafx.h"
#include "IRuleFilter.h"

FilterAllNameNumberForFiveElements::FilterAllNameNumberForFiveElements()
{
}

FilterAllNameNumberForFiveElements::~FilterAllNameNumberForFiveElements()
{
}

bool FilterAllNameNumberForFiveElements::Initialize()
{
    bool isok = true;
    isInit = isok;
    return isInit;
}

bool FilterAllNameNumberForFiveElements::Filter(vector<NameProfile>& nameprofiles)
{
    bool isok = false;
    try{
        isok = true;
    }
    catch(...){
    }
    return isok;
}

bool FilterAllNameNumberForFiveElements::IsInitialized()
{
    return isInit;
}