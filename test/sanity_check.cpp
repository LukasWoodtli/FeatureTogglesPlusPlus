#include "../src/FeatureToggles.h"

#include <string>
using std::string;

#include <gmock/gmock.h>
using ::testing::Eq;
#include <gtest/gtest.h>
using ::testing::Test;


using namespace FeaturesTogglePlusPlus;

namespace testing
{
class FeatureToggleTest : public Test
{
protected:
    FeatureToggleTest() {}
    ~FeatureToggleTest() {}

    virtual void SetUp() {}
    virtual void TearDown() {}

};


TEST_F(FeatureToggleTest, CheckFirstFeatureEnabled)
{

    bool isFeatureEnabled = featureEnabled(MyFirstFeature);

    ASSERT_TRUE(isFeatureEnabled);
}

} // namespace testing