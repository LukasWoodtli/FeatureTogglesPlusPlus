
#ifndef __FEATURE_H__
#define __FEATURE_H__

namespace FeaturesTogglePlusPlus{

    

    

    


class StaticFeature
{
public:
    StaticFeature() : m_enabled(false) {}
    StaticFeature(bool enable);

  virtual ~StaticFeature(void);
  virtual bool isEnabled() const {return m_enabled;}

private:
   const bool m_enabled;

};

class DynamicFeature
{
public:
    DynamicFeature(bool enable) : m_enabled(enable) {}
        
    ~DynamicFeature(void) {}
    void enable(bool enable) {m_enabled = enable;}

    bool isEnabled() const {return m_enabled;}

private:
    bool m_enabled;
        
};
    
}

#endif /* __FEATURE_H__ */
