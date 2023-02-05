#ifndef GRAPH_H
#define GRAPH_H
#include<graphics.h>
#include<iostream>
#include "KNN.h"
#include "DataSet.h"
#include<string>
using namespace std;
/** @brief This class is the class in which the KNN calculation is made.
    @author Serdar Soylemez
    @date January 2023
*/
class Graph
{
	public:
		/**This constructor take the DataSet object and KNN object to use in plotting in graphics*/
		Graph(const DataSet&,const KNN&);
		/**This destructor is empty*/
		~Graph();
		/**printPoint function is used for plotting training data values and category id of test data*/
		void printPoints();
		/**This function is used for setting coordinates*/
		void setCoordinates();
	private:
		/**This variable holds the value generated from DataSet class*/
		const DataSet data1;
		/**This variable holds the value generated from KNN class*/
		const KNN knn1;
};

#endif
