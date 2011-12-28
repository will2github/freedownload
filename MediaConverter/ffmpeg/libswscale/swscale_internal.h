/*
  Free Download Manager Copyright (c) 2003-2011 FreeDownloadManager.ORG
*/



#ifndef SWSCALE_SWSCALE_INTERNAL_H
#define SWSCALE_SWSCALE_INTERNAL_H

#include "config.h"

#if HAVE_ALTIVEC_H
#include <altivec.h>
#endif

#include "libavutil/avutil.h"

#define STR(s)         AV_TOSTRING(s) 

#define MAX_FILTER_SIZE 256

#if ARCH_X86
#define VOFW 5120
#else
#define VOFW 2048 
#endif

#define VOF  (VOFW*2)

#if HAVE_BIGENDIAN
#define ALT32_CORR (-1)
#else
#define ALT32_CORR   1
#endif

#if ARCH_X86_64
#   define APCK_PTR2 8
#   define APCK_COEF 16
#   define APCK_SIZE 24
#else
#   define APCK_PTR2 4
#   define APCK_COEF 8
#   define APCK_SIZE 16
#endif

struct SwsContext;

typedef int (*SwsFunc)(struct SwsContext *context, const uint8_t* src[],
                       int srcStride[], int srcSliceY, int srcSliceH,
                       uint8_t* dst[], int dstStride[]);


