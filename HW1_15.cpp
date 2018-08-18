#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

string file="E:\\迅雷下载\\hw1_15_train.dat";//读取文件名
#define demension 5   //特征维度+x0
vector<double> weight(demension);
void getdata(ifstream &datafile)
{[InternetShortcut]
URL=https://github.com/zyx1996/homework

  
}
void main()
{
  ifstream datafile(file);//以文件模式打开
  if(datafile.is_open()){
    getdata(datafile);
  }
  else{
    cout << "出错，文件打开失败！" << endl;
    exit(1);
    system("pause");
  }
  int i;
  for(auto x:weight)
  pla();
}
