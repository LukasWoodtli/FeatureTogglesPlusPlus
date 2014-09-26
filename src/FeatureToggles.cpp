/************************************************************************************/
/*! \file

 - Project           : FeatureToggles++
 - Functional Block  : Feature List, handling of all feature objects
 
 License: This project has not a license yet. You can do what ever you want with
 this code. Just don't blame me if something goes wrong!

 In this file a list with all feature obects is generated. There is also an array with
 pointers (void*) toeach object. And there are some functions that help getting a
 feature object (and casting is properly).

 */
/************************************************************************************/


#include "FeatureToggles.h"
#include "Feature.h"

// ifdef
#include <string.h>
#include <stdint.h>


namespace FeaturesTogglePlusPlus
{


// objects of features
#define FEATURE_DEFINE_MACRO FEATURE_DEFINE_MACRO_OBJECT
#include "FeatureDefinesMacros.def"



// pointer to the feature objects
static void * const mod_features[] =
{
#define FEATURE_DEFINE_MACRO FEATURE_DEFINE_MACRO_OBJECT_POINTER
#include "FeatureDefinesMacros.def"
};



//#if defined(DISCOVER_FEATUES_BY_NAME)
// names of the features (as char*)
static char const * const mod_featureNames[] =
{
#define FEATURE_DEFINE_MACRO FEATURE_DEFINE_MACRO_NAME_STRINGS
#include "FeatureDefinesMacros.def"
};


char const * const _getFeatureName(featureId_t id)
{
    //assert((int) id < numOfFeatures)
    return mod_featureNames[id];
}



featureId_t _getFeaureId(char const * const featureName)
{
    for (uint_fast8_t i=0; i<FEATURE_NMB; ++i)
    {

        const uint_least8_t MAX_LEN_OF_STRING = strlen(mod_featureNames[i]); // the strings are generated: so they are '\0' terminated
        if (0 == strncmp(mod_featureNames[i], featureName, MAX_LEN_OF_STRING))
        {
            return static_cast<featureId_t>(i);
        }
    }
    return FEATURE_NMB;
}



void * const __getFeature(featureId_t id)
{
    return mod_features[id];
}







}