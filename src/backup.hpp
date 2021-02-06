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
        mkdir("./backup",777);
        system("cp -rf ./* /tmp/backup");
        system("cp -rf /tmp/backup/* ./backup/lastest");
    }
PST_END