#include <iostream>
#include <boost/version.hpp>

int main()
{
    std::cout << "Hello world!" << std::endl;
    std::cout << "Using Boost "     
        << BOOST_VERSION / 100000     << "."  // major version
        << BOOST_VERSION / 100 % 1000 << "."  // minor version
        << BOOST_VERSION % 100                // patch level
        << std::endl;
}

