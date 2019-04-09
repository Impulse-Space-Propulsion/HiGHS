/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                       */
/*    This file is part of the HiGHS linear optimization suite           */
/*                                                                       */
/*    Written and engineered 2008-2019 at the University of Edinburgh    */
/*                                                                       */
/*    Available as open-source under the MIT License                     */
/*                                                                       */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**@file io/HMPSIO.h
 * @brief 
 * @author Julian Hall, Ivet Galabova, Qi Huangfu and Michael Feldmeier
 */
#ifndef IO_HMPSIO_H_
#define IO_HMPSIO_H_

#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using std::vector;
using std::string;

const int MPS_ROW_TY_N = 0;
const int MPS_ROW_TY_E = 1;
const int MPS_ROW_TY_L = 2;
const int MPS_ROW_TY_G = 3;

int readMPS(const char *filename, int mxNumRow, int mxNumCol, int &numRow,
            int &numCol, int &objSense, double &objOffset, vector<int> &Astart,
            vector<int> &Aindex, vector<double> &Avalue,
            vector<double> &colCost, vector<double> &colLower,
            vector<double> &colUpper, vector<double> &rowLower,
            vector<double> &rowUpper, vector<int> &integerColumn,
            vector<string>& row_names, vector<string> &col_names);

int writeMPS(const char* filename, const int& numRow, const int& numCol, const int& numInt,
             const int& objSense, const double& objOffset, const vector<int>& Astart,
             const vector<int>& Aindex, const vector<double>& Avalue,
             const vector<double>& colCost, const vector<double>& colLower,
             const vector<double>& colUpper, const vector<double>& rowLower,
             const vector<double>& rowUpper, const vector<int>& integerColumn,
	     const vector<std::string>col_names, const vector<std::string>row_names);

bool load_mpsLine(FILE* file, int& integerVar, int lmax, char* line, char* flag,
                  double* data);
// int isspace(int c);
// char* fgets(char* str, int num, FILE* stream);

inline const char* const BoolToString(bool b);

#endif /* IO_HMPSIO_H_ */
