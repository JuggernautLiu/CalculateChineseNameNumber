#include "stdafx.h"
#include "MainProcessor.h"


MainProcessor::MainProcessor(void)
{
}


MainProcessor::~MainProcessor(void)
{
}

void MainProcessor::Run(vector<NameProfile>& nameprofiles, int lastname, int lackElement)
{
	// Create All Data
	DataProducerByCount dataproducer;
    NameProfileCfg cfg;
    cfg.lastname_num = lastname;
    cfg.limit_maxNumber = 22;
    cfg.limit_minNumber = 1;
    dataproducer.SetNameProfileCfg(cfg);
	dataproducer.ProduceNameProfiles(nameprofiles);

	bool isok = false;
	// Start Filter
	// First FilterAllNameNumberForFiveElements
	FilterAllNameNumberForFiveElements filter1;
	filter1.Initialize();
	filter1.SetLackOfElement(lackElement);
	filter1.Filter(nameprofiles);

	// Second FilterThreeWordsPhase
	FilterThreeWordsPhase filter2;
	filter2.Initialize();	
	filter2.Filter(nameprofiles);

	// Third Filter81GoodNumber
	Filter81GoodNumber filter3;
	filter3.Initialize();	
	filter3.Filter(nameprofiles);
}