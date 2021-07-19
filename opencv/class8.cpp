#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main() {

	string path = "C:/Users/saura/Videos/16 Shots.mp4";


	VideoCapture cap(path);
	//cap.set(CAP_PROP_BUFFERSIZE, 3);
	//cap is the object of class video capture that tries to capture test_vide0.mp4
	if (!cap.isOpened())  // isOpened() returns true if capturing has been initialized.
	{
		cout << "Cannot open the video file. \n";
		return -1;
	}

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) { cout << "XML file not loaded" << endl; }

	while (true) {
		Mat img;
		cap.read(img);

		///////////////haar cascade/////////////////////////



		vector<Rect> faces;
		faceCascade.detectMultiScale(img, faces, 1.1, 10);

		/////////////////////////hog////////////////

		/*frontal_face_detector hogFaceDetector = get_frontal_face_detector();
		// Convert OpenCV image format to Dlib's image format
		cv_image<bgr_pixel> dlibIm(frameDlibHogSmall);
		// Detect faces in the image
		vector<dlib::rectangle> faces = hogFaceDetector(dlibIm);*/

		for (int i = 0; i < faces.size(); i++)
		{
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255));
		}

		imshow("image", img);
		waitKey(1);
	}
	/*string path = "Resources/test2.jpg";
	Mat img = imread(path);*/


	return 0;
}