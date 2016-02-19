// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "realsense/common/win/command_queue.h"

#include "base/logging.h"
#include "realsense/common/win/command.h"

namespace realsense {
namespace common {

CommandQueue::CommandQueue(CommandQueueDelegate* delegate)
  : delegate_(delegate) {
}

void CommandQueue::AppendCommand(scoped_ptr<Command> command) {
  command_queue_.push_back(std::move(command));
}

void CommandQueue::ExecutePendingCommands() {
  PXCCapture::Sample* sample = delegate_->QuerySample();
  if (!sample) {
    DLOG(ERROR) << "Failed to query sample from command queue delegate.";
    return;
  }

  for (auto &i : command_queue_) {
    i->Execute(sample);
  }
  command_queue_.clear();
}

}  // namespace common
}  // namespace realsense
