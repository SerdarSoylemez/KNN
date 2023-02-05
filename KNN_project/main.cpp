#include "DataSet.h"
#include<algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "KNN.h"
#include "Graph.h"
#include<graphics.h>
#include <sstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double randomGenerator(){
	return rand()%(11)-5;
}
int main(int argc, char** argv) {
	DataSet data1(30);
	//data1.readFromFile();
	data1.print();
	//cout<<data1;//Operator overloading
	/** This variable holds test sample of X values as a vector.*/
	vector<double>testSamplesx(10);
	/** This variable holds test sample of X values as a vector.*/
	vector<double>testSamplesy(10);
	/** This function generate random numbers to test sample of X*/
	generate(testSamplesx.begin(),testSamplesx.end(),randomGenerator);
	/** This function generate random numbers to test sample of X*/
	generate(testSamplesy.begin(),testSamplesy.end(),randomGenerator);
	
	for(int i=0;i<10;i++){
		cout<<"Data ID : "<<i+30;
		cout<<"\tCategory ID :-";
		cout<<" \t\tTestX :"<<testSamplesx[i];
		cout<<"\t\tTestY :"<<testSamplesy[i]<<endl;
	}
	KNN knn(5,data1,testSamplesx,testSamplesy);
	
	knn.predict();
	knn.print();
	Graph g1(data1,knn);
	g1.printPoints();
	return 0;
}
