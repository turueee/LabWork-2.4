#pragma once
#include <iostream>
#include <string>
#include <utility>
#include "TString.h"


class TError
{
protected:
  TString message;

public:
  TError(char* error,
    char* function,
    char* file,
    int line)
  {
    TString er(error), func(function), fi(file),prob(" ");
    message = er + prob + func +prob + fi;
    //cout << "\nError: " << er << "Function: " << func << "File: " << fi <<"Line:"<<line<< endl;
  }
};

#define THROW_ERROR(err, ...) throw TError(err, __func__, __FILE__, __LINE__)