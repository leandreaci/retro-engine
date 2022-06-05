#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/le/Documents/Development/c++/retro_engine/cmake-build-debug
  make -f /Users/le/Documents/Development/c++/retro_engine/cmake-build-debug/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/le/Documents/Development/c++/retro_engine/cmake-build-debug
  make -f /Users/le/Documents/Development/c++/retro_engine/cmake-build-debug/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/le/Documents/Development/c++/retro_engine/cmake-build-debug
  make -f /Users/le/Documents/Development/c++/retro_engine/cmake-build-debug/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/le/Documents/Development/c++/retro_engine/cmake-build-debug
  make -f /Users/le/Documents/Development/c++/retro_engine/cmake-build-debug/CMakeScripts/ReRunCMake.make
fi

