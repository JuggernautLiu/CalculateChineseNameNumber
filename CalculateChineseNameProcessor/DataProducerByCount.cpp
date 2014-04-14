#include "stdafx.h"
#include "IDataProducer.h"

using namespace std;
DataProducerByCount::DataProducerByCount()
{
}

DataProducerByCount::~DataProducerByCount()
{
}

bool DataProducerByCount::ProduceNameProfiles(vector<NameProfile> &nameprofiles)
{
    bool isok = false;
    nameprofiles.clear();
    try{
        NameProfile::limit_maxNumber = nameprofilecfg.limit_maxNumber;
        NameProfile::limit_minNumber = nameprofilecfg.limit_minNumber;

        for(int i=NameProfile::limit_minNumber ; i<=NameProfile::limit_maxNumber ; i++){
            for(int j=i ; j <= NameProfile::limit_maxNumber ; j++){
                // First. Ex. 15,1,22
                NameProfile profile(nameprofilecfg.lastname_num);
                profile.Set_name1_num(i);
                profile.Set_name2_num(j);
                if(profile.FinishSetting()){
                    nameprofiles.push_back(profile);
                }
                
                if(i==j){
                    continue;
                }
                
                // Second Ex. 15,22,1
                NameProfile profile2(nameprofilecfg.lastname_num);
                profile2.Set_name1_num(j);
                profile2.Set_name2_num(i);
                if(profile.FinishSetting()){
                    nameprofiles.push_back(profile2);
                }
            }
        }
        isok = true;
    }
    catch(...){

    }
    return isok;
}