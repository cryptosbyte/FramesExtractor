#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

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

        ifstream file(file_loc);
        if (!file.is_open())
        {
            cout << "File not found" << endl;
            return -1;
        }

        system("mkdir -p extraction");

        const size_t str_size = 53 + strlen(file_loc);
        char *exec_str = new char[str_size];

        snprintf(exec_str, str_size, "ffmpeg -i %s -vf fps=1 extraction/%03d.png", file_loc);
        system(exec_str);

        delete[] exec_str;
    };

    return 0;
}