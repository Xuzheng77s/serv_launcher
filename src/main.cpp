#include <iostream>
#include <cstdlib>
#include <cassert>
#include "lock.hpp"
#include "defs.hpp"
#include "backup.hpp"
#include <sys/stat.h>
using namespace std;
using namespace pst;

int main(int argc, char const *argv[])
{
  system("clear");
  lock lks;
  if(lks.get_state())
  {
    title("LOCK");
    cout<<"另一个服务器正在运行中..."<<endl;
    return EXIT_UNEXPECTED;
  }
  int choose;
  const char* src="./start.sh";
  cout<<"MCLake Version "<<LAUNCHER_VERSION<<endl;
  cout<<"菜单:"<<endl;
  cout<<"[0] 启动服务器"<<endl;
  cout<<"[1] 退出"<<endl;
  cout<<"[2] 备份"<<endl;
  cin>>choose;
  switch (choose)
  {
    case 0:
    title("LOCK");
    cout<<"Locking..."<<endl;
    lks.locks();
    title("LOCK");
    cout<<"Locked"<<endl;
    start_server(src);
    break;

    case 1:
    return EXIT_SUCCESFUL;
    break;

    case 2:
    title("BACKUP");
    cout<<"Backup-ing"<<endl;
    backups();
    title("BACKUP");
    cout<<"Backup sucessful!"<<endl;
    return EXIT_SUCCESFUL;

    default:
    return EXIT_FAILURE;
  }
}
