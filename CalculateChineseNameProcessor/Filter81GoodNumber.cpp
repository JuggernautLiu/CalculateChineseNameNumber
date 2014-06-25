#include "stdafx.h"
#include "IRuleFilter.h"

Filter81GoodNumber::Filter81GoodNumber()
{	
}

Filter81GoodNumber::~Filter81GoodNumber()
{
}

bool Filter81GoodNumber::Initialize()
{    
    isInit = CreateGood81Numbers();
    return isInit;
}

bool Filter81GoodNumber::Filter(vector<NameProfile>& nameprofiles)
{
	bool isok = false;
	vector<NameProfile> Outnameprofiles;
    try{
		vector<NameProfile>::iterator iter = nameprofiles.begin();
		for(iter = nameprofiles.begin(); iter != nameprofiles.end() ; ++iter){
			bool bNeedAdd = false;
			//int nsky = 1 + iter->Get_lastname_num();
			int npeople = iter->Get_lastname_num() + iter->Get_name1_num();
			int nearth = iter->Get_name1_num() + iter->Get_name2_num();
			int nall = iter->Get_sum_num();
			int nout = nall - npeople + 1;

			while(true)
			{
				vector<int>::iterator it;
	            it = find(good81Numbers.begin(),good81Numbers.end(),nall);
			    if(it == good81Numbers.end()){
					// Not in the good81Numbers
		             break;
				}
				it = find(good81Numbers.begin(),good81Numbers.end(),npeople);
			    if(it == good81Numbers.end()){
					// Not in the good81Numbers
		             break;
				}
				it = find(good81Numbers.begin(),good81Numbers.end(),nearth);
			    if(it == good81Numbers.end()){
					// Not in the good81Numbers
		             break;
				}
				it = find(good81Numbers.begin(),good81Numbers.end(),nout);
			    if(it == good81Numbers.end()){
					// Not in the good81Numbers
		             break;
				}

				// nall, npeople and nearth are all in the good81Numbers.
				// Add to new vector
				Outnameprofiles.push_back(*iter);
				break;
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

bool Filter81GoodNumber::CreateGood81Numbers()
{
	bool isok = false;
	try{
		good81Numbers.clear();
		good81Numbers.push_back(1);
		good81Numbers.push_back(3);
		good81Numbers.push_back(5);
		good81Numbers.push_back(6);
		good81Numbers.push_back(7);
		good81Numbers.push_back(8);
		good81Numbers.push_back(11);
		good81Numbers.push_back(13);
		good81Numbers.push_back(15);
		good81Numbers.push_back(16);
		good81Numbers.push_back(17);
		good81Numbers.push_back(18);
		good81Numbers.push_back(21);
		good81Numbers.push_back(23);
		good81Numbers.push_back(24);
		good81Numbers.push_back(25);
		good81Numbers.push_back(29);
		good81Numbers.push_back(31);
		good81Numbers.push_back(32);
		good81Numbers.push_back(33);
		good81Numbers.push_back(35);		
		good81Numbers.push_back(37);
		good81Numbers.push_back(39);
		good81Numbers.push_back(41);		
		good81Numbers.push_back(45);		
		good81Numbers.push_back(47);
		good81Numbers.push_back(48);
		good81Numbers.push_back(52);
		good81Numbers.push_back(57);
		good81Numbers.push_back(61);
		good81Numbers.push_back(63);
		good81Numbers.push_back(65);		
		good81Numbers.push_back(67);
		good81Numbers.push_back(68);
		good81Numbers.push_back(81);
		isok = true;
	}
	catch(...){
	}	
	return isok;
}

bool Filter81GoodNumber::IsInitialized()
{
    return isInit;
}