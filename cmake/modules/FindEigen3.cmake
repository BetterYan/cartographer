# Copyright 2018 The Cartographer Authors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

find_package(Eigen3 QUIET NO_MODULE)
if (TARGET Eigen3::Eigen)
  # Config file found (e.g. provided by vcpkg). It only defines the
  # Eigen3::Eigen target; propagate the old-style variables that
  # Cartographer's CMakeLists.txt expects.
  set(EIGEN3_FOUND TRUE)
  set(Eigen3_FOUND TRUE)
  if (NOT EIGEN3_INCLUDE_DIR)
    get_target_property(EIGEN3_INCLUDE_DIR Eigen3::Eigen INTERFACE_INCLUDE_DIRECTORIES)
  endif()
  set(EIGEN3_LIBRARIES Eigen3::Eigen)
else()
  list(APPEND EIGEN3_POSSIBLE_DIRS
    /usr/local/include/eigen3
    /usr/include/eigen3
  )
  find_path(EIGEN3_INCLUDE_DIR
    NAMES Eigen/Core
    PATHS ${EIGEN3_POSSIBLE_DIRS}
  )
  if (EIGEN3_INCLUDE_DIR AND EXISTS ${EIGEN3_INCLUDE_DIR})
    set(EIGEN3_FOUND TRUE)
    set(Eigen3_FOUND TRUE)
  else()
    message(WARNING "Failed to find Eigen3. Please, define the path manually.")
  endif()
endif()
