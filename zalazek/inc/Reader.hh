#ifndef READER_HH
#define READER_HH
#pragma once

#include <cstdio>
#include <sstream>
#include <string>
#include <iostream>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/SAX2XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>

#include "../inc/Configuration.hh"
#include "../inc/xmlinterp.hh"

#define LINE_SIZE 500

class Reader
{
private:
    std::string CmdFileName;
public:
    Reader(){};
    bool init(std::string CmdFile);
    bool execPreprocesor(std::istringstream &IStrm4Cmds);
    bool ReadFile(const char* sFileName, Configuration &rConfig);
};
#endif

