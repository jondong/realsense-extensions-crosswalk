// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef REALSENSE_COMMON_WIN_COMMAND_H_
#define REALSENSE_COMMON_WIN_COMMAND_H_

#include "third_party/libpxc/include/pxccapture.h"
#include "xwalk/common/xwalk_extension_function_handler.h"

namespace realsense {
namespace common {

class Command {
 public:
  explicit Command(scoped_ptr<xwalk::common::XWalkExtensionFunctionInfo> info);
  virtual ~Command();

  virtual void Execute(PXCCapture::Sample* sample) = 0;

 protected:
  scoped_ptr<xwalk::common::XWalkExtensionFunctionInfo> function_info_;
};

}  // namespace common
}  // namespace realsense

#endif  // REALSENSE_COMMON_WIN_COMMAND_H_
