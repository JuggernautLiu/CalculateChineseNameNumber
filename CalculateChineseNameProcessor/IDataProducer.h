#pragma once
#include <vector>
#include "NameProfile.h"


using namespace std;
class IDataProducer
{
public:
    IDataProducer(void);
    virtual ~IDataProducer(void)=0;
    virtual bool ProduceNameProfiles(vector<NameProfile>& nameprofiles)=0;
    virtual void SetNameProfileCfg(NameProfileCfg cfg);
protected:
    NameProfileCfg nameprofilecfg;
};

class DataProducerByCount : public IDataProducer
{
public:
    DataProducerByCount(void);
    ~DataProducerByCount(void);
    bool ProduceNameProfiles(vector<NameProfile>& nameprofiles);
};
