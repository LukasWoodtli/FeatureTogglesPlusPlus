#include <projectname/version.h>
#include "libraryinfo.h"

EXTERNC int projectname_version_major()
{ 
    return APPLICATION_VERSION_MAJOR; 
}

EXTERNC int projectname_version_minor()
{
    return APPLICATION_VERSION_MINOR;
}

EXTERNC int projectname_version_patch()
{
    return APPLICATION_VERSION_PATCH;
}
