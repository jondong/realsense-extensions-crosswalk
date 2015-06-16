// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SRC_REALSENSE_SCENEPERCEPTION_SCENEPERCEPTION_INSTANCE_H_
#define SRC_REALSENSE_SCENEPERCEPTION_SCENEPERCEPTION_INSTANCE_H_

#include "base/threading/thread.h"
#include "realsense/common/extension.h"
#include "realsense/common/binding_object_store.h"
#include "realsense/common/xwalk_extension_function_handler.h"

namespace realsense {
namespace sceneperception {

class ScenePerceptionInstance : public realsense::common::Instance {
 public:
  ScenePerceptionInstance();
  virtual ~ScenePerceptionInstance();

 private:
  virtual void HandleMessage(const char* msg);
  virtual void HandleSyncMessage(const char* msg);

  // Called on sp_ext_thread_
  void OnHandleMessage(scoped_ptr<base::Value> msg);
  void OnScenePerceptionConstructor(
      scoped_ptr<realsense::common::XWalkExtensionFunctionInfo> info);

  realsense::common::XWalkExtensionFunctionHandler handler_;
  realsense::common::BindingObjectStore store_;
  base::Thread sp_ext_thread_;
};

}  // namespace sceneperception
}  // namespace realsense

#endif  // SRC_REALSENSE_SCENEPERCEPTION_SCENEPERCEPTION_INSTANCE_H_
