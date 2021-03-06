
#include "typegrind/logger/demo_cout.h"
#include "gtest/gtest.h"

class LoggerDemoCoutTest : public ::testing::Test {
  protected:

    virtual void SetUp() {
      // make sure the logger is initialized before the first capture
      typegrind::logger::demo_cout::get();
    }
};

TEST_F(LoggerDemoCoutTest, LoggingNew)
{
  int* ip = nullptr;
  testing::internal::CaptureStdout();
  EXPECT_EQ(TYPEGRIND_LOG_NEW("file:13", "typeName", "canonicalName" , 137, ip), ip);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "allocation at:file:13 type:typeName canonical:canonicalName type_size:137 total_size:0 addr:0\n");
}

TEST_F(LoggerDemoCoutTest, LoggingDelete)
{
  int* ip = nullptr;
  testing::internal::CaptureStdout();
  EXPECT_EQ(TYPEGRIND_LOG_DELETE("file:13", "typeName", "canonicalName",  ip), ip);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "free at:file:13 type:typeName canonical:canonicalName addr:0\n");
}


TEST_F(LoggerDemoCoutTest, LoggingNewArray)
{
  int* ip = nullptr;
  testing::internal::CaptureStdout();
  EXPECT_EQ(TYPEGRIND_LOG_NEW_ARRAY("file:13", "typeName", "canonicalName" , 137, 5, ip), ip);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "allocation at:file:13 type:typeName canonical:canonicalName type_size:137 total_size:5 addr:0\n");
}

TEST_F(LoggerDemoCoutTest, LoggingDeleteArray)
{
  int* ip = nullptr;
  testing::internal::CaptureStdout();
  EXPECT_EQ(TYPEGRIND_LOG_DELETE_ARRAY("file:13", "typeName", "canonicalName",  ip), ip);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "free at:file:13 type:typeName canonical:canonicalName addr:0\n");
}

TEST_F(LoggerDemoCoutTest, LoggingOpNew)
{
  int* ip = nullptr;
  testing::internal::CaptureStdout();
  EXPECT_EQ(TYPEGRIND_LOG_OP_NEW("file:13", "typeName", "canonicalName" , 137, 5, ip), ip);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "allocation at:file:13 type:typeName canonical:canonicalName type_size:137 total_size:5 addr:0\n");
}

TEST_F(LoggerDemoCoutTest, LoggingOpDelete)
{
  int* ip = nullptr;
  testing::internal::CaptureStdout();
  EXPECT_EQ(TYPEGRIND_LOG_OP_DELETE("file:13", "typeName", "canonicalName",  ip), ip);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "free at:file:13 type:typeName canonical:canonicalName addr:0\n");
}

TEST_F(LoggerDemoCoutTest, LoggingOpNewArray)
{
  int* ip = nullptr;
  testing::internal::CaptureStdout();
  EXPECT_EQ(TYPEGRIND_LOG_OP_NEW_ARRAY("file:13", "typeName", "canonicalName" , 137, 5, ip), ip);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "allocation at:file:13 type:typeName canonical:canonicalName type_size:137 total_size:5 addr:0\n");
}

TEST_F(LoggerDemoCoutTest, LoggingOpDeleteArray)
{
  int* ip = nullptr;
  testing::internal::CaptureStdout();
  EXPECT_EQ(TYPEGRIND_LOG_OP_DELETE_ARRAY("file:13", "typeName", "canonicalName",  ip), ip);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "free at:file:13 type:typeName canonical:canonicalName addr:0\n");
}