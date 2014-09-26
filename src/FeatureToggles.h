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





void* __getFeature(featureId_t id);

#define getFeature(id) _getFeature<id>()



template <featureId_t id>
typename idToType_t<id>::Type& _getFeature()
{
    using T = typename idToType_t<id>::Type;
    T * const pFeature = static_cast<T*>(__getFeature(id));
    T & feature = *pFeature;
    return feature;
}


#define featureEnabled(id) _featureEnabled<id>()

template <featureId_t Id>
bool _featureEnabled()
{
    using T = typename idToType_t<Id>::Type;
    const T & feature = _getFeature<Id>();
    return feature.isEnabled();
}



// ifdef
char const * const _getFeatureName(featureId_t id);


}

#endif /* __FEATURETOGGLE_H__ */
