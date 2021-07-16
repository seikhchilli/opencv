#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
/*
////////////////images////////////////////////////


void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	imshow("image", img);
	waitKey(0);
	
}*/

//int main() {
//
//	string path = "Resources/test_video.mp4";
//	VideoCapture cap(path);
//	// cap is the object of class video capture that tries to capture test_vide0.mp4
//	if (!cap.isOpened())  // isOpened() returns true if capturing has been initialized.
//	{
//		cout << "Cannot open the video file. \n";
//		return -1;
//	}
//	
//
//	while (true) {
//		Mat img;
//		cap.read(img);
//
//		imshow("Image", img);
//		waitKey(20);
//
//
//	}
//}
// 
// 
// 
/////////////////////////////webacam///////////////////////
int main() {

	
	VideoCapture cap(0);
	// cap is the object of class video capture that tries to capture test_vide0.mp4
	if (!cap.isOpened())  // isOpened() returns true if capturing has been initialized.
	{
		cout << "Cannot open the video file. \n";
		return -1;
	}


	while (true) {
		Mat img;
		cap.read(img);

		imshow("Image", img);
		waitKey(1);


	}
}