#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define demension 5   //特征维度+x0

//训练样本结构
struct record {
	double input[demension];
	int output;
};

//把数据读取到训练样本向量
void getdata(ifstream &datafile,vector<record> &dataset)
{
	while (!datafile.fail())
	{//判断输入是否成功
		record currecord;
		currecord.input[0] = 1;
		for (int i = 1; i<demension; i++)
		{
			datafile >> currecord.input[i];
		}
		datafile >> currecord.output;
		dataset.push_back(currecord);//将元素添加到矢量末尾
	}
	datafile.close();
}
//计算w*x
double multiply(double *w, double *x)
{
	double w_x = 0;
	for (int i = 0; i<demension; i++)
	{
		w_x += w[i] * x[i];
	}
	return w_x;
}
//计算y*x
void multiply(double *result, double *x, int y) {
	for (int i = 0; i<demension; i++)
	{
		result[i] = y * x[i];
	}
}

void add(double *wt, double *yx)
{
	for (int i = 0; i<demension; i++)
	{
		wt[i] += yx[i];
	}
}

int sign(double x) {
	if (x > 0)return 1;
	else return -1;
}

double geterrorRate(double *weight,vector<record> &dataset) {
	int n = dataset.size();
	double errorRate = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (sign(multiply(weight, dataset[i].input)) != dataset[i].output)errorRate++;
	}
	return errorRate / n;
}

void pocket_pla(vector<record> &trainingset,double *pocketweight,double *weight,int iteration) {
	int n = trainingset.size();
	int index = 0, iter = 1;
	while (iter<iteration)
	{
		if (trainingset[index].output != sign(multiply(weight, trainingset[index].input)))
		{//出错，执行修正算法
		    //临时数组
			double temp[demension];
			//计算y*x
			multiply(temp, trainingset[index].input, trainingset[index].output);
			//修正w(t+1)=w(t)+yx
			add(weight, temp);
			if(geterrorRate(weight,trainingset)<geterrorRate(pocketweight,trainingset)){
				for(int i=0;i<demension;i++){
					pocketweight[i]=weight[i];
				}
			}
			//步数
			iter++;
		}
		if (index == n - 1)index = 0;
		else index++;
	}
}

int main()
{
	double weight[demension],pocket_weight[demension];//权重
	ifstream datafile1("E:\\迅雷下载\\hw1_18_train.dat");
	ifstream datafile2("E:\\迅雷下载\\hw1_18_test.dat");//以文件模式打开
	vector<record> trainingset;
	vector<record> testset;
	int n = trainingset.size();
	double avg_error = 0.0;
	if (datafile1.is_open()&&datafile2.is_open()) {
		getdata(datafile1,trainingset);
		getdata(datafile2,testset);
	}
	else {
		cout << "出错，文件打开失败！" << endl;
		exit(1);
		system("pause");
	}
	for (int i = 0; i < 2000; i++)
	{
		random_shuffle(trainingset.begin(),trainingset.end());
		for (int j = 0; j<demension; j++)
		{
			pocket_weight[j] = 0;
			weight[j] = 0;
		}
		pocket_pla(trainingset,pocketweight,weight,50);
		double trainerror = geterrorRate(pocketweight,trainingset);
		double testerror = geterrorRate(pocketweight, testset);
		avg_error+=testerror;
		cout << "第" << i << "次实验---" << "training error:" << trainerror << " test error:" << testerror << endl;
	}
	cout << "average error rate:" << avg_error / 2000 << endl;
	system("pause");
	return 0;
}
