/************************************************************************************/
/*! \file
 
 - Project           : FeatureToggles++
 - Functional Block  : Feature List
 
 License: This project has not a license yet. You can do what ever you want with
 this code. Just don't blame me if something goes wrong!
 
 This is the main entry point to get access to the feature objects and the information
 they store. Use the macro getFeature(id) to get a reference to a feature object.
 
 */
/************************************************************************************/

#ifndef __FEATURETOGGLE_H__
#define __FEATURETOGGLE_H__

#include "Feature.h"

namespace FeaturesTogglePlusPlus
{


enum featureId_t
{
#define FEATURE_DEFINE_MACRO FEATURE_DEFINE_MACRO_ID
#include "FeatureDefinesMacros.def"
    FEATURE_NMB
};


template<featureId_t id>
struct idToType_t
{};






#define FEATURE_DEFINE_MACRO FEATURE_DEFINE_MACRO_MAP_FEATURE_TO_TYPE
#include "FeatureDefinesMacros.def"





void * const __getFeature(featureId_t id);

#define getFeature(id) _getFeature<id>()



template <featureId_t id>
typename idToType_t<id>::Type& _getFeature()
{
    typedef idToType_t<id>::Type T;
    T * const pFeature = static_cast<T*>(__getFeature(id));
    T & feature = *pFeature;
    return feature;
}


#define featureEnabled(id) _featureEnabled<id>()

template <featureId_t Id>
bool _featureEnabled()
{
    typedef idToType_t<Id>::Type T;
    const T & feature = _getFeature<Id>();
    return feature.isEnabled();
}



// ifdef
char const * const _getFeatureName(featureId_t id);


}

#endif /* __FEATURETOGGLE_H__ */
