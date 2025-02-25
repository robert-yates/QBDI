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
#ifndef INSTINFO_X86_64_H
#define INSTINFO_X86_64_H

namespace llvm {
class MCInst;
class MCInstrDesc;
} // namespace llvm

namespace QBDI {

bool isStackRead(const llvm::MCInst &inst);

bool isStackWrite(const llvm::MCInst &inst);

bool isMinSizeRead(const llvm::MCInst &inst);

bool isMinSizeWrite(const llvm::MCInst &inst);

bool isDoubleRead(const llvm::MCInst &inst);

// does the instruction may change the value of register used to address a
// strore
bool mayChangeWriteAddr(const llvm::MCInst &inst,
                        const llvm::MCInstrDesc &desc);

bool hasREPPrefix(const llvm::MCInst &instr);

bool implicitDSIAccess(const llvm::MCInst &inst, const llvm::MCInstrDesc &desc);

} // namespace QBDI

#endif
