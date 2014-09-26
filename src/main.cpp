/************************************************************************************/
/*! \file
 
 - Project           : FeatureToggles++
 - Functional Block  : Feature List
 
 License: This project has not a license yet. You can do what ever you want with
 this code. Just don't blame me if something goes wrong!
 
 This file has just some example use cases of the library.
 
*/
/************************************************************************************/

 
#include <iostream>
#include <string>
#include "FeatureToggles.h"


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

    std::cout << "Feature " << featureNo <<
                enabledText << " activated" << std::endl;
}


void waitForKey()
{
    int a;
    std::cin >> a;
}

int main()
{

    bool isFeatureEnabled = featureEnabled(MyFirstFeature);
    printMessage(1, isFeatureEnabled);

    isFeatureEnabled = featureEnabled(MySecondFeature);
    printMessage(2, isFeatureEnabled);

    isFeatureEnabled = featureEnabled(MyDynamicFeature);
    printMessage(3, isFeatureEnabled);


    // You cannot call enable(bool) on a static feature.
    // StaticFeature& f1 = getFeature(MyFirstFeature);
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

