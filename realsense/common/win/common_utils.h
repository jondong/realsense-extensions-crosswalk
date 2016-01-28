// Copyright 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef REALSENSE_COMMON_WIN_COMMON_UTILS_H_
#define REALSENSE_COMMON_WIN_COMMON_UTILS_H_

#include <string>

#include "base/memory/scoped_ptr.h"
#include "base/values.h"
// This file is auto-generated by common.idl
#include "extensions/realsense/common/common.h"  // NOLINT

namespace realsense {
using namespace jsapi::common;  // NOLINT
namespace common {

scoped_ptr<base::ListValue> CreateErrorResult(ErrorCode error);
scoped_ptr<base::ListValue> CreateErrorResult(ErrorCode error,
                                              const std::string& message);
scoped_ptr<base::ListValue> CreateSuccessResult();
void GetBinaryValueFromArgs(base::ListValue* args, base::BinaryValue** value);

}  // namespace common
}  // namespace realsense

#endif  // REALSENSE_COMMON_WIN_COMMON_UTILS_H_
