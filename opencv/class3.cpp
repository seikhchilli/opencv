#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void main() {
	string path = "Resources/test2.jpg";
	Mat img = imread(path);
	Mat imgResize, imgCrop;


	//cout << img.size() << endl;
	resize(img, imgResize, Size(780, 800));

	Rect roi(100, 100, 300, 250);

	imgCrop = img(roi);

	imshow("image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);

	waitKey(0);
}