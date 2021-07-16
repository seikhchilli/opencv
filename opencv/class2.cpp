#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void main() {
	string path = "Resources/test2.jpg";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(3,3),3,0);
	Canny(imgBlur, imgCanny, 80, 240);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

	dilate(imgCanny, imgDil, kernel);

	erode(imgDil, imgErode, kernel);

	imshow("image", img);
	//imshow("image gray", imgGray);
	imshow("image blur", imgBlur);
	imshow("image canny", imgCanny);
	//imshow("image dilation", imgDil);
	//imshow("Image Erode", imgErode);
	waitKey(0);

}