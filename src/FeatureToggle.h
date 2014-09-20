#ifndef __FEATURETOGGLE_H__
#define __FEATURETOGGLE_H__

#include "Feature.h"

namespace FeaturesTogglePlusPlus{
  

  enum featureId_t
  {
      featureId_beginn,
#define FEATURE_DEFINE_MACRO FEATURE_DEFINE_MACRO_ID
#include "FeatureDefinesMacros.def"
      featureId_end
  };
    

    template<featureId_t id>
    struct idToType_t
    {};
    
    
    
    
    
#define FEATURE_DEFINE_MACRO FEATURE_DEFINE_MACRO_MAP_FEATURE_TO_TYPE
#include "FeatureDefinesMacros.def"
    
    


  bool featureEnabled(featureId_t id);


    IFeature* getFeature(featureId_t id);

#define GET_FEATURE(id) getFeature<id, idToType_t<id>::Type>()
    
    template<featureId_t T_id, typename T_type>
    T_type & getFeature()
    {
        return *(static_cast<T_type*>(getFeature(T_id)));
    }
    

}

#endif /* __FEATURETOGGLE_H__ */
