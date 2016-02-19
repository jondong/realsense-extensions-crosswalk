// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "realsense/scene_perception/win/scene_perception_command.h"

#include "realsense/scene_perception/win/scene_perception_object.h"

namespace realsense {
namespace scene_perception {

ScenePerceptionCommand::ScenePerceptionCommand(
  scoped_ptr<xwalk::common::XWalkExtensionFunctionInfo> info,
  ScenePerceptionObject* spObject)
  : Command(std::move(info)), scene_perception_object_(spObject) {
}

EventCommand::EventCommand(ScenePerceptionObject* spObject)
  : ScenePerceptionCommand(NULL, spObject) {
}

void EventCommand::Execute(PXCCapture::Sample* sample) {
  scene_perception_object_->ProcessEventCommand(sample);
}

GetSampleCommand::GetSampleCommand(
  scoped_ptr<xwalk::common::XWalkExtensionFunctionInfo> info,
  ScenePerceptionObject* spObject)
  : ScenePerceptionCommand(std::move(info), spObject) {
}

void GetSampleCommand::Execute(PXCCapture::Sample* sample) {
  scene_perception_object_->ProcessGetSampleCommand(std::move(function_info_),
                                                    sample);
}

GetVerticesCommand::GetVerticesCommand(
  scoped_ptr<xwalk::common::XWalkExtensionFunctionInfo> info,
  ScenePerceptionObject* spObject)
  : ScenePerceptionCommand(std::move(info), spObject) {
}

void GetVerticesCommand::Execute(PXCCapture::Sample* sample) {
  scene_perception_object_->ProcessGetVerticesCommand(std::move(function_info_),
                                                      sample);
}

GetNormalsCommand::GetNormalsCommand(
  scoped_ptr<xwalk::common::XWalkExtensionFunctionInfo> info,
  ScenePerceptionObject* spObject)
  : ScenePerceptionCommand(std::move(info), spObject) {
}

void GetNormalsCommand::Execute(PXCCapture::Sample* sample) {
  scene_perception_object_->ProcessGetNormalsCommand(std::move(function_info_),
                                                     sample);
}

}  // namespace scene_perception
}  // namespace realsense
