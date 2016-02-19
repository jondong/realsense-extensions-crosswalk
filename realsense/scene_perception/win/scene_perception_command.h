// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef REALSENSE_SCENE_PERCEPTION_WIN_SCENE_PERCEPTION_COMMAND_H_
#define REALSENSE_SCENE_PERCEPTION_WIN_SCENE_PERCEPTION_COMMAND_H_

#include "realsense/common/win/command.h"

namespace realsense {
namespace scene_perception {

class ScenePerceptionObject;

class ScenePerceptionCommand : public common::Command {
 public:
  ScenePerceptionCommand(
      scoped_ptr<xwalk::common::XWalkExtensionFunctionInfo> info,
      ScenePerceptionObject* spObject);

 protected:
  ScenePerceptionObject* scene_perception_object_;
};

class EventCommand : public ScenePerceptionCommand {
 public:
  explicit EventCommand(ScenePerceptionObject* spObject);

  virtual void Execute(PXCCapture::Sample* sample);
};

class GetSampleCommand : public ScenePerceptionCommand {
 public:
  GetSampleCommand(scoped_ptr<xwalk::common::XWalkExtensionFunctionInfo> info,
                   ScenePerceptionObject* spObject);

  virtual void Execute(PXCCapture::Sample* sample);
};

class GetVerticesCommand : public ScenePerceptionCommand {
 public:
  GetVerticesCommand(scoped_ptr<xwalk::common::XWalkExtensionFunctionInfo> info,
                     ScenePerceptionObject* spObject);

  virtual void Execute(PXCCapture::Sample* sample);
};

class GetNormalsCommand : public ScenePerceptionCommand {
 public:
  GetNormalsCommand(scoped_ptr<xwalk::common::XWalkExtensionFunctionInfo> info,
                    ScenePerceptionObject* spObject);

  virtual void Execute(PXCCapture::Sample* sample);
};

}  // namespace scene_perception
}  // namespace realsense

#endif  // REALSENSE_SCENE_PERCEPTION_WIN_SCENE_PERCEPTION_COMMAND_H_
