# SKFGetter
A very simple video keyframes getter which generates PNG files of some indexes from a input video.

# Requirements
*	OpenCV 3.x
*	An appropriate set of CODECs

# Arguments
	./SKFGetter <videoFilePath> <keyframesFilePath.csv> <outputfolder>

	1. videoFilePath - The path of the input video file
	2. keyframesFilePath.csv - The path to a CSV file formated as (shotnumber, framenumber). See the FAST (https://github.com/Trojahn/FAST) program for more details.
	3. The output folder where the images will be saved. *The folder must exist!*

