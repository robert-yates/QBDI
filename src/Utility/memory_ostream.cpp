/*
 * This file is part of QBDI.
 *
 * Copyright 2017 - 2022 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdlib.h>

#include "Utility/LogSys.h"
#include "Utility/memory_ostream.h"

#include "llvm/Support/Memory.h"

namespace QBDI {

void *memory_ostream::get_ptr() const {
  if (os == nullptr) {
    return nullptr;
  } else {
    return os->base();
  }
}

void memory_ostream::write_impl(const char *Ptr, size_t Size) {
  QBDI_REQUIRE_ABORT(os != nullptr, "No memory where to write");
  QBDI_REQUIRE_ABORT(pos + Size <= os->allocatedSize(), "Fail to write");
  char *os_ptr = (char *)((uint64_t)os->base() + pos);
  for (uint64_t i = 0; i < Size; i++)
    os_ptr[i] = Ptr[i];
  pos += Size;
}

void memory_ostream::seek(uint64_t pos) {
  QBDI_REQUIRE_ABORT(os != nullptr, "Fail to seek");
  QBDI_REQUIRE_ABORT(pos < os->allocatedSize(), "Fail to seek");
  this->pos = pos;
}

} // namespace QBDI
