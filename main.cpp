#include <iostream>

#include <reader.h>


int main() {
    Reader reader;
    try {
        reader.setCaseSensitivity(false); // ignore key case
        // read sttings file
        //
        //reader.readValidKeysFile("validkeys.txt");
        reader.readSettingsFile("test.txt");
        //
        // Display all key names found in file
        std::cout << "valid keys found in file : ";
        for (const auto &key : reader.getAllKeys())
            std::cout << key << " ";
        std::cout << std::endl;
        //
        // print key/value pairs in different formats
        std::cout << "\nread key as different types :" << std::endl;
        std::cout << "B as string = " << reader.getValueByKey<std::string>("B") << std::endl;
        std::cout << "B as double = " << reader.getValueByKey<double>("B") << std::endl;
        std::cout << "B as int    = " << reader.getValueByKey<int>("B") << std::endl;
        //
        // read vector numbers as ints
        std::cout << "\nread value as vector of different types :" << std::endl;
        auto invec = reader.getValueByKey<std::vector<int> >("numVec");
        std::cout << "numVec as ints : ";
        for (auto n:invec)
            std::cout << n <<" ";
        std::cout << std::endl;
        // read numbers as vector of doubles
        auto dnvec = reader.getValueByKey<std::vector<double> > ("numVec");
        std::cout << "numVec as doubles : ";
        for (auto n:dnvec)
            std::cout << n <<" ";
        std::cout << std::endl;
        //
        // read vector of strings
        std::cout << "\nread vector of strings : " << std::endl;
        std::vector<std::string> svec = reader.getValueByKey<std::vector<std::string> >("strVec");
        std::cout << "strVec : ";
        for (auto s:svec)
            std::cout << s << " ";
        std::cout << std::endl;
        //
        // Read key/values using default value
        std::cout << "\nread key that is missing but use provided default string value : " << reader.get<std::string>("K", "default string") << std::endl;
        //
        // using vector initialiser list
        std::cout << "read key that is missing but use provided default vector of ints value : ";
        auto vec = reader.get<std::vector<int>>("K", {1,2,3});
        for(auto v : vec) std::cout << v << " " ;
        std::cout << std::endl;
        //
        // first read assignement as string
        // then as number, causing error
        try {
        std::cout << "\nread value as string then incorrectly as a number " << std::endl;
        std::cout << "C (string) = " << reader.getValueByKey<std::string>("C") << std::endl;
        std::cout << "C (float)  = " << reader.getValueByKey<float>("C") << std::endl;
        } catch (ReaderError e) {
            e.printError();
        }

        //
        // Read empty vector, make sure its length is 0
        std::vector<int> emptyVec = reader.getValueByKey<std::vector<int>>("emptyVec");
        std::cout << "lenght of empty vector is " << emptyVec.size() << std::endl;


    } catch(ReaderError e) { // PRINT ALL ERRORS
        std::cout << std::endl;
        e.printError();
        std::cout << std::endl;
    }

    return 0;
}

