//
// Created by indrek on 30.04.2016.
//

#ifndef _BUFFEREDCAMERAOV7670_QQVGA_30HZ_H
#define _BUFFEREDCAMERAOV7670_QQVGA_30HZ_H

#include "../BufferedCameraOV7670.h"


// 160 x 120 @ 30Hz
class BufferedCameraOV7670_QQVGA_30hz : public BufferedCameraOV7670<uint16_t, 320, uint8_t, 160, uint8_t, 120> {


public:
    BufferedCameraOV7670_QQVGA_30hz(PixelFormat format) : BufferedCameraOV7670(Resolution::RESOLUTION_QQVGA_160x120, format, 2) {};

  inline void readLine() override __attribute__((always_inline));


private:
  inline void readPixels_unrolled_x160(uint16_t byteIndex) __attribute__((always_inline));
  inline void readPixels_unrolled_x10(uint16_t byteIndex) __attribute__((always_inline));
  inline void readPixel_unrolled(uint16_t byteIndex) __attribute__((always_inline));

};




void BufferedCameraOV7670_QQVGA_30hz::readLine() {
  pixelBuffer.writeBufferPadding = 0;
  waitForPixelClockLow();

  // only way to get line data at 10Hz is to unroll pixel reading
  readPixels_unrolled_x160(0);

  //C14_ON;
  //C14_OFF;
}


#define BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP 20
void BufferedCameraOV7670_QQVGA_30hz::readPixels_unrolled_x160(uint16_t byteIndex) {
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 0);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 1);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 2);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 3);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 4);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 5);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 6);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 7);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 8);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 9);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 10);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 11);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 12);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 13);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 14);
  readPixels_unrolled_x10(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X160_STEP * 15);
}

#define BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X10_STEP 2
void BufferedCameraOV7670_QQVGA_30hz::readPixels_unrolled_x10(uint16_t byteIndex) {
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X10_STEP * 0);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X10_STEP * 1);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X10_STEP * 2);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X10_STEP * 3);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X10_STEP * 4);
  //asm volatile("nop");
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X10_STEP * 5);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X10_STEP * 6);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X10_STEP * 7);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X10_STEP * 8);
  readPixel_unrolled(byteIndex + BufferedCameraOV7670_QQVGA_30hz_READ_PIXEL_X10_STEP * 9);
  asm volatile("nop");
}

void BufferedCameraOV7670_QQVGA_30hz::readPixel_unrolled(uint16_t byteIndex) {
  readPixelByte(pixelBuffer.writeBuffer[byteIndex + 0]);
  //C14_ON;
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");

  readPixelByte(pixelBuffer.writeBuffer[byteIndex + 1]);
  //C14_OFF;

  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");


}




#endif //_BUFFEREDCAMERAOV7670_QQVGA_30HZ_H
