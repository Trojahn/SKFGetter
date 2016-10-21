#ifndef UTILS_H
#define UTILS_H

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cmath>
#include <thread>

using namespace std;
using namespace cv;

class Utils {
	private:
		static vector<pair<int,int>> parseCSV(string path);
		static bool pairCompare(const pair<int,int> &a, const pair<int,int> &b);
		static void normalizePairs(vector< pair<int,int> > &pairs, int val);
		
	public:
		static vector<int> getKeyframesNumbers(string path);
		static bool checkFile(string path);
};

#endif
