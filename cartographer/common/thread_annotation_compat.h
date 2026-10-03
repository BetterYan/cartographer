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

// Compatibility shim for Abseil >= LTS 2025, which removed the deprecated,
// unprefixed thread-annotation macros (GUARDED_BY, LOCKS_EXCLUDED, ...).
// Map the legacy names to the ABSL_-prefixed equivalents. The #ifndef guards
// make this header a no-op on toolchains / Abseil versions that still provide
// the legacy macros.

#ifndef CARTOGRAPHER_COMMON_THREAD_ANNOTATION_COMPAT_H_
#define CARTOGRAPHER_COMMON_THREAD_ANNOTATION_COMPAT_H_

#include "absl/base/thread_annotations.h"

#ifndef GUARDED_BY
#define GUARDED_BY(x) ABSL_GUARDED_BY(x)
#endif

#ifndef LOCKS_EXCLUDED
#define LOCKS_EXCLUDED(...) ABSL_LOCKS_EXCLUDED(__VA_ARGS__)
#endif

#ifndef EXCLUSIVE_LOCKS_REQUIRED
#define EXCLUSIVE_LOCKS_REQUIRED(...) ABSL_EXCLUSIVE_LOCKS_REQUIRED(__VA_ARGS__)
#endif

#ifndef SHARED_LOCKS_REQUIRED
#define SHARED_LOCKS_REQUIRED(...) ABSL_SHARED_LOCKS_REQUIRED(__VA_ARGS__)
#endif

#ifndef NO_THREAD_SAFETY_ANALYSIS
#define NO_THREAD_SAFETY_ANALYSIS ABSL_NO_THREAD_SAFETY_ANALYSIS
#endif

#ifndef SCOPED_LOCKABLE
#define SCOPED_LOCKABLE ABSL_SCOPED_LOCKABLE
#endif

#endif  // CARTOGRAPHER_COMMON_THREAD_ANNOTATION_COMPAT_H_
