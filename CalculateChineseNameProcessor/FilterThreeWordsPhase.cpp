#include "stdafx.h"
#include "IRuleFilter.h"

FilterThreeWordsPhase::FilterThreeWordsPhase()
{	
}

FilterThreeWordsPhase::~FilterThreeWordsPhase()
{
}

bool FilterThreeWordsPhase::Initialize()
{    
    isInit = true;
    return isInit;
}

bool FilterThreeWordsPhase::IsInitialized()
{
    return isInit;
}

bool FilterThreeWordsPhase::Filter(vector<NameProfile>& nameprofiles)
{
	bool isok = false;
	vector<NameProfile> Outnameprofiles;
    try{
		vector<NameProfile>::iterator iter = nameprofiles.begin();
		for(iter = nameprofiles.begin(); iter != nameprofiles.end() ; ++iter){
			bool bNeedAdd = false;
			int nsky = 1 + iter->Get_lastname_num();
			int npeople = iter->Get_lastname_num() + iter->Get_name1_num();
			int nearth = iter->Get_name1_num() + iter->Get_name2_num();			
			
			int phasesky = GetPhase((nsky%10));
			int phasepeople = GetPhase((npeople%10));
			int phaseearth = GetPhase((nearth%10));

			bool bsky_people = IsAdjacent(phasesky,phasepeople);
			bool bpeople_earth = IsAdjacent(phasepeople,phaseearth);

			if(true==bsky_people && true==bpeople_earth){							
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

int FilterThreeWordsPhase::GetPhase(int mod)
{
	int nPhase = -1;
	switch(mod)
	{
	    case 1:
	    case 2:
		{
			nPhase = (int)IRuleFilter::Enum_Elements::Wood;
		}
		break;
		case 3:
	    case 4:
		{
			nPhase = (int)IRuleFilter::Enum_Elements::Fire;
		}
		break;
		case 5:
	    case 6:
		{
			nPhase = (int)IRuleFilter::Enum_Elements::Earth;
		}
		break;
		case 7:
	    case 8:
		{
			nPhase = (int)IRuleFilter::Enum_Elements::Gold;
		}
		break;
		case 9:
	    case 0:
		{
			nPhase = (int)IRuleFilter::Enum_Elements::Water;
		}
		break;
	}
	return nPhase;
}

bool FilterThreeWordsPhase::IsAdjacent(int lhs, int rhs)
{
	bool isAdjacent = false;
	int diff = rhs - lhs;
	if((diff>=-1 && diff<=1) || (diff==4 || diff == -4)){
		isAdjacent = true;
	}
	return isAdjacent;
}