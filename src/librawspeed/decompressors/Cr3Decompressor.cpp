/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post
    Copyright (C) 2017 Axel Waggershauser
    Copyright (C) 2017-2018 Roman Lebedev

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

#include "decompressors/Cr3Decompressor.h"
#include "common/Array2DRef.h"            // for Array2DRef
#include "common/Point.h"                 // for iPoint2D, iPoint2D::area_type
#include "common/RawImage.h"              // for RawImage, RawImageData
#include "decoders/RawDecoderException.h" // for ThrowRDE
#include "io/BitPumpJPEG.h"               // for BitPumpJPEG, BitStream<>::...
#include <algorithm>                      // for copy_n, min
#include <array>                          // for array
#include <cassert>                        // for assert
#include <initializer_list>               // for initializer_list

namespace rawspeed {

  Cr3Decompressor::Cr3Decompressor(const ByteStream& bs, const RawImage& img)
    : AbstractBmffDecompressor(bs, img) {
} // namespace rawspeed
