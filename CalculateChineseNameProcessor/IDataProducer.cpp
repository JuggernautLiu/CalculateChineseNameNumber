#include "StdAfx.h"
#include "IDataProducer.h"


IDataProducer::IDataProducer(void)
{
}

IDataProducer::~IDataProducer(void)
{
}

void IDataProducer::SetNameProfileCfg(NameProfileCfg cfg)
{    
    nameprofilecfg = cfg;
}
