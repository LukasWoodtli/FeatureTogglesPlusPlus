#include <iostream>
#include <string>
#include "FeatureToggle.h"


using namespace std;
using namespace FeaturesTogglePlusPlus;

static void printMessage(const string & msg);

static void printMessage(const string & msg)
{
  std::cout << msg << std::endl;
}
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
    



	waitForKey();

  return 0;
}

