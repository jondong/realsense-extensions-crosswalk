// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "realsense/common/win/command.h"

namespace realsense {
namespace common {

Command::Command(scoped_ptr<xwalk::common::XWalkExtensionFunctionInfo> info)
  : function_info_(std::move(info)) {
}

Command::~Command() {
}

}  // namespace common
}  // namespace realsense
