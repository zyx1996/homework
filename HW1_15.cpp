#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

string file="E:\\迅雷下载\\hw1_15_train.dat";//读取文件名
int n;//训练样本数
#define demension 5   //特征维度+x0

double weight[demension];//权重
//训练样本结构
struct record{
  double input[demension];
  int output;
};
//训练样本向量
vector<record> trainingset;
//把数据读取到训练样本向量
void getdata(ifstream &datafile)
{
  while(!datafile.fail())
  {//判断输入是否成功
    record currecord;
    currecord.input[0]=1;
    for(int i=1;i<demension;i++)
    {
      datafile>>currecord.input[i];
    }
    datafile>>currecord.output[i];
    trainingset.push_back(currecord);//将元素添加到矢量末尾
  }
  datafile.close();
  n=trainingset.size();
}
//计算w*x
void multiply(double *w,double *x)
{
  double w_x=0;
  for(int i=0;i<demension;i++)
  {
    w_x+=w[i]*x[i];
  }
  return w_X;
}
//计算y*x
void multiply(double *result,double *x,int y){
  for(int i=0;i<demension;i++)
  {
    result=y*x[i];
  }
}

void pla(){
  int correctnum=0;
  int index=0;
  bool isfinished=false;
  while(!isfinished)
  {
    if(trainingset[index].output==sign(multiply(weight,trainingset[index].input)))correctnum++;
    else{//出错，执行修正算法
      double temp[demension];
      multiply(temp,trainingset[index].input,trainingset[index].output);
      
    }
    if(index==n-1)index=0;
    else index++;
    if(correctnum=n)isfinished=true;
  }
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
  for(auto x:weight)x=0;
  pla();
}
