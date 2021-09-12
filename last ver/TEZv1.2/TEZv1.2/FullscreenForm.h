#pragma once
#include <opencv2\opencv.hpp>
#include <opencv2\opencv_modules.hpp>
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\face.hpp>
#include <msclr\marshal_cppstd.h>
#include <sys\timeb.h>
#include <string.h>
#using <System.Data.dll>
#include <sql.h>
#include <iostream>
#include <fstream>

namespace TEZv12 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace cv;
    using namespace std;
	using namespace  cv::face;
    //public delegate void delPassData(Mat frame);

    
    /// <summary>
    /// Summary for FullscreenForm
    /// </summary>
    public ref class FullscreenForm : public System::Windows::Forms::Form
    {
    public:
		
		int _rb;
		
        System::String ^ _name;
        FullscreenForm(void)
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
        ~FullscreenForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::PictureBox^  middlePB;
    protected:



    private: System::Windows::Forms::Label^  middleLabel;


    private: System::Windows::Forms::Label^  label2;

    private: System::ComponentModel::IContainer^  components;
	
	private: System::Void FullscreenForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		//camera.~VideoCapture();
	}


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FullscreenForm::typeid));
			this->middlePB = (gcnew System::Windows::Forms::PictureBox());
			this->middleLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->middlePB))->BeginInit();
			this->SuspendLayout();
			// 
			// middlePB
			// 
			this->middlePB->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->middlePB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"middlePB.Image")));
			this->middlePB->Location = System::Drawing::Point(427, 12);
			this->middlePB->Name = L"middlePB";
			this->middlePB->Size = System::Drawing::Size(90, 90);
			this->middlePB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->middlePB->TabIndex = 3;
			this->middlePB->TabStop = false;
			// 
			// middleLabel
			// 
			this->middleLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->middleLabel->AutoSize = true;
			this->middleLabel->BackColor = System::Drawing::Color::Red;
			this->middleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->middleLabel->ForeColor = System::Drawing::Color::Black;
			this->middleLabel->Location = System::Drawing::Point(460, 45);
			this->middleLabel->Name = L"middleLabel";
			this->middleLabel->Size = System::Drawing::Size(24, 25);
			this->middleLabel->TabIndex = 6;
			this->middleLabel->Text = L"3";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label2->AutoSize = true;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(294, 253);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(421, 37);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Please Look At The Red Dot";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// FullscreenForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(961, 537);
			this->ControlBox = false;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->middleLabel);
			this->Controls->Add(this->middlePB);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"FullscreenForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FullscreenForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FullscreenForm::FullscreenForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &FullscreenForm::FullscreenForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->middlePB))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

    public:void setRB(int rb)
    {
        _rb = rb;
    }

    public:void setName(System::String ^ name)
    {
        _name = name;
    }


    private: System::Void FullscreenForm_Load(System::Object^  sender, System::EventArgs^  e)
    {
        takeProfile();
    }

             void takeProfile()
             {
				 string outputFolder = "C:\\Profiles\\";
                 System::String^ name = _name;
                 string name2 = msclr::interop::marshal_as<string>(name);
                 bool timeisup = false;
                 bool cameraOpen = true;
                 string faceCascadeName = "haarcascade_frontalface_alt.xml";
                 CascadeClassifier faceCascade;
                 faceCascade.load(faceCascadeName);
                 Mat grayFrame;
                 Mat actualFrame;
				 VideoCapture camera;
                 Mat edges, crop;
                 vector<Rect> faces;
				 vector<Mat> images;
				 vector <int> labels;
                 Rect roi_c;
                 int ab = 0;


                 while (cameraOpen)
                 {
                     //This is for profile positions
                     camera.open(0);
                     // Label counter
                     for (int i = 3; i >= 0; i--)
                     {
                         middleLabel->Text = i.ToString();
                         waitKey(1000);
                         if (i == 0)
                             timeisup = true;
                     }
                     camera >> actualFrame;

                     cvtColor(actualFrame, grayFrame, CV_BGR2GRAY);
                     equalizeHist(grayFrame, grayFrame);


                     faceCascade.detectMultiScale(grayFrame, faces, 1.4, 1, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(40, 40));
                     for (int i = 0; i < faces.size(); i++)
                     {
                         roi_c.x = faces[i].x;
                         roi_c.y = faces[i].y;
                         roi_c.width = faces[i].width;
                         roi_c.height = faces[i].height;
                         ab = roi_c.width * roi_c.height;

                         crop = actualFrame(roi_c);
                         rectangle(grayFrame, faces[i], CV_RGB(0, 255, 0), 1, 8, 0);

                         if (timeisup)
                         {
                             resize(actualFrame, grayFrame, cv::Size(256, 256), 3, 4, INTER_LINEAR);
                             cvtColor(crop, grayFrame, CV_BGR2GRAY);
                             imshow("Profile", grayFrame);
                             if (MessageBox::Show("Do you want to save this image!", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
                             {
                                 //imwrite(outputFolder+"profile" + name2 + ".png", grayFrame);
								 writeCSV(outputFolder, grayFrame);

                                 timeisup = false;
                                 cameraOpen = false;
                                 destroyWindow("Profile");
                             }
                         }
                     }
                 }

				 LBPHFaceTrainer();
                 this->Close();
             }
             /*void InsertToDB(Mat recievedImage, string username)
             {
                 SqlConnection^ connection = gcnew SqlConnection();
                 SqlDataAdapter da;
                 connection->ConnectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\Rabia\\Documents\\profile.mdf;Integrated Security=True;Connect Timeout=30";
                 if (connection->State == ConnectionState::Closed)
                     connection->Open();
                 //string mySelect = "INSERT INTO PROFILE(username, Name, Surname, Age, Email, Password, Sex, LeftImage, ProfileImage, RightImage) VALUES(@un,@n,@sn,@age,@mail,@pas,@sex,@leftimg,@prof,@rigimg)";
                 SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO PROFILE(username,) VALUES(@un,@im)", connection);

                 cmd->Parameters->AddWithValue("@un", _name);
                 try
                 {
                     cmd->ExecuteNonQuery();
                     if (connection->State == ConnectionState::Open)
                         connection->Close();
                     MessageBox::Show("Profile created", "Sucessful", MessageBoxButtons::OK, MessageBoxIcon::Information);
                 }
                 catch (EventHandler^ ev)
                 {
                     MessageBox::Show("There is something wrong with Database", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                 }
             }*/

			 void writeCSV(string filename, Mat m)
			 {
				 ofstream myfile;
				 myfile.open(filename.c_str());
				 myfile << cv::format(m, cv::Formatter::FMT_CSV) << std::endl;
				 myfile.close();
			 }

			 static void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels) 
             {
				
				 std::ifstream file(filename.c_str(), ifstream::in);
				 if (!file) {
					 string error_message = "No valid input file was given, please check the given filename.";
					 CV_Error(Error::StsBadArg, error_message);
				 }
				 string line, path, classlabel;
				 while (getline(file, line)) {
					 stringstream liness(line);
					 getline(liness, path, ';');
					 getline(liness, classlabel);
					 if (!path.empty() && !classlabel.empty()) {
						 images.push_back(imread(path, 0));
						 labels.push_back(atoi(classlabel.c_str()));
					 }
				 }
			 }



			 void LBPHFaceTrainer() 
			 {
				 //lbph face recognier model
				 Ptr<FaceRecognizer> model = cv::face::createLBPHFaceRecognizer(4,1,8,8,1.8);

				 string outputFolder = "C:\\Profiles\\";
				 vector<Mat> images;
				 vector<int> labels;

				 try {
					 read_csv(outputFolder, images, labels);

					// cout << "size of the images is " << images.size() << endl;
					// cout << "size of the labes is " << labels.size() << endl;
					// cout << "Training begins...." << endl;
				 }
				 catch (cv::Exception& e) {
					// cerr << " Error opening the file " << e.msg << endl;
					 exit(1);
				 }
				
				//training images with relevant labels 
				 model->train(images, labels);

				 //save the data in yaml file
				 model->save("C:\\Users\\Rabia\\Desktop\\rabia\\Tez\\yaml\\LBPHface.yml");

				 cout << "training finished...." << endl;

				 waitKey(10000);
			 }

	
};
}
