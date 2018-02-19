#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <utility>
#include <algorithm>

#include "Utils.hpp"

using namespace std;
using namespace cv;


int main(int argc, char* argv[]) {
	
	if(argc != 4) {
		cout << "Incorrect parameter count." << endl;
		cout << "./SKFGetter <videoFilePath> <keyframesFilePath.csv> <outputfolder>" << endl;
		cout << "Example: " << endl;
		cout << "./SKFGetter video.avi keyframes.csv keyframes_output/" << endl;
		return 1;
	}
	
	string vPath = string(argv[1]);
	if(!Utils::checkFile(vPath)) {
		cout << "The videoFilePath seems to be invalid or cannot be read" << endl;
		return 1;
	}
	
	string kfPath = string(argv[2]);
	if(!Utils::checkFile(kfPath)) {
		cout << "The keyframesFilePath seems to be invalid or cannot be read" << endl;
		return 1;
	}

	string outFolder = string(argv[3]);
	if(outFolder.back() != '/') {
		outFolder = outFolder + "/";
	}

	VideoCapture video(vPath);
	if(!video.isOpened()) {
		cout << "The video file could not be opened" << endl;
		return 1;
	}

	vector<int> params;
	params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	params.push_back(9);

	vector<int> desFrames = Utils::getKeyframesNumbers(kfPath);
	int index = 0;
	int fNum = 0;
	Mat frame;

	while(true) {
		bool status = video.read(frame);
		if (!status || fNum > desFrames.back()) {
			break;
		}
		if(fNum == desFrames[index]) {
			cv::resize(frame, frame, Size(224,224));
			imwrite(outFolder + to_string(fNum+1) + ".png", frame, params);
		}
		fNum = fNum + 1;
		if(fNum > desFrames[index]) {
			index = index + 1;
		}
	}

	return 0;
}
