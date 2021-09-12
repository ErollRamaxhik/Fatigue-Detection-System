#pragma once
#include <opencv2\opencv.hpp>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\ml\ml.hpp>
#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\video\video.hpp>
#include <vector>
#include <math.h>
#include <ctype.h>
#include <iostream>
namespace Tezv11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace System::Runtime::InteropServices;
	using namespace cv;
	using namespace std;
	const float eyeTop = 0.26f;     //y
	const float eyeSide = 0.16f;  //x
	const float eyeHeight = 0.28f;  //h
	const float eyeWidth = 0.65f;       //w
	int calibrationFace = 2;
	VideoCapture capture;
	Rect faceArea;
	Mat lastFace;
	Mat actualFace;
	
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
	private: System::Windows::Forms::Button^  openCameraBtn;
	private: System::Windows::Forms::PictureBox^  camPB;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label1;


	private: System::ComponentModel::IContainer^  components;
	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openCameraBtn = (gcnew System::Windows::Forms::Button());
			this->camPB = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camPB))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openCameraBtn
			// 
			this->openCameraBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->openCameraBtn->Location = System::Drawing::Point(13, 12);
			this->openCameraBtn->Name = L"openCameraBtn";
			this->openCameraBtn->Size = System::Drawing::Size(130, 36);
			this->openCameraBtn->TabIndex = 0;
			this->openCameraBtn->Text = L"Open Camera";
			this->openCameraBtn->UseVisualStyleBackColor = true;
			this->openCameraBtn->Click += gcnew System::EventHandler(this, &MainForm::openCameraBtn_Click);
			// 
			// camPB
			// 
			this->camPB->Location = System::Drawing::Point(13, 54);
			this->camPB->Name = L"camPB";
			this->camPB->Size = System::Drawing::Size(549, 403);
			this->camPB->TabIndex = 1;
			this->camPB->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox1->Location = System::Drawing::Point(568, 44);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 100);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Status :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Chartreuse;
			this->label1->Location = System::Drawing::Point(59, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"NORMAL";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(780, 471);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->camPB);
			this->Controls->Add(this->openCameraBtn);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Main Form";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camPB))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

			private: System::Void openCameraBtn_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				Mat image;
				Mat gray;
				char key = 0;

				capture.open(0);
				if (!capture.isOpened())
					return;
				string faceCascadeName = "haarcascade_frontalface_alt.xml";
				string eyeCascadeName = "haarcascade_eye_tree_eyeglasses.xml";
				CascadeClassifier faceCascade;
				CascadeClassifier eyesCascade;
				// Load the cascades
				faceCascade.load(faceCascadeName);
				eyesCascade.load(eyeCascadeName);
				std::vector<Rect> faces,eyes;
	
				Mat face;
				while (key!='q')
				{
					capture >> image;
					cvtColor(image, gray, CV_BGR2GRAY);		

					//detectFace2(image,gray,faceCascade,faceArea);
					detectFace(face,image,gray,faceCascade,eyesCascade,faces,eyes);
					//eyeTracking(image, gray);
					DrawCVImage(camPB, image);

					key = waitKey(2);
				}
			}
			void detectFace2(Mat image, Mat grayImage, CascadeClassifier faceCascade, Rect &faceArea)
			{
				Rect face = detectLargestObject(grayImage, faceCascade);
				/*if (face.width == 0 && face.height == 0)
				{
					imshow("Result", image);
					return;
				}*/
				calibrationFace--;
				if(faceArea.height == 0 || calibrationFace<1)
				{
					faceArea = face;
					lastFace = grayImage(face);
					calibrationFace = 2;
				}
				else
				{
					actualFace = grayImage(faceArea);

					Mat flow, cflow;
					calcOpticalFlowFarneback(lastFace, actualFace, flow, 0.5, 3, 15, 3, 5, 1.2, 0);
					cvtColor(lastFace, cflow, CV_GRAY2BGR);

					int x, y;

					calcFlow(flow, cflow, 1, x, y);

					faceArea.x += x;
					faceArea.y += y;

					if (faceArea.x < 0)
						faceArea.x = 0;
					if (faceArea.y < 0)
						faceArea.y = 0;
					if (faceArea.x + faceArea.width > image.size().width - 1)
						faceArea.x = image.size().width - faceArea.width - 1;

					if (faceArea.y + faceArea.height > image.size().height - 1)
						faceArea.y = image.size().height - faceArea.height - 1;

					actualFace = grayImage(faceArea);
					eyeTracking(actualFace, lastFace);
					swap(lastFace, actualFace);
				}

			}

			void calcFlow(const Mat& flow, Mat& cflowmap, int step, int &globalMoveX, int &globalMoveY)
			{
				int localMoveX = 0;
				int localMoveY = 0;

				for (int y = 0; y < cflowmap.rows; y += step)
				{
					for (int x = 0; x < cflowmap.cols; x += step)
					{
						const Point2f& fxy = flow.at<Point2f>(y, x);

						localMoveX = localMoveX + fxy.x;
						localMoveY = localMoveY + fxy.y;
					}
				}

				globalMoveX = (localMoveX / (cflowmap.cols * cflowmap.rows)) * 2;
				globalMoveY = (localMoveY / (cflowmap.rows * cflowmap.cols)) * 2;
			}
			Rect detectLargestObject(Mat grayImage, CascadeClassifier cascFace) {

				Rect value;

				vector<Rect> faces;
				cascFace.detectMultiScale(grayImage, faces, 1.4, 2, 0, cv::Size(90, 90));
				if (faces.size() > 0) {
					
					return faces[0];
				}
				else {
					return value;
				}
			}
			
			void detectFace(Mat face,Mat image,Mat gray,CascadeClassifier faceCascade,CascadeClassifier eyesCascade, std::vector<Rect> faces,std::vector<Rect> eyes)
			 {
				 Rect face_i, eyes_i;
				 faceCascade.detectMultiScale(gray, faces, 1.4, 4, 0, cv::Size(90, 90));
				 for (int i = 0; i < faces.size(); i++)
				 {
					 face = gray(faces[i]);

					 rectangle(image, faces[i], CV_RGB(0, 255, 0), 1, 8, 0);
					 //Rect calculateEyesROI((int)(faces[i].width / 2)*1.618, (int)(faces[i].height / 2)*1.618, (int)faces[i].width / 2, (int)faces[i].height / 4);
					 //-- In each face, detect eyes,nose,mouth
					 eyesCascade.detectMultiScale(image, eyes, 1.25, 4, 0, cv::Size(30, 30));
					 for (size_t j = 0; j < eyes.size(); j++)
					 {
						 cv::Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
						 int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
						 circle(image, center, radius, Scalar(255, 0, 0), 1, 8, 0);
					 }					 
					 //eyesCascade.detectMultiScale(image, eyes, 1.4, 4, 0, cv::Size(30, 30));
					 //eyeTracking(image, face);
				 }
			 }

			 void eyeTracking(Mat &actualFace,Mat &lastFace)
			 {
				 Mat eyeActual;
				 getEyes(actualFace, eyeActual);
				 Mat eyeActualgray;
				 cvtColor(eyeActual, eyeActualgray, COLOR_GRAY2BGR);
				 medianBlur(eyeActual, eyeActual,5);
				 vector<Vec3f> circles;
				 HoughCircles(eyeActual, circles, CV_HOUGH_GRADIENT, 1, eyeActual.rows / 8, 50, 25, 5, 15);
				 for (int i = 0; i < circles.size(); i++)
				 {
					 Vec3i c = circles[i];
					 cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
					 int radius = cvRound(circles[i][2]);
					 circle(eyeActualgray, center, radius,cv::Scalar(0, 255, 0), 2,8,0);
				 }

				 imshow("Result", eyeActualgray);
			 }
			 void getEyes(Mat &face, Mat &eye)
			 {
				 cv::Size faceSize = face.size();

				 int eye_area_width = faceSize.width * eyeWidth;
				 int eye_area_height = faceSize.width *eyeHeight;
				 int eye_area_top = faceSize.height *eyeTop;

				 Rect rightEyeArea(faceSize.width*eyeSide, eye_area_top, eye_area_width, eye_area_height);
				 eye = face(rightEyeArea);
			 }


			 void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage)
			 {
				 System::Drawing::Graphics^ graphics = control->CreateGraphics();
				 System::IntPtr ptr(colorImage.ptr());
				 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
				 System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
				 graphics->DrawImage(b, rect);
				 delete graphics;
			 }





private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
{
	capture.~VideoCapture();
}
};
}
