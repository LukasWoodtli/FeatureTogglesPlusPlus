#include "FeatureToggle.h"
#include "Feature.h"

namespace FeaturesTogglePlusPlus{

    
// objects
#define FEATURE_DEFINE_MACRO FEATURE_DEFINE_MACRO_OBJECT
#include "FeatureDefinesMacros.def"
    
    


static void * mod_features[] = {
#define FEATURE_DEFINE_MACRO FEATURE_DEFINE_MACRO_OBJECT_POINTER
#include "FeatureDefinesMacros.def"
    };

    

    void * __getFeature(featureId_t id)
    {
        return mod_features[id];
    }
    






}