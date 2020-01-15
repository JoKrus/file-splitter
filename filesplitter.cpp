#include <iostream>
#include <fstream>
#include <string>


long get_file_size(std::string filename);
int main(int argc, char *argv[])
{
    std::ifstream fs(argv[1], std::ios::in | std::ios::binary);

    std::string end(".htsfof");

    if (fs.is_open())
    {
        long size = get_file_size(argv[1]);
        long counter = 0;
        int fcount = 0;
        double wanted = size / 100.;
        double storage = 0;
        long thisIter = wanted;
        
        std::ofstream ofs(std::to_string(fcount) + end, std::ofstream::out);

        char c;
        while (fs.get(c))
        {
            ofs << c;
        }
        ofs.close();
    }

    return 0;
}

long get_file_size(std::string filename) // path to file
{
    FILE *p_file = NULL;
    p_file = fopen(filename.c_str(), "rb");
    fseek(p_file, 0, SEEK_END);
    long size = ftell(p_file);
    fclose(p_file);
    return size;
}