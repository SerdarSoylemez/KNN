#ifndef KNN_H
#define KNN_H
#include "DataSet.h"
#include<iostream>
#include<vector>
using namespace std;
/** @brief This class is the class in which the KNN calculation is made.
    @author Serdar Soylemez
    @date January 2023
*/
class KNN
{
	public:
		/**This constructor set K value,data from DataSet,generated test point of X and test point of Y.*/ 
		KNN(int,const DataSet&,vector<double>,vector<double>);
		/**This destructor has a empty body*/
		~KNN();
		/**This function will predict category id of test samples*/
		void predict();
		/**This function will calculate euclidean distance of test and training samples.
		*@param double x1,double x2,double y1,double y2.
		*/
		double euclideanDistance(double,double,double,double);
		/**This function will set feaure of X value.*/
		void setTestX(vector<double>);
		/**This function will set feature of Y value.*/
		void setTestY(vector<double>);
		/**This function will set K value.*/
		void setK(int);
		/**This function will get the value of determined category.*/
		void setDeterminedCategory(vector<int>);
		/**This function will get the value of K.*/
		int getK(void)const;
		/**This function will get the value of X.*/
		vector<double> getTestSampleX()const;
		/**This function will get the value of Y.*/
		vector<double> getTestSampleY()const;
		/**This function will get the value of determined category.*/
		vector<int>getDeterMinedCategory()const;
		/** This function print the test data and predicted category id.*/
		void print()const;
	private:
		/** This variable holds test sample of X values as a vector.*/
		vector<double>testSampleX;
		/** This variable holds test sample of Y values as a vector.*/
		vector<double>testSampleY;
		/** This variable holds the data whose data type is DataSet.*/
		const DataSet data;
		/**This variable holds the number of neighbors as an integer.*/
		int k;
		/**This variable will hold the integer category id of test sample as a vector.*/
		vector<int> determinedCategory;		
};

#endif