typedef struct SwsContext {
    
    const AVClass *av_class;

    
    SwsFunc swScale;
    int srcW;                     
    int srcH;                     
    int dstH;                     
    int chrSrcW;                  
    int chrSrcH;                  
    int chrDstW;                  
    int chrDstH;                  
    int lumXInc, chrXInc;
    int lumYInc, chrYInc;
    enum PixelFormat dstFormat;   
    enum PixelFormat srcFormat;   
    int dstFormatBpp;             
    int srcFormatBpp;             
    int chrSrcHSubSample;         
    int chrSrcVSubSample;         
    int chrDstHSubSample;         
    int chrDstVSubSample;         
    int vChrDrop;                 
    int sliceDir;                 
    double param[2];              

    uint32_t pal_yuv[256];
    uint32_t pal_rgb[256];

    
    
    int16_t **lumPixBuf;          
    int16_t **chrPixBuf;          
    int16_t **alpPixBuf;          
    int       vLumBufSize;        
    int       vChrBufSize;        
    int       lastInLumBuf;       
    int       lastInChrBuf;       
    int       lumBufIndex;        
    int       chrBufIndex;        
    

    uint8_t formatConvBuffer[VOF]; 

    
    
    int16_t *hLumFilter;          
    int16_t *hChrFilter;          
    int16_t *vLumFilter;          
    int16_t *vChrFilter;          
    int16_t *hLumFilterPos;       
    int16_t *hChrFilterPos;       
    int16_t *vLumFilterPos;       
    int16_t *vChrFilterPos;       
    int      hLumFilterSize;      
    int      hChrFilterSize;      
    int      vLumFilterSize;      
    int      vChrFilterSize;      
    

    int lumMmx2FilterCodeSize;    
    int chrMmx2FilterCodeSize;    
    uint8_t *lumMmx2FilterCode;   
    uint8_t *chrMmx2FilterCode;   

    int canMMX2BeUsed;

    int dstY;                     
    int flags;                    
    void * yuvTable;            
    uint8_t * table_rV[256];
    uint8_t * table_gU[256];
    int    table_gV[256];
    uint8_t * table_bU[256];

    
    int contrast, brightness, saturation;    
    int srcColorspaceTable[4];
    int dstColorspaceTable[4];
    int srcRange;                 
    int dstRange;                 
    int yuv2rgb_y_offset;
    int yuv2rgb_y_coeff;
    int yuv2rgb_v2r_coeff;
    int yuv2rgb_v2g_coeff;
    int yuv2rgb_u2g_coeff;
    int yuv2rgb_u2b_coeff;

#define RED_DITHER            "0*8"
#define GREEN_DITHER          "1*8"
#define BLUE_DITHER           "2*8"
#define Y_COEFF               "3*8"
#define VR_COEFF              "4*8"
#define UB_COEFF              "5*8"
#define VG_COEFF              "6*8"
#define UG_COEFF              "7*8"
#define Y_OFFSET              "8*8"
#define U_OFFSET              "9*8"
#define V_OFFSET              "10*8"
#define LUM_MMX_FILTER_OFFSET "11*8"
#define CHR_MMX_FILTER_OFFSET "11*8+4*4*256"
#define DSTW_OFFSET           "11*8+4*4*256*2" 
#define ESP_OFFSET            "11*8+4*4*256*2+8"
#define VROUNDER_OFFSET       "11*8+4*4*256*2+16"
#define U_TEMP                "11*8+4*4*256*2+24"
#define V_TEMP                "11*8+4*4*256*2+32"
#define Y_TEMP                "11*8+4*4*256*2+40"
#define ALP_MMX_FILTER_OFFSET "11*8+4*4*256*2+48"

    DECLARE_ALIGNED(8, uint64_t, redDither);
    DECLARE_ALIGNED(8, uint64_t, greenDither);
    DECLARE_ALIGNED(8, uint64_t, blueDither);

    DECLARE_ALIGNED(8, uint64_t, yCoeff);
    DECLARE_ALIGNED(8, uint64_t, vrCoeff);
    DECLARE_ALIGNED(8, uint64_t, ubCoeff);
    DECLARE_ALIGNED(8, uint64_t, vgCoeff);
    DECLARE_ALIGNED(8, uint64_t, ugCoeff);
    DECLARE_ALIGNED(8, uint64_t, yOffset);
    DECLARE_ALIGNED(8, uint64_t, uOffset);
    DECLARE_ALIGNED(8, uint64_t, vOffset);
    int32_t  lumMmxFilter[4*MAX_FILTER_SIZE];
    int32_t  chrMmxFilter[4*MAX_FILTER_SIZE];
    int dstW;                     
    DECLARE_ALIGNED(8, uint64_t, esp);
    DECLARE_ALIGNED(8, uint64_t, vRounder);
    DECLARE_ALIGNED(8, uint64_t, u_temp);
    DECLARE_ALIGNED(8, uint64_t, v_temp);
    DECLARE_ALIGNED(8, uint64_t, y_temp);
    int32_t  alpMmxFilter[4*MAX_FILTER_SIZE];

#if HAVE_ALTIVEC
    vector signed short   CY;
    vector signed short   CRV;
    vector signed short   CBU;
    vector signed short   CGU;
    vector signed short   CGV;
    vector signed short   OY;
    vector unsigned short CSHIFT;
    vector signed short   *vYCoeffsBank, *vCCoeffsBank;
#endif

#if ARCH_BFIN
    DECLARE_ALIGNED(4, uint32_t, oy);
    DECLARE_ALIGNED(4, uint32_t, oc);
    DECLARE_ALIGNED(4, uint32_t, zero);
    DECLARE_ALIGNED(4, uint32_t, cy);
    DECLARE_ALIGNED(4, uint32_t, crv);
    DECLARE_ALIGNED(4, uint32_t, rmask);
    DECLARE_ALIGNED(4, uint32_t, cbu);
    DECLARE_ALIGNED(4, uint32_t, bmask);
    DECLARE_ALIGNED(4, uint32_t, cgu);
    DECLARE_ALIGNED(4, uint32_t, cgv);
    DECLARE_ALIGNED(4, uint32_t, gmask);
#endif

#if HAVE_VIS
    DECLARE_ALIGNED(8, uint64_t, sparc_coeffs)[10];
#endif

    
    void (*yuv2nv12X  )(struct SwsContext *c,
                        const int16_t *lumFilter, const int16_t **lumSrc, int lumFilterSize,
                        const int16_t *chrFilter, const int16_t **chrSrc, int chrFilterSize,
                        uint8_t *dest, uint8_t *uDest,
                        int dstW, int chrDstW, int dstFormat);
    void (*yuv2yuv1   )(struct SwsContext *c,
                        const int16_t *lumSrc, const int16_t *chrSrc, const int16_t *alpSrc,
                        uint8_t *dest,
                        uint8_t *uDest, uint8_t *vDest, uint8_t *aDest,
                        long dstW, long chrDstW);
    void (*yuv2yuvX   )(struct SwsContext *c,
                        const int16_t *lumFilter, const int16_t **lumSrc, int lumFilterSize,
                        const int16_t *chrFilter, const int16_t **chrSrc, int chrFilterSize,
                        const int16_t **alpSrc,
                        uint8_t *dest,
                        uint8_t *uDest, uint8_t *vDest, uint8_t *aDest,
                        long dstW, long chrDstW);
    void (*yuv2packed1)(struct SwsContext *c,
                        const uint16_t *buf0,
                        const uint16_t *uvbuf0, const uint16_t *uvbuf1,
                        const uint16_t *abuf0,
                        uint8_t *dest,
                        int dstW, int uvalpha, int dstFormat, int flags, int y);
    void (*yuv2packed2)(struct SwsContext *c,
                        const uint16_t *buf0, const uint16_t *buf1,
                        const uint16_t *uvbuf0, const uint16_t *uvbuf1,
                        const uint16_t *abuf0, const uint16_t *abuf1,
                        uint8_t *dest,
                        int dstW, int yalpha, int uvalpha, int y);
    void (*yuv2packedX)(struct SwsContext *c,
                        const int16_t *lumFilter, const int16_t **lumSrc, int lumFilterSize,
                        const int16_t *chrFilter, const int16_t **chrSrc, int chrFilterSize,
                        const int16_t **alpSrc, uint8_t *dest,
                        long dstW, long dstY);

    void (*lumToYV12)(uint8_t *dst, const uint8_t *src,
                      long width, uint32_t *pal); 
    void (*alpToYV12)(uint8_t *dst, const uint8_t *src,
                      long width, uint32_t *pal); 
    void (*chrToYV12)(uint8_t *dstU, uint8_t *dstV,
                      const uint8_t *src1, const uint8_t *src2,
                      long width, uint32_t *pal); 
    void (*hyscale_fast)(struct SwsContext *c,
                         int16_t *dst, long dstWidth,
                         const uint8_t *src, int srcW, int xInc);
    void (*hcscale_fast)(struct SwsContext *c,
                         int16_t *dst, long dstWidth,
                         const uint8_t *src1, const uint8_t *src2,
                         int srcW, int xInc);

    void (*hScale)(int16_t *dst, int dstW, const uint8_t *src, int srcW,
                   int xInc, const int16_t *filter, const int16_t *filterPos,
                   long filterSize);

    void (*lumConvertRange)(uint16_t *dst, int width); 
    void (*chrConvertRange)(uint16_t *dst, int width); 

    int lumSrcOffset; 
    int chrSrcOffset; 
    int alpSrcOffset; 

    int needs_hcscale; 

} SwsContext;


