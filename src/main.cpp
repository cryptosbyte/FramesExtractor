#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << "[Frames Extracter] Failed to supply arguments. Use --help for help."
             << "\n";
        return -1;
    };

    if (string(argv[1]) == "--help" || string(argv[1]) == "-h")
    {
        cout << "[Frame Extracter] Run the program with the video file location as the first argument"
             << endl
             << "\t\t  If you want to specify the amount of frames per second to extract, then use the \"-i\" option, followed by an integer."
             << endl;

        return 0;
    }
    else
    {

        const char *file_loc = argv[1];
        char *frames = "1";

        if (string(argv[2]) == "-i")
            frames = argv[3];

        ifstream file(file_loc);
        if (!file.is_open())
        {
            cout << "File not found" << endl;
            return -1;
        }

        system("mkdir -p $HOME/extraction");

        system("ffmpeg -i %s -vf fps=%s $HOME/extraction/video_ext%06d" + file_loc + frames);
    };

    return 0;
}