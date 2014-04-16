#pragma once
#include "stdafx.h"
#include <vector>
#include "IDataProducer.h"
#include "ILoadSettings.h"
#include "IRuleFilter.h"
#include "NameProfile.h"

class MainProcessor
{
public:
	MainProcessor(void);
	~MainProcessor(void);
	void Run(vector<NameProfile>& nameprofiles, int lastname,int lackElement);
};

