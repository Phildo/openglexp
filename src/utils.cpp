#include "utils.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

void FLATUtils::stringFromFile(const char *fileName, std::string& contentString)
{
  contentString = "";
  std::string line = "";
  std::ifstream fileStream(fileName, std::ios::in);
  while(getline(fileStream, line))
    contentString += "\n" + line;
  fileStream.close();
}

