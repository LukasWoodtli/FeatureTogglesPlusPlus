#ifndef __FEATURE_H__
#define __FEATURE_H__

namespace FeaturesTogglePlusPlus{

    
    template<typename T>
    struct featureClassType_t
    {
        typedef T featureType;
    };
    

class IFeature
{
public:
    virtual bool isEnabled() const = 0;
    
;
protected:
    virtual ~IFeature() {}
};
    


class StaticFeature : public IFeature
{
public:
    StaticFeature() : m_enabled(false) {}
  StaticFeature(bool enable);

  virtual ~StaticFeature(void);
  virtual bool isEnabled() const {return m_enabled;}

private:
   const bool m_enabled;

};

    class DynamicFeature : public IFeature
    {
    public:
        DynamicFeature(bool enable) : m_enabled(enable) {}
        
        virtual ~DynamicFeature(void) {}
        virtual bool isEnabled() const {return m_enabled;}
        void enable(bool enable) {m_enabled = enable;}
    private:
        bool m_enabled;
        
    };
    
}

#endif /* __FEATURE_H__ */
