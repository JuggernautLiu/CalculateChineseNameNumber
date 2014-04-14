#include "StdAfx.h"
#include "NameProfile.h"

int NameProfile::limit_maxNumber = 22;
int NameProfile::limit_minNumber = 1;
NameProfile::NameProfile(void):isSet(false)
{    
}

NameProfile::NameProfile(int lastnamenum)
{
    Set_lastname_num(lastnamenum);
}

NameProfile::~NameProfile(void)
{
    isSet = false;
}

bool NameProfile::FinishSetting()
{
    bool isok = false;
    try{
        if(isSet){
            Cal_allSumNum();
            isok = true;
        }        
    }
    catch(...){
    }
    return isok;
}

void NameProfile::checkLimit(int& num)
{   
    if(num > NameProfile::limit_maxNumber){
        num = NameProfile::limit_maxNumber;
    }
    else if(num < NameProfile::limit_minNumber){
        num = NameProfile::limit_minNumber;
    }
    else{}    
}

void NameProfile::Set_lastname_num(int num)
{
    checkLimit(num);
    this->lastname_num = num;
}

void NameProfile::Set_name1_num(int num)
{
    checkLimit(num);
    this->name1_num = num;
    isSet = true;
}

void NameProfile::Set_name2_num(int num)
{
    checkLimit(num);
    this->name2_num = num;
    isSet = true;
}

void NameProfile::Cal_allSumNum()
{    
    this->sum_num = (this->lastname_num + this->name1_num + this->name2_num);
}

int NameProfile::Get_lastname_num()
{
    return this->lastname_num;
}

int NameProfile::Get_name1_num()
{
    return this->name1_num;
}

int NameProfile::Get_name2_num()
{
    return this->name2_num;
}

int NameProfile::Get_sum_num()
{
    return this->sum_num;
}