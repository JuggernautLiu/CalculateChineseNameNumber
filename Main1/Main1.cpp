// Main1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include "MainProcessor.h"
#include <string>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	bool ballconditionOK = true;
	
	wstring strlastname(argv[1]);
	wstring strlackofelement(argv[2]);

	
	fstream file;
	file.open("name.txt",ios::out);	

	MainProcessor processor;
	vector<NameProfile> nameprofiles;
	int lastname = stoi(strlastname);
	int lackelement = stoi(strlackofelement);
	//int lackelement = IRuleFilter::Enum_Elements::Water;
	string strLackofelement;
	switch(lackelement)
	{
	    case IRuleFilter::Enum_Elements::Wood:
			strLackofelement = "Wood";
		break;
		case IRuleFilter::Enum_Elements::Fire:
			strLackofelement = "Fire";
		break;
		case IRuleFilter::Enum_Elements::Earth:
			strLackofelement = "Earth";
		break;
		case IRuleFilter::Enum_Elements::Gold:
			strLackofelement = "Gold";
		break;
		case IRuleFilter::Enum_Elements::Water:
			strLackofelement = "Water";
		break;
		default:
			ballconditionOK = false;
			break;
	}
	file << "Last Name Number : " << lastname <<endl;
	file << "Lack of element : " << strLackofelement.c_str() <<endl;
	file << "=======================================================" << endl;

	if(ballconditionOK){
		processor.Run(nameprofiles,lastname,lackelement);

	    vector<NameProfile>::iterator iter;
		int i = 0;
	    for(iter = nameprofiles.begin(); iter != nameprofiles.end() ; ++iter){
			file << "(" << ++i << ")" << " SUM = (" << iter->Get_sum_num() << ") ["<<iter->Get_lastname_num() << "," << iter->Get_name1_num() << "," << iter->Get_name2_num() << "]" << endl;			
	    }
	}
	else{
		
	}
	
	file.close();
	return 0;
}

