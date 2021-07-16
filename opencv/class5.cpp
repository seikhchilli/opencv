#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;


/// <summary>
/// /////////////////////////Warp Images///////////
/// </summary>
/// 
/// 
float w = 250, h = 350;
Mat matrix, imgWarp;

void main() {
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	Point2f src[4] = { {529, 142}, {771, 190}, {405, 395}, {674, 457} };
	Point2f dst[4] = { {0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("image", img);
	imshow("image Warp", imgWarp);
	waitKey(0);

}