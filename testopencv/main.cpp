#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string> 

using namespace cv;
int main()
{

	Mat img = imread("pic.jpg", CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);

	namedWindow("��Ϸԭ��");

	imshow("��Ϸԭ��",img);

	waitKey(6000);

	return 0;



}