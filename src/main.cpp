#include <iostream>
#include <string>
#include "FeatureToggle.h"


using namespace std;
using namespace FeaturesTogglePlusPlus;


static void printMessage(int featureNo, bool enabled);

static void printMessage(int featureNo, bool enabled)
{
    string enabledText = "";
    if (!enabled) {
        enabledText = " NOT";
    }
    
    
    std::cout << "Feature " << featureNo <<  enabledText << " activated" << std::endl;
}


void waitForKey() {
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
    printMessage(2, isFeatureEnabled);
    

    StaticFeature f1 = GET_FEATURE(MyFirstFeature);
    // Fails as it should: f3.enable(false);
    
    DynamicFeature f3 = GET_FEATURE(MyDynamicFeature);
    f3.enable(false);

	waitForKey();

  return 0;
}

