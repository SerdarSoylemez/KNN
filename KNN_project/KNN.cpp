#include "KNN.h"
#include "DataSet.h"
#include<algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<vector>
#include <cmath>
#include<map>
#include<stdexcept>
using namespace std;
KNN::KNN(int K,const DataSet&Data,vector<double>testX,vector<double>testY):data(Data),testSampleX(testX),testSampleY(testY)
{
	setK(K);
	//setTestX(testX);
	//setTestY(testY);
}
KNN::~KNN()
{
	//Nothing to do
}
void KNN::setK(int x){
	
	if(x>0)
		k=x;
	else
		throw invalid_argument("Invalid K value.");
}

void KNN::setTestX(vector<double>testX){testSampleX=testX;}
void KNN::setTestY(vector<double>testY){testSampleY=testY;}
void KNN::setDeterminedCategory(vector<int> d_cat){determinedCategory=d_cat;}
vector<double> KNN::getTestSampleX()const{return testSampleX;}
vector<double> KNN::getTestSampleY()const{return testSampleY;}
vector<int> KNN::getDeterMinedCategory()const{return determinedCategory;}
int KNN::getK()const{return k;}
double KNN::euclideanDistance(double x1,double x2,double y1,double y2){
	double value=pow((x1-x2),2)+pow((y1-y2),2);
	return sqrt(value);
}
void KNN::predict(){
	vector<double> distances;
	vector<pair<double,int> > dist_Index;
	
	for(int i=0;i<testSampleX.size();i++){
		for(int j=0;j<data.getFeatureX().size();j++){
			distances.push_back(euclideanDistance(testSampleX[i],data.getFeatureX()[j],testSampleY.at(i),data.getFeatureY()[j]));
			dist_Index.push_back(make_pair(distances[j],j));
		}
		
		distances.clear();
		sort(dist_Index.begin(),dist_Index.end());
		/*for(int l=0;l<data.getFeatureX().size();l++){
		
		}*/
		int predictionCategory[3]={0,0,0};
		for(int m=0;m<k;m++){
			cout<<"Distances: "<<dist_Index[m].first<<" Index:"<<dist_Index[m].second<<" Category ID "<<data.getCategoryID().at(dist_Index[m].second)<<endl;
			if(m==(k-1)){
				cout<<"\n";
			}
			predictionCategory[data.getCategoryID().at(dist_Index[m].second)]++;
		}
		dist_Index.clear();
		if(predictionCategory[0]>predictionCategory[1] && predictionCategory[0]>predictionCategory[2])
			determinedCategory.push_back(0);
		
		else if(predictionCategory[1]>predictionCategory[0] && predictionCategory[1]>predictionCategory[2])
			determinedCategory.push_back(1);
		
		else
			determinedCategory.push_back(2);	
	}
}
void KNN::print()const{
	for(int i=0;i<testSampleX.size();i++)
	cout << "Test data : " << i << "  Category ID is predicted " << determinedCategory[i]<<endl;
}
	

