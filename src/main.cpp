// dirty way to override setenv
#if defined(_WIN32) && !defined(_MSC_VER) 
    #include <windows.h>
    #include <tchar.h>

    #define setenv(name, value, overwrite) { \
        if (!SetEnvironmentVariable(TEXT(name), TEXT(value))) { \
            std::cout << "false" << std::endl; \
        } \
    }
#endif

#include <iostream>
#include <dotenv.h>
#include <stdlib.h>

int main()
{
    dotenv::init("../test.env");

    std::cout << std::getenv("DATABASE_USERNAME") << std::endl;
    std::cout << std::getenv("DATABASE_PASSWORD") << std::endl;

    std::string str;
    std::getline(std::cin, str);

    return 0;
}