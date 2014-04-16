#include "stdafx.h"
#include "IRuleFilter.h"

FilterAllNameNumberForFiveElements::FilterAllNameNumberForFiveElements()
{
	modNumber1 = -1;
	modNumber2 = -1;
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
	vector<NameProfile> Outnameprofiles;
    try{
		vector<NameProfile>::iterator iter;
		for(iter = nameprofiles.begin(); iter != nameprofiles.end() ; ++iter){			
			int mod = (iter->Get_sum_num()) % 10;
			if((modNumber1 == mod) || (modNumber2 == mod)){
				// Add to new vector				
				Outnameprofiles.push_back(*iter);
			}			
		}
		nameprofiles.clear();
		nameprofiles = Outnameprofiles;
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

void FilterAllNameNumberForFiveElements::SetLackOfElement(int element)
{
	lackofelement = element;
	switch(element)
	{
	    case IRuleFilter::Enum_Elements::Wood:
		{
			modNumber1 = 1;
			modNumber2 = 2;
		}
		break;
		case IRuleFilter::Enum_Elements::Fire:
		{
			modNumber1 = 3;
			modNumber2 = 4;
		}
		break;
		case IRuleFilter::Enum_Elements::Earth:
		{
			modNumber1 = 5;
			modNumber2 = 6;
		}
		break;
		case IRuleFilter::Enum_Elements::Gold:
		{
			modNumber1 = 7;
			modNumber2 = 8;
		}
		break;
		case IRuleFilter::Enum_Elements::Water:
		{
			modNumber1 = 9;
			modNumber2 = 0;
		}
		break;
		default:
			break;
	}
}