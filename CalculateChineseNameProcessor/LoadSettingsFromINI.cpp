#include "stdafx.h"
#include "ILoadSettings.h"
#include <map>
#include <string>


LoadSettingsFromINI::LoadSettingsFromINI(void)
{
}


LoadSettingsFromINI::~LoadSettingsFromINI(void)
{
}

bool LoadSettingsFromINI::LoadSettings()
{
	bool isok = false;
	settings.clear();

	string MAX = "MaxofNameNumber";
	string MAX_Value = "22";
	string MIN = "MinofNameNumber";
	string MIN_Value = "1";
	try{		
		settings.insert(TStrStrPair(MAX,MAX_Value));
		settings.insert(TStrStrPair(MIN,MIN_Value));		
		isok = true;
	}
	catch(...)
	{
		isok = false;
	}
	return isok;
}
