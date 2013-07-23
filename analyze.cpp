/*--- Analyze.cpp ---
 * extracts high-level features from a video file 
 * and dumps them into a splunkable log-file
 */

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
using namespace cv;

#define SIZE_REDUCTION_CONSTANT 8 

int main (int argc, char ** argv) {


	Size original_size, reduced_size; //will hold information on frame dimensions.

	/*### Step 1: get the image capture going ###*/
	if (argc != 2) {
		cout << "Error: enter the name of the file you want to work with. exiting." << endl;	
		return 0;
	}
	VideoCapture video(argv[1]);
	if (!video.isOpened()) {
		cout << "ERROR: could not open the video: " << argv[1] << endl;
		return 0;
	}



	/*### Step 2: set up displays ###*/
	namedWindow ("frame");


	/*### Step 3: start getting frames ###*/
	Mat current_frame, prev_frame;
	video >> current_frame;
	original_size = Size (current_frame.cols, current_frame.rows);
	reduced_size = Size (original_size.width/8, original_size.height/8);
	waitKey (30);


	while (true) {

		/*### Step 4: update current and previous frames ###*/
		prev_frame = current_frame.clone();
		video >> current_frame;


		/*### Step 5: get difference in pixels ###*/
		// Mat pix_difference;
		// absdiff (prev_frame, current_frame, pix_difference);
		// long total_diff = 
		imshow ("frame", current_frame);
		waitKey (30);



	}
	return 0;
}

