#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define demension 5
//样本结构体
struct record{
  double x[demension];
  int y;
}
//读取数据文件
void getdata(fstream& datafile,vector<record> &dataset){
  while(){
    
  }
}

void main()
{
  vector<record> dataset;
  vector<double> weight(demension);
  vector<double> pocket_weight(demension);
  vector<double> weigh(demension);
  fstream datafile1("E:\\迅雷下载\\hw1_18_train.dat");
  fstream datafile2("E:\\迅雷下载\\hw1_18_test.dat");
  if(datafile)
}
