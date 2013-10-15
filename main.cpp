#include <iostream>

#include <reader.h>


int main()
{

    Reader reader;
    try {
        reader.setCaseSensitivity(false);
        // read sttings file

        reader.readValidKeysFile("validkeys.txt");
        reader.readSettingsFile("test.txt");


        // print key/value pairs in different formats
        std::cout << "A (string) = " << reader.getValueByKey<std::string>("A") << std::endl;
        std::cout << "B (double) = " << reader.getValueByKey<double>("B") << std::endl;
        std::cout << "B (int)    = " << reader.getValueByKey<int>("B") << std::endl;
        std::cout << "B (string) = " << reader.getValueByKey<std::string>("B") << std::endl;
        std::cout << "B (float)  = " << reader.getValueByKey<float> ("B") << std::endl;

        // read vector numbers as ints
        auto invec = reader.getValueByKey<std::vector<int> >("numVec");
        std::cout << "numVec (int) : ";
        for (auto n:invec)
            std::cout << n <<" ";
        std::cout << std::endl;

        // read numbers as vector of doubles
        auto dnvec = reader.getValueByKey<std::vector<double> > ("numVec");
        std::cout << "numVec (double) : ";
        for (auto n:dnvec)
            std::cout << n <<" ";
        std::cout << std::endl;

        // read vector of strings
        std::vector<std::string> svec = reader.getValueByKey<std::vector<std::string> >("strVec");
        std::cout << "strVec : ";
        for (auto s:svec)
            std::cout << s << " ";
        std::cout << std::endl;

        // first read assignement as string
        // then as number, causing error
        std::cout << "C (string) = " << reader.getValueByKey<std::string>("C") << std::endl;
        std::cout << "C (float)  = " << reader.getValueByKey<float>("C") << std::endl;


    }catch(ReaderError e){ // PRINT ALL ERRORS
        std::cout << std::endl;
        e.printError();
        std::cout << std::endl;
    }

    return 0;
}

