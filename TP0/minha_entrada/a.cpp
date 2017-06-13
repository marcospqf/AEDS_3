#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string name;
  cin>>name;
  ofstream ofs(name.c_str(),std::ofstream::out);
  for(int i=0;i<n;i++){
    ofs<<2;
    ofs<<" ";
  }
  for(int i=0;i<n-2;i++) ofs<<"? ";
  ofs<<"?"<<endl;
  ofs<<(1ll<<(n-2))<<endl;
  ofs.close();
}
