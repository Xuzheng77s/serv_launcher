#include <iostream>
#include <cstdlib>
#include "defs.hpp"
using namespace std;
using namespace pst;

int main(int argc, char const *argv[])
{
  cout<<"欢迎来到服务器启动器 版本v"<<LAUNCHER_VERSION<<endl;
  cutline();
  int choose;
  const char* src="./start.sh";
  cout<<"请选择要做的事情:(1)启动服务器,(2)退出,(3)备份,(4)回滚纠错"<<endl;
  cin>>choose
  switch (choose)
  {
    case 1:
    start_server(src);
    break;

    case 2:
    return EXIT_SUCCESFUL;
    break;

    case 3:
    
  }
  return EXIT_SUCCESFUL;
}
