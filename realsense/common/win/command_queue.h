// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef REALSENSE_COMMON_WIN_COMMAND_QUEUE_H_
#define REALSENSE_COMMON_WIN_COMMAND_QUEUE_H_

#include <list>

#include "base/memory/scoped_ptr.h"
#include "third_party/libpxc/include/pxccapture.h"

namespace realsense {
namespace common {

class Command;

class CommandQueueDelegate {
 public:
  virtual PXCCapture::Sample* QuerySample() = 0;
};

class CommandQueue {
 public:
  explicit CommandQueue(CommandQueueDelegate* delegate);

  void AppendCommand(scoped_ptr<Command> command);
  void ExecutePendingCommands();

 private:
  CommandQueueDelegate* delegate_;
  std::list< scoped_ptr<Command> > command_queue_;
};

}  // namespace common
}  // namespace realsense

#endif  // REALSENSE_COMMON_WIN_COMMAND_QUEUE_H_
