#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include <cstdlib>
#include <sys/types.h>
#include "defs.hpp"
#include <sys/stat.h>
using namespace std;

struct lock
{
    bool get_state()
    {
        ifstream check("./.guard.lock");
        ifstream lk("./.guard.lock",ios::in|ios::binary);
        if(!check.is_open())
        {
            pst::title();
            cout<<"第一次运行服务器!祝服主好运!"<<endl;
            ofstream cf("./.guard.lock");
            cf.close();
            check.close();
            get_state();
        }
        check.close();
        pid_t* s=new pid_t();
        lk.read(reinterpret_cast<char*>(s),sizeof(pid_t));
        string dir="/proc/"+to_string(*s)+"/io";
        ifstream ext(dir.c_str());
        lk.close();
        if(!ext.is_open())
        {
            ext.close();
            return false;
        }
        else
        {
            ext.close();
            return true;
        }
    }
    void locks()
    {
        ofstream lk("./.guard.lock",ios::out|ios::binary);
        chmod("./.guard.lock",444);
        pid_t* d=new pid_t(getpid());
        const char* s=reinterpret_cast<char*>(d);
        lk.write(s,sizeof(pid_t));
        lk.close();
        delete d;
    }
};