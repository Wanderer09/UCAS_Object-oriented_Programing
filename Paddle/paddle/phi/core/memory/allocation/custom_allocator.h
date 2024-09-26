// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include <mutex>  // NOLINT

#include "paddle/phi/common/place.h"
#include "paddle/phi/core/memory/allocation/allocator.h"

namespace paddle {
namespace memory {
namespace allocation {

class CustomAllocator : public Allocator {
 public:
  explicit CustomAllocator(const phi::CustomPlace& place) : place_(place) {}

  bool IsAllocThreadSafe() const override;

 protected:
  void FreeImpl(phi::Allocation* allocation) override;
  phi::Allocation* AllocateImpl(size_t size) override;

 private:
  phi::Place place_;
  std::once_flag once_flag_;
};

}  // namespace allocation
}  // namespace memory
}  // namespace paddle
