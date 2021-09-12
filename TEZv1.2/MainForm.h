#pragma once
#pragma comment(lib, "winmm.lib")
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv_modules.hpp>
#include<opencv2\core\core.hpp>
#include <opencv2\ml.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\objdetect\objdetect.hpp>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <string.h>
#include <sys\timeb.h>
#include <tbb\tbb.h>


namespace TEZv12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	using namespace std;
    using namespace tbb;

	
    class Parallel_process : public cv::ParallelLoopBody
    {
    private:
        Mat actFrm;
        bool eyes = false;
        clock_t time;

    public:
        Parallel_process(){}
       // Parallel_process(Mat actualFrame, bool eyeOpen, clock_t closeTime) : actFrm(actualFrame), eyes(eyeOpen), time(closeTime) {}

        virtual void operator()(const cv::Range& range) const
        {
            for (int i = range.start; i < range.end; i++)
            {
                PlaySound(TEXT("alarm.wav"), NULL, SND_SYNC);
               
            }
        }
       /* void warning(Mat actualFrame, bool eyeOpen, clock_t closeTime)
    {
        

        }*/
    
    };

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
	private: System::Windows::Forms::Panel^  panel1;


	protected:
		//Mat actualFrame,lastFrame;
	bool _qpcInited = false;
	double PCFreq = 0.0;
	__int64 CounterStart = 0;
	double _avgdur = 0;
	double fpsStart = 0;
	double avgFps = 0;
	double fps1sec = 0;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
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
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(16, 162);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 100);
			this->panel1->TabIndex = 3;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(273, 297);
			this->Controls->Add(this->panel1);
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
			if (!_qpcInited)    InitCounter();
			LARGE_INTEGER li;
			QueryPerformanceCounter(&li);
			return double(li.QuadPart) / PCFreq;
		}

		double avgdur(double newdur)
		{
			_avgdur = 0.98*_avgdur + 0.02*newdur;
			return _avgdur;
		}

		double funcAvgfps()
		{
			if (CLOCK() - fpsStart>1000)
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
		VideoCapture capVideo;
		capVideo.open(0);
		if (!capVideo.isOpened())
			return;

		bool eyeOpen = true;
		clock_t closeTime;
		double start, dur;
		string faceCascadeName = "haarcascade_frontalface_default.xml";
		string eyesCascadeName = "haarcascade_mcs_righteye_alt.xml";
		CascadeClassifier faceCascade, eyesCascade;
		faceCascade.load(faceCascadeName);
		eyesCascade.load(eyesCascadeName);
		Mat grayFrame;
		Mat actualFrame;
		namedWindow("Actual Frame", 1);
		vector<Rect> faces, eyes;
		vector<Vec3f> circles;
		int sumx = 0, sumy = 0;
		float numPixel = 0;
        
		while (true)
		{
			start = CLOCK();

			capVideo >> actualFrame;
			process(actualFrame);
			cvtColor(actualFrame, grayFrame, CV_BGR2GRAY);
			equalizeHist(grayFrame, grayFrame);

			numPixel = 0; 
			faceCascade.detectMultiScale(grayFrame, faces, 1.25, 4, 0 | CASCADE_FIND_BIGGEST_OBJECT, cv::Size(30, 30));
			if (faces.size() > 0)
			{
                Mat lastFrame = grayFrame(faces[0]);
				rectangle(actualFrame, faces[0], CV_RGB(0, 255, 0), 3, 8, 0);

				eyesCascade.detectMultiScale(lastFrame, eyes, 1.45, 2, 0 | CASCADE_FIND_BIGGEST_OBJECT, cv::Size(10, 10));
				if(eyes.size()>0)
				{
					eyeOpen = true;
					Rect eye = eyes[0];
					Mat prevEyeroi = lastFrame(eye);
					Mat currentEyeroi = lastFrame(eye);
					//check eyes is open or close
					
					//rectangle(test, eyes[j], CV_RGB(0, 0, 255), 2, 8, 0);
					
					equalizeHist(currentEyeroi, currentEyeroi);

					threshold(prevEyeroi, currentEyeroi, 50, 255, THRESH_BINARY + THRESH_OTSU);
					GaussianBlur(prevEyeroi, grayFrame, cv::Size(5, 5), 0, 0);

					threshold(currentEyeroi, currentEyeroi, 50, 255, THRESH_BINARY + THRESH_OTSU);
					GaussianBlur(currentEyeroi, grayFrame, cv::Size(5, 5), 0, 0);
					rectangle(lastFrame, eyes[0], CV_RGB(0, 255, 0), 2, 8, 0);

					Moments m = moments((currentEyeroi >= 50), true);
					cv::Point p2(int(m.m10 / m.m00),int( m.m01 / m.m00));
					circle(currentEyeroi, p2, 5, cv::Scalar(255, 255, 255), -1);
					imshow("Binary Eyes", lastFrame);

					//detectBlink(prevEyeroi, currentEyeroi, eyeOpen, closeTime);
					prevEyeroi.release();
					currentEyeroi.release();
				}
				else
				{
					eyeOpen = false;
					closeTime = clock();
					rectangle(actualFrame, faces[0], CV_RGB(255, 0, 0), 3, 8, 0);
					circle(actualFrame, cv::Point(40, 40), 20, Scalar(0, 0, 255), 40, 8, 0);
					putText(actualFrame,"open eyes please", cvPoint(100, 45), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(100, 100, 100), 1, CV_AA);
                        //warn user if eyes is close more time than 5 seconds
                    if (eyeOpen)
                    {                                                                 //when the eye is open, circle will be drawn on top of the image
                        circle(actualFrame, cv::Point(40, 40), 20, Scalar(102, 255, 51), 40, 8, 0);
                    }
                    else
                    {                                                                             //when the eye is closed, time from closing is calculated and drawn on the image
                        circle(actualFrame, cv::Point(40, 40), 20, Scalar(0, 0, 255), 40, 8, 0);

                        double diffticks = clock() - closeTime;
                        double diffms = diffticks / (CLOCKS_PER_SEC / 1000);
                        //putText(matCapturedImage, to_string_with_precision(diffms), cvPoint(80, 100), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(50, 50, 50), 1, CV_AA);

                        if (diffms >= 3.5)                                              //when the time of closed is is bigger than 5 seconds, beeping starts
                        {
                            cv::parallel_for_(cv::Range(0, 2), Parallel_process());
                        }
                    }
                    
				}
			}
			else
			{
				putText(actualFrame,"Face Not Detected", cvPoint(100, 45), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(100, 100, 100), 1, CV_AA);       //number of eye blinks
			}
			

			dur = CLOCK() - start;
			label1->Text = "Average FPS " + funcAvgfps().ToString();
            imshow("Actual Frame", actualFrame);
			if (waitKey(10) == 27) break;
			actualFrame.release();
			grayFrame.release();

		}
	}

	//void blinkDetectSelim();
			 void detectBlink(Mat prevEyeROI, Mat curEyeROI, bool &eyeOpen, clock_t &closeTime)
			 {
				 /*Mat flow, cflow;
				 calcOpticalFlowFarneback(previousFace, currentFace, flow, 0.5, 3, 15, 3, 5, 1.2, 0);

				 cvtColor(previousFace, cflow, CV_GRAY2BGR);

				 int globalMovementX, globalMovementY;

				 calcFlow(flow, cflow, 1, globalMovementX, globalMovementY);*/
				 


				 //calculate eyes flow
				 Mat flow;
				 Mat cflow;
				 int step=0;
				 int movementX;
				 int movementY;
				 
				 calcOpticalFlowFarneback(prevEyeROI, curEyeROI, flow, 0.5,2, 15, 3, 7, 1.5, 0);
				 cvtColor(prevEyeROI, cflow, CV_GRAY2BGR);
				 //cvtColor(prevEyeROI, cflow, CV_BGR2GRAY);
				 movementX = 0;
				 movementY = 0;

				 for (int y = 0; y < cflow.rows; y += step)
				 {
					 for (int x = 0; x < cflow.cols; x += step)
					 {
						 const Point2f& fxy = flow.at<Point2f>(y, x);

						 movementX =(int)( movementX + fxy.x);														//these are raw values of movement (not divided by number of pixels)
						 movementY =(int)( movementY + fxy.y);
					 }
				 }

				 //check eyes are open or close
				 if (movementY == 0) {
					 return;
				 }

				 if (movementY > 0 && eyeOpen) {						//eye is now closed

					 closeTime = clock();

					 eyeOpen = false;
				 }
				 else if (movementY < 0 && !eyeOpen) {				//eye is now open
					 eyeOpen = true;
				 }

				 /*
				 if (eyeROI.empty())
				 {
					 closeTime = clock();
					 eyeOpen = false;
				 }
				 else
				 {
					 eyeOpen = true;
				 }*/
			 }




            



             

			 // this will close camera after being used
	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		VideoCapture capVideo;
		capVideo.~VideoCapture();
	}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		/*
		RegistrationForm^ rf = gcnew RegistrationForm;
		rf->ShowDialog();
		*/
	}
	};
}