SwsFunc ff_yuv2rgb_get_func_ptr(SwsContext *c);
int ff_yuv2rgb_c_init_tables(SwsContext *c, const int inv_table[4],
                             int fullRange, int brightness,
                             int contrast, int saturation);

void ff_yuv2rgb_init_tables_altivec(SwsContext *c, const int inv_table[4],
                                    int brightness, int contrast, int saturation);
SwsFunc ff_yuv2rgb_init_mmx(SwsContext *c);
SwsFunc ff_yuv2rgb_init_vis(SwsContext *c);
SwsFunc ff_yuv2rgb_init_mlib(SwsContext *c);
SwsFunc ff_yuv2rgb_init_altivec(SwsContext *c);
SwsFunc ff_yuv2rgb_get_func_ptr_bfin(SwsContext *c);
void ff_bfin_get_unscaled_swscale(SwsContext *c);
void ff_yuv2packedX_altivec(SwsContext *c,
                            const int16_t *lumFilter, int16_t **lumSrc, int lumFilterSize,
                            const int16_t *chrFilter, int16_t **chrSrc, int chrFilterSize,
                            uint8_t *dest, int dstW, int dstY);

const char *sws_format_name(enum PixelFormat format);


#define is16BPS(x)      (           \
           (x)==PIX_FMT_GRAY16BE    \
        || (x)==PIX_FMT_GRAY16LE    \
        || (x)==PIX_FMT_RGB48BE     \
        || (x)==PIX_FMT_RGB48LE     \
        || (x)==PIX_FMT_YUV420P16LE   \
        || (x)==PIX_FMT_YUV422P16LE   \
        || (x)==PIX_FMT_YUV444P16LE   \
        || (x)==PIX_FMT_YUV420P16BE   \
        || (x)==PIX_FMT_YUV422P16BE   \
        || (x)==PIX_FMT_YUV444P16BE   \
    )
#define isBE(x) ((x)&1)
#define isPlanar8YUV(x) (           \
           (x)==PIX_FMT_YUV410P     \
        || (x)==PIX_FMT_YUV420P     \
        || (x)==PIX_FMT_YUVA420P    \
        || (x)==PIX_FMT_YUV411P     \
        || (x)==PIX_FMT_YUV422P     \
        || (x)==PIX_FMT_YUV444P     \
        || (x)==PIX_FMT_YUV440P     \
        || (x)==PIX_FMT_NV12        \
        || (x)==PIX_FMT_NV21        \
    )
#define isPlanarYUV(x)  (           \
        isPlanar8YUV(x)             \
        || (x)==PIX_FMT_YUV420P16LE   \
        || (x)==PIX_FMT_YUV422P16LE   \
        || (x)==PIX_FMT_YUV444P16LE   \
        || (x)==PIX_FMT_YUV420P16BE   \
        || (x)==PIX_FMT_YUV422P16BE   \
        || (x)==PIX_FMT_YUV444P16BE   \
    )
#define isYUV(x)        (           \
           (x)==PIX_FMT_UYVY422     \
        || (x)==PIX_FMT_YUYV422     \
        || isPlanarYUV(x)           \
    )
#define isGray(x)       (           \
           (x)==PIX_FMT_GRAY8       \
        || (x)==PIX_FMT_GRAY16BE    \
        || (x)==PIX_FMT_GRAY16LE    \
    )
#define isGray16(x)     (           \
           (x)==PIX_FMT_GRAY16BE    \
        || (x)==PIX_FMT_GRAY16LE    \
    )
#define isRGBinInt(x)   (           \
           (x)==PIX_FMT_RGB48BE     \
        || (x)==PIX_FMT_RGB48LE     \
        || (x)==PIX_FMT_RGB32       \
        || (x)==PIX_FMT_RGB32_1     \
        || (x)==PIX_FMT_RGB24       \
        || (x)==PIX_FMT_RGB565BE    \
        || (x)==PIX_FMT_RGB565LE    \
        || (x)==PIX_FMT_RGB555BE    \
        || (x)==PIX_FMT_RGB555LE    \
        || (x)==PIX_FMT_RGB444BE    \
        || (x)==PIX_FMT_RGB444LE    \
        || (x)==PIX_FMT_RGB8        \
        || (x)==PIX_FMT_RGB4        \
        || (x)==PIX_FMT_RGB4_BYTE   \
        || (x)==PIX_FMT_MONOBLACK   \
        || (x)==PIX_FMT_MONOWHITE   \
    )
#define isBGRinInt(x)   (           \
           (x)==PIX_FMT_BGR32       \
        || (x)==PIX_FMT_BGR32_1     \
        || (x)==PIX_FMT_BGR24       \
        || (x)==PIX_FMT_BGR565BE    \
        || (x)==PIX_FMT_BGR565LE    \
        || (x)==PIX_FMT_BGR555BE    \
        || (x)==PIX_FMT_BGR555LE    \
        || (x)==PIX_FMT_BGR444BE    \
        || (x)==PIX_FMT_BGR444LE    \
        || (x)==PIX_FMT_BGR8        \
        || (x)==PIX_FMT_BGR4        \
        || (x)==PIX_FMT_BGR4_BYTE   \
        || (x)==PIX_FMT_MONOBLACK   \
        || (x)==PIX_FMT_MONOWHITE   \
    )
#define isRGBinBytes(x) (           \
           (x)==PIX_FMT_RGB48BE     \
        || (x)==PIX_FMT_RGB48LE     \
        || (x)==PIX_FMT_RGBA        \
        || (x)==PIX_FMT_ARGB        \
        || (x)==PIX_FMT_RGB24       \
    )
#define isBGRinBytes(x) (           \
           (x)==PIX_FMT_BGRA        \
        || (x)==PIX_FMT_ABGR        \
        || (x)==PIX_FMT_BGR24       \
    )
#define isAnyRGB(x)     (           \
            isRGBinInt(x)           \
        ||  isBGRinInt(x)           \
    )
#define isALPHA(x)      (           \
           (x)==PIX_FMT_BGR32       \
        || (x)==PIX_FMT_BGR32_1     \
        || (x)==PIX_FMT_RGB32       \
        || (x)==PIX_FMT_RGB32_1     \
        || (x)==PIX_FMT_YUVA420P    \
    )
#define usePal(x) (av_pix_fmt_descriptors[x].flags & PIX_FMT_PAL)

extern const uint64_t ff_dither4[2];
extern const uint64_t ff_dither8[2];

extern const AVClass sws_context_class;


void ff_get_unscaled_swscale(SwsContext *c);


int ff_hardcodedcpuflags(void);


SwsFunc ff_getSwsFunc(SwsContext *c);

#endif 