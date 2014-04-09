#pragma once
#include <map>

using namespace std;
typedef pair<string, string> TStrStrPair;
class ILoadSettings
{
public:
	ILoadSettings(void);
	virtual ~ILoadSettings(void) = 0;
	virtual bool LoadSettings() = 0;
	map<string,string> settings;	
};

class LoadSettingsFromINI : public ILoadSettings
{
public:
	LoadSettingsFromINI(void);
	~LoadSettingsFromINI(void);
	bool LoadSettings();
};