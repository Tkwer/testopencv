#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string> 

using namespace cv;
using namespace std;

	/*----------------全局变量声明-------------------------*/
	//描述：
	/*----------------------------------------------------*/
	Mat Image_src, Image_dst1, Image_dst2; //存储图片Mat类型

	int g_nboxfiltervalue = 3;             //初始化方框滤波内核值
	int g_nGaussianBlurvalue = 3;          //初始化高斯滤波内核值



	/*----------------全局函数声明-------------------------*/
	//描述：
	/*----------------------------------------------------*/

	//轨迹回调函数声明
	static void change_boxFiler(int, void* );//方框滤波回调
	static void change_Gaussian(int, void* );//高斯滤波回调



int main(void)
{
	//导入图片
	Image_src = imread("pic.jpg", CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
	if (!Image_src.data)
	{
		cout << "读取图片错误\n";
	}


	//克隆原图到三个Mat类型中，（弄不清楚Mat数据类型）
	Image_dst1 = Image_src.clone();
	Image_dst2 = Image_src.clone();
	
	//创建窗口
	namedWindow("原    图", WINDOW_NORMAL );
	namedWindow("图像处理", WINDOW_NORMAL );

	//显示原图
	imshow("原    图", Image_src);

	//方框滤波函数
	createTrackbar("boxFiler_Size:", "图像处理", &g_nboxfiltervalue, 100, change_boxFiler);//创建轨迹条
	change_boxFiler(g_nboxfiltervalue, 0 );


	//高斯滤波函数
	createTrackbar("Gaussian_Size:", "图像处理", &g_nGaussianBlurvalue, 100, change_Gaussian);//创建轨迹条
	change_Gaussian(g_nGaussianBlurvalue, 0);



	waitKey(0);
	return 0;

}


/*------------------方框滤波回调---------------------*/
void change_boxFiler(int, void *)
{
	//方框滤波
	boxFilter(Image_src, Image_dst1, -1, Size(g_nboxfiltervalue+1, g_nboxfiltervalue+1));	
	//默认为true相当于blur函数。注意此函数的第5个参数不仅只是true和false

	imshow("图像处理", Image_dst1);
}


/*------------------高斯滤波回调---------------------*/
void change_Gaussian(int, void *)
{
	GaussianBlur(Image_src, Image_dst2, Size(g_nGaussianBlurvalue*2+1, g_nGaussianBlurvalue*2+1), 0, 0);
	//第4，5参数填零，sigma由平均差公式计算得到
	//内核值为奇数
	imshow("图像处理", Image_dst2);
}
