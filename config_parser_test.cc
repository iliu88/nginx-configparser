#include "gtest/gtest.h"
#include "config_parser.h"

TEST(NginxConfigParserTest, SimpleConfig) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("example_config", &out_config);

  EXPECT_TRUE(success);
}


TEST(NginxConfigParserTest, ProxyConfig) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("proxy_config", &out_config);

  EXPECT_TRUE(success);
}

TEST(NginxConfigParserTest, NotNestedConfig) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool fail = parser.Parse("hello world!", &out_config);

  EXPECT_FALSE(fail);
}

TEST(NginxConfigParserTest, MoreComplexConfig) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("nginxExample_config", &out_config);

  EXPECT_TRUE(success);
}

// This is the reason the above complex config failed
TEST(NginxConfigParserTest, NestedConfig) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("foo { bar { sweet; }}", &out_config);

  EXPECT_TRUE(success);
}


