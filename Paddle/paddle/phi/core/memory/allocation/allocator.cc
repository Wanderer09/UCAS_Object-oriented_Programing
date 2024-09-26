// Copyright (c) 2018 PaddlePaddle Authors. All Rights Reserved.
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

#include "paddle/phi/core/memory/allocation/allocator.h"

namespace paddle::memory::allocation {

void Allocator::FreeImpl(phi::Allocation* allocation) {
  static_cast<Allocation*>(allocation)
      ->TopDecoratedAllocator()
      ->Free(allocation);
}

}  // namespace paddle::memory::allocation
