/**************************************************************************
** CanvasEngine is a C11 cross platform multimedia library.              **
** Copyright (C) 2025 Jacob Isonell (isonelljacob@gmail.com)             **
**                                                                       **
** This program is free software: you can redistribute it and/or modify  **
** it under the terms of the GNU General Public License as published by  **
** the Free Software Foundation, either version 3 of the License, or     **
** (at your option) any later version.                                   **
**                                                                       **
** This program is distributed in the hope that it will be useful,       **
** but WITHOUT ANY WARRANTY; without even the implied warranty of        **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          **
** GNU General Public License for more details.                          **
**                                                                       **
** You should have received a copy of the GNU General Public License     **
** along with this program. If not, see <https://www.gnu.org/licenses/>. **
**************************************************************************/

#ifdef CANVAS_HAS_ATOMICS

#if defined(ICE_ATOMICS_CXX11)
#  include <atomic>
#  define ICE_MEMORD_RELAXED ((int)::std::memory_order_relaxed)
#  define ICE_MEMORD_CONSUME ((int)::std::memory_order_consume)
#  define ICE_MEMORD_ACQUIRE ((int)::std::memory_order_acquire)
#  define ICE_MEMORD_RELEASE ((int)::std::memory_order_release)
#  define ICE_MEMORD_ACQ_REL ((int)::std::memory_order_acq_rel)
#  define ICE_MEMORD_SEQ_CST ((int)::std::memory_order_seq_cst)
#elif defined(ICE_ATOMICS_C11)
#  include <stdatomic.h>
#  define ICE_MEMORD_RELAXED memory_order_relaxed
#  define ICE_MEMORD_CONSUME memory_order_consume
#  define ICE_MEMORD_ACQUIRE memory_order_acquire
#  define ICE_MEMORD_RELEASE memory_order_release
#  define ICE_MEMORD_ACQ_REL memory_order_acq_rel
#  define ICE_MEMORD_SEQ_CST memory_order_seq_cst
#elif defined(ICE_ATOMICS_CLANG)
#  define ICE_MEMORD_RELAXED __ATOMIC_RELAXED
#  define ICE_MEMORD_CONSUME __ATOMIC_CONSUME
#  define ICE_MEMORD_ACQUIRE __ATOMIC_ACQUIRE
#  define ICE_MEMORD_RELEASE __ATOMIC_RELEASE
#  define ICE_MEMORD_ACQ_REL __ATOMIC_ACQ_REL
#  define ICE_MEMORD_SEQ_CST __ATOMIC_SEQ_CST
#elif defined(ICE_ATOMICS_GNU)
#  define ICE_MEMORD_RELAXED __ATOMIC_RELAXED
#  define ICE_MEMORD_CONSUME __ATOMIC_CONSUME
#  define ICE_MEMORD_ACQUIRE __ATOMIC_ACQUIRE
#  define ICE_MEMORD_RELEASE __ATOMIC_RELEASE
#  define ICE_MEMORD_ACQ_REL __ATOMIC_ACQ_REL
#  define ICE_MEMORD_SEQ_CST __ATOMIC_SEQ_CST
#else
#  define ICE_MEMORD_RELAXED 0
#  define ICE_MEMORD_CONSUME 1
#  define ICE_MEMORD_ACQUIRE 2
#  define ICE_MEMORD_RELEASE 3
#  define ICE_MEMORD_ACQ_REL 4
#  define ICE_MEMORD_SEQ_CST 5
#endif

#endif /* !CANVAS_HAS_ATOMICS */
