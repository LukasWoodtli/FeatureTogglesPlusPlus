#include <iostream>
#include <string>
#include "FeatureToggle.h"


using namespace std;
using namespace FeaturesTogglePlusPlus;


static void printMessage(int featureNo, bool enabled);

static void printMessage(int featureNo, bool enabled)
{
    string enabledText = "";
    if (!enabled)
    {
        enabledText = " NOT";
    }


    std::cout << "Feature " << featureNo <<  enabledText << " activated" << std::endl;
}


void waitForKey()
{
    int age;
    std::cin >> age;
}

int main()
{

    bool isFeatureEnabled = featureEnabled(MyFirstFeature);
    printMessage(1, isFeatureEnabled);

    isFeatureEnabled = featureEnabled(MySecondFeature);
    printMessage(2, isFeatureEnabled);

    isFeatureEnabled = featureEnabled(MyDynamicFeature);
    printMessage(3, isFeatureEnabled);


    StaticFeature& f1 = getFeature(MyFirstFeature);
    /*Fails as it should: f3.enable(false);*/

    DynamicFeature& f3 = getFeature(MyDynamicFeature);
    f3.enable(true);
    isFeatureEnabled = featureEnabled(MyDynamicFeature);
    printMessage(3, isFeatureEnabled);

    std::cout << "Printing all features:\n";
    for (uint_fast8_t i = 0; i<FEATURE_NMB; ++i)
        std::cout << _getFeatureName((featureId_t) i);



    waitForKey();

    return 0;
}

