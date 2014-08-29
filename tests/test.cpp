#include <gtest/gtest.h>

#include "stringtools/all.hpp"

TEST(String, splitting)
{

    {
        auto const s = str::split(",");
        auto expected = std::vector<std::string>{"a","b"};
        EXPECT_EQ(expected,s("a,b"));
    }

    {
        auto const s = str::split(",");
        auto expected = std::vector<std::string>{"a","b","c"};
        EXPECT_EQ(expected,s("a,b,c"));
    }

    {
        auto const s = str::split("##");
        auto expected = std::vector<std::string>{"a","b","c"};
        EXPECT_EQ(expected,s("a##b##c"));
    }
}

TEST(String, joining)
{

    {
        auto const j = str::join(",");
        EXPECT_EQ("a,b",j(std::vector<std::string>{"a","b"}));
    }

    {
        EXPECT_EQ(
            "a##b##ab",
            str::join("##")(std::vector<std::string>{"a","b","ab"})
        );
    }

}

TEST(String, formating)
{
    auto s = str::format("bla %d")(5);

    EXPECT_EQ("bla 5",s);

    EXPECT_EQ("hello world",str::format("hello %s")("world"));

    auto const f = str::format("%s world");
    EXPECT_EQ("hello world",f("hello"));
    EXPECT_EQ("hello world",f(std::string("hello")));
}

TEST(Print, print)
{
    str::print("hello");
    str::print("hello","world");
    str::print("hello","world",6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
