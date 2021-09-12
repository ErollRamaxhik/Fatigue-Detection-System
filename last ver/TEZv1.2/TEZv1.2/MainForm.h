#pragma once

#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\ml.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\video\tracking.hpp>
#include <opencv2\objdetect\objdetect.hpp>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <sys\timeb.h>


//#include "RegistrationForm.h"

namespace TEZv12 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace cv;
    using namespace std;
    VideoCapture capVideo;
    //Mat actualFrame,lastFrame;
    bool _qpcInited = false;
    double PCFreq = 0.0;
    __int64 CounterStart = 0;
    double _avgdur = 0;
    double fpsStart = 0;
    double avgFps = 0;
    double fps1sec = 0;




    bool leftEyeOpen = true;
    bool eyeOpen = true;
    bool rightEyeOpen = true;
    int calibrationFace = 100;//calibrationDefault
    int blinkNumber = 0;
    int blinkNumberLeft = 0;
    int blinkNumberRight = 0;

    clock_t leftEyeCloseTime;
    clock_t eyeCloseTime;
    clock_t rightEyeCloseTime;


    const int kEyePercentTop = 25;
    const int kEyePercentSide = 13;
    const int kEyePercentHeight = 30;
    const int kEyePercentWidth = 35;

    Mat previousFace;
    Mat currentFace;

    /// <summary>
    /// Summary for MainForm
    /// </summary>
    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:

		


        MainForm(void)
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
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^  opnCamBtn;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Label^  label2;



    protected:


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
			this->opnCamBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// opnCamBtn
			// 
			this->opnCamBtn->Location = System::Drawing::Point(13, 13);
			this->opnCamBtn->Name = L"opnCamBtn";
			this->opnCamBtn->Size = System::Drawing::Size(187, 23);
			this->opnCamBtn->TabIndex = 0;
			this->opnCamBtn->Text = L"Open Camera";
			this->opnCamBtn->UseVisualStyleBackColor = true;
			this->opnCamBtn->Click += gcnew System::EventHandler(this, &MainForm::opnCamBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 98);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(141, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(522, 297);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->opnCamBtn);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Main Form";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
        int rb;
        void InitCounter()
        {
            LARGE_INTEGER li;
            if (!QueryPerformanceFrequency(&li))
                return;
            PCFreq = double(li.QuadPart) / 1000.f;
            _qpcInited = true;

        }
        double CLOCK()
        {
            if (!_qpcInited)	InitCounter();
            LARGE_INTEGER li;
            QueryPerformanceCounter(&li);
            return double(li.QuadPart) / PCFreq;
        }

        double avgdur(double newdur)
        {
            _avgdur = 0.98*_avgdur + 0.02*newdur;
            return _avgdur;
        }

        double avgfps()
        {
            if (CLOCK() - fpsStart > 1000)
            {
                fpsStart = CLOCK();
                avgFps = 0.7*avgFps + 0.3*fps1sec;
                fps1sec = 0;
            }
            fps1sec++;
            return avgFps;
        }

        void process(Mat& frame)
        {
            Sleep(3);
        }
    private: System::Void opnCamBtn_Click(System::Object^  sender, System::EventArgs^  e)
    {
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
        namedWindow("Actual Frame", 1);
        vector<Rect> faces, eyes;
        vector<Vec3f> circles;
        int sumx = 0, sumy = 0;
        float numPixel = 0;
        Rect detectedFaceRegion;
        while (true)
        {
            start = CLOCK();

            capVideo >> actualFrame;
            //process(actualFrame);
            flip(actualFrame, actualFrame, 1);
            cvtColor(actualFrame, grayFrame, CV_BGR2GRAY);
            equalizeHist(grayFrame, grayFrame);
            numPixel = 0;

            headTracing(grayFrame, actualFrame, leftEyeCascade, rightEyeCascade, faceCascade, detectedFaceRegion);

            dur = CLOCK() - start;
            label1->Text = "Average FPS " + avgfps().ToString();
            imshow("Actual Frame", actualFrame);
            if (waitKey(10) == 27) break;
            actualFrame.release();
            grayFrame.release();

        }
    }
             // this will close camera after being used
    private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
    {
        capVideo.~VideoCapture();
    }

             void eyeTracking2(Mat &matCurrentFace, Mat &matPreviousFace, CascadeClassifier leftEyeCasc, CascadeClassifier rightEyeCasc)
             {

                 Mat matEyePrevious;
                 Mat matEyeCurrent;

                 getEyesFromFace2(matPreviousFace, matEyePrevious, leftEyeCasc);
                 getEyesFromFace2(matCurrentFace, matEyeCurrent, leftEyeCasc);
                 getEyesFromFace2(matPreviousFace, matEyePrevious, rightEyeCasc);
                 getEyesFromFace2(matCurrentFace, matEyeCurrent, rightEyeCasc);
                 //imshow("EyePrevious", matEyePrevious);
                 //imshow("matRightEyePrevious", matPreviousFace);
                 //imshow("EyeCurrent", matEyeCurrent);
                 //imshow("matRightEyeCurrent", matCurrentFace);


                 detectBlink(matEyePrevious, matEyeCurrent, eyeOpen, blinkNumber, eyeCloseTime);	//left			// each eye have its own blinking detection, timer and blink counter

             }
             void eyeTracking(Mat &matCurrentFace, Mat &matPreviousFace) {

                 Mat matLeftEyePrevious;
                 Mat matRightEyePrevious;
                 Mat matLeftEyeCurrent;
                 Mat matRightEyeCurrent;

                 getEyesFromFace(matPreviousFace, matLeftEyePrevious, matRightEyePrevious);
                 getEyesFromFace(matCurrentFace, matLeftEyeCurrent, matRightEyeCurrent);
                 getPupilFromEyes(matLeftEyePrevious);
                 //imshow("matLeftEyePrevious", matLeftEyePrevious);
                 //imshow("matRightEyePrevious", matRightEyePrevious);
                 //imshow("matLeftEyeCurrent", matLeftEyeCurrent);
                 //imshow("matRightEyeCurrent", matRightEyeCurrent);

                 detectBlink(matLeftEyePrevious, matLeftEyeCurrent, leftEyeOpen, blinkNumberLeft, leftEyeCloseTime);	//left			// each eye have its own blinking detection, timer and blink counter
                 detectBlink(matRightEyePrevious, matRightEyeCurrent, rightEyeOpen, blinkNumberRight, rightEyeCloseTime);//right
             }

             void getEyesFromFace2(Mat &matface, Mat &matEye, CascadeClassifier eyeCascade)
             {
                 Rect eyes = findEye(matface, eyeCascade);
                 matEye = matface(eyes);
                 rectangle(matface, eyes, 1234);
             }

             Rect findEye(Mat capturedFace, CascadeClassifier eyeCascade)
             {
                 Rect returnValue;

                 vector<Rect> eyes;
                 eyeCascade.detectMultiScale(capturedFace, eyes, 1.25, 2, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));

                 if (eyes.size() > 0) {
                     return eyes[0];
                 }
                 else {
                     return returnValue;
                 }

             }
             void getEyesFromFace(Mat &matFace, Mat &matLeftEye, Mat &matRightEye)
             {

                 cv::Size faceSize = matFace.size();

                 int eye_region_width = faceSize.width * (kEyePercentWidth / 100.0);
                 int eye_region_height = faceSize.width * (kEyePercentHeight / 100.0);
                 int eye_region_top = faceSize.height * (kEyePercentTop / 100.0);
                 Rect leftEyeRegion(faceSize.width*(kEyePercentSide / 100.0), eye_region_top, eye_region_width, eye_region_height);
                 Rect rightEyeRegion(faceSize.width - eye_region_width - faceSize.width*(kEyePercentSide / 100.0), eye_region_top, eye_region_width, eye_region_height);            
                 
                 matLeftEye = matFace(leftEyeRegion);
                 
                 matRightEye = matFace(rightEyeRegion);
             
             }

             void getPupilFromEyes(Mat &leftEye )
             {
                 cv::Size LeftEyeSize = leftEye.size();

                 float pupilRegionWidth = LeftEyeSize.width  * (25 / 100.0);
                 float pupilRegionHeight = LeftEyeSize.height * (25 / 100.0);
                 float pupilRegionTop = LeftEyeSize.height * (50 / 100.0);

                 Rect pupilLeftRegion(LeftEyeSize.width * (40 / 100.0) + LeftEyeSize.height * (50 / 100), pupilRegionTop, pupilRegionWidth, pupilRegionHeight);

                 Mat matPupil = leftEye(pupilLeftRegion);

                 equalizeHist(matPupil, matPupil);
                 threshold(matPupil, matPupil, 10, 255, THRESH_BINARY + THRESH_OTSU);
                // GaussianBlur(matPupil, leftEye, cv::Size(5, 5), 0, 0);

                 imshow("Left Pupil", matPupil);
             }
             void detectBlink(Mat &matEyePrevious, Mat &matEyeCurrent, bool &eyeOpen, int &blinkNumber, clock_t &closeTime)
             {
                 Mat eyeflow, eyecflow;
                 calcOpticalFlowFarneback(matEyePrevious, matEyeCurrent, eyeflow, 0.5, 3, 15, 3, 5, 1.2, 0);
                 cvtColor(matEyePrevious, eyecflow, CV_GRAY2BGR);
                 int movementX, movementY;

                 calcFlowEyes(eyeflow, eyecflow, 1, movementX, movementY);


                 if (movementY == 0) {
                     return;
                 }

                 if (movementY > 0 && eyeOpen) {						//eye is now closed

                     closeTime = clock();

                     eyeOpen = false;
                     blinkNumber = blinkNumber + 1;					//increment blink count number for current eye
                                                                    //cout << eye;
                                                                    //cout << "IS CLOSED, localmovementX=";
                                                                    //cout << movementX;
                                                                    //cout << ", localmovementY=";
                                                                    //cout << movementY;
                                                                    //cout << "\n";
                                                                    //cout << '\a';
                 }
                 else if (movementY < 0 && !eyeOpen) {				//eye is now open
                     eyeOpen = true;
                     //cout << eye;
                     //cout << "IS OPEN, localmovementX=";
                     //cout << movementX;
                     //cout << ", localmovementY=";
                     //cout << movementY;
                     //cout << "\n";
                     ////cout << '\a';
                 }
             }
             void calcFlowEyes(const Mat& flow, Mat& cflowmap, int step, int &movementX, int &movementY)
             {
                 movementX = 0;
                 movementY = 0;

                 for (int y = 0; y < cflowmap.rows; y += step)
                 {
                     for (int x = 0; x < cflowmap.cols; x += step)
                     {
                         const Point2f& fxy = flow.at<Point2f>(y, x);

                         movementX = movementX + fxy.x;														//these are raw values of movement (not divided by number of pixels)
                         movementY = movementY + fxy.y;
                     }
                 }
             }

             void headTracing(Mat matCapturedGrayImage, Mat matCapturedImage, CascadeClassifier leftEyeCasc, CascadeClassifier rightEyeCasc, CascadeClassifier cascFace, Rect &detectedFaceRegion)
             {

                 Rect face = findBiggestFace(matCapturedGrayImage, cascFace);
                 if (face.width == 0 && face.height == 0) {
                     imshow("Result", matCapturedImage);									// just face
                     return;																// no face was found
                 }

                 calibrationFace = calibrationFace - 1;

                 if (detectedFaceRegion.height == 0 || calibrationFace < 1) {			//first frame cannot calculate flow; there have to be previous frame to do that; face is calibrated each "x" frames (here)
                     detectedFaceRegion = face;
                     previousFace = matCapturedGrayImage(face);
                     calibrationFace = 100;		//calibrationDefault					//reset calibration number to default (from constants.h)
                 }
                 else {																	//first frame captured with face; now will be calculated optical flow

                     currentFace = matCapturedGrayImage(detectedFaceRegion);

                     //imshow("currentFace", currentFace);
                     //imshow("previousFace", previousFace);

                     Mat flow, cflow;
                     calcOpticalFlowFarneback(previousFace, currentFace, flow, 0.5, 3, 15, 3, 5, 1.2, 0);

                     cvtColor(previousFace, cflow, CV_GRAY2BGR);

                     int globalMovementX, globalMovementY;

                     calcFlow(flow, cflow, 1, globalMovementX, globalMovementY);


                     detectedFaceRegion.x = detectedFaceRegion.x + globalMovementX;		//move rectangle to a new place (according to calculated optical flow)
                     detectedFaceRegion.y = detectedFaceRegion.y + globalMovementY;

                     if (detectedFaceRegion.x < 0) {										//when the rectangle is out of visible window; so it doesn't crash
                         detectedFaceRegion.x = 0;
                     }
                     if (detectedFaceRegion.y < 0) {
                         detectedFaceRegion.y = 0;
                     }

                     if (detectedFaceRegion.x + detectedFaceRegion.width > matCapturedImage.size().width - 1) {				// when the rectangle is out of visible window; so it doesn't crash
                         detectedFaceRegion.x = matCapturedImage.size().width - detectedFaceRegion.width - 1;
                     }
                     if (detectedFaceRegion.y + detectedFaceRegion.height > matCapturedImage.size().height - 1) {
                         detectedFaceRegion.y = matCapturedImage.size().height - detectedFaceRegion.height - 1;
                     }

                     //rectangle(matCapturedImage, detectedFaceRegion, 12);				//na povodnom obrazku sa ukaze novo posunuty rectangle
                     currentFace = matCapturedGrayImage(detectedFaceRegion);				//currentFace sa posunie na novu poziciu, na ktoru podla porovnania s previousFace patri
                     imshow("Current", currentFace);
                     // teraz je nutne porovnat predch. tvar a aktualnu a pozriet float uz konkretnych oci 
                     eyeTracking(currentFace, previousFace);
                     //eyeTracking2(currentFace, previousFace, leftEyeCasc, rightEyeCasc);								//when we have two stabilised faces (previous and current) now we can calculate their movement

                     swap(previousFace, currentFace);									//previousFace is now currentFace and vice versa
                 }

                 rectangle(matCapturedImage, face, 1234);								//make rectangle around face

                 if (eyeOpen) {																	//when the eye is open, circle will be drawn on top of the image
                     circle(matCapturedImage, cv::Point(40, 40), 20, Scalar(102, 255, 51), 40, 8, 0);
                 }
                 else {																				//when the eye is closed, time from closing is calculated and drawn on the image
                     circle(matCapturedImage, cv::Point(40, 40), 20, Scalar(0, 0, 255), 40, 8, 0);

                     double diffticks = clock() - eyeCloseTime;
                     double diffms = diffticks / (CLOCKS_PER_SEC / 1000);
                     //putText(matCapturedImage, to_string_with_precision(diffms), cvPoint(80, 100), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(50, 50, 50), 1, CV_AA);

                     if (diffms > 5000) cout << "\a";												//when the time of closed is is bigger than 5 seconds, beeping starts

                 }

                 putText(matCapturedImage, to_string(blinkNumberLeft), cvPoint(100, 45), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(100, 100, 100), 1, CV_AA);		//number of eye blinks
                 putText(matCapturedImage, to_string(blinkNumberRight), cvPoint(520, 45), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(100, 100, 100), 1, CV_AA);

                 imshow("Result", matCapturedImage);										//show face with rectangle
             }

             Rect findBiggestFace(Mat matCapturedGrayImage, CascadeClassifier cascFace) {

                 Rect returnValue;

                 vector<Rect> faces;
                 cascFace.detectMultiScale(matCapturedGrayImage, faces, 1.2, 2, 0 | CV_HAAR_SCALE_IMAGE | CV_HAAR_FIND_BIGGEST_OBJECT, cv::Size(150, 150), cv::Size(300, 300));

                 if (faces.size() > 0) {
                     return faces[0];
                 }
                 else {
                     return returnValue;
                 }
             }

             void calcFlow(const Mat& flow, Mat& cflowmap, int step, int &globalMovementX, int &globalMovementY)
             {
                 int localMovementX = 0;
                 int localMovementY = 0;

                 for (int y = 0; y < cflowmap.rows; y += step)
                 {
                     for (int x = 0; x < cflowmap.cols; x += step)
                     {
                         const Point2f& fxy = flow.at<Point2f>(y, x);

                         localMovementX = localMovementX + fxy.x;
                         localMovementY = localMovementY + fxy.y;
                     }
                 }

                 globalMovementX = (localMovementX / (cflowmap.cols * cflowmap.rows)) * 2;							//these are usable values for global movement of face (for example + 2 pixels to axis x)
                 globalMovementY = (localMovementY / (cflowmap.rows * cflowmap.cols)) * 2;
             }
    };
}
