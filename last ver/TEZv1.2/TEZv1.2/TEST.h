#pragma once

#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include<opencv2\core\core.hpp>
#include <opencv2\ml.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\video\tracking.hpp>
#include <opencv2\objdetect\objdetect.hpp>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <sys\timeb.h>
namespace TEZv12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

    using namespace cv;
    using namespace std;

	/// <summary>
	/// Summary for TEST
	/// </summary>
	public ref class TEST : public System::Windows::Forms::Form
	{
	public:
		TEST(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TEST()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->SuspendLayout();
            // 
            // TEST
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Name = L"TEST";
            this->Text = L"TEST";
            this->Load += gcnew System::EventHandler(this, &TEST::TEST_Load);
            this->ResumeLayout(false);

        }
#pragma endregion
            private: System::Void TEST_Load(System::Object^  sender, System::EventArgs^  e) 
            {
                VideoCapture capVideo;
                string faceCascadeName = "haarcascade_frontalface_alt.xml";
                string eyesLeftCascadeName = "haarcascade_mcs_lefteye.xml";
                string eyesRightCascadeName = "haarcascade_mcs_righteye.xml";
                CascadeClassifier faceCascade, leftEyeCascade, rightEyeCascade;
                capVideo.open(0);
                if (!capVideo.isOpened())
                    return;

                faceCascade.load(faceCascadeName);
                leftEyeCascade.load(eyesLeftCascadeName);
                rightEyeCascade.load(eyesRightCascadeName);

                double start, dur;

                Mat grayFrame;
                Mat actualFrame;

               
                Mat matLeftEyeCurrent;
                Mat matRightEyeCurrent;
                namedWindow("Actual Frame", 1);
                vector<Rect> faces, eyes;
                vector<Vec3f> circles;
                vector<Point2d> framePoints;

                int sumx = 0, sumy = 0;
                float numPixel = 0;
                Rect detectedFaceRegion;
                while (true)
                {
                    Mat matLeftEye;
                    Mat matRightEye;
                    capVideo >> actualFrame;
                    //process(actualFrame);
                    flip(actualFrame, actualFrame, 1);
                    cvtColor(actualFrame, grayFrame, CV_BGR2GRAY);
                    equalizeHist(grayFrame, grayFrame);

                    faceCascade.detectMultiScale(grayFrame, faces, 1.15, 1, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(60, 60));
                    if (faces.size() != 0)
                    {
                        Mat matFaces = grayFrame(faces[0]);
                        rectangle(actualFrame, faces[0], 12);
                        FindEyes(matFaces, matLeftEye, matRightEye,actualFrame); 

                        matFaces.release();
                    }

                    imshow("Actual Frame", actualFrame);
                    if (waitKey(10) == 27) break;
                    actualFrame.release();
                    grayFrame.release();

                }
            }
             void FindEyes(Mat faceCascade, Mat& matLeftEye, Mat& matRightEye, Mat actualFrame)
             {
                 cv::Size faceSize = faceCascade.size();

                 int eye_region_width = faceSize.width * (40 / 100.0);
                 int eye_region_height = faceSize.height * (40 / 100.0);
                 int eye_region_top = faceSize.height * (35 / 100.0);
                 Rect leftEyeRegion(faceSize.width*(13 / 100.0), eye_region_top, eye_region_width, eye_region_height);
                 Rect rightEyeRegion(faceSize.width - eye_region_width - faceSize.width*(13 / 100.0), eye_region_top, eye_region_width, eye_region_height);

                 matLeftEye = faceCascade(leftEyeRegion);

                 matRightEye = faceCascade(rightEyeRegion);
                 // Left Eye Points
                 circle(faceCascade, cv::Point(eye_region_width,eye_region_height),2,cv::Scalar(255,255,255),1,5,0); // Near nose 
                 circle(faceCascade, cv::Point(eye_region_width- (faceSize.width * (18 / 100.0)), eye_region_height), 2, cv::Scalar(255, 255, 255), 1, 5, 0); // 
                 // Right eye points
                 circle(faceCascade, cv::Point(eye_region_width*1.95, eye_region_height), 2, cv::Scalar(255, 255, 255), 1, 5, 0);
                 circle(faceCascade, cv::Point(eye_region_width + (faceSize.width * (18 / 100.0)), eye_region_height), 2, cv::Scalar(255, 255, 255), 1, 5, 0); // Near Nose

                 int nose_width = eye_region_width + (faceSize.width * (9 / 100.0));
                 // Nose Points
                 circle(faceCascade, cv::Point(nose_width, eye_region_height+30), 2, cv::Scalar(255, 255, 255), 1, 5, 0);
                 imshow("TEST", faceCascade);
             }
    };
}
