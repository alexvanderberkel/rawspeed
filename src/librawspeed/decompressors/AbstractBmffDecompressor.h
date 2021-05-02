/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post
    Copyright (C) 2017 Axel Waggershauser

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/
#pragma once

// #include "common/RawImage.h"                    // for RawImage
// #include "decoders/RawDecoderException.h"       // for ThrowRDE
#include "decompressors/AbstractDecompressor.h" // for AbstractDecompressor
//#include "decompressors/HuffmanTable.h"         // for HuffmanTable
#include "io/ByteStream.h"                      // for ByteStream
#include <array>                                // for array
#include <cstdint>                              // for uint32_t, uint16_t
#include <memory>                               // for unique_ptr
#include <vector>                               // for vector

namespace rawspeed {

} // namespace rawspeed