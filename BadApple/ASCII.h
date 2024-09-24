#pragma once
#include "dependents.h"

vector<Mat> ConvertA(VideoCapture video) {
    vector<Mat> frames;
    Mat frame;
    Mat temp;
    while (true) {

        video >> frame;

        if (frame.empty())
            break;

        cv::resize(frame, temp, cv::Size(), 0.4, 0.4);

        frames.push_back(temp.clone());
    }
    video.release();
    return frames;
}

vector<string> ASCIIB(vector<Mat> frames) {
    vector<string> res;

    for (int i = 0; i < frames.size(); i++)
    {
        string str = "";
        Mat frame = frames[i];

        for (int y = 0; y < frame.rows; y += 2) {
            for (int x = 0; x < frame.cols; x++)
            {
                Vec3b& color = frame.at<Vec3b>(y, x);
                if (color[0] == 0 && color[1] == 0 && color[2] == 0)
                    str += ".";
                else if (color[0] == 255 && color[1] == 255 && color[2] == 255)
                    str += "#";
            }
            str += "\n";
        }

        res.push_back(str);
    }

    return res;
}