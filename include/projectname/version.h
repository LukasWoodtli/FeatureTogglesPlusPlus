// <Copyright Holder>. Copyright (C) <Copyright Year(s)>. <License>
#ifndef HEADER_PROJECTNAME_VERSION_H_INCLUDED
#define HEADER_PROJECTNAME_VERSION_H_INCLUDED

#ifdef __cplusplus
#   define EXTERNC extern "C"
#else
#   define EXTERNC
#endif

EXTERNC int projectname_version_major();
EXTERNC int projectname_version_minor();
EXTERNC int projectname_version_patch();

#endif
