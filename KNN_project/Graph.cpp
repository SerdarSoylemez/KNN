#include "Graph.h"
#include<string>
using namespace std;
Graph::Graph(const DataSet&Data,const KNN&k_nn):data1(Data),knn1(k_nn)
{
}

Graph::~Graph()
{
}
void Graph::setCoordinates(){
	initwindow(800,800);
	int x1 = 400, y1 = 0, x2 = 400, y2 = 800; // Y-axis
    line(x1, y1, x2, y2);
    int x3 = 0, y3 = 500, x4 = 800, y4 = 400; // X-axis
    line(x3, y3, x4, y4);
    //X-axis
    outtextxy(100,  453, "-5");
    outtextxy(140,  453, "-4");
    outtextxy(180, 453, "-3");
    outtextxy(220, 453, "-2");
    outtextxy(260, 453, "-1");
    outtextxy(300, 450, "0");
    outtextxy(340, 453, "1");
    outtextxy(380, 453, "2");
    outtextxy(420, 453, "3");
    outtextxy(460, 453, "4");
    outtextxy(500, 453, "5");
    //Y-axis
    outtextxy(453, 100, "5");
    outtextxy(453, 140, "4");
    outtextxy(453, 180, "3");
    outtextxy(453, 220, "2");
    outtextxy(453, 260, "1");
    outtextxy(450, 300, "0");
    outtextxy(453, 340, "-1");
    outtextxy(453, 380, "-2");
    outtextxy(453, 420, "-3");
    outtextxy(453, 460, "-4");
    outtextxy(453, 500, "-5");
}
void Graph::printPoints(){
	setCoordinates();
	
	for (int i = 0; i <knn1.getTestSampleX().size(); i++){

    	int x = knn1.getTestSampleX()[i] *  40 ;
    	int y = knn1.getTestSampleY()[i] * -40 ;

    if(knn1.getDeterMinedCategory()[i]==0){

     setcolor(RED);
     rectangle(x+240, y+240, x+260,y+260);
     outtextxy(x+250,y+250,"0");
    }
	else if (knn1.getDeterMinedCategory()[i]==1){
        setcolor(MAGENTA);
        int triangle[] = {x+400, y+455, x+400, y+445, x+460, y+445, x+450, y+455};
        drawpoly(4, triangle);
        fillpoly(4,triangle);
        outtextxy(x+400,y+400,"1");
    }
    else{
        setcolor(GREEN);
        circle(x+400,y+400,8);
        setfillstyle(SOLID_FILL,RED);
        floodfill(x+400,y+400,GREEN);
        outtextxy(x+400,y+400,"2");
    }
    }
    for (int i = 0; i < 30; i++)
    {
    	setcolor(BROWN);
    	int x1=data1.getFeatureX()[i] * 40;
    	int y1=data1.getFeatureY()[i] * -40;

    	if(data1.getCategoryID()[i]==0){
   	 		//circle(x1+250,y1+250,10);
    		outtextxy(x1+400,y1+400,"C0");
    }	
		else if (data1.getCategoryID()[i]==1){
    		//circle(x1+250,y1+250,10);
    		outtextxy(x1+400,y1+400,"C1");
    }
    	else{
    		//circle(x1+250,y1+250,10);
    		outtextxy(x1+400,y1+400,"C2");
    }
    }
    getch();
	closegraph();
}
