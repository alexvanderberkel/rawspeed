/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post
    Copyright (C) 2015-2017 Roman Lebedev
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

#include "decoders/Cr3Decoder.h"
#include "common/Point.h"                      // for iPoint2D
#include "common/RawspeedException.h"          // for RawspeedException
#include "decoders/RawDecoderException.h"      // for ThrowRDE
#include "decompressors/Cr3Decompressor.h"     // for Cr2Decompressor, Cr2S...
#include "interpolators/Cr2sRawInterpolator.h" // for Cr2sRawInterpolator
#include "io/Buffer.h"                         // for Buffer, DataBuffer
#include "io/ByteStream.h"                     // for ByteStream
#include "io/Endianness.h"                     // for Endianness, Endiannes...
#include "metadata/Camera.h"                   // for Hints
#include "metadata/ColorFilterArray.h"         // for CFA_GREEN, CFA_BLUE
#include "parsers/TiffParserException.h"       // for ThrowTPE
#include "tiff/TiffEntry.h"                    // for TiffEntry, TIFF_SHORT
#include "tiff/TiffTag.h"                      // for TiffTag, CANONCOLORDATA
#include <array>                               // for array
#include <cassert>                             // for assert
#include <cstdint>                             // for uint32_t, uint16_t
#include <memory>                              // for unique_ptr, allocator...
#include <string>                              // for operator==, string
#include <vector>                              // for vector
// IWYU pragma: no_include <ext/alloc_traits.h>

using std::string;

namespace rawspeed {


} // namespace rawspeed