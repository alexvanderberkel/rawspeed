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

#include "decompressors/AbstractBmffDecompressor.h"
#include "common/Point.h"                       // for iPoint2D
#include "decoders/RawDecoderException.h"       // for ThrowRDE
#include "decompressors/AbstractHuffmanTable.h" // for AbstractHuffmanTable
#include "decompressors/HuffmanTable.h"         // for HuffmanTable, Huffma...
#include "io/ByteStream.h"                      // for ByteStream
#include "io/Endianness.h"                      // for Endianness, Endianne...
#include <array>                                // for array
#include <cassert>                              // for assert
#include <memory>                               // for unique_ptr, make_unique
#include <utility>                              // for move
#include <vector>                               // for vector



namespace rawspeed {

const TiffIFD* AbstractBmffDecoder::getIFDWithLargestImage(TiffTag filter) const
{
  std::vector<const TiffIFD*> ifds = mRootIFD->getIFDsWithTag(filter);

  if (ifds.empty())
    ThrowRDE("No suitable IFD with tag 0x%04x found.", filter);

  const auto* res = ifds[0];
  uint32_t width = res->getEntry(IMAGEWIDTH)->getU32();
  for (const auto* ifd : ifds) {
    TiffEntry* widthE = ifd->getEntry(IMAGEWIDTH);
    // guard against random maker note entries with the same tag
    if (widthE->count == 1 && widthE->getU32() > width) {
      res = ifd;
      width = widthE->getU32();
    }
  }

  return res;
}

} 