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
    



  bool featureEnabled(featureId_t id);
}

#endif /* __FEATURETOGGLE_H__ */
