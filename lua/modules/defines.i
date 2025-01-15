%module Defines
%include "stl.i"

%nodefaultctor SDL;
%nodefaultdtor SDL;
%nodefaultctor InternalEvents;
%nodefaultdtor InternalEvents;
%nodefaultctor RenderEvents;
%nodefaultdtor RenderEvents;

%ignore InternalEventNames;
%ignore RenderEventNames;

%{
#include "InternalEvents.h"
#include "RenderEvents.h"
#include "luaDefines.h"
%}
%include "InternalEvents.h"
%include "RenderEvents.h"
%include "luaDefines.h"
