#ifndef SHAPEANALYSISTOOLCOMPUTATION_H
#define SHAPEANALYSISTOOLCOMPUTATION_H

#include "Parameters.h"


#include <strstream> 
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <itksys/Process.h>
#include <vector>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataWriter.h>
#include <vtkSmartPointer.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <itksys/Glob.hxx>
#include <dirent.h>

#include "bmScriptParser.h"
#include "BMString.h"

class ShapeAnalysisModuleComputation: public Parameters
{
 public:
	
	ShapeAnalysisModuleComputation();
	~ShapeAnalysisModuleComputation();

	void SetBMSShapeAnalysisModuleFile(bool);
	char *GetBMSShapeAnalysisModuleFile();
	void SetBMSShapeAnalysisModuleFile2(bool);
	char *GetBMSShapeAnalysisModuleFile2();
	void SetBMSShapeAnalysisModuleMRMLFile(bool);
	char* GetBMSShapeAnalysisModuleMRMLFile();
	void SetOuputFile();
	char* GetOutputFile();
	void WriteBMSMRMLScene();
  	void WriteBMSShapeAnalysisModuleFile();
	void WriteBMSShapeAnalysisModuleFile2();
	void ExecuteBatchMake(char *_Input);  
  	void ExecuteMeshMath(int,char*);

	void Computation();
	void OverWrite();
	void ComputationMean();
	void WriteMeanFile(int);


	vector<double> transformStorage;
	int countline;
	int countcol;
	int countshape;
	void GetRandomNum(int,int);

  
	private:
  
	int m_StudyNumber;
	int ComputeMean;
    	char m_BMSShapeAnalysisModuleFile[512];
	char m_BMSShapeAnalysisModuleMRLMFile[512];
	char m_OutputFile[512];
	char m_SegPostProcessDir[512];
	char m_GenParaMeshDir[512];
	char m_ParaToSPHARMMeshDir[512];
	double const_orientation;

	vector<int> m_Dims;
	vector<double>m_meanX;
	vector<double>m_meanY;
	vector<double>m_meanZ;	


	vector<int> m_permutations;

};

#endif
