#include "ASCII.h"

// Driver code 
int main(int argc, char** argv)
{
	VideoCapture video("C:\\Users\\aikas\\source\\repos\\BadApple\\Video.mp4");

	if (!video.isOpened()) {
		cout << "Video doesn't find" << endl;

		cin.get();
		return -1;
	}

	vector<Mat> frames = ConvertA(video);
	vector<string> res = ASCIIB(frames);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		waitKey(1);
		system("cls");
	}

	destroyAllWindows();

	waitKey(0);
	return 0;
}
