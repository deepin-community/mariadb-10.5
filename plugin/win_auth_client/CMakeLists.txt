# Copyright (c) 2011, 2013, Oracle and/or its affiliates. All rights reserved.
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1335 USA

IF(WIN32)
  #
  # Configuration for building Windows Authentication Plugin (client-side)
  #

  ADD_DEFINITIONS(-DSECURITY_WIN32)
  ADD_DEFINITIONS(-DDEBUG_ERRROR_LOG)  # no error logging in production builds
  #ADD_DEFINITIONS(-DWINAUTH_USE_DBUG_LIB)      # it is OK to use dbug library in statically
  #                                             # linked plugin

  SET(HEADERS common.h handshake.h)
  SET(PLUGIN_SOURCES plugin_client.cc handshake_client.cc
      log_client.cc common.cc handshake.cc)

  MYSQL_ADD_PLUGIN(authentication_windows_client ${PLUGIN_SOURCES} ${HEADERS}
    LINK_LIBRARIES Secur32
    MODULE_ONLY COMPONENT ClientPlugins CLIENT)

ENDIF(WIN32)
