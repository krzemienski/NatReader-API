//
//  IMediaReader.hpp
//  NatReader
//
//  Created by Yusuf Olokoba on 11/15/19.
//  Copyright (c) 2019 Yusuf Olokoba. All rights reserved.
//

#pragma once

#include <mfapi.h>
#include <mfreadwrite.h>
#include <string>

#pragma comment(lib, "mf")
#pragma comment(lib, "mfreadwrite")

class IMediaReader {
	public:
		virtual ~IMediaReader () {};
		virtual bool CopyNextFrame (void* dstBuffer, uint32_t* outSize, int64_t* outTimestamp) = 0;
};

class FrameReader : public IMediaReader {
	public:
		FrameReader (const wchar_t* uri, int64_t startTime);
		~FrameReader ();
		bool CopyNextFrame (void* dstBuffer, uint32_t* outSize, int64_t* outTimestamp) override;
		void GetDimensions (int32_t* width, int32_t* height, float* framerate);
	private:
		IMFSourceReader* frameReader;
		uint32_t pixelWidth, pixelHeight;
		float framerate;
};