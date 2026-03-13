/******************************************************************************/
/*    INCLUDED FILES                                                          */
/******************************************************************************/

#include <gtest/gtest.h>
#include <sstream>
#include <string>
/* TARGET LIBRARY */
#include "file.hpp"

/******************************************************************************/
/*    TEST FUNCTIONS                                                          */
/******************************************************************************/

TEST(File, zero)
{
    File f("cases/0.txt");
    std::cout << f << std::endl;
    std::istringstream ss(f.queries);
    std::string query;
    while (std::getline(ss, query))
    {
        std::cout << query << std::endl;
        f.find(query, f.listing);
    }
    ASSERT_EQ(0, 0);
}

TEST(File, one)
{
    File f("cases/1.txt");
    std::cout << f << std::endl;
    std::istringstream ss(f.queries);
    std::string query;
    while (std::getline(ss, query))
    {
        std::cout << query << std::endl;
        f.find(query, f.listing);
    }
    ASSERT_EQ(0, 0);
}

TEST(File, two)
{
    File f("cases/2.txt");
    std::cout << f << std::endl;
    std::istringstream ss(f.queries);
    std::string query;
    while (std::getline(ss, query))
    {
        std::cout << query << std::endl;
        f.find(query, f.listing);
    }
    ASSERT_EQ(0, 0);
}

TEST(File, three)
{
    File f("cases/3.txt");
    std::cout << f << std::endl;
    std::istringstream ss(f.queries);
    std::string query;
    while (std::getline(ss, query))
    {
        std::cout << query << std::endl;
        f.find(query, f.listing);
    }
    ASSERT_EQ(0, 0);
}

TEST(File, four)
{
    File f("cases/4.txt");
    std::cout << f << std::endl;
    std::istringstream ss(f.queries);
    std::string query;
    while (std::getline(ss, query))
    {
        std::cout << query << std::endl;
        f.find(query, f.listing);
    }
    ASSERT_EQ(0, 0);
}

TEST(File, five)
{
    File f("cases/5.txt");
    std::cout << f << std::endl;
    std::istringstream ss(f.queries);
    std::string query;
    while (std::getline(ss, query))
    {
        std::cout << query << std::endl;
        f.find(query, f.listing);
    }
    ASSERT_EQ(0, 0);
}
