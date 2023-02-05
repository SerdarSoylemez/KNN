#ifndef DATASET_H
#define DATASET_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/** @brief The DataSet is a class that holds,writes,reads or prints data points required for implementing the KNN algorithm.
    @author Serdar Soylemez
    @date January 2023
*/
class DataSet
{
	friend ostream &operator<<(ostream&,const DataSet&);
	public:
		/**This function gets size of features and returns size of features,id,category id and generated data set.*/
		DataSet(int n);
		/** This constructor has empty body.*/
		~DataSet();
		/**This function sets feature of X and Y randomly,category id in the range of 0-2 and id in the range of 0-29.*/
		void Generator();
		/**This function returns the desired category id value of the generated data set.*/
		vector<int> getCategoryID()const;
		/**This function returns the desired X value of the generated data set.*/
		vector<double> getFeatureX()const;
		/**This function returns the desired Y value of the generated data set.*/
		vector<double> getFeatureY()const;
		/**This function returns the desired id value of the generated data set.*/
		vector<int> getID();
		/**This function returns count of called constructor.*/
		static int getPointCount();
		
		void setSize(int);
		/**This function is a function that will set category id value.
		*@param vector<double>*/
		void setCategoryID(vector<int>);
		/**This function is a function that will set id value.
		*@param vector<double>*/
		void setID(vector<int>);
		/**This function is a function that will set X value.
		*@param vector<double>*/
		void setFeatureX(vector<double>);
		/**This function is a function that will set Y value.
		*@param vector<double>*/
		void setFeatureY(vector<double>);
		/**This function is a function that print the generated X,Y,,id,category id values.*/
		void print()const;
		/**This funciton will read from the written "KNN_data.text" file.*/
		void readFromFile();
		/**This function will write feature of X,Y,category id,and id to "KNN_data.txt" file.
		*@param vector<int>ID,vector<int>categoryID,vector<double>featureX,vector<double>featureY.
		*/
		void writeToFile(vector<int>,vector<int>,vector<double>,vector<double>);
		/**This function returns the size of features. */
		int getSize()const;
		
	private:
		/** This variable holds integer size of features.*/
		int size;
		/** This variable holds integer category id values of features as a vector.*/
		vector<int> categoryID;
		/** This variable holds integer id values of features as a vector.*/
		vector<int> ID;
		/** This variable holds integer features of X as a vector.*/
		vector<double> featureX;
		/** This variable holds integer features of Y as a vector.*/
		vector<double> featureY;
		/** This variable holds integer count of Points.*/
		static int pointCount;
	
};

#endif
