// Check initializer lists

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

// Size of data will be size of map - 3

class Input
{
    std::vector<double> omega1, omega2, time;
    std::map<int, std::vector<std::string>> csv_contents;
    double wheelRadius, wheelToCenter;

    public:

    std::string readFileIntoString(const std::string& path) 
    {
        auto ss = std::ostringstream{};
        std::ifstream input_file(path);
        ss << input_file.rdbuf();
        return ss.str();
    }

    
    std::map<int, std::vector<std::string>> getFileContent()
    {
        std::string filename("inputData.csv");
        std::string file_contents = readFileIntoString(filename);;
        char delimiter{','};

        std::istringstream sstream(file_contents);
        std::vector<std::string> items;
        std::string record;

        int counter{0};
        while(std::getline(sstream, record)) 
            {
                std::istringstream line(record);
                while(std::getline(line, record, delimiter)) 
                {
                    items.push_back(record);
                }
                csv_contents[counter] = items;
                items.clear();
                counter += 1;
            }

        return csv_contents;
    }

    void getCSVContents()
    {
        csv_contents = getFileContent();
    }

    void getWheelRadius()
    {
       wheelRadius = std::stod (csv_contents[1][0], nullptr); 
    }

    void getWheelToCenter()
    {
        wheelToCenter = std::stod(csv_contents[1][1], nullptr);
    }

    void getOmega1()
    {
        for(int i{3}; i < csv_contents.size(); i++)
        {
            omega1.push_back(std::stod(csv_contents[i][1]));
        }
    }

    void getOmega2()
    {
        for(int i{3}; i < csv_contents.size(); i++)
        {
            omega2.push_back(std::stod(csv_contents[i][2]));
        }
    }

    void getTime()
    {
        for(int i{3}; i < csv_contents.size(); i++)
        {
            time.push_back(std::stod(csv_contents[i][0]));
        }
    }
};