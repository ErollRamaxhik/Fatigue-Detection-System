/*
            faceCascade.detectMultiScale(grayFrame, faces, 1.25, 4, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(100, 100));
            for (int i = 0; i < faces.size(); i++)
            {
                Mat lastFrame = grayFrame(faces[i]);

                rectangle(actualFrame, faces[i], CV_RGB(0, 255, 0), 1, 8, 0);
                detectedFaceRegion = faces[i];
                eyesCascade.detectMultiScale(lastFrame, eyes, 1.25, 2, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(10, 10));
                for (int j = 0; j < eyes.size(); j++)
                {
                    Mat eyeroi = lastFrame(eyes[j]);

                    //rectangle(test, eyes[j], CV_RGB(0, 0, 255), 2, 8, 0);
                    rectangle(eyeroi, eyes[j], CV_RGB(255, 0, 0), 2, 8, 0);

                    equalizeHist(eyeroi, eyeroi);
                    threshold(eyeroi, eyeroi,50, 255, THRESH_BINARY + THRESH_OTSU);
                    GaussianBlur(eyeroi, grayFrame, cv::Size(5, 5), 0, 0);
                    /*for (int x=0; x < eyeroi.cols; x++)
                    {
                    for (int y = 0; y < eyeroi.rows; y++)
                    {
                    val = eyeroi.at<uchar>(y, x);
                    if (val >= 50)
                    {
                    sumx += x;
                    sumy += y;
                    numPixel++;
                    }
                    }
                    }
                    cv::Point p (sumx / numPixel, sumy / numPixel);
                    Moments m = moments((eyeroi >= 50), true);
                    cv::Point p2(m.m10 / m.m00, m.m01 / m.m00);
                    circle(eyeroi, p2, 5, cv::Scalar(255, 255, 255), -1);

                     imshow("eyeCenter", eyeroi);

                    imshow("Binary Eyes", lastFrame);
                    eyeroi.release();
                }
            }*/