#include "FLAT_utils.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

void FLAT_Utils::stringFromFile(const char *fileName, std::string& contentString)
{
  contentString = "";
  std::string line = "";
  std::ifstream fileStream(fileName, std::ios::in);
  while(getline(fileStream, line))
    contentString += "\n" + line;
  fileStream.close();
}

float FLAT_Utils::randf()
{
  return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

