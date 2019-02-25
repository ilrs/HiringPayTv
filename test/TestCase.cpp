#include <gtest/gtest.h>

#include "Client.h"
#include "JsonReader.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

TEST(Client, test) 
{
	Client client;
	client.Request("argo", "");
    JsonReader reader;
    EXPECT_TRUE(reader.LoadFile(kJsonLocation.c_str()));
    EXPECT_FALSE(reader.LoadFile("wrong_file"));
	reader.PrintContent();
}