#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string> 

using namespace cv;
using namespace std;

	/*----------------ȫ�ֱ�������-------------------------*/
	//������
	/*----------------------------------------------------*/
	Mat Image_src, Image_dst1, Image_dst2; //�洢ͼƬMat����

	int g_nboxfiltervalue = 3;             //��ʼ�������˲��ں�ֵ
	int g_nGaussianBlurvalue = 3;          //��ʼ����˹�˲��ں�ֵ



	/*----------------ȫ�ֺ�������-------------------------*/
	//������
	/*----------------------------------------------------*/

	//�켣�ص���������
	static void change_boxFiler(int, void* );//�����˲��ص�
	static void change_Gaussian(int, void* );//��˹�˲��ص�



int main(void)
{
	//����ͼƬ
	Image_src = imread("pic.jpg", CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
	if (!Image_src.data)
	{
		cout << "��ȡͼƬ����\n";
	}


	//��¡ԭͼ������Mat�����У���Ū�����Mat�������ͣ�
	Image_dst1 = Image_src.clone();
	Image_dst2 = Image_src.clone();
	
	//��������
	namedWindow("ԭ    ͼ", WINDOW_NORMAL );
	namedWindow("ͼ����", WINDOW_NORMAL );

	//��ʾԭͼ
	imshow("ԭ    ͼ", Image_src);

	//�����˲�����
	createTrackbar("boxFiler_Size:", "ͼ����", &g_nboxfiltervalue, 100, change_boxFiler);//�����켣��
	change_boxFiler(g_nboxfiltervalue, 0 );


	//��˹�˲�����
	createTrackbar("Gaussian_Size:", "ͼ����", &g_nGaussianBlurvalue, 100, change_Gaussian);//�����켣��
	change_Gaussian(g_nGaussianBlurvalue, 0);



	waitKey(0);
	return 0;

}


/*------------------�����˲��ص�---------------------*/
void change_boxFiler(int, void *)
{
	//�����˲�
	boxFilter(Image_src, Image_dst1, -1, Size(g_nboxfiltervalue+1, g_nboxfiltervalue+1));	
	//Ĭ��Ϊtrue�൱��blur������ע��˺����ĵ�5����������ֻ��true��false

	imshow("ͼ����", Image_dst1);
}


/*------------------��˹�˲��ص�---------------------*/
void change_Gaussian(int, void *)
{
	GaussianBlur(Image_src, Image_dst2, Size(g_nGaussianBlurvalue*2+1, g_nGaussianBlurvalue*2+1), 0, 0);
	//��4��5�������㣬sigma��ƽ���ʽ����õ�
	//�ں�ֵΪ����
	imshow("ͼ����", Image_dst2);
}
