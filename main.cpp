#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <complex>
#include <thread>

using namespace std; 
using namespace cv;
Mat frame;   // matrice de notre image

 
 #define V 4 //norme a pas dépasser
 #define ITER 150 // nombre d'iteration max
 #define HEIGHT 500 // hauteur image
 #define WIDTH 500 // largeur image

std::complex<long double> c(-0.7269,0.1889); // constance de la fractal

void calculJulia();

int main( int argc, char** argv )
{
  frame=cv::Mat(WIDTH, HEIGHT, CV_8UC3);
    
    calculJulia();
     while( true )
     {
     	 
	     imshow("julia frame", frame ); 
     	 if(cvWaitKey(5) > 0){
        break;
       }
}
 
 
  return 0;
}

 void calculJulia(){
  for(int x=0;x<WIDTH;x++){
      for(int y=0;y<HEIGHT;y++){
        long double newX=((long double)((long double)x-((long double)WIDTH/2))/((long double)WIDTH/2));
        long double newY=((long double)((long double)y-((long double)HEIGHT/2))/((long double)HEIGHT/2));
        std::complex<long double> point(newY,newX);
        int iteration=0;
        long double norm = std::norm(point);
        while(iteration<ITER && norm<V){
          point=(point*point)+c;
          norm = std::norm(point);
          iteration++;
        }
        if(iteration==ITER && norm<V){
          frame.at<Vec3b>(x,y)[0]=0; 
          frame.at<Vec3b>(x,y)[1]=0; 
          frame.at<Vec3b>(x,y)[2]=0;
        }
        else{
          int couleur=(int)((float)iteration/(float)ITER*255);
          frame.at<Vec3b>(x,y)[0]=couleur;
          frame.at<Vec3b>(x,y)[1]=couleur;
          frame.at<Vec3b>(x,y)[2]=couleur;
      }
    } 
  }
 }