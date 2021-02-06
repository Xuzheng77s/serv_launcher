#pragma once

#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "defs.hpp"
using namespace std;

PST_BEGIN
    void backups()
    {
        mkdir("./backup",0777);
        system("sudo rm -rf ../backup");
        mkdir("../backup",0777);
        system("sudo mkdir ./backup/lastest");
        system("sudo cp -rf ./* ../backup");
        system("sudo cp -rf ../backup/* ./backup/lastest");
        system("sudo rm -rf ../backup");
        system("sudo rm -rf ./backup/lastest/backup/lastest/*");
        chmod("./backup",777);
    }
PST_END