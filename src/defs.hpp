#ifndef LAUNCHER_DEFS_H
#define LAUNCHER_DEFS_H

#define LAUNCHER_VERSION 0.1
#define EXIT_SUCCESFUL 0
#define EXIT_ERROR 1
#define EXIT_UNEXPECTED -1
#define PST_BEGIN namespace pst{
#define PST_END }

#include <iostream>
using namespace std;

PST_BEGIN
  void cutline()
  {
    cout << "-------------------------------------" << endl;
  }

  int start server(const char* script_src)
  {
    int exit_code=system(script_src);
    if(exit_code==0)
    {
      int c;
      cout<<"退出成功,是否重启?(0)重启,(1)退出"<<endl;
      cin>>c;
      if(c==0)
      {
        start_server(script_src);
      }
      else
      {
        return EXIT_SUCCESFUL;
      }
    }
    else
    {
      int c;
      cout<<"退出失败,是否重启?(0)重启,(1)退出"<<endl;
      cin>>c;
      if(c==0)
      {
        start_server(script_src);
      }
      else
      {
        return exit_code;
      }
    }
  }
PST_END

#endif
