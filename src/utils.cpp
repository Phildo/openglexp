#include "utils.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

const std::string FLATUtils::stringFromFile(const char *fileName)
{
  std::string line = "";
  std::string resultString;
  std::ifstream fileStream(fileName, std::ios::in);
  while(getline(fileStream, line))
    resultString += "\n" + line;
  fileStream.close();
  return resultString;
}

