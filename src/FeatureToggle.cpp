#include "FeatureToggle.h"
#include "Feature.h"

namespace FeaturesTogglePlusPlus{

    struct null_struct{};
    
    struct feature_to_type_start
    {
        enum {id = featureId_beginn};
        null_struct Object;
        typedef null_struct objectType;
    };
    
    struct feature_to_type_end
    {
        enum {id = featureId_end};
        null_struct Object;
        typedef null_struct objectType;
    };

template<typename S, featureId_t _id, typename T>
struct feature_to_type
{
    feature_to_type(S& _previousObject) : previousObject(_previousObject) {}
    enum {id = _id};
    T Object;
    typedef T objectType;
    S& previousObject;
    typedef S& previousObjectType;
    
};


    
    //test
    feature_to_type_start start_obj;
    feature_to_type_end end_obj;
    
    typedef feature_to_type<feature_to_type_start, featureId_beginn, StaticFeature> firstType_t;
    firstType_t firstObject(start_obj);
    
    typedef feature_to_type<firstType_t, MyFirstFeature, StaticFeature>  secondType_t;
    secondType_t secondObject(firstObject);

    typedef feature_to_type<secondType_t, MySecondFeature, StaticFeature>  thirdType_t;
    thirdType_t thirdObject(secondObject);
    
    typedef feature_to_type<thirdType_t, featureId_end, feature_to_type_end>  lastType_t;
    lastType_t lastObject(thirdType_t);
    //test end
    
#define FEATURE_DEFINE_MACRO FEATURE_DEFINE_MACRO_OBJECT
#include "FeatureDefinesMacros.def"
    
    
  static IFeature * mod_features[] = {
#define FEATURE_DEFINE_MACRO FEATURE_DEFINE_MACRO_OBJECT_POINTER
#include "FeatureDefinesMacros.def"
  };

  template<typename T>
  typename T::objectType& getFeature(const featureId_t _id)
    {

        
        if (_id == T::id)
        {
            return T.Object;
        }
        else
        {
            return getFeature<T>(_id);
        }

    }




    
  bool featureEnabled(featureId_t id)
  {
      
      return mod_features[id]->isEnabled();
  }
    
    IFeature * getFeature(featureId_t id)
    {
        getFeature<lastType_t>(id);
        return mod_features[id];
    }

}