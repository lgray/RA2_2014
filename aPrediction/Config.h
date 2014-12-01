#ifndef Config_H
#define Config_H
#include "vector"
#include "string"
#include "fstream"
#include "map"
#include <iostream>
#include "stdlib.h"
#include "algorithm"
class Cuts
{
public:
	Cuts();
	Cuts(std::string Variable, std::string cutTyp,unsigned int CutTyp, double value){Variable_=Variable;cutTyp_=cutTyp;CutTyp_=CutTyp;value_=value;}
	std::string Variable(){return Variable_;}
	std::string cutTyp(){return cutTyp_;}
	unsigned int CutTyp(){return CutTyp_;}
	double value(){return value_;}
	~Cuts(){}
private:
	std::string Variable_, cutTyp_;
	double value_;
	unsigned int CutTyp_;
};
class Efficiency
{
public:
	Efficiency();
	Efficiency(std::string Name,std::string FileName,std::string variableX, std::string variableY){Name_=Name;FileName_=FileName;variableX_=variableX;variableY_=variableY;}

	~Efficiency(){}
private:
	std::string Name_, FileName_,variableX_,variableY_;
	

};

class Config
{
public:
	Config(const char* ConfFile);
	~Config();
private:
	// filename and file itself
	std::string fileName_;
	std::ifstream fileStr_;
	// functions
	void ReadFile();
	bool initilized_;
	std::map<std::string, Cuts*> cuts_;
	std::map<std::string, Efficiency*> efficiencies_;
	std::vector<std::string> operators_;
	std::vector<std::string> EfficiencySharedValues_;
};

#endif