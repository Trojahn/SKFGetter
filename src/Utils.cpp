#include "Utils.hpp"


vector< pair<int,int> > Utils::parseCSV(string path) {
	ifstream file(path.c_str());
	string line;
	string token;
	vector< pair<int,int> > ret;
	
	if(file.is_open()) {
		while(getline(file,line)) {
			istringstream str(line);
			vector<int> temp;
			while(getline(str,token,',')) {
				temp.push_back(atoi(token.c_str()));
			}
			ret.push_back(make_pair(temp[0],temp[1]));
			temp.clear();
		}
	}	
    file.close();
	return ret;
}

vector<int> Utils::getKeyframesNumbers(string path) {
	vector<pair<int,int>> keyframes = Utils::parseCSV(path);
	sort(keyframes.begin(),keyframes.end(),Utils::pairCompare);
	//Check if the first shot is "0". If it's not, make it so...
	if(keyframes[0].first > 0) {
		Utils::normalizePairs(keyframes,-(keyframes[0].first));
	}

	vector<int> desiredFrames;
	for(auto &t : keyframes) {
		desiredFrames.push_back(t.second);
	}
	
	return desiredFrames;
}

bool Utils::checkFile(string path) {
  	if(FILE *file = fopen(path.c_str(),"r")) {
		fclose(file);
		return true;
	}
	return false;
}

bool Utils::pairCompare(const pair<int,int> &a, const pair<int,int> &b) {
	return (a.first < b.first || (a.first == b.first && a.second < b.second));
}

void Utils::normalizePairs(vector< pair<int,int> > &pairs, int val) {
	for(int i = 0; i < pairs.size(); i++) {
		pairs[i].first = pairs[i].first + val;
		pairs[i].second = pairs[i].second + val;
	}
}

