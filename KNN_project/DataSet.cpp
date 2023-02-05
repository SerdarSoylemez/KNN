#include "DataSet.h"
#include<algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include<string>
#include<stdexcept>
using namespace std;
int DataSet::pointCount=0;
DataSet::DataSet(int n)
{
	setSize(n);
	Generator();
	pointCount++;
}
DataSet::~DataSet(){
	//Nothing to do
}
vector<double> DataSet::getFeatureX()const{return featureX;}
vector<double> DataSet::getFeatureY()const{return featureY;}
vector<int> DataSet::getCategoryID()const{return categoryID;}
vector<int> DataSet::getID(){return ID;}
int DataSet::getSize()const{return size;}
int DataSet::getPointCount(){return pointCount;}		
void DataSet::setFeatureX(vector<double>a){featureX =a;}
void DataSet::setFeatureY(vector<double>b){featureY =b;}
void DataSet::setCategoryID(vector<int>c){categoryID =c;}
void DataSet::setID(vector<int>d){ID=d;}
void DataSet::setSize(int n){
	if(size>0){
		size=n;
	}
	else
		throw invalid_argument("Invalid size value.");
}
void DataSet::Generator(){
	srand(time(NULL));
	for(int i=0;i<size;i++){
		int randX=rand()%(11)-5;
		int randY=rand()%(11)-5;
		featureX.push_back(randX);
		featureY.push_back(randY);
		ID.push_back(i);
		if(i/10==0){
			categoryID.push_back(0);
		}
		else if(i/10==1){
			categoryID.push_back(1);
		}
		else if(i/10==2){
			categoryID.push_back(2);
		}
	}
	writeToFile(ID,categoryID,featureX,featureY);
}
void DataSet::print()const{
	for(int i=0;i<size;i++){
		cout << "Data ID : " << ID[i] << "\tCategory ID : "<< categoryID[i] << "\t\tFeature X : " << featureX[i] << "\t\tFeature Y: " << featureY[i] << endl;
	}
}
ostream &operator<<(ostream &output,const DataSet&obj){
	for(int i=0;i<obj.size;i++){
		output << "Data ID : " << obj.ID[i] << "\tCategory ID : "<< obj.categoryID[i] << "\t\tFeature X : " << obj.featureX[i] << "\t\tFeature Y: " << obj.featureY[i] << endl;
	}
	return output;
}
void DataSet::readFromFile(){
	string myText;
	ifstream readedFile("KNN_data");
	while(getline(readedFile,myText)){
		cout<<myText<<endl;
	}
	readedFile.close();
}
void DataSet::writeToFile(vector<int> x,vector<int> y,vector<double> z,vector<double> t){
		vector<int>s_x;
		vector<int>s_y;
		vector<double>s_z;
		vector<double>s_t;
		ofstream file("KNN_data");
		file<<"Data ID"<<"\t\tCategory ID"<<"\t\tFeature X"<<"\tFeature Y"<<endl;
		for(int i=0;i<z.size();i++){
			s_x.push_back((x[i]));
			s_y.push_back((y[i]));	
			s_z.push_back((z[i]));	
			s_t.push_back((t[i]));	
		}
		for(int m=0;m<30;m++){
			file<<s_x[m]<<"\t\t";
			file<<s_y[m]<<"\t\t\t";
			file<<s_z[m]<<"\t\t";
			file<<s_t[m]<<endl;
		}
		
    	file.close();
}
