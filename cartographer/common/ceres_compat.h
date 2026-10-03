/*
 * Copyright 2026 The Cartographer Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Compatibility shim for Ceres >= 2.3, which removed the
// LocalParameterization API in favour of Manifold. Re-create the removed
// type names as aliases of their Manifold-based equivalents so that older
// code keeps compiling unchanged. Semantics are preserved:
//   * IdentityParameterization(k)     == EuclideanManifold<DYNAMIC>(k)
//   * QuaternionParameterization      == QuaternionManifold ((w,x,y,z) order)
//   * SubsetParameterization(k, ids)  == SubsetManifold(k, ids)
//   * AutoDiffLocalParameterization   == AutoDiffManifold

#ifndef CARTOGRAPHER_COMMON_CERES_COMPAT_H_
#define CARTOGRAPHER_COMMON_CERES_COMPAT_H_

#include "ceres/autodiff_manifold.h"
#include "ceres/manifold.h"

namespace ceres {

using LocalParameterization = Manifold;

template <typename Functor, int kGlobalSize, int kLocalSize>
using AutoDiffLocalParameterization =
    AutoDiffManifold<Functor, kGlobalSize, kLocalSize>;

using IdentityParameterization = EuclideanManifold<ceres::DYNAMIC>;

using QuaternionParameterization = QuaternionManifold;

using SubsetParameterization = SubsetManifold;

}  // namespace ceres

#endif  // CARTOGRAPHER_COMMON_CERES_COMPAT_H_
