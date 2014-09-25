
#ifndef __FEATURE_H__
#define __FEATURE_H__

namespace FeaturesTogglePlusPlus
{



#define DISABLE_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&);   \
void operator=(const TypeName&)



class StaticFeature
{
    DISABLE_COPY_AND_ASSIGN(StaticFeature);
public:
    StaticFeature() : m_enabled(false) {}
    StaticFeature(bool enable);

    virtual ~StaticFeature(void);
    virtual bool isEnabled() const
    {
        return m_enabled;
    }

private:
    const bool m_enabled;

};

class DynamicFeature
{
    DISABLE_COPY_AND_ASSIGN(DynamicFeature);
public:
    DynamicFeature(bool enable) : m_enabled(enable) {}

    ~DynamicFeature(void) {}
    void enable(bool enable)
    {
        m_enabled = enable;
    }

    bool isEnabled() const
    {
        return m_enabled;
    }

private:
    bool m_enabled;

};

}

#endif /* __FEATURE_H__ */
