#ifndef HSVERSION_H_INCLUDED
#define HSVERSION_H_INCLUDED

#ifndef SWIG
/*
Change the version numbers here
*/
#define HS_VER_MAJOR 1
#define HS_VER_MINOR 10
#define HS_VER_PATCH 0

#define BUILD_IDENTIFIER_HASH "unknown_build"
#define BUILD_BRANCH ""
#include "Version.autogen.hpp"
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

#ifdef __linux__ || defined(__APPLE__)
    #ifdef __i386__
        #define BUILD_TGT " x86"
    #else
        #define BUILD_TGT " x64"
    #endif // __arch
#else
#define BUILD_TGT ""
#endif // __linux__

const std::string branchName = BUILD_BRANCH;
const std::string identifier = BUILD_IDENTIFIER_HASH;
const std::string tgtSystem = BUILD_TGT;
const std::string featurePrefix = "feature/";
static std::string computedIdentifier = ""; // Optimization to hold the computed string rather than re-generating it each time since there will only be one instance of HyperspaceVersion anyways we can put it here safely.
#endif // !SWIG

struct HyperspaceVersion
{
    const int getDeprecatedIntegerVersion() const
    {
        return major * 100 + minor * 10 + patch;
    }

    /** Returns true if the branch begins with "feature/" */
    const bool isFeatureBuild() const
    {
        return branchName.rfind(featurePrefix, 0) == 0;
    }

    /** Returns the branch name after "feature/" if this was a feature branch, otherwise an empty string */
    const std::string getFeatureName() const
    {
        if(!isFeatureBuild())
            return "";
        return branchName.substr(featurePrefix.size());
    }

    const std::string toIdentifierString() const
    {
        if(computedIdentifier.empty())
        {
            std::string baseString = toVersionString();
            if(isFeatureBuild())
            {
                baseString = boost::str(boost::format("%s-%s") % baseString % getFeatureName());
            }
            computedIdentifier = boost::str(boost::format("%s%s %s") % baseString % tgtSystem % identifier);
        }
        return computedIdentifier;
    }

    const std::string toVersionString() const
    {
        return boost::str(boost::format("%1%.%2%.%3%") % (unsigned int) major % (unsigned int) minor % (unsigned int) patch);
    }

    const unsigned int major;
    const unsigned int minor;
    const unsigned int patch;
};

static const HyperspaceVersion HS_Version = { HS_VER_MAJOR, HS_VER_MINOR, HS_VER_PATCH };

#endif // HSVERSION_H_INCLUDED
