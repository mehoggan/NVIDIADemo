#ifndef GL_FUNCTIONS_H_INCLUDED
#define GL_FUNCTIONS_H_INCLUDED

#include "declspec.h"

#include <cstdint>

#include "declspec.h"

#include "nvidia_demo/platform.h"

// OpenGL 1.1 Related
extern "C"
{
  typedef unsigned int GLenum;
  typedef unsigned int GLbitfield;
  typedef unsigned int GLuint;
  typedef int GLint;
  typedef int GLsizei;
  typedef unsigned char GLboolean;
  typedef signed char GLbyte;
  typedef short GLshort;
  typedef unsigned char GLubyte;
  typedef unsigned short GLushort;
  typedef unsigned long GLulong;
  typedef float GLfloat;
  typedef float GLclampf;
  typedef double GLdouble;
  typedef double GLclampd;
  typedef void GLvoid;
#ifndef __gl_h_
  typedef long long int GLint64EXT;
#endif
#ifndef __gl_h_
  typedef unsigned long long int GLuint64EXT;
#endif
  typedef GLint64EXT  GLint64;
  typedef GLuint64EXT GLuint64;
  typedef struct __GLsync *GLsync;
  typedef char GLchar;

#define GL_ZERO 0
#define GL_FALSE 0
#define GL_LOGIC_OP 0x0BF1
#define GL_NONE 0
#define GL_TEXTURE_COMPONENTS 0x1003
#define GL_NO_ERROR 0
#define GL_POINTS 0x0000
#define GL_CURRENT_BIT 0x00000001
#define GL_TRUE 1
#define GL_ONE 1
#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_POINT_BIT 0x00000002
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define GL_LINE_STRIP 0x0003
#define GL_LINE_BIT 0x00000004
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_QUADS 0x0007
#define GL_QUAD_STRIP 0x0008
#define GL_POLYGON_BIT 0x00000008
#define GL_POLYGON 0x0009
#define GL_POLYGON_STIPPLE_BIT 0x00000010
#define GL_PIXEL_MODE_BIT 0x00000020
#define GL_LIGHTING_BIT 0x00000040
#define GL_FOG_BIT 0x00000080
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_ACCUM 0x0100
#define GL_LOAD 0x0101
#define GL_RETURN 0x0102
#define GL_MULT 0x0103
#define GL_ADD 0x0104
#define GL_NEVER 0x0200
#define GL_ACCUM_BUFFER_BIT 0x00000200
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_AND_BACK 0x0408
#define GL_AUX0 0x0409
#define GL_AUX1 0x040A
#define GL_AUX2 0x040B
#define GL_AUX3 0x040C
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_OUT_OF_MEMORY 0x0505
#define GL_2D 0x0600
#define GL_3D 0x0601
#define GL_3D_COLOR 0x0602
#define GL_3D_COLOR_TEXTURE 0x0603
#define GL_4D_COLOR_TEXTURE 0x0604
#define GL_PASS_THROUGH_TOKEN 0x0700
#define GL_POINT_TOKEN 0x0701
#define GL_LINE_TOKEN 0x0702
#define GL_POLYGON_TOKEN 0x0703
#define GL_BITMAP_TOKEN 0x0704
#define GL_DRAW_PIXEL_TOKEN 0x0705
#define GL_COPY_PIXEL_TOKEN 0x0706
#define GL_LINE_RESET_TOKEN 0x0707
#define GL_EXP 0x0800
#define GL_VIEWPORT_BIT 0x00000800
#define GL_EXP2 0x0801
#define GL_CW 0x0900
#define GL_CCW 0x0901
#define GL_COEFF 0x0A00
#define GL_ORDER 0x0A01
#define GL_DOMAIN 0x0A02
#define GL_CURRENT_COLOR 0x0B00
#define GL_CURRENT_INDEX 0x0B01
#define GL_CURRENT_NORMAL 0x0B02
#define GL_CURRENT_TEXTURE_COORDS 0x0B03
#define GL_CURRENT_RASTER_COLOR 0x0B04
#define GL_CURRENT_RASTER_INDEX 0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
#define GL_CURRENT_RASTER_POSITION 0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
#define GL_CURRENT_RASTER_DISTANCE 0x0B09
#define GL_POINT_SMOOTH 0x0B10
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_LINE_STIPPLE 0x0B24
#define GL_LINE_STIPPLE_PATTERN 0x0B25
#define GL_LINE_STIPPLE_REPEAT 0x0B26
#define GL_LIST_MODE 0x0B30
#define GL_MAX_LIST_NESTING 0x0B31
#define GL_LIST_BASE 0x0B32
#define GL_LIST_INDEX 0x0B33
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_POLYGON_STIPPLE 0x0B42
#define GL_EDGE_FLAG 0x0B43
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_FRONT_FACE 0x0B46
#define GL_LIGHTING 0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#define GL_LIGHT_MODEL_AMBIENT 0x0B53
#define GL_SHADE_MODEL 0x0B54
#define GL_COLOR_MATERIAL_FACE 0x0B55
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#define GL_COLOR_MATERIAL 0x0B57
#define GL_FOG 0x0B60
#define GL_FOG_INDEX 0x0B61
#define GL_FOG_DENSITY 0x0B62
#define GL_FOG_START 0x0B63
#define GL_FOG_END 0x0B64
#define GL_FOG_MODE 0x0B65
#define GL_FOG_COLOR 0x0B66
#define GL_DEPTH_RANGE 0x0B70
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_FUNC 0x0B74
#define GL_ACCUM_CLEAR_VALUE 0x0B80
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_MATRIX_MODE 0x0BA0
#define GL_NORMALIZE 0x0BA1
#define GL_VIEWPORT 0x0BA2
#define GL_MODELVIEW_STACK_DEPTH 0x0BA3
#define GL_PROJECTION_STACK_DEPTH 0x0BA4
#define GL_TEXTURE_STACK_DEPTH 0x0BA5
#define GL_MODELVIEW_MATRIX 0x0BA6
#define GL_PROJECTION_MATRIX 0x0BA7
#define GL_TEXTURE_MATRIX 0x0BA8
#define GL_ATTRIB_STACK_DEPTH 0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#define GL_ALPHA_TEST 0x0BC0
#define GL_ALPHA_TEST_FUNC 0x0BC1
#define GL_ALPHA_TEST_REF 0x0BC2
#define GL_DITHER 0x0BD0
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_BLEND 0x0BE2
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_INDEX_LOGIC_OP 0x0BF1
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_AUX_BUFFERS 0x0C00
#define GL_DRAW_BUFFER 0x0C01
#define GL_READ_BUFFER 0x0C02
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_INDEX_CLEAR_VALUE 0x0C20
#define GL_INDEX_WRITEMASK 0x0C21
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_INDEX_MODE 0x0C30
#define GL_RGBA_MODE 0x0C31
#define GL_DOUBLEBUFFER 0x0C32
#define GL_STEREO 0x0C33
#define GL_RENDER_MODE 0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_POINT_SMOOTH_HINT 0x0C51
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_FOG_HINT 0x0C54
#define GL_TEXTURE_GEN_S 0x0C60
#define GL_TEXTURE_GEN_T 0x0C61
#define GL_TEXTURE_GEN_R 0x0C62
#define GL_TEXTURE_GEN_Q 0x0C63
#define GL_PIXEL_MAP_I_TO_I 0x0C70
#define GL_PIXEL_MAP_S_TO_S 0x0C71
#define GL_PIXEL_MAP_I_TO_R 0x0C72
#define GL_PIXEL_MAP_I_TO_G 0x0C73
#define GL_PIXEL_MAP_I_TO_B 0x0C74
#define GL_PIXEL_MAP_I_TO_A 0x0C75
#define GL_PIXEL_MAP_R_TO_R 0x0C76
#define GL_PIXEL_MAP_G_TO_G 0x0C77
#define GL_PIXEL_MAP_B_TO_B 0x0C78
#define GL_PIXEL_MAP_A_TO_A 0x0C79
#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_MAP_COLOR 0x0D10
#define GL_MAP_STENCIL 0x0D11
#define GL_INDEX_SHIFT 0x0D12
#define GL_INDEX_OFFSET 0x0D13
#define GL_RED_SCALE 0x0D14
#define GL_RED_BIAS 0x0D15
#define GL_ZOOM_X 0x0D16
#define GL_ZOOM_Y 0x0D17
#define GL_GREEN_SCALE 0x0D18
#define GL_GREEN_BIAS 0x0D19
#define GL_BLUE_SCALE 0x0D1A
#define GL_BLUE_BIAS 0x0D1B
#define GL_ALPHA_SCALE 0x0D1C
#define GL_ALPHA_BIAS 0x0D1D
#define GL_DEPTH_SCALE 0x0D1E
#define GL_DEPTH_BIAS 0x0D1F
#define GL_MAX_EVAL_ORDER 0x0D30
#define GL_MAX_LIGHTS 0x0D31
#define GL_MAX_CLIP_PLANES 0x0D32
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_PIXEL_MAP_TABLE 0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define GL_MAX_NAME_STACK_DEPTH 0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_INDEX_BITS 0x0D51
#define GL_RED_BITS 0x0D52
#define GL_GREEN_BITS 0x0D53
#define GL_BLUE_BITS 0x0D54
#define GL_ALPHA_BITS 0x0D55
#define GL_DEPTH_BITS 0x0D56
#define GL_STENCIL_BITS 0x0D57
#define GL_ACCUM_RED_BITS 0x0D58
#define GL_ACCUM_GREEN_BITS 0x0D59
#define GL_ACCUM_BLUE_BITS 0x0D5A
#define GL_ACCUM_ALPHA_BITS 0x0D5B
#define GL_NAME_STACK_DEPTH 0x0D70
#define GL_AUTO_NORMAL 0x0D80
#define GL_MAP1_COLOR_4 0x0D90
#define GL_MAP1_INDEX 0x0D91
#define GL_MAP1_NORMAL 0x0D92
#define GL_MAP1_TEXTURE_COORD_1 0x0D93
#define GL_MAP1_TEXTURE_COORD_2 0x0D94
#define GL_MAP1_TEXTURE_COORD_3 0x0D95
#define GL_MAP1_TEXTURE_COORD_4 0x0D96
#define GL_MAP1_VERTEX_3 0x0D97
#define GL_MAP1_VERTEX_4 0x0D98
#define GL_MAP2_COLOR_4 0x0DB0
#define GL_MAP2_INDEX 0x0DB1
#define GL_MAP2_NORMAL 0x0DB2
#define GL_MAP2_TEXTURE_COORD_1 0x0DB3
#define GL_MAP2_TEXTURE_COORD_2 0x0DB4
#define GL_MAP2_TEXTURE_COORD_3 0x0DB5
#define GL_MAP2_TEXTURE_COORD_4 0x0DB6
#define GL_MAP2_VERTEX_3 0x0DB7
#define GL_MAP2_VERTEX_4 0x0DB8
#define GL_MAP1_GRID_DOMAIN 0x0DD0
#define GL_MAP1_GRID_SEGMENTS 0x0DD1
#define GL_MAP2_GRID_DOMAIN 0x0DD2
#define GL_MAP2_GRID_SEGMENTS 0x0DD3
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
#define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
#define GL_SELECTION_BUFFER_POINTER 0x0DF3
#define GL_SELECTION_BUFFER_SIZE 0x0DF4
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TRANSFORM_BIT 0x00001000
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_TEXTURE_BORDER 0x1005
#define GL_DONT_CARE 0x1100
#define GL_FASTEST 0x1101
#define GL_NICEST 0x1102
#define GL_AMBIENT 0x1200
#define GL_DIFFUSE 0x1201
#define GL_SPECULAR 0x1202
#define GL_POSITION 0x1203
#define GL_SPOT_DIRECTION 0x1204
#define GL_SPOT_EXPONENT 0x1205
#define GL_SPOT_CUTOFF 0x1206
#define GL_CONSTANT_ATTENUATION 0x1207
#define GL_LINEAR_ATTENUATION 0x1208
#define GL_QUADRATIC_ATTENUATION 0x1209
#define GL_COMPILE 0x1300
#define GL_COMPILE_AND_EXECUTE 0x1301
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_2_BYTES 0x1407
#define GL_3_BYTES 0x1408
#define GL_4_BYTES 0x1409
#define GL_DOUBLE 0x140A
#define GL_CLEAR 0x1500
#define GL_AND 0x1501
#define GL_AND_REVERSE 0x1502
#define GL_COPY 0x1503
#define GL_AND_INVERTED 0x1504
#define GL_NOOP 0x1505
#define GL_XOR 0x1506
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_EQUIV 0x1509
#define GL_INVERT 0x150A
#define GL_OR_REVERSE 0x150B
#define GL_COPY_INVERTED 0x150C
#define GL_OR_INVERTED 0x150D
#define GL_NAND 0x150E
#define GL_SET 0x150F
#define GL_EMISSION 0x1600
#define GL_SHININESS 0x1601
#define GL_AMBIENT_AND_DIFFUSE 0x1602
#define GL_COLOR_INDEXES 0x1603
#define GL_MODELVIEW 0x1700
#define GL_PROJECTION 0x1701
#define GL_TEXTURE 0x1702
#define GL_COLOR 0x1800
#define GL_DEPTH 0x1801
#define GL_STENCIL 0x1802
#define GL_COLOR_INDEX 0x1900
#define GL_STENCIL_INDEX 0x1901
#define GL_DEPTH_COMPONENT 0x1902
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_LUMINANCE 0x1909
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_BITMAP 0x1A00
#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
#define GL_FILL 0x1B02
#define GL_RENDER 0x1C00
#define GL_FEEDBACK 0x1C01
#define GL_SELECT 0x1C02
#define GL_FLAT 0x1D00
#define GL_SMOOTH 0x1D01
#define GL_KEEP 0x1E00
#define GL_REPLACE 0x1E01
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03
#define GL_S 0x2000
#define GL_ENABLE_BIT 0x00002000
#define GL_T 0x2001
#define GL_R 0x2002
#define GL_Q 0x2003
#define GL_MODULATE 0x2100
#define GL_DECAL 0x2101
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_TEXTURE_ENV_COLOR 0x2201
#define GL_TEXTURE_ENV 0x2300
#define GL_EYE_LINEAR 0x2400
#define GL_OBJECT_LINEAR 0x2401
#define GL_SPHERE_MAP 0x2402
#define GL_TEXTURE_GEN_MODE 0x2500
#define GL_OBJECT_PLANE 0x2501
#define GL_EYE_PLANE 0x2502
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_CLAMP 0x2900
#define GL_REPEAT 0x2901
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_R3_G3_B2 0x2A10
#define GL_V2F 0x2A20
#define GL_V3F 0x2A21
#define GL_C4UB_V2F 0x2A22
#define GL_C4UB_V3F 0x2A23
#define GL_C3F_V3F 0x2A24
#define GL_N3F_V3F 0x2A25
#define GL_C4F_N3F_V3F 0x2A26
#define GL_T2F_V3F 0x2A27
#define GL_T4F_V4F 0x2A28
#define GL_T2F_C4UB_V3F 0x2A29
#define GL_T2F_C3F_V3F 0x2A2A
#define GL_T2F_N3F_V3F 0x2A2B
#define GL_T2F_C4F_N3F_V3F 0x2A2C
#define GL_T4F_C4F_N3F_V4F 0x2A2D
#define GL_CLIP_PLANE0 0x3000
#define GL_CLIP_PLANE1 0x3001
#define GL_CLIP_PLANE2 0x3002
#define GL_CLIP_PLANE3 0x3003
#define GL_CLIP_PLANE4 0x3004
#define GL_CLIP_PLANE5 0x3005
#define GL_LIGHT0 0x4000
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_LIGHT1 0x4001
#define GL_LIGHT2 0x4002
#define GL_LIGHT3 0x4003
#define GL_LIGHT4 0x4004
#define GL_LIGHT5 0x4005
#define GL_LIGHT6 0x4006
#define GL_LIGHT7 0x4007
#define GL_HINT_BIT 0x00008000
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_ALPHA4 0x803B
#define GL_ALPHA8 0x803C
#define GL_ALPHA12 0x803D
#define GL_ALPHA16 0x803E
#define GL_LUMINANCE4 0x803F
#define GL_LUMINANCE8 0x8040
#define GL_LUMINANCE12 0x8041
#define GL_LUMINANCE16 0x8042
#define GL_LUMINANCE4_ALPHA4 0x8043
#define GL_LUMINANCE6_ALPHA2 0x8044
#define GL_LUMINANCE8_ALPHA8 0x8045
#define GL_LUMINANCE12_ALPHA4 0x8046
#define GL_LUMINANCE12_ALPHA12 0x8047
#define GL_LUMINANCE16_ALPHA16 0x8048
#define GL_INTENSITY 0x8049
#define GL_INTENSITY4 0x804A
#define GL_INTENSITY8 0x804B
#define GL_INTENSITY12 0x804C
#define GL_INTENSITY16 0x804D
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB8 0x8051
#define GL_RGB10 0x8052
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGB5_A1 0x8057
#define GL_RGBA8 0x8058
#define GL_RGB10_A2 0x8059
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#define GL_TEXTURE_INTENSITY_SIZE 0x8061
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
#define GL_TEXTURE_PRIORITY 0x8066
#define GL_TEXTURE_RESIDENT 0x8067
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_VERTEX_ARRAY 0x8074
#define GL_NORMAL_ARRAY 0x8075
#define GL_COLOR_ARRAY 0x8076
#define GL_INDEX_ARRAY 0x8077
#define GL_TEXTURE_COORD_ARRAY 0x8078
#define GL_EDGE_FLAG_ARRAY 0x8079
#define GL_VERTEX_ARRAY_SIZE 0x807A
#define GL_VERTEX_ARRAY_TYPE 0x807B
#define GL_VERTEX_ARRAY_STRIDE 0x807C
#define GL_NORMAL_ARRAY_TYPE 0x807E
#define GL_NORMAL_ARRAY_STRIDE 0x807F
#define GL_COLOR_ARRAY_SIZE 0x8081
#define GL_COLOR_ARRAY_TYPE 0x8082
#define GL_COLOR_ARRAY_STRIDE 0x8083
#define GL_INDEX_ARRAY_TYPE 0x8085
#define GL_INDEX_ARRAY_STRIDE 0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C
#define GL_VERTEX_ARRAY_POINTER 0x808E
#define GL_NORMAL_ARRAY_POINTER 0x808F
#define GL_COLOR_ARRAY_POINTER 0x8090
#define GL_INDEX_ARRAY_POINTER 0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
#define GL_COLOR_INDEX1_EXT 0x80E2
#define GL_COLOR_INDEX2_EXT 0x80E3
#define GL_COLOR_INDEX4_EXT 0x80E4
#define GL_COLOR_INDEX8_EXT 0x80E5
#define GL_COLOR_INDEX12_EXT 0x80E6
#define GL_COLOR_INDEX16_EXT 0x80E7
#define GL_EVAL_BIT 0x00010000
#define GL_LIST_BIT 0x00020000
#define GL_TEXTURE_BIT 0x00040000
#define GL_SCISSOR_BIT 0x00080000
#ifndef GL_ALL_ATTRIB_BITS
#define GL_ALL_ATTRIB_BITS 0x000fffff
#endif
#ifndef GL_CLIENT_ALL_ATTRIB_BITS
#define GL_CLIENT_ALL_ATTRIB_BITS 0xffffffff
#endif

  OGLAPI void OGLAPIENTRY glAccum(GLenum op, GLfloat value);
  OGLAPI void OGLAPIENTRY glAlphaFunc(GLenum func, GLclampf ref);
  OGLAPI GLboolean OGLAPIENTRY glAreTexturesResident(GLsizei n,
    const GLuint *textures, GLboolean *residences);
  OGLAPI void OGLAPIENTRY glArrayElement(GLint i);
  OGLAPI void OGLAPIENTRY glBegin(GLenum mode);
  OGLAPI void OGLAPIENTRY glBindTexture(GLenum target, GLuint texture);
  OGLAPI void OGLAPIENTRY glBitmap(GLsizei width, GLsizei height,
    GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove,
    const GLubyte *bitmap);
  OGLAPI void OGLAPIENTRY glBlendFunc(GLenum sfactor, GLenum dfactor);
  OGLAPI void OGLAPIENTRY glCallList(GLuint list);
  OGLAPI void OGLAPIENTRY glCallLists(GLsizei n, GLenum type,
    const void *lists);
  OGLAPI void OGLAPIENTRY glClear(GLbitfield mask);
  OGLAPI void OGLAPIENTRY glClearAccum(GLfloat red, GLfloat green,
    GLfloat blue, GLfloat alpha);
  OGLAPI void OGLAPIENTRY glClearColor(GLclampf red, GLclampf green,
    GLclampf blue, GLclampf alpha);
  OGLAPI void OGLAPIENTRY glClearDepth(GLclampd depth);
  OGLAPI void OGLAPIENTRY glClearIndex(GLfloat c);
  OGLAPI void OGLAPIENTRY glClearStencil(GLint s);
  OGLAPI void OGLAPIENTRY glClipPlane(GLenum plane,
    const GLdouble *equation);
  OGLAPI void OGLAPIENTRY glColor3b(GLbyte red, GLbyte green, GLbyte blue);
  OGLAPI void OGLAPIENTRY glColor3bv(const GLbyte *v);
  OGLAPI void OGLAPIENTRY glColor3d(GLdouble red, GLdouble green,
    GLdouble blue);
  OGLAPI void OGLAPIENTRY glColor3dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glColor3f(GLfloat red, GLfloat green,
    GLfloat blue);
  OGLAPI void OGLAPIENTRY glColor3fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glColor3i(GLint red, GLint green, GLint blue);
  OGLAPI void OGLAPIENTRY glColor3iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glColor3s(GLshort red, GLshort green,
    GLshort blue);
  OGLAPI void OGLAPIENTRY glColor3sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glColor3ub(GLubyte red, GLubyte green,
    GLubyte blue);
  OGLAPI void OGLAPIENTRY glColor3ubv(const GLubyte *v);
  OGLAPI void OGLAPIENTRY glColor3ui(GLuint red, GLuint green, GLuint blue);
  OGLAPI void OGLAPIENTRY glColor3uiv(const GLuint *v);
  OGLAPI void OGLAPIENTRY glColor3us(GLushort red, GLushort green,
    GLushort blue);
  OGLAPI void OGLAPIENTRY glColor3usv(const GLushort *v);
  OGLAPI void OGLAPIENTRY glColor4b(GLbyte red, GLbyte green, GLbyte blue,
    GLbyte alpha);
  OGLAPI void OGLAPIENTRY glColor4bv(const GLbyte *v);
  OGLAPI void OGLAPIENTRY glColor4d(GLdouble red, GLdouble green,
    GLdouble blue, GLdouble alpha);
  OGLAPI void OGLAPIENTRY glColor4dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glColor4f(GLfloat red, GLfloat green, GLfloat blue,
    GLfloat alpha);
  OGLAPI void OGLAPIENTRY glColor4fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glColor4i(GLint red, GLint green, GLint blue,
    GLint alpha);
  OGLAPI void OGLAPIENTRY glColor4iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glColor4s(GLshort red, GLshort green, GLshort blue,
    GLshort alpha);
  OGLAPI void OGLAPIENTRY glColor4sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glColor4ub(GLubyte red, GLubyte green,
    GLubyte blue, GLubyte alpha);
  OGLAPI void OGLAPIENTRY glColor4ubv(const GLubyte *v);
  OGLAPI void OGLAPIENTRY glColor4ui(GLuint red, GLuint green, GLuint blue,
    GLuint alpha);
  OGLAPI void OGLAPIENTRY glColor4uiv(const GLuint *v);
  OGLAPI void OGLAPIENTRY glColor4us(GLushort red, GLushort green,
    GLushort blue, GLushort alpha);
  OGLAPI void OGLAPIENTRY glColor4usv(const GLushort *v);
  OGLAPI void OGLAPIENTRY glColorMask(GLboolean red, GLboolean green,
    GLboolean blue, GLboolean alpha);
  OGLAPI void OGLAPIENTRY glColorMaterial(GLenum face, GLenum mode);
  OGLAPI void OGLAPIENTRY glColorPointer(GLint size, GLenum type,
    GLsizei stride, const void *pointer);
  OGLAPI void OGLAPIENTRY glCopyPixels(GLint x, GLint y, GLsizei width,
    GLsizei height, GLenum type);
  OGLAPI void OGLAPIENTRY glCopyTexImage1D(GLenum target, GLint level,
    GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
  OGLAPI void OGLAPIENTRY glCopyTexImage2D(GLenum target, GLint level,
    GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height,
    GLint border);
  OGLAPI void OGLAPIENTRY glCopyTexSubImage1D(GLenum target, GLint level,
    GLint xoffset, GLint x, GLint y, GLsizei width);
  OGLAPI void OGLAPIENTRY glCopyTexSubImage2D(GLenum target, GLint level,
    GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width,
    GLsizei height);
  OGLAPI void OGLAPIENTRY glCullFace(GLenum mode);
  OGLAPI void OGLAPIENTRY glDeleteLists(GLuint list, GLsizei range);
  OGLAPI void OGLAPIENTRY glDeleteTextures(GLsizei n,
    const GLuint *textures);
  OGLAPI void OGLAPIENTRY glDepthFunc(GLenum func);
  OGLAPI void OGLAPIENTRY glDepthMask(GLboolean flag);
  OGLAPI void OGLAPIENTRY glDepthRange(GLclampd zNear, GLclampd zFar);
  OGLAPI void OGLAPIENTRY glDisable(GLenum cap);
  OGLAPI void OGLAPIENTRY glDisableClientState(GLenum array);
  OGLAPI void OGLAPIENTRY glDrawArrays(GLenum mode, GLint first,
    GLsizei count);
  OGLAPI void OGLAPIENTRY glDrawBuffer(GLenum mode);
  OGLAPI void OGLAPIENTRY glDrawElements(GLenum mode, GLsizei count,
    GLenum type, const void *indices);
  OGLAPI void OGLAPIENTRY glDrawPixels(GLsizei width, GLsizei height,
    GLenum format, GLenum type, const void *pixels);
  OGLAPI void OGLAPIENTRY glEdgeFlag(GLboolean flag);
  OGLAPI void OGLAPIENTRY glEdgeFlagPointer(GLsizei stride,
    const void *pointer);
  OGLAPI void OGLAPIENTRY glEdgeFlagv(const GLboolean *flag);
  OGLAPI void OGLAPIENTRY glEnable(GLenum cap);
  OGLAPI void OGLAPIENTRY glEnableClientState(GLenum array);
  OGLAPI void OGLAPIENTRY glEnd(void);
  OGLAPI void OGLAPIENTRY glEndList(void);
  OGLAPI void OGLAPIENTRY glEvalCoord1d(GLdouble u);
  OGLAPI void OGLAPIENTRY glEvalCoord1dv(const GLdouble *u);
  OGLAPI void OGLAPIENTRY glEvalCoord1f(GLfloat u);
  OGLAPI void OGLAPIENTRY glEvalCoord1fv(const GLfloat *u);
  OGLAPI void OGLAPIENTRY glEvalCoord2d(GLdouble u, GLdouble v);
  OGLAPI void OGLAPIENTRY glEvalCoord2dv(const GLdouble *u);
  OGLAPI void OGLAPIENTRY glEvalCoord2f(GLfloat u, GLfloat v);
  OGLAPI void OGLAPIENTRY glEvalCoord2fv(const GLfloat *u);
  OGLAPI void OGLAPIENTRY glEvalMesh1(GLenum mode, GLint i1, GLint i2);
  OGLAPI void OGLAPIENTRY glEvalMesh2(GLenum mode, GLint i1, GLint i2,
    GLint j1, GLint j2);
  OGLAPI void OGLAPIENTRY glEvalPoint1(GLint i);
  OGLAPI void OGLAPIENTRY glEvalPoint2(GLint i, GLint j);
  OGLAPI void OGLAPIENTRY glFeedbackBuffer(GLsizei size, GLenum type,
    GLfloat *buffer);
  OGLAPI void OGLAPIENTRY glFinish(void);
  OGLAPI void OGLAPIENTRY glFlush(void);
  OGLAPI void OGLAPIENTRY glFogf(GLenum pname, GLfloat param);
  OGLAPI void OGLAPIENTRY glFogfv(GLenum pname, const GLfloat *params);
  OGLAPI void OGLAPIENTRY glFogi(GLenum pname, GLint param);
  OGLAPI void OGLAPIENTRY glFogiv(GLenum pname, const GLint *params);
  OGLAPI void OGLAPIENTRY glFrontFace(GLenum mode);
  OGLAPI void OGLAPIENTRY glFrustum(GLdouble left, GLdouble right,
    GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
  OGLAPI GLuint OGLAPIENTRY glGenLists(GLsizei range);
  OGLAPI void OGLAPIENTRY glGenTextures(GLsizei n, GLuint *textures);
  OGLAPI void OGLAPIENTRY glGetBooleanv(GLenum pname, GLboolean *params);
  OGLAPI void OGLAPIENTRY glGetClipPlane(GLenum plane, GLdouble *equation);
  OGLAPI void OGLAPIENTRY glGetDoublev(GLenum pname, GLdouble *params);
  OGLAPI GLenum OGLAPIENTRY glGetError(void);
  OGLAPI void OGLAPIENTRY glGetFloatv(GLenum pname, GLfloat *params);
  OGLAPI void OGLAPIENTRY glGetIntegerv(GLenum pname, GLint *params);
  OGLAPI void OGLAPIENTRY glGetLightfv(GLenum light, GLenum pname,
    GLfloat *params);
  OGLAPI void OGLAPIENTRY glGetLightiv(GLenum light, GLenum pname,
    GLint *params);
  OGLAPI void OGLAPIENTRY glGetMapdv(GLenum target, GLenum query,
    GLdouble *v);
  OGLAPI void OGLAPIENTRY glGetMapfv(GLenum target, GLenum query,
    GLfloat *v);
  OGLAPI void OGLAPIENTRY glGetMapiv(GLenum target, GLenum query, GLint *v);
  OGLAPI void OGLAPIENTRY glGetMaterialfv(GLenum face, GLenum pname,
    GLfloat *params);
  OGLAPI void OGLAPIENTRY glGetMaterialiv(GLenum face, GLenum pname,
    GLint *params);
  OGLAPI void OGLAPIENTRY glGetPixelMapfv(GLenum map, GLfloat *values);
  OGLAPI void OGLAPIENTRY glGetPixelMapuiv(GLenum map, GLuint *values);
  OGLAPI void OGLAPIENTRY glGetPixelMapusv(GLenum map, GLushort *values);
  OGLAPI void OGLAPIENTRY glGetPointerv(GLenum pname, void* *params);
  OGLAPI void OGLAPIENTRY glGetPolygonStipple(GLubyte *mask);
  OGLAPI const GLubyte * OGLAPIENTRY glGetString(GLenum name);
  OGLAPI void OGLAPIENTRY glGetTexEnvfv(GLenum target, GLenum pname,
    GLfloat *params);
  OGLAPI void OGLAPIENTRY glGetTexEnviv(GLenum target, GLenum pname,
    GLint *params);
  OGLAPI void OGLAPIENTRY glGetTexGendv(GLenum coord, GLenum pname,
    GLdouble *params);
  OGLAPI void OGLAPIENTRY glGetTexGenfv(GLenum coord, GLenum pname,
    GLfloat *params);
  OGLAPI void OGLAPIENTRY glGetTexGeniv(GLenum coord, GLenum pname,
    GLint *params);
  OGLAPI void OGLAPIENTRY glGetTexImage(GLenum target, GLint level,
    GLenum format, GLenum type, void *pixels);
  OGLAPI void OGLAPIENTRY glGetTexLevelParameterfv(GLenum target,
    GLint level, GLenum pname, GLfloat *params);
  OGLAPI void OGLAPIENTRY glGetTexLevelParameteriv(GLenum target,
    GLint level, GLenum pname, GLint *params);
  OGLAPI void OGLAPIENTRY glGetTexParameterfv(GLenum target, GLenum pname,
    GLfloat *params);
  OGLAPI void OGLAPIENTRY glGetTexParameteriv(GLenum target, GLenum pname,
    GLint *params);
  OGLAPI void OGLAPIENTRY glHint(GLenum target, GLenum mode);
  OGLAPI void OGLAPIENTRY glIndexMask(GLuint mask);
  OGLAPI void OGLAPIENTRY glIndexPointer(GLenum type, GLsizei stride,
    const void *pointer);
  OGLAPI void OGLAPIENTRY glIndexd(GLdouble c);
  OGLAPI void OGLAPIENTRY glIndexdv(const GLdouble *c);
  OGLAPI void OGLAPIENTRY glIndexf(GLfloat c);
  OGLAPI void OGLAPIENTRY glIndexfv(const GLfloat *c);
  OGLAPI void OGLAPIENTRY glIndexi(GLint c);
  OGLAPI void OGLAPIENTRY glIndexiv(const GLint *c);
  OGLAPI void OGLAPIENTRY glIndexs(GLshort c);
  OGLAPI void OGLAPIENTRY glIndexsv(const GLshort *c);
  OGLAPI void OGLAPIENTRY glIndexub(GLubyte c);
  OGLAPI void OGLAPIENTRY glIndexubv(const GLubyte *c);
  OGLAPI void OGLAPIENTRY glInitNames(void);
  OGLAPI void OGLAPIENTRY glInterleavedArrays(GLenum format,
    GLsizei stride, const void *pointer);
  OGLAPI GLboolean OGLAPIENTRY glIsEnabled(GLenum cap);
  OGLAPI GLboolean OGLAPIENTRY glIsList(GLuint list);
  OGLAPI GLboolean OGLAPIENTRY glIsTexture(GLuint texture);
  OGLAPI void OGLAPIENTRY glLightModelf(GLenum pname, GLfloat param);
  OGLAPI void OGLAPIENTRY glLightModelfv(GLenum pname,
    const GLfloat *params);
  OGLAPI void OGLAPIENTRY glLightModeli(GLenum pname, GLint param);
  OGLAPI void OGLAPIENTRY glLightModeliv(GLenum pname, const GLint *params);
  OGLAPI void OGLAPIENTRY glLightf(GLenum light, GLenum pname,
    GLfloat param);
  OGLAPI void OGLAPIENTRY glLightfv(GLenum light, GLenum pname,
    const GLfloat *params);
  OGLAPI void OGLAPIENTRY glLighti(GLenum light, GLenum pname, GLint param);
  OGLAPI void OGLAPIENTRY glLightiv(GLenum light, GLenum pname,
    const GLint *params);
  OGLAPI void OGLAPIENTRY glLineStipple(GLint factor, GLushort pattern);
  OGLAPI void OGLAPIENTRY glLineWidth(GLfloat width);
  OGLAPI void OGLAPIENTRY glListBase(GLuint base);
  OGLAPI void OGLAPIENTRY glLoadIdentity(void);
  OGLAPI void OGLAPIENTRY glLoadMatrixd(const GLdouble *m);
  OGLAPI void OGLAPIENTRY glLoadMatrixf(const GLfloat *m);
  OGLAPI void OGLAPIENTRY glLoadName(GLuint name);
  OGLAPI void OGLAPIENTRY glLogicOp(GLenum opcode);
  OGLAPI void OGLAPIENTRY glMap1d(GLenum target, GLdouble u1, GLdouble u2,
    GLint stride, GLint order, const GLdouble *points);
  OGLAPI void OGLAPIENTRY glMap1f(GLenum target, GLfloat u1, GLfloat u2,
    GLint stride, GLint order, const GLfloat *points);
  OGLAPI void OGLAPIENTRY glMap2d(GLenum target, GLdouble u1, GLdouble u2,
    GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride,
    GLint vorder, const GLdouble *points);
  OGLAPI void OGLAPIENTRY glMap2f(GLenum target, GLfloat u1, GLfloat u2,
    GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride,
    GLint vorder, const GLfloat *points);
  OGLAPI void OGLAPIENTRY glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
  OGLAPI void OGLAPIENTRY glMapGrid1f(GLint un, GLfloat u1, GLfloat u2);
  OGLAPI void OGLAPIENTRY glMapGrid2d(GLint un, GLdouble u1, GLdouble u2,
    GLint vn, GLdouble v1, GLdouble v2);
  OGLAPI void OGLAPIENTRY glMapGrid2f(GLint un, GLfloat u1, GLfloat u2,
    GLint vn, GLfloat v1, GLfloat v2);
  OGLAPI void OGLAPIENTRY glMaterialf(GLenum face, GLenum pname,
    GLfloat param);
  OGLAPI void OGLAPIENTRY glMaterialfv(GLenum face, GLenum pname,
    const GLfloat *params);
  OGLAPI void OGLAPIENTRY glMateriali(GLenum face, GLenum pname,
    GLint param);
  OGLAPI void OGLAPIENTRY glMaterialiv(GLenum face, GLenum pname,
    const GLint *params);
  OGLAPI void OGLAPIENTRY glMatrixMode(GLenum mode);
  OGLAPI void OGLAPIENTRY glMultMatrixd(const GLdouble *m);
  OGLAPI void OGLAPIENTRY glMultMatrixf(const GLfloat *m);
  OGLAPI void OGLAPIENTRY glNewList(GLuint list, GLenum mode);
  OGLAPI void OGLAPIENTRY glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz);
  OGLAPI void OGLAPIENTRY glNormal3bv(const GLbyte *v);
  OGLAPI void OGLAPIENTRY glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz);
  OGLAPI void OGLAPIENTRY glNormal3dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
  OGLAPI void OGLAPIENTRY glNormal3fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glNormal3i(GLint nx, GLint ny, GLint nz);
  OGLAPI void OGLAPIENTRY glNormal3iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glNormal3s(GLshort nx, GLshort ny, GLshort nz);
  OGLAPI void OGLAPIENTRY glNormal3sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glNormalPointer(GLenum type, GLsizei stride,
    const void *pointer);
  OGLAPI void OGLAPIENTRY glOrtho(GLdouble left, GLdouble right,
    GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
  OGLAPI void OGLAPIENTRY glPassThrough(GLfloat token);
  OGLAPI void OGLAPIENTRY glPixelMapfv(GLenum map, GLsizei mapsize,
    const GLfloat *values);
  OGLAPI void OGLAPIENTRY glPixelMapuiv(GLenum map, GLsizei mapsize,
    const GLuint *values);
  OGLAPI void OGLAPIENTRY glPixelMapusv(GLenum map, GLsizei mapsize,
    const GLushort *values);
  OGLAPI void OGLAPIENTRY glPixelStoref(GLenum pname, GLfloat param);
  OGLAPI void OGLAPIENTRY glPixelStorei(GLenum pname, GLint param);
  OGLAPI void OGLAPIENTRY glPixelTransferf(GLenum pname, GLfloat param);
  OGLAPI void OGLAPIENTRY glPixelTransferi(GLenum pname, GLint param);
  OGLAPI void OGLAPIENTRY glPixelZoom(GLfloat xfactor, GLfloat yfactor);
  OGLAPI void OGLAPIENTRY glPointSize(GLfloat size);
  OGLAPI void OGLAPIENTRY glPolygonMode(GLenum face, GLenum mode);
  OGLAPI void OGLAPIENTRY glPolygonOffset(GLfloat factor, GLfloat units);
  OGLAPI void OGLAPIENTRY glPolygonStipple(const GLubyte *mask);
  OGLAPI void OGLAPIENTRY glPopAttrib(void);
  OGLAPI void OGLAPIENTRY glPopClientAttrib(void);
  OGLAPI void OGLAPIENTRY glPopMatrix(void);
  OGLAPI void OGLAPIENTRY glPopName(void);
  OGLAPI void OGLAPIENTRY glPrioritizeTextures(GLsizei n,
    const GLuint *textures, const GLclampf *priorities);
  OGLAPI void OGLAPIENTRY glPushAttrib(GLbitfield mask);
  OGLAPI void OGLAPIENTRY glPushClientAttrib(GLbitfield mask);
  OGLAPI void OGLAPIENTRY glPushMatrix(void);
  OGLAPI void OGLAPIENTRY glPushName(GLuint name);
  OGLAPI void OGLAPIENTRY glRasterPos2d(GLdouble x, GLdouble y);
  OGLAPI void OGLAPIENTRY glRasterPos2dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glRasterPos2f(GLfloat x, GLfloat y);
  OGLAPI void OGLAPIENTRY glRasterPos2fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glRasterPos2i(GLint x, GLint y);
  OGLAPI void OGLAPIENTRY glRasterPos2iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glRasterPos2s(GLshort x, GLshort y);
  OGLAPI void OGLAPIENTRY glRasterPos2sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glRasterPos3d(GLdouble x, GLdouble y, GLdouble z);
  OGLAPI void OGLAPIENTRY glRasterPos3dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
  OGLAPI void OGLAPIENTRY glRasterPos3fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glRasterPos3i(GLint x, GLint y, GLint z);
  OGLAPI void OGLAPIENTRY glRasterPos3iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glRasterPos3s(GLshort x, GLshort y, GLshort z);
  OGLAPI void OGLAPIENTRY glRasterPos3sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glRasterPos4d(GLdouble x, GLdouble y, GLdouble z,
    GLdouble w);
  OGLAPI void OGLAPIENTRY glRasterPos4dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glRasterPos4f(GLfloat x, GLfloat y, GLfloat z,
    GLfloat w);
  OGLAPI void OGLAPIENTRY glRasterPos4fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glRasterPos4i(GLint x, GLint y, GLint z, GLint w);
  OGLAPI void OGLAPIENTRY glRasterPos4iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glRasterPos4s(GLshort x, GLshort y, GLshort z,
    GLshort w);
  OGLAPI void OGLAPIENTRY glRasterPos4sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glReadBuffer(GLenum mode);
  OGLAPI void OGLAPIENTRY glReadPixels(GLint x, GLint y, GLsizei width,
    GLsizei height, GLenum format, GLenum type, void *pixels);
  OGLAPI void OGLAPIENTRY glRectd(GLdouble x1, GLdouble y1, GLdouble x2,
    GLdouble y2);
  OGLAPI void OGLAPIENTRY glRectdv(const GLdouble *v1, const GLdouble *v2);
  OGLAPI void OGLAPIENTRY glRectf(GLfloat x1, GLfloat y1, GLfloat x2,
    GLfloat y2);
  OGLAPI void OGLAPIENTRY glRectfv(const GLfloat *v1, const GLfloat *v2);
  OGLAPI void OGLAPIENTRY glRecti(GLint x1, GLint y1, GLint x2, GLint y2);
  OGLAPI void OGLAPIENTRY glRectiv(const GLint *v1, const GLint *v2);
  OGLAPI void OGLAPIENTRY glRects(GLshort x1, GLshort y1, GLshort x2,
    GLshort y2);
  OGLAPI void OGLAPIENTRY glRectsv(const GLshort *v1, const GLshort *v2);
  OGLAPI GLint OGLAPIENTRY glRenderMode(GLenum mode);
  OGLAPI void OGLAPIENTRY glRotated(GLdouble angle, GLdouble x, GLdouble y,
    GLdouble z);
  OGLAPI void OGLAPIENTRY glRotatef(GLfloat angle, GLfloat x, GLfloat y,
    GLfloat z);
  OGLAPI void OGLAPIENTRY glScaled(GLdouble x, GLdouble y, GLdouble z);
  OGLAPI void OGLAPIENTRY glScalef(GLfloat x, GLfloat y, GLfloat z);
  OGLAPI void OGLAPIENTRY glScissor(GLint x, GLint y, GLsizei width,
    GLsizei height);
  OGLAPI void OGLAPIENTRY glSelectBuffer(GLsizei size, GLuint *buffer);
  OGLAPI void OGLAPIENTRY glShadeModel(GLenum mode);
  OGLAPI void OGLAPIENTRY glStencilFunc(GLenum func, GLint ref, GLuint mask);
  OGLAPI void OGLAPIENTRY glStencilMask(GLuint mask);
  OGLAPI void OGLAPIENTRY glStencilOp(GLenum fail, GLenum zfail,
    GLenum zpass);
  OGLAPI void OGLAPIENTRY glTexCoord1d(GLdouble s);
  OGLAPI void OGLAPIENTRY glTexCoord1dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glTexCoord1f(GLfloat s);
  OGLAPI void OGLAPIENTRY glTexCoord1fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glTexCoord1i(GLint s);
  OGLAPI void OGLAPIENTRY glTexCoord1iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glTexCoord1s(GLshort s);
  OGLAPI void OGLAPIENTRY glTexCoord1sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glTexCoord2d(GLdouble s, GLdouble t);
  OGLAPI void OGLAPIENTRY glTexCoord2dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glTexCoord2f(GLfloat s, GLfloat t);
  OGLAPI void OGLAPIENTRY glTexCoord2fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glTexCoord2i(GLint s, GLint t);
  OGLAPI void OGLAPIENTRY glTexCoord2iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glTexCoord2s(GLshort s, GLshort t);
  OGLAPI void OGLAPIENTRY glTexCoord2sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glTexCoord3d(GLdouble s, GLdouble t, GLdouble r);
  OGLAPI void OGLAPIENTRY glTexCoord3dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glTexCoord3f(GLfloat s, GLfloat t, GLfloat r);
  OGLAPI void OGLAPIENTRY glTexCoord3fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glTexCoord3i(GLint s, GLint t, GLint r);
  OGLAPI void OGLAPIENTRY glTexCoord3iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glTexCoord3s(GLshort s, GLshort t, GLshort r);
  OGLAPI void OGLAPIENTRY glTexCoord3sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glTexCoord4d(GLdouble s, GLdouble t, GLdouble r,
    GLdouble q);
  OGLAPI void OGLAPIENTRY glTexCoord4dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glTexCoord4f(GLfloat s, GLfloat t, GLfloat r,
    GLfloat q);
  OGLAPI void OGLAPIENTRY glTexCoord4fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glTexCoord4i(GLint s, GLint t, GLint r, GLint q);
  OGLAPI void OGLAPIENTRY glTexCoord4iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glTexCoord4s(GLshort s, GLshort t, GLshort r,
    GLshort q);
  OGLAPI void OGLAPIENTRY glTexCoord4sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glTexCoordPointer(GLint size, GLenum type,
    GLsizei stride, const void *pointer);
  OGLAPI void OGLAPIENTRY glTexEnvf(GLenum target, GLenum pname,
    GLfloat param);
  OGLAPI void OGLAPIENTRY glTexEnvfv(GLenum target, GLenum pname,
    const GLfloat *params);
  OGLAPI void OGLAPIENTRY glTexEnvi(GLenum target, GLenum pname,
    GLint param);
  OGLAPI void OGLAPIENTRY glTexEnviv(GLenum target, GLenum pname,
    const GLint *params);
  OGLAPI void OGLAPIENTRY glTexGend(GLenum coord, GLenum pname,
    GLdouble param);
  OGLAPI void OGLAPIENTRY glTexGendv(GLenum coord, GLenum pname,
    const GLdouble *params);
  OGLAPI void OGLAPIENTRY glTexGenf(GLenum coord, GLenum pname,
    GLfloat param);
  OGLAPI void OGLAPIENTRY glTexGenfv(GLenum coord, GLenum pname,
    const GLfloat *params);
  OGLAPI void OGLAPIENTRY glTexGeni(GLenum coord, GLenum pname, GLint param);
  OGLAPI void OGLAPIENTRY glTexGeniv(GLenum coord, GLenum pname,
    const GLint *params);
  OGLAPI void OGLAPIENTRY glTexImage1D(GLenum target, GLint level,
    GLint internalformat, GLsizei width, GLint border, GLenum format,
    GLenum type, const void *pixels);
  OGLAPI void OGLAPIENTRY glTexImage2D(GLenum target, GLint level,
    GLint internalformat, GLsizei width, GLsizei height, GLint border,
    GLenum format, GLenum type, const void *pixels);
  OGLAPI void OGLAPIENTRY glTexParameterf(GLenum target, GLenum pname,
    GLfloat param);
  OGLAPI void OGLAPIENTRY glTexParameterfv(GLenum target, GLenum pname,
    const GLfloat *params);
  OGLAPI void OGLAPIENTRY glTexParameteri(GLenum target, GLenum pname,
    GLint param);
  OGLAPI void OGLAPIENTRY glTexParameteriv(GLenum target, GLenum pname,
    const GLint *params);
  OGLAPI void OGLAPIENTRY glTexSubImage1D(GLenum target, GLint level,
    GLint xoffset, GLsizei width, GLenum format, GLenum type,
    const void *pixels);
  OGLAPI void OGLAPIENTRY glTexSubImage2D(GLenum target, GLint level,
    GLint xoffset, GLint yoffset, GLsizei width, GLsizei height,
    GLenum format, GLenum type, const void *pixels);
  OGLAPI void OGLAPIENTRY glTranslated(GLdouble x, GLdouble y, GLdouble z);
  OGLAPI void OGLAPIENTRY glTranslatef(GLfloat x, GLfloat y, GLfloat z);
  OGLAPI void OGLAPIENTRY glVertex2d(GLdouble x, GLdouble y);
  OGLAPI void OGLAPIENTRY glVertex2dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glVertex2f(GLfloat x, GLfloat y);
  OGLAPI void OGLAPIENTRY glVertex2fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glVertex2i(GLint x, GLint y);
  OGLAPI void OGLAPIENTRY glVertex2iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glVertex2s(GLshort x, GLshort y);
  OGLAPI void OGLAPIENTRY glVertex2sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glVertex3d(GLdouble x, GLdouble y, GLdouble z);
  OGLAPI void OGLAPIENTRY glVertex3dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glVertex3f(GLfloat x, GLfloat y, GLfloat z);
  OGLAPI void OGLAPIENTRY glVertex3fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glVertex3i(GLint x, GLint y, GLint z);
  OGLAPI void OGLAPIENTRY glVertex3iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glVertex3s(GLshort x, GLshort y, GLshort z);
  OGLAPI void OGLAPIENTRY glVertex3sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glVertex4d(GLdouble x, GLdouble y, GLdouble z,
    GLdouble w);
  OGLAPI void OGLAPIENTRY glVertex4dv(const GLdouble *v);
  OGLAPI void OGLAPIENTRY glVertex4f(GLfloat x, GLfloat y, GLfloat z,
    GLfloat w);
  OGLAPI void OGLAPIENTRY glVertex4fv(const GLfloat *v);
  OGLAPI void OGLAPIENTRY glVertex4i(GLint x, GLint y, GLint z, GLint w);
  OGLAPI void OGLAPIENTRY glVertex4iv(const GLint *v);
  OGLAPI void OGLAPIENTRY glVertex4s(GLshort x, GLshort y, GLshort z,
    GLshort w);
  OGLAPI void OGLAPIENTRY glVertex4sv(const GLshort *v);
  OGLAPI void OGLAPIENTRY glVertexPointer(GLint size, GLenum type,
    GLsizei stride, const void *pointer);
  OGLAPI void OGLAPIENTRY glViewport(GLint x, GLint y, GLsizei width,
    GLsizei height);
}

// OpenGL 1.2 Related
extern "C"
{
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
#define GL_RESCALE_NORMAL 0x803A
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_PACK_IMAGE_HEIGHT 0x806C
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_TEXTURE_3D 0x806F
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_BGR 0x80E0
#define GL_BGRA 0x80E1
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
#define GL_SINGLE_COLOR 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR 0x81FA
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E

  typedef void (OGLAPIENTRY *PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target,
    GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x,
    GLint y, GLsizei width, GLsizei height);
  typedef void (OGLAPIENTRY *PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode,
    GLuint start, GLuint end, GLsizei count, GLenum type,
    const void *indices);
  typedef void (OGLAPIENTRY *PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level,
    GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth,
    GLint border, GLenum format, GLenum type, const void *pixels);
  typedef void (OGLAPIENTRY *PFNGLTEXSUBIMAGE3DPROC)(GLenum target,
    GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
    GLsizei height, GLsizei depth, GLenum format, GLenum type,
    const void *pixels);
}

// OpenGL 1.3 Related
extern "C"
{
#define GL_MULTISAMPLE 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLES 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_CLAMP_TO_BORDER 0x812D
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#define GL_SUBTRACT 0x84E7
#define GL_COMPRESSED_ALPHA 0x84E9
#define GL_COMPRESSED_LUMINANCE 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define GL_COMPRESSED_INTENSITY 0x84EC
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_NORMAL_MAP 0x8511
#define GL_REFLECTION_MAP 0x8512
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_COMBINE 0x8570
#define GL_COMBINE_RGB 0x8571
#define GL_COMBINE_ALPHA 0x8572
#define GL_RGB_SCALE 0x8573
#define GL_ADD_SIGNED 0x8574
#define GL_INTERPOLATE 0x8575
#define GL_CONSTANT 0x8576
#define GL_PRIMARY_COLOR 0x8577
#define GL_PREVIOUS 0x8578
#define GL_SOURCE0_RGB 0x8580
#define GL_SOURCE1_RGB 0x8581
#define GL_SOURCE2_RGB 0x8582
#define GL_SOURCE0_ALPHA 0x8588
#define GL_SOURCE1_ALPHA 0x8589
#define GL_SOURCE2_ALPHA 0x858A
#define GL_OPERAND0_RGB 0x8590
#define GL_OPERAND1_RGB 0x8591
#define GL_OPERAND2_RGB 0x8592
#define GL_OPERAND0_ALPHA 0x8598
#define GL_OPERAND1_ALPHA 0x8599
#define GL_OPERAND2_ALPHA 0x859A
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_DOT3_RGB 0x86AE
#define GL_DOT3_RGBA 0x86AF
#define GL_MULTISAMPLE_BIT 0x20000000

  typedef void (OGLAPIENTRY *PFNGLACTIVETEXTUREPROC)(GLenum texture);
  typedef void (OGLAPIENTRY *PFNGLCLIENTACTIVETEXTUREPROC)(GLenum texture);
  typedef void (OGLAPIENTRY *PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum target,
    GLint level, GLenum internalformat, GLsizei width, GLint border,
    GLsizei imageSize, const void *data);
  typedef void (OGLAPIENTRY *PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target,
    GLint level, GLenum internalformat, GLsizei width, GLsizei height,
    GLint border, GLsizei imageSize, const void *data);
  typedef void (OGLAPIENTRY *PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target,
    GLint level, GLenum internalformat, GLsizei width, GLsizei height,
    GLsizei depth, GLint border, GLsizei imageSize, const void *data);
  typedef void (OGLAPIENTRY *PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum target,
    GLint level, GLint xoffset, GLsizei width, GLenum format,
    GLsizei imageSize, const void *data);
  typedef void (OGLAPIENTRY *PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target,
    GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height,
    GLenum format, GLsizei imageSize, const void *data);
  typedef void (OGLAPIENTRY *PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target,
    GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
    GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize,
    const void *data);
  typedef void (OGLAPIENTRY *PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum target,
    GLint lod, void *img);
  typedef void (OGLAPIENTRY *PFNGLLOADTRANSPOSEMATRIXDPROC)(
    const GLdouble m[16]);
  typedef void (OGLAPIENTRY *PFNGLLOADTRANSPOSEMATRIXFPROC)(
    const GLfloat m[16]);
  typedef void (OGLAPIENTRY *PFNGLMULTTRANSPOSEMATRIXDPROC)(
    const GLdouble m[16]);
  typedef void (OGLAPIENTRY *PFNGLMULTTRANSPOSEMATRIXFPROC)(
    const GLfloat m[16]);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD1DPROC)(GLenum target,
    GLdouble s);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD1DVPROC) (GLenum target,
    const GLdouble *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD1FPROC) (GLenum target,
    GLfloat s);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD1FVPROC)(GLenum target,
    const GLfloat *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD1IPROC)(GLenum target,
    GLint s);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD1IVPROC)(GLenum target,
    const GLint *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD1SPROC)(GLenum target,
    GLshort s);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD1SVPROC)(GLenum target,
    const GLshort *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD2DPROC)(GLenum target,
    GLdouble s, GLdouble t);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD2DVPROC)(GLenum target,
    const GLdouble *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD2FPROC)(GLenum target,
    GLfloat s, GLfloat t);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD2FVPROC)(GLenum target,
    const GLfloat *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD2IPROC)(GLenum target,
    GLint s, GLint t);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD2IVPROC)(GLenum target,
    const GLint *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD2SPROC)(GLenum target,
    GLshort s, GLshort t);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD2SVPROC)(GLenum target,
    const GLshort *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD3DPROC)(GLenum target,
    GLdouble s, GLdouble t, GLdouble r);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD3DVPROC)(GLenum target,
    const GLdouble *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD3FPROC)(GLenum target,
    GLfloat s, GLfloat t, GLfloat r);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD3FVPROC)(GLenum target,
    const GLfloat *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD3IPROC)(GLenum target,
    GLint s, GLint t, GLint r);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD3IVPROC)(GLenum target,
    const GLint *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD3SPROC)(GLenum target,
    GLshort s, GLshort t, GLshort r);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD3SVPROC)(GLenum target,
    const GLshort *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD4DPROC)(GLenum target,
    GLdouble s, GLdouble t, GLdouble r, GLdouble q);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD4DVPROC)(GLenum target,
    const GLdouble *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD4FPROC)(GLenum target,
    GLfloat s, GLfloat t, GLfloat r, GLfloat q);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD4FVPROC)(GLenum target,
    const GLfloat *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD4IPROC)(GLenum target,
    GLint s, GLint t, GLint r, GLint q);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD4IVPROC)(GLenum target,
    const GLint *v);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD4SPROC)(GLenum target,
    GLshort s, GLshort t, GLshort r, GLshort q);
  typedef void (OGLAPIENTRY *PFNGLMULTITEXCOORD4SVPROC)(GLenum target,
    const GLshort *v);
  typedef void (OGLAPIENTRY *PFNGLSAMPLECOVERAGEPROC)(GLclampf value,
    GLboolean invert);
}

// OpenGL 1.4 Related
extern "C"
{
#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_POINT_SIZE_MIN 0x8126
#define GL_POINT_SIZE_MAX 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#define GL_GENERATE_MIPMAP 0x8191
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_MIRRORED_REPEAT 0x8370
#define GL_FOG_COORDINATE_SOURCE 0x8450
#define GL_FOG_COORDINATE 0x8451
#define GL_FRAGMENT_DEPTH 0x8452
#define GL_CURRENT_FOG_COORDINATE 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
#define GL_FOG_COORDINATE_ARRAY 0x8457
#define GL_COLOR_SUM 0x8458
#define GL_CURRENT_SECONDARY_COLOR 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#define GL_SECONDARY_COLOR_ARRAY 0x845E
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_TEXTURE_FILTER_CONTROL 0x8500
#define GL_TEXTURE_LOD_BIAS 0x8501
#define GL_INCR_WRAP 0x8507
#define GL_DECR_WRAP 0x8508
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_DEPTH_TEXTURE_MODE 0x884B
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_COMPARE_R_TO_TEXTURE 0x884E

  typedef void (OGLAPIENTRY *PFNGLBLENDCOLORPROC)(GLclampf red,
    GLclampf green, GLclampf blue, GLclampf alpha);
  typedef void (OGLAPIENTRY *PFNGLBLENDEQUATIONPROC)(GLenum mode);
  typedef void (OGLAPIENTRY *PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB,
    GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
  typedef void (OGLAPIENTRY *PFNGLFOGCOORDPOINTERPROC)(GLenum type,
    GLsizei stride, const void *pointer);
  typedef void (OGLAPIENTRY *PFNGLFOGCOORDDPROC)(GLdouble coord);
  typedef void (OGLAPIENTRY *PFNGLFOGCOORDDVPROC)(const GLdouble *coord);
  typedef void (OGLAPIENTRY *PFNGLFOGCOORDFPROC)(GLfloat coord);
  typedef void (OGLAPIENTRY *PFNGLFOGCOORDFVPROC)(const GLfloat *coord);
  typedef void (OGLAPIENTRY *PFNGLMULTIDRAWARRAYSPROC)(GLenum mode,
    const GLint *first, const GLsizei *count, GLsizei drawcount);
  typedef void (OGLAPIENTRY *PFNGLMULTIDRAWELEMENTSPROC)(GLenum mode,
    const GLsizei *count, GLenum type, const void *const*indices,
    GLsizei drawcount);
  typedef void (OGLAPIENTRY *PFNGLPOINTPARAMETERFPROC)(GLenum pname,
    GLfloat param);
  typedef void (OGLAPIENTRY *PFNGLPOINTPARAMETERFVPROC)(GLenum pname,
    const GLfloat *params);
  typedef void (OGLAPIENTRY *PFNGLPOINTPARAMETERIPROC)(GLenum pname,
    GLint param);
  typedef void (OGLAPIENTRY *PFNGLPOINTPARAMETERIVPROC)(GLenum pname,
    const GLint *params);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3BPROC)(GLbyte red,
    GLbyte green, GLbyte blue);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte *v);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3DPROC)(GLdouble red,
    GLdouble green, GLdouble blue);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble *v);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3FPROC)(GLfloat red,
    GLfloat green, GLfloat blue);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat *v);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3IPROC)(GLint red,
    GLint green, GLint blue);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3IVPROC)(const GLint *v);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3SPROC)(GLshort red,
    GLshort green, GLshort blue);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3SVPROC)(const GLshort *v);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3UBPROC)(GLubyte red,
    GLubyte green, GLubyte blue);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte *v);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3UIPROC)(GLuint red,
    GLuint green, GLuint blue);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint *v);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3USPROC)(GLushort red,
    GLushort green, GLushort blue);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLOR3USVPROC)(const GLushort *v);
  typedef void (OGLAPIENTRY *PFNGLSECONDARYCOLORPOINTERPROC)(GLint size,
    GLenum type, GLsizei stride, const void *pointer);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS2DPROC)(GLdouble x, GLdouble y);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS2DVPROC)(const GLdouble *p);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS2FPROC)(GLfloat x, GLfloat y);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS2FVPROC)(const GLfloat *p);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS2IPROC)(GLint x, GLint y);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS2IVPROC)(const GLint *p);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS2SPROC)(GLshort x, GLshort y);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS2SVPROC)(const GLshort *p);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS3DPROC)(GLdouble x, GLdouble y,
    GLdouble z);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS3DVPROC)(const GLdouble *p);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS3FPROC)(GLfloat x, GLfloat y,
    GLfloat z);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS3FVPROC)(const GLfloat *p);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS3IPROC)(GLint x, GLint y,
    GLint z);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS3IVPROC)(const GLint *p);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS3SPROC)(GLshort x, GLshort y,
    GLshort z);
  typedef void (OGLAPIENTRY *PFNGLWINDOWPOS3SVPROC)(const GLshort *p);
}

// OpenGL 1.5
extern "C"
{
#ifndef GL_CURRENT_FOG_COORD
#define GL_CURRENT_FOG_COORD GL_CURRENT_FOG_COORDINATE
#endif
#ifndef GL_FOG_COORD
#define GL_FOG_COORD GL_FOG_COORDINATE
#endif
#ifndef GL_FOG_COORD_ARRAY
#define GL_FOG_COORD_ARRAY GL_FOG_COORDINATE_ARRAY
#endif
#ifndef GL_FOG_COORD_ARRAY_BUFFER_BINDING
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING \
  GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
#endif
#ifndef GL_FOG_COORD_ARRAY_POINTER
#define GL_FOG_COORD_ARRAY_POINTER GL_FOG_COORDINATE_ARRAY_POINTER
#endif
#ifndef GL_FOG_COORD_ARRAY_STRIDE
#define GL_FOG_COORD_ARRAY_STRIDE GL_FOG_COORDINATE_ARRAY_STRIDE
#endif
#ifndef GL_FOG_COORD_ARRAY_TYPE
#define GL_FOG_COORD_ARRAY_TYPE GL_FOG_COORDINATE_ARRAY_TYPE
#endif
#ifndef GL_FOG_COORD_SRC
#define GL_FOG_COORD_SRC GL_FOG_COORDINATE_SOURCE
#endif
#ifndef GL_SRC0_ALPHA
#define GL_SRC0_ALPHA GL_SOURCE0_ALPHA
#endif
#ifndef GL_SRC0_RGB
#define GL_SRC0_RGB GL_SOURCE0_RGB
#endif
#ifndef GL_SRC1_ALPHA
#define GL_SRC1_ALPHA GL_SOURCE1_ALPHA
#endif
#ifndef GL_SRC1_RGB
#define GL_SRC1_RGB GL_SOURCE1_RGB
#endif
#ifndef GL_SRC2_ALPHA
#define GL_SRC2_ALPHA GL_SOURCE2_ALPHA
#endif
#ifndef GL_SRC2_RGB
#define GL_SRC2_RGB GL_SOURCE2_RGB
#endif
#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_CURRENT_QUERY 0x8865
#define GL_QUERY_RESULT 0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY 0x88B8
#define GL_WRITE_ONLY 0x88B9
#define GL_READ_WRITE 0x88BA
#define GL_BUFFER_ACCESS 0x88BB
#define GL_BUFFER_MAPPED 0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_STREAM_COPY 0x88E2
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STATIC_COPY 0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA
#define GL_SAMPLES_PASSED 0x8914

  typedef ptrdiff_t GLintptr;
  typedef ptrdiff_t GLsizeiptr;

  typedef void (OGLAPIENTRY *PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
  typedef void (OGLAPIENTRY *PFNGLBINDBUFFERPROC)(GLenum target,
    GLuint buffer);
  typedef void (OGLAPIENTRY *PFNGLBUFFERDATAPROC)(GLenum target,
    GLsizeiptr size, const void* data, GLenum usage);
  typedef void (OGLAPIENTRY *PFNGLBUFFERSUBDATAPROC)(GLenum target,
    GLintptr offset, GLsizeiptr size, const void* data);
  typedef void (OGLAPIENTRY *PFNGLDELETEBUFFERSPROC)(GLsizei n,
    const GLuint* buffers);
  typedef void (OGLAPIENTRY *PFNGLDELETEQUERIESPROC)(GLsizei n,
   const GLuint* ids);
  typedef void (OGLAPIENTRY *PFNGLENDQUERYPROC)(GLenum target);
  typedef void (OGLAPIENTRY *PFNGLGENBUFFERSPROC)(GLsizei n,
    GLuint* buffers);
  typedef void (OGLAPIENTRY *PFNGLGENQUERIESPROC)(GLsizei n, GLuint* ids);
  typedef void (OGLAPIENTRY *PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target,
    GLenum pname, GLint* params);
  typedef void (OGLAPIENTRY *PFNGLGETBUFFERPOINTERVPROC)(GLenum target,
    GLenum pname, void** params);
  typedef void (OGLAPIENTRY *PFNGLGETBUFFERSUBDATAPROC)(GLenum target,
    GLintptr offset, GLsizeiptr size, void* data);
  typedef void (OGLAPIENTRY *PFNGLGETQUERYOBJECTIVPROC)(GLuint id,
    GLenum pname, GLint* params);
  typedef void (OGLAPIENTRY *PFNGLGETQUERYOBJECTUIVPROC)(GLuint id,
    GLenum pname, GLuint* params);
  typedef void (OGLAPIENTRY *PFNGLGETQUERYIVPROC)(GLenum target,
    GLenum pname, GLint* params);
  typedef GLboolean(OGLAPIENTRY *PFNGLISBUFFERPROC)(GLuint buffer);
  typedef GLboolean(OGLAPIENTRY *PFNGLISQUERYPROC)(GLuint id);
  typedef void* (OGLAPIENTRY *PFNGLMAPBUFFERPROC)(GLenum target,
    GLenum access);
  typedef GLboolean(OGLAPIENTRY *PFNGLUNMAPBUFFERPROC)(GLenum target);
}

// OpenGL 2.0
extern "C"
{
#ifndef GL_BLEND_EQUATION_RGB
#define GL_BLEND_EQUATION_RGB GL_BLEND_EQUATION
#endif
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_POINT_SPRITE 0x8861
#define GL_COORD_REPLACE 0x8862
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_COORDS 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE 0x8B4F
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5

  typedef void (OGLAPIENTRY *PFNGLATTACHSHADERPROC) (GLuint program,
    GLuint shader);
  typedef void (OGLAPIENTRY *PFNGLBINDATTRIBLOCATIONPROC) (GLuint program,
    GLuint index, const GLchar* name);
  typedef void (OGLAPIENTRY *PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum modeRGB,
    GLenum modeAlpha);
  typedef void (OGLAPIENTRY *PFNGLCOMPILESHADERPROC) (GLuint shader);
  typedef GLuint(OGLAPIENTRY *PFNGLCREATEPROGRAMPROC) (void);
  typedef GLuint(OGLAPIENTRY *PFNGLCREATESHADERPROC) (GLenum type);
  typedef void (OGLAPIENTRY *PFNGLDELETEPROGRAMPROC) (GLuint program);
  typedef void (OGLAPIENTRY *PFNGLDELETESHADERPROC) (GLuint shader);
  typedef void (OGLAPIENTRY *PFNGLDETACHSHADERPROC) (GLuint program,
    GLuint shader);
  typedef void (OGLAPIENTRY *PFNGLDISABLEVERTEXATTRIBARRAYPROC) (
    GLuint index);
  typedef void (OGLAPIENTRY *PFNGLDRAWBUFFERSPROC) (GLsizei n,
    const GLenum* bufs);
  typedef void (OGLAPIENTRY *PFNGLENABLEVERTEXATTRIBARRAYPROC) (
    GLuint index);
  typedef void (OGLAPIENTRY *PFNGLGETACTIVEATTRIBPROC) (GLuint program,
    GLuint index, GLsizei maxLength, GLsizei* length, GLint* size,
    GLenum* type, GLchar* name);
  typedef void (OGLAPIENTRY *PFNGLGETACTIVEUNIFORMPROC) (GLuint program,
    GLuint index, GLsizei maxLength, GLsizei* length, GLint* size,
    GLenum* type, GLchar* name);
  typedef void (OGLAPIENTRY *PFNGLGETATTACHEDSHADERSPROC) (GLuint program,
    GLsizei maxCount, GLsizei* count, GLuint* shaders);
  typedef GLint(OGLAPIENTRY *PFNGLGETATTRIBLOCATIONPROC) (GLuint program,
    const GLchar* name);
  typedef void (OGLAPIENTRY *PFNGLGETPROGRAMINFOLOGPROC) (GLuint program,
    GLsizei bufSize, GLsizei* length, GLchar* infoLog);
  typedef void (OGLAPIENTRY *PFNGLGETPROGRAMIVPROC) (GLuint program,
    GLenum pname, GLint* param);
  typedef void (OGLAPIENTRY *PFNGLGETSHADERINFOLOGPROC) (GLuint shader,
    GLsizei bufSize, GLsizei* length, GLchar* infoLog);
  typedef void (OGLAPIENTRY *PFNGLGETSHADERSOURCEPROC) (GLuint obj,
    GLsizei maxLength, GLsizei* length, GLchar* source);
  typedef void (OGLAPIENTRY *PFNGLGETSHADERIVPROC) (GLuint shader,
    GLenum pname, GLint* param);
  typedef GLint(OGLAPIENTRY *PFNGLGETUNIFORMLOCATIONPROC) (GLuint program,
    const GLchar* name);
  typedef void (OGLAPIENTRY *PFNGLGETUNIFORMFVPROC) (GLuint program,
    GLint location, GLfloat* params);
  typedef void (OGLAPIENTRY *PFNGLGETUNIFORMIVPROC) (GLuint program,
    GLint location, GLint* params);
  typedef void (OGLAPIENTRY *PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint index,
    GLenum pname, void** pointer);
  typedef void (OGLAPIENTRY *PFNGLGETVERTEXATTRIBDVPROC) (GLuint index,
    GLenum pname, GLdouble* params);
  typedef void (OGLAPIENTRY *PFNGLGETVERTEXATTRIBFVPROC) (GLuint index,
    GLenum pname, GLfloat* params);
  typedef void (OGLAPIENTRY *PFNGLGETVERTEXATTRIBIVPROC) (GLuint index,
    GLenum pname, GLint* params);
  typedef GLboolean(OGLAPIENTRY *PFNGLISPROGRAMPROC) (GLuint program);
  typedef GLboolean(OGLAPIENTRY *PFNGLISSHADERPROC) (GLuint shader);
  typedef void (OGLAPIENTRY *PFNGLLINKPROGRAMPROC) (GLuint program);
  typedef void (OGLAPIENTRY *PFNGLSHADERSOURCEPROC) (GLuint shader,
    GLsizei count, const GLchar *const*string, const GLint *length);
  typedef void (OGLAPIENTRY *PFNGLSTENCILFUNCSEPARATEPROC) (GLenum frontfunc,
    GLenum backfunc, GLint ref, GLuint mask);
  typedef void (OGLAPIENTRY *PFNGLSTENCILMASKSEPARATEPROC) (GLenum face,
    GLuint mask);
  typedef void (OGLAPIENTRY *PFNGLSTENCILOPSEPARATEPROC) (GLenum face,
    GLenum sfail, GLenum dpfail, GLenum dppass);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM1FPROC) (GLint location,
    GLfloat v0);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM1FVPROC) (GLint location,
    GLsizei count, const GLfloat* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM1IVPROC) (GLint location,
    GLsizei count, const GLint* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0,
    GLfloat v1);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM2FVPROC) (GLint location,
    GLsizei count, const GLfloat* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM2IPROC) (GLint location, GLint v0,
    GLint v1);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM2IVPROC) (GLint location,
    GLsizei count, const GLint* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0,
    GLfloat v1, GLfloat v2);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM3FVPROC) (GLint location,
    GLsizei count, const GLfloat* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM3IPROC) (GLint location, GLint v0,
    GLint v1, GLint v2);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM3IVPROC) (GLint location,
    GLsizei count, const GLint* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0,
    GLfloat v1, GLfloat v2, GLfloat v3);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM4FVPROC) (GLint location,
    GLsizei count, const GLfloat* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM4IPROC) (GLint location, GLint v0,
    GLint v1, GLint v2, GLint v3);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM4IVPROC) (GLint location,
    GLsizei count, const GLint* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORMMATRIX2FVPROC) (GLint location,
    GLsizei count, GLboolean transpose, const GLfloat* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORMMATRIX3FVPROC) (GLint location,
    GLsizei count, GLboolean transpose, const GLfloat* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORMMATRIX4FVPROC) (GLint location,
    GLsizei count, GLboolean transpose, const GLfloat* value);
  typedef void (OGLAPIENTRY *PFNGLUSEPROGRAMPROC) (GLuint program);
  typedef void (OGLAPIENTRY *PFNGLVALIDATEPROGRAMPROC) (GLuint program);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB1DPROC) (GLuint index,
    GLdouble x);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB1DVPROC) (GLuint index,
    const GLdouble* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB1FPROC) (GLuint index,
    GLfloat x);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB1FVPROC) (GLuint index,
    const GLfloat* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB1SPROC) (GLuint index,
    GLshort x);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB1SVPROC) (GLuint index,
    const GLshort* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB2DPROC) (GLuint index,
    GLdouble x, GLdouble y);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB2DVPROC) (GLuint index,
    const GLdouble* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB2FPROC) (GLuint index,
    GLfloat x, GLfloat y);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB2FVPROC) (GLuint index,
    const GLfloat* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB2SPROC) (GLuint index,
    GLshort x, GLshort y);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB2SVPROC) (GLuint index,
    const GLshort* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB3DPROC) (GLuint index,
    GLdouble x, GLdouble y, GLdouble z);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB3DVPROC) (GLuint index,
    const GLdouble* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB3FPROC) (GLuint index,
    GLfloat x, GLfloat y, GLfloat z);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB3FVPROC) (GLuint index,
    const GLfloat* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB3SPROC) (GLuint index,
    GLshort x, GLshort y, GLshort z);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB3SVPROC) (GLuint index,
    const GLshort* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4NBVPROC) (GLuint index,
    const GLbyte* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4NIVPROC) (GLuint index,
    const GLint* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4NSVPROC) (GLuint index,
    const GLshort* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4NUBPROC) (GLuint index,
    GLubyte x, GLubyte y, GLubyte z, GLubyte w);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4NUBVPROC) (GLuint index,
    const GLubyte* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4NUIVPROC) (GLuint index,
    const GLuint* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4NUSVPROC) (GLuint index,
    const GLushort* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4BVPROC) (GLuint index,
    const GLbyte* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4DPROC) (GLuint index,
    GLdouble x, GLdouble y, GLdouble z, GLdouble w);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4DVPROC) (GLuint index,
    const GLdouble* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4FPROC) (GLuint index,
    GLfloat x, GLfloat y, GLfloat z, GLfloat w);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4FVPROC) (GLuint index,
    const GLfloat* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4IVPROC) (GLuint index,
    const GLint* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4SPROC) (GLuint index,
    GLshort x, GLshort y, GLshort z, GLshort w);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4SVPROC) (GLuint index,
    const GLshort* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4UBVPROC) (GLuint index,
    const GLubyte* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4UIVPROC) (GLuint index,
    const GLuint* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIB4USVPROC) (GLuint index,
    const GLushort* v);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index,
    GLint size, GLenum type, GLboolean normalized, GLsizei stride,
    const void* pointer);
}

// OpenGL 2.1
extern "C"
{
#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define GL_FLOAT_MAT2x3 0x8B65
#define GL_FLOAT_MAT2x4 0x8B66
#define GL_FLOAT_MAT3x2 0x8B67
#define GL_FLOAT_MAT3x4 0x8B68
#define GL_FLOAT_MAT4x2 0x8B69
#define GL_FLOAT_MAT4x3 0x8B6A
#define GL_SRGB 0x8C40
#define GL_SRGB8 0x8C41
#define GL_SRGB_ALPHA 0x8C42
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_SLUMINANCE_ALPHA 0x8C44
#define GL_SLUMINANCE8_ALPHA8 0x8C45
#define GL_SLUMINANCE 0x8C46
#define GL_SLUMINANCE8 0x8C47
#define GL_COMPRESSED_SRGB 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#define GL_COMPRESSED_SLUMINANCE 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B

  typedef void (OGLAPIENTRY *PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location,
    GLsizei count, GLboolean transpose, const GLfloat *value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location,
    GLsizei count, GLboolean transpose, const GLfloat *value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location,
    GLsizei count, GLboolean transpose, const GLfloat *value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location,
    GLsizei count, GLboolean transpose, const GLfloat *value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location,
    GLsizei count, GLboolean transpose, const GLfloat *value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location,
    GLsizei count, GLboolean transpose, const GLfloat *value);
}

// OpenGL 3.0
extern "C"
{
#ifndef GL_CLIP_DISTANCE0
#define GL_CLIP_DISTANCE0 GL_CLIP_PLANE0
#endif
#ifndef GL_CLIP_DISTANCE1
#define GL_CLIP_DISTANCE1 GL_CLIP_PLANE1
#endif
#ifndef GL_CLIP_DISTANCE2
#define GL_CLIP_DISTANCE2 GL_CLIP_PLANE2
#endif
#ifndef GL_CLIP_DISTANCE3
#define GL_CLIP_DISTANCE3 GL_CLIP_PLANE3
#endif
#ifndef GL_CLIP_DISTANCE4
#define GL_CLIP_DISTANCE4 GL_CLIP_PLANE4
#endif
#ifndef GL_CLIP_DISTANCE5
#define GL_CLIP_DISTANCE5 GL_CLIP_PLANE5
#endif
#ifndef GL_COMPARE_REF_TO_TEXTURE
#define GL_COMPARE_REF_TO_TEXTURE GL_COMPARE_R_TO_TEXTURE_ARB
#endif
#ifndef GL_MAX_CLIP_DISTANCES
#define GL_MAX_CLIP_DISTANCES GL_MAX_CLIP_PLANES
#endif
#ifndef GL_MAX_VARYING_COMPONENTS
#define GL_MAX_VARYING_COMPONENTS GL_MAX_VARYING_FLOATS
#endif
#ifndef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x0001
#endif
#define GL_MAJOR_VERSION 0x821B
#define GL_MINOR_VERSION 0x821C
#define GL_NUM_EXTENSIONS 0x821D
#define GL_CONTEXT_FLAGS 0x821E
#define GL_DEPTH_BUFFER 0x8223
#define GL_STENCIL_BUFFER 0x8224
#define GL_RGBA32F 0x8814
#define GL_RGB32F 0x8815
#define GL_RGBA16F 0x881A
#define GL_RGB16F 0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define GL_CLAMP_VERTEX_COLOR 0x891A
#define GL_CLAMP_FRAGMENT_COLOR 0x891B
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_FIXED_ONLY 0x891D
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE 0x8C15
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_R11F_G11F_B10F 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_RGB9_E5 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_SEPARATE_ATTRIBS 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI 0x8D70
#define GL_RGB32UI 0x8D71
#define GL_RGBA16UI 0x8D76
#define GL_RGB16UI 0x8D77
#define GL_RGBA8UI 0x8D7C
#define GL_RGB8UI 0x8D7D
#define GL_RGBA32I 0x8D82
#define GL_RGB32I 0x8D83
#define GL_RGBA16I 0x8D88
#define GL_RGB16I 0x8D89
#define GL_RGBA8I 0x8D8E
#define GL_RGB8I 0x8D8F
#define GL_RED_INTEGER 0x8D94
#define GL_GREEN_INTEGER 0x8D95
#define GL_BLUE_INTEGER 0x8D96
#define GL_ALPHA_INTEGER 0x8D97
#define GL_RGB_INTEGER 0x8D98
#define GL_RGBA_INTEGER 0x8D99
#define GL_BGR_INTEGER 0x8D9A
#define GL_BGRA_INTEGER 0x8D9B
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_UNSIGNED_INT_VEC4 0x8DC8
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_INT_SAMPLER_CUBE 0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_QUERY_WAIT 0x8E13
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16

  typedef void (OGLAPIENTRY *PFNGLBEGINCONDITIONALRENDERPROC)(GLuint id,
    GLenum mode);
  typedef void (OGLAPIENTRY *PFNGLBEGINTRANSFORMFEEDBACKPROC)(
    GLenum primitiveMode);
  typedef void (OGLAPIENTRY *PFNGLBINDFRAGDATALOCATIONPROC)(GLuint program,
    GLuint colorNumber, const GLchar* name);
  typedef void (OGLAPIENTRY *PFNGLCLAMPCOLORPROC)(GLenum target,
    GLenum clamp);
  typedef void (OGLAPIENTRY *PFNGLCLEARBUFFERFIPROC)(GLenum buffer,
    GLint drawBuffer, GLfloat depth, GLint stencil);
  typedef void (OGLAPIENTRY *PFNGLCLEARBUFFERFVPROC)(GLenum buffer,
    GLint drawBuffer, const GLfloat* value);
  typedef void (OGLAPIENTRY *PFNGLCLEARBUFFERIVPROC)(GLenum buffer,
    GLint drawBuffer, const GLint* value);
  typedef void (OGLAPIENTRY *PFNGLCLEARBUFFERUIVPROC)(GLenum buffer,
    GLint drawBuffer, const GLuint* value);
  typedef void (OGLAPIENTRY *PFNGLCOLORMASKIPROC)(GLuint buf, GLboolean red,
    GLboolean green, GLboolean blue, GLboolean alpha);
  typedef void (OGLAPIENTRY *PFNGLDISABLEIPROC)(GLenum cap, GLuint index);
  typedef void (OGLAPIENTRY *PFNGLENABLEIPROC)(GLenum cap, GLuint index);
  typedef void (OGLAPIENTRY *PFNGLENDCONDITIONALRENDERPROC)(void);
  typedef void (OGLAPIENTRY *PFNGLENDTRANSFORMFEEDBACKPROC)(void);
  typedef void (OGLAPIENTRY *PFNGLGETBOOLEANI_VPROC)(GLenum pname,
    GLuint index, GLboolean* data);
  typedef GLint(OGLAPIENTRY *PFNGLGETFRAGDATALOCATIONPROC)(GLuint program,
    const GLchar* name);
  typedef const GLubyte* (OGLAPIENTRY *PFNGLGETSTRINGIPROC)(GLenum name,
    GLuint index);
  typedef void (OGLAPIENTRY *PFNGLGETTEXPARAMETERIIVPROC)(GLenum target,
    GLenum pname, GLint* params);
  typedef void (OGLAPIENTRY *PFNGLGETTEXPARAMETERIUIVPROC)(GLenum target,
    GLenum pname, GLuint* params);
  typedef void (OGLAPIENTRY *PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(
    GLuint program, GLuint index, GLsizei bufSize, GLsizei *length,
    GLsizei *size, GLenum *type, GLchar *name);
  typedef void (OGLAPIENTRY *PFNGLGETUNIFORMUIVPROC)(GLuint program,
    GLint location, GLuint* params);
  typedef void (OGLAPIENTRY *PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index,
    GLenum pname, GLint* params);
  typedef void (OGLAPIENTRY *PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index,
    GLenum pname, GLuint* params);
  typedef GLboolean(OGLAPIENTRY *PFNGLISENABLEDIPROC)(GLenum cap,
    GLuint index);
  typedef void (OGLAPIENTRY *PFNGLTEXPARAMETERIIVPROC)(GLenum target,
    GLenum pname, const GLint* params);
  typedef void (OGLAPIENTRY *PFNGLTEXPARAMETERIUIVPROC)(GLenum target,
    GLenum pname, const GLuint* params);
  typedef void (OGLAPIENTRY *PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(
    GLuint program, GLsizei count, const GLchar *const *varyings,
    GLenum buffer_mode);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM1UIVPROC)(GLint location,
    GLsizei count, const GLuint* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0,
    GLuint v1);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM2UIVPROC)(GLint location,
    GLsizei count, const GLuint* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0,
    GLuint v1, GLuint v2);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM3UIVPROC)(GLint location,
    GLsizei count, const GLuint* value);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0,
    GLuint v1, GLuint v2, GLuint v3);
  typedef void (OGLAPIENTRY *PFNGLUNIFORM4UIVPROC)(GLint location,
    GLsizei count, const GLuint* value);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI1IPROC)(GLuint index,
    GLint v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI1IVPROC)(GLuint index,
    const GLint* v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI1UIPROC)(GLuint index,
    GLuint v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI1UIVPROC)(GLuint index,
    const GLuint* v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI2IPROC)(GLuint index,
    GLint v0, GLint v1);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI2IVPROC)(GLuint index,
    const GLint* v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI2UIPROC)(GLuint index,
    GLuint v0, GLuint v1);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI2UIVPROC)(GLuint index,
    const GLuint* v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI3IPROC)(GLuint index,
    GLint v0, GLint v1, GLint v2);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI3IVPROC)(GLuint index,
    const GLint* v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI3UIPROC)(GLuint index,
    GLuint v0, GLuint v1, GLuint v2);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI3UIVPROC)(GLuint index,
    const GLuint* v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI4BVPROC)(GLuint index,
    const GLbyte* v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI4IPROC)(GLuint index,
    GLint v0, GLint v1, GLint v2, GLint v3);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI4IVPROC)(GLuint index,
    const GLint* v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI4SVPROC)(GLuint index,
    const GLshort* v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI4UBVPROC)(GLuint index,
    const GLubyte* v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI4UIPROC)(GLuint index,
    GLuint v0, GLuint v1, GLuint v2, GLuint v3);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index,
    const GLuint* v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBI4USVPROC)(GLuint index,
    const GLushort* v0);
  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index,
    GLint size, GLenum type, GLsizei stride, const void*pointer);
}

// OpenGL 3.1
extern "C"
{
#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT 0x8C2E
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_INT_SAMPLER_BUFFER 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#define GL_RED_SNORM 0x8F90
#define GL_RG_SNORM 0x8F91
#define GL_RGB_SNORM 0x8F92
#define GL_RGBA_SNORM 0x8F93
#define GL_R8_SNORM 0x8F94
#define GL_RG8_SNORM 0x8F95
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA8_SNORM 0x8F97
#define GL_R16_SNORM 0x8F98
#define GL_RG16_SNORM 0x8F99
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGBA16_SNORM 0x8F9B
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_BUFFER_MAP_OFFSET 0x9121

  typedef void (OGLAPIENTRY *PFNGLDRAWARRAYSINSTANCEDPROC) (GLenum mode,
    GLint first, GLsizei count, GLsizei primcount);
  typedef void (OGLAPIENTRY *PFNGLDRAWELEMENTSINSTANCEDPROC) (GLenum mode,
    GLsizei count, GLenum type, const void* indices, GLsizei primcount);
  typedef void (OGLAPIENTRY *PFNGLPRIMITIVERESTARTINDEXPROC) (GLuint buffer);
  typedef void (OGLAPIENTRY *PFNGLTEXBUFFERPROC) (GLenum target,
    GLenum internalFormat, GLuint buffer);
}

// OpenGL 3.2
extern "C"
{
#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY 0x000A
#define GL_LINE_STRIP_ADJACENCY 0x000B
#define GL_TRIANGLES_ADJACENCY 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
#define GL_PROGRAM_POINT_SIZE 0x8642
#define GL_GEOMETRY_VERTICES_OUT 0x8916
#define GL_GEOMETRY_INPUT_TYPE 0x8917
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define GL_CONTEXT_PROFILE_MASK 0x9126

  typedef void (OGLAPIENTRY *PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target,
    GLenum attachment, GLuint texture, GLint level);
  typedef void (OGLAPIENTRY *PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target,
    GLenum value, GLint64 *data);
  typedef void (OGLAPIENTRY *PFNGLGETINTEGER64I_VPROC)(GLenum pname,
    GLuint index, GLint64 *data);
  typedef void (OGLAPIENTRY *PFNGLGENVERTEXARRAYSPROC)(GLsizei n,
    GLuint *arrays);
  typedef void (OGLAPIENTRY *PFNGLBINDVERTEXARRAYPROC)(GLuint array);
}

// OpenGL 3.3
extern "C"
{
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
#define GL_RGB10_A2UI 0x906F

  typedef void (OGLAPIENTRY *PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index,
    GLuint divisor);
}

// OpenGL 4.0
extern "C"
{
#define GL_SAMPLE_SHADING 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS 0x8F9F
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F

  typedef void (OGLAPIENTRY *PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint buf,
    GLenum modeRGB, GLenum modeAlpha);
  typedef void (OGLAPIENTRY *PFNGLBLENDEQUATIONIPROC)(GLuint buf,
    GLenum mode);
  typedef void (OGLAPIENTRY *PFNGLBLENDFUNCSEPARATEIPROC)(GLuint buf,
    GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
  typedef void (OGLAPIENTRY *PFNGLBLENDFUNCIPROC)(GLuint buf,
    GLenum src, GLenum dst);
  typedef void (OGLAPIENTRY *PFNGLMINSAMPLESHADINGPROC)(GLclampf value);
}

// OpenGL 4.1
extern "C"
{
}


// OpenGL 4.2
extern "C"
{
#define GL_COMPRESSED_RGBA_BPTC_UNORM 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#define GL_COPY_READ_BUFFER_BINDING 0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING 0x8F37
}

// OpenGL 4.3
extern "C"
{
#define GL_NUM_SHADING_LANGUAGE_VERSIONS 0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG 0x874E
}

// OpenGL 4.4
extern "C"
{
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_MAX_VERTEX_ATTRIB_STRIDE 0x82E5
#define GL_TEXTURE_BUFFER_BINDING 0x8C2A
}

// OpenGL 4.5
extern "C"
{
  typedef GLenum(OGLAPIENTRY *PFNGLGETGRAPHICSRESETSTATUSPROC)(void);
}

EXTERN_OPENGL_CORE_API PFNGLCOPYTEXSUBIMAGE3DPROC
  opengl_core_CopyTexSubImage3D;
EXTERN_OPENGL_CORE_API PFNGLDRAWRANGEELEMENTSPROC
  opengl_core_DrawRangeElements;
EXTERN_OPENGL_CORE_API PFNGLTEXIMAGE3DPROC
  opengl_core_TexImage3D;
EXTERN_OPENGL_CORE_API PFNGLTEXSUBIMAGE3DPROC
  opengl_core_TexSubImage3D;

#define glCopyTexSubImage3D opengl_core_CopyTexSubImage3D
#define glDrawRangeElements opengl_core_DrawRangeElements
#define glTexImage3D opengl_core_TexImage3D
#define glTexSubImage3D opengl_core_TexSubImage3D

EXTERN_OPENGL_CORE_API PFNGLACTIVETEXTUREPROC opengl_core_ActiveTexture;
EXTERN_OPENGL_CORE_API PFNGLCLIENTACTIVETEXTUREPROC
  opengl_core_ClientActiveTexture;
EXTERN_OPENGL_CORE_API PFNGLCOMPRESSEDTEXIMAGE1DPROC
  opengl_core_CompressedTexImage1D;
EXTERN_OPENGL_CORE_API PFNGLCOMPRESSEDTEXIMAGE2DPROC
  opengl_core_CompressedTexImage2D;
EXTERN_OPENGL_CORE_API PFNGLCOMPRESSEDTEXIMAGE3DPROC
  opengl_core_CompressedTexImage3D;
EXTERN_OPENGL_CORE_API PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC
  opengl_core_CompressedTexSubImage1D;
EXTERN_OPENGL_CORE_API PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC
  opengl_core_CompressedTexSubImage2D;
EXTERN_OPENGL_CORE_API PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC
  opengl_core_CompressedTexSubImage3D;
EXTERN_OPENGL_CORE_API PFNGLGETCOMPRESSEDTEXIMAGEPROC
  opengl_core_GetCompressedTexImage;
EXTERN_OPENGL_CORE_API PFNGLLOADTRANSPOSEMATRIXDPROC
  opengl_core_LoadTransposeMatrixd;
EXTERN_OPENGL_CORE_API PFNGLLOADTRANSPOSEMATRIXFPROC
  opengl_core_LoadTransposeMatrixf;
EXTERN_OPENGL_CORE_API PFNGLMULTTRANSPOSEMATRIXDPROC
  opengl_core_MultTransposeMatrixd;
EXTERN_OPENGL_CORE_API PFNGLMULTTRANSPOSEMATRIXFPROC
  opengl_core_MultTransposeMatrixf;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD1DPROC opengl_core_MultiTexCoord1d;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD1DVPROC
  opengl_core_MultiTexCoord1dv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD1FPROC opengl_core_MultiTexCoord1f;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD1FVPROC
  opengl_core_MultiTexCoord1fv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD1IPROC opengl_core_MultiTexCoord1i;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD1IVPROC
  opengl_core_MultiTexCoord1iv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD1SPROC opengl_core_MultiTexCoord1s;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD1SVPROC
  opengl_core_MultiTexCoord1sv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD2DPROC opengl_core_MultiTexCoord2d;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD2DVPROC
  opengl_core_MultiTexCoord2dv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD2FPROC opengl_core_MultiTexCoord2f;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD2FVPROC
  opengl_core_MultiTexCoord2fv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD2IPROC opengl_core_MultiTexCoord2i;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD2IVPROC
  opengl_core_MultiTexCoord2iv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD2SPROC opengl_core_MultiTexCoord2s;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD2SVPROC
  opengl_core_MultiTexCoord2sv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD3DPROC opengl_core_MultiTexCoord3d;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD3DVPROC
  opengl_core_MultiTexCoord3dv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD3FPROC opengl_core_MultiTexCoord3f;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD3FVPROC
  opengl_core_MultiTexCoord3fv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD3IPROC opengl_core_MultiTexCoord3i;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD3IVPROC
  opengl_core_MultiTexCoord3iv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD3SPROC opengl_core_MultiTexCoord3s;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD3SVPROC
  opengl_core_MultiTexCoord3sv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD4DPROC opengl_core_MultiTexCoord4d;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD4DVPROC
  opengl_core_MultiTexCoord4dv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD4FPROC opengl_core_MultiTexCoord4f;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD4FVPROC
  opengl_core_MultiTexCoord4fv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD4IPROC opengl_core_MultiTexCoord4i;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD4IVPROC
  opengl_core_MultiTexCoord4iv;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD4SPROC opengl_core_MultiTexCoord4s;
EXTERN_OPENGL_CORE_API PFNGLMULTITEXCOORD4SVPROC
  opengl_core_MultiTexCoord4sv;
EXTERN_OPENGL_CORE_API PFNGLSAMPLECOVERAGEPROC opengl_core_SampleCoverage;

#define glActiveTexture opengl_core_ActiveTexture
#define glClientActiveTexture opengl_core_ClientActiveTexture
#define glCompressedTexImage1D opengl_core_CompressedTexImage1D
#define glCompressedTexImage2D opengl_core_CompressedTexImage2D
#define glCompressedTexImage3D opengl_core_CompressedTexImage3D
#define glCompressedTexSubImage1D opengl_core_CompressedTexSubImage1D
#define glCompressedTexSubImage2D opengl_core_CompressedTexSubImage2D
#define glCompressedTexSubImage3D opengl_core_CompressedTexSubImage3D
#define glGetCompressedTexImage opengl_core_GetCompressedTexImage
#define glLoadTransposeMatrixd opengl_core_LoadTransposeMatrixd
#define glLoadTransposeMatrixf opengl_core_LoadTransposeMatrixf
#define glMultTransposeMatrixd opengl_core_MultTransposeMatrixd
#define glMultTransposeMatrixf opengl_core_MultTransposeMatrixf
#define glMultiTexCoord1d opengl_core_MultiTexCoord1d
#define glMultiTexCoord1dv opengl_core_MultiTexCoord1dv
#define glMultiTexCoord1f opengl_core_MultiTexCoord1f
#define glMultiTexCoord1fv opengl_core_MultiTexCoord1fv
#define glMultiTexCoord1i opengl_core_MultiTexCoord1i
#define glMultiTexCoord1iv opengl_core_MultiTexCoord1iv
#define glMultiTexCoord1s opengl_core_MultiTexCoord1s
#define glMultiTexCoord1sv opengl_core_MultiTexCoord1sv
#define glMultiTexCoord2d opengl_core_MultiTexCoord2d
#define glMultiTexCoord2dv opengl_core_MultiTexCoord2dv
#define glMultiTexCoord2f opengl_core_MultiTexCoord2f
#define glMultiTexCoord2fv opengl_core_MultiTexCoord2fv
#define glMultiTexCoord2i opengl_core_MultiTexCoord2i
#define glMultiTexCoord2iv opengl_core_MultiTexCoord2iv
#define glMultiTexCoord2s opengl_core_MultiTexCoord2s
#define glMultiTexCoord2sv opengl_core_MultiTexCoord2sv
#define glMultiTexCoord3d opengl_core_MultiTexCoord3d
#define glMultiTexCoord3dv opengl_core_MultiTexCoord3dv
#define glMultiTexCoord3f opengl_core_MultiTexCoord3f
#define glMultiTexCoord3fv opengl_core_MultiTexCoord3fv
#define glMultiTexCoord3i opengl_core_MultiTexCoord3i
#define glMultiTexCoord3iv opengl_core_MultiTexCoord3iv
#define glMultiTexCoord3s opengl_core_MultiTexCoord3s
#define glMultiTexCoord3sv opengl_core_MultiTexCoord3sv
#define glMultiTexCoord4d opengl_core_MultiTexCoord4d
#define glMultiTexCoord4dv opengl_core_MultiTexCoord4dv
#define glMultiTexCoord4f opengl_core_MultiTexCoord4f
#define glMultiTexCoord4fv opengl_core_MultiTexCoord4fv
#define glMultiTexCoord4i opengl_core_MultiTexCoord4i
#define glMultiTexCoord4iv opengl_core_MultiTexCoord4iv
#define glMultiTexCoord4s opengl_core_MultiTexCoord4s
#define glMultiTexCoord4sv opengl_core_MultiTexCoord4sv
#define glSampleCoverage opengl_core_SampleCoverage

EXTERN_OPENGL_CORE_API PFNGLBLENDCOLORPROC opengl_core_BlendColor;
EXTERN_OPENGL_CORE_API PFNGLBLENDEQUATIONPROC opengl_core_BlendEquation;
EXTERN_OPENGL_CORE_API PFNGLBLENDFUNCSEPARATEPROC
  opengl_core_BlendFuncSeparate;
EXTERN_OPENGL_CORE_API PFNGLFOGCOORDPOINTERPROC opengl_core_FogCoordPointer;
EXTERN_OPENGL_CORE_API PFNGLFOGCOORDDPROC opengl_core_FogCoordd;
EXTERN_OPENGL_CORE_API PFNGLFOGCOORDDVPROC opengl_core_FogCoorddv;
EXTERN_OPENGL_CORE_API PFNGLFOGCOORDFPROC opengl_core_FogCoordf;
EXTERN_OPENGL_CORE_API PFNGLFOGCOORDFVPROC opengl_core_FogCoordfv;
EXTERN_OPENGL_CORE_API PFNGLMULTIDRAWARRAYSPROC opengl_core_MultiDrawArrays;
EXTERN_OPENGL_CORE_API PFNGLMULTIDRAWELEMENTSPROC
  opengl_core_MultiDrawElements;
EXTERN_OPENGL_CORE_API PFNGLPOINTPARAMETERFPROC opengl_core_PointParameterf;
EXTERN_OPENGL_CORE_API PFNGLPOINTPARAMETERFVPROC
  opengl_core_PointParameterfv;
EXTERN_OPENGL_CORE_API PFNGLPOINTPARAMETERIPROC opengl_core_PointParameteri;
EXTERN_OPENGL_CORE_API PFNGLPOINTPARAMETERIVPROC
  opengl_core_PointParameteriv;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3BPROC
  opengl_core_SecondaryColor3b;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3BVPROC
  opengl_core_SecondaryColor3bv;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3DPROC
  opengl_core_SecondaryColor3d;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3DVPROC
  opengl_core_SecondaryColor3dv;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3FPROC
  opengl_core_SecondaryColor3f;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3FVPROC
  opengl_core_SecondaryColor3fv;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3IPROC
  opengl_core_SecondaryColor3i;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3IVPROC
  opengl_core_SecondaryColor3iv;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3SPROC
  opengl_core_SecondaryColor3s;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3SVPROC
  opengl_core_SecondaryColor3sv;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3UBPROC
  opengl_core_SecondaryColor3ub;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3UBVPROC
  opengl_core_SecondaryColor3ubv;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3UIPROC
  opengl_core_SecondaryColor3ui;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3UIVPROC
  opengl_core_SecondaryColor3uiv;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3USPROC
  opengl_core_SecondaryColor3us;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLOR3USVPROC
  opengl_core_SecondaryColor3usv;
EXTERN_OPENGL_CORE_API PFNGLSECONDARYCOLORPOINTERPROC
  opengl_core_SecondaryColorPointer;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS2DPROC opengl_core_WindowPos2d;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS2DVPROC opengl_core_WindowPos2dv;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS2FPROC opengl_core_WindowPos2f;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS2FVPROC opengl_core_WindowPos2fv;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS2IPROC opengl_core_WindowPos2i;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS2IVPROC opengl_core_WindowPos2iv;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS2SPROC opengl_core_WindowPos2s;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS2SVPROC opengl_core_WindowPos2sv;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS3DPROC opengl_core_WindowPos3d;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS3DVPROC opengl_core_WindowPos3dv;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS3FPROC opengl_core_WindowPos3f;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS3FVPROC opengl_core_WindowPos3fv;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS3IPROC opengl_core_WindowPos3i;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS3IVPROC opengl_core_WindowPos3iv;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS3SPROC opengl_core_WindowPos3s;
EXTERN_OPENGL_CORE_API PFNGLWINDOWPOS3SVPROC opengl_core_WindowPos3sv;

#define glBlendColor opengl_core_BlendColor
#define glBlendEquation opengl_core_BlendEquation
#define glBlendFuncSeparate opengl_core_BlendFuncSeparate
#define glFogCoordPointer opengl_core_FogCoordPointer
#define glFogCoordd opengl_core_FogCoordd
#define glFogCoorddv opengl_core_FogCoorddv
#define glFogCoordf opengl_core_FogCoordf
#define glFogCoordfv opengl_core_FogCoordfv
#define glMultiDrawArrays opengl_core_MultiDrawArrays
#define glMultiDrawElements opengl_core_MultiDrawElements
#define glPointParameterf opengl_core_PointParameterf
#define glPointParameterfv opengl_core_PointParameterfv
#define glPointParameteri opengl_core_PointParameteri
#define glPointParameteriv opengl_core_PointParameteriv
#define glSecondaryColor3b opengl_core_SecondaryColor3b
#define glSecondaryColor3bv opengl_core_SecondaryColor3bv
#define glSecondaryColor3d opengl_core_SecondaryColor3d
#define glSecondaryColor3dv opengl_core_SecondaryColor3dv
#define glSecondaryColor3f opengl_core_SecondaryColor3f
#define glSecondaryColor3fv opengl_core_SecondaryColor3fv
#define glSecondaryColor3i opengl_core_SecondaryColor3i
#define glSecondaryColor3iv opengl_core_SecondaryColor3iv
#define glSecondaryColor3s opengl_core_SecondaryColor3s
#define glSecondaryColor3sv opengl_core_SecondaryColor3sv
#define glSecondaryColor3ub opengl_core_SecondaryColor3ub
#define glSecondaryColor3ubv opengl_core_SecondaryColor3ubv
#define glSecondaryColor3ui opengl_core_SecondaryColor3ui
#define glSecondaryColor3uiv opengl_core_SecondaryColor3uiv
#define glSecondaryColor3us opengl_core_SecondaryColor3us
#define glSecondaryColor3usv opengl_core_SecondaryColor3usv
#define glSecondaryColorPointer opengl_core_SecondaryColorPointer
#define glWindowPos2d opengl_core_WindowPos2d
#define glWindowPos2dv opengl_core_WindowPos2dv
#define glWindowPos2f opengl_core_WindowPos2f
#define glWindowPos2fv opengl_core_WindowPos2fv
#define glWindowPos2i opengl_core_WindowPos2i
#define glWindowPos2iv opengl_core_WindowPos2iv
#define glWindowPos2s opengl_core_WindowPos2s
#define glWindowPos2sv opengl_core_WindowPos2sv
#define glWindowPos3d opengl_core_WindowPos3d
#define glWindowPos3dv opengl_core_WindowPos3dv
#define glWindowPos3f opengl_core_WindowPos3f
#define glWindowPos3fv opengl_core_WindowPos3fv
#define glWindowPos3i opengl_core_WindowPos3i
#define glWindowPos3iv opengl_core_WindowPos3iv
#define glWindowPos3s opengl_core_WindowPos3s
#define glWindowPos3sv opengl_core_WindowPos3sv

EXTERN_OPENGL_CORE_API PFNGLBEGINQUERYPROC opengl_core_BeginQuery;
EXTERN_OPENGL_CORE_API PFNGLBINDBUFFERPROC opengl_core_BindBuffer;
EXTERN_OPENGL_CORE_API PFNGLBUFFERDATAPROC opengl_core_BufferData;
EXTERN_OPENGL_CORE_API PFNGLBUFFERSUBDATAPROC opengl_core_BufferSubData;
EXTERN_OPENGL_CORE_API PFNGLDELETEBUFFERSPROC opengl_core_DeleteBuffers;
EXTERN_OPENGL_CORE_API PFNGLDELETEQUERIESPROC opengl_core_DeleteQueries;
EXTERN_OPENGL_CORE_API PFNGLENDQUERYPROC opengl_core_EndQuery;
EXTERN_OPENGL_CORE_API PFNGLGENBUFFERSPROC opengl_core_GenBuffers;
EXTERN_OPENGL_CORE_API PFNGLGENQUERIESPROC opengl_core_GenQueries;
EXTERN_OPENGL_CORE_API PFNGLGETBUFFERPARAMETERIVPROC
  opengl_core_GetBufferParameteriv;
EXTERN_OPENGL_CORE_API PFNGLGETBUFFERPOINTERVPROC
  opengl_core_GetBufferPointerv;
EXTERN_OPENGL_CORE_API PFNGLGETBUFFERSUBDATAPROC
  opengl_core_GetBufferSubData;
EXTERN_OPENGL_CORE_API PFNGLGETQUERYOBJECTIVPROC
  opengl_core_GetQueryObjectiv;
EXTERN_OPENGL_CORE_API PFNGLGETQUERYOBJECTUIVPROC
  opengl_core_GetQueryObjectuiv;
EXTERN_OPENGL_CORE_API PFNGLGETQUERYIVPROC opengl_core_GetQueryiv;
EXTERN_OPENGL_CORE_API PFNGLISBUFFERPROC opengl_core_IsBuffer;
EXTERN_OPENGL_CORE_API PFNGLISQUERYPROC opengl_core_IsQuery;
EXTERN_OPENGL_CORE_API PFNGLMAPBUFFERPROC opengl_core_MapBuffer;
EXTERN_OPENGL_CORE_API PFNGLUNMAPBUFFERPROC opengl_core_UnmapBuffer;

#define glBeginQuery opengl_core_BeginQuery
#define glBindBuffer opengl_core_BindBuffer
#define glBufferData opengl_core_BufferData
#define glBufferSubData opengl_core_BufferSubData
#define glDeleteBuffers opengl_core_DeleteBuffers
#define glDeleteQueries opengl_core_DeleteQueries
#define glEndQuery opengl_core_EndQuery
#define glGenBuffers opengl_core_GenBuffers
#define glGenQueries opengl_core_GenQueries
#define glGetBufferParameteriv opengl_core_GetBufferParameteriv
#define glGetBufferPointerv opengl_core_GetBufferPointerv
#define glGetBufferSubData opengl_core_GetBufferSubData
#define glGetQueryObjectiv opengl_core_GetQueryObjectiv
#define glGetQueryObjectuiv opengl_core_GetQueryObjectuiv
#define glGetQueryiv opengl_core_GetQueryiv
#define glIsBuffer opengl_core_IsBuffer
#define glIsQuery opengl_core_IsQuery
#define glMapBuffer opengl_core_MapBuffer
#define glUnmapBuffer opengl_core_UnmapBuffer

EXTERN_OPENGL_CORE_API PFNGLATTACHSHADERPROC opengl_core_AttachShader;
EXTERN_OPENGL_CORE_API PFNGLBINDATTRIBLOCATIONPROC
  opengl_core_BindAttribLocation;
EXTERN_OPENGL_CORE_API PFNGLBLENDEQUATIONSEPARATEPROC
  opengl_core_BlendEquationSeparate;
EXTERN_OPENGL_CORE_API PFNGLCOMPILESHADERPROC opengl_core_CompileShader;
EXTERN_OPENGL_CORE_API PFNGLCREATEPROGRAMPROC opengl_core_CreateProgram;
EXTERN_OPENGL_CORE_API PFNGLCREATESHADERPROC opengl_core_CreateShader;
EXTERN_OPENGL_CORE_API PFNGLDELETEPROGRAMPROC opengl_core_DeleteProgram;
EXTERN_OPENGL_CORE_API PFNGLDELETESHADERPROC opengl_core_DeleteShader;
EXTERN_OPENGL_CORE_API PFNGLDETACHSHADERPROC opengl_core_DetachShader;
EXTERN_OPENGL_CORE_API PFNGLDISABLEVERTEXATTRIBARRAYPROC
  opengl_core_DisableVertexAttribArray;
EXTERN_OPENGL_CORE_API PFNGLDRAWBUFFERSPROC opengl_core_DrawBuffers;
EXTERN_OPENGL_CORE_API PFNGLENABLEVERTEXATTRIBARRAYPROC
  opengl_core_EnableVertexAttribArray;
EXTERN_OPENGL_CORE_API PFNGLGETACTIVEATTRIBPROC opengl_core_GetActiveAttrib;
EXTERN_OPENGL_CORE_API PFNGLGETACTIVEUNIFORMPROC
  opengl_core_GetActiveUniform;
EXTERN_OPENGL_CORE_API PFNGLGETATTACHEDSHADERSPROC
  opengl_core_GetAttachedShaders;
EXTERN_OPENGL_CORE_API PFNGLGETATTRIBLOCATIONPROC
  opengl_core_GetAttribLocation;
EXTERN_OPENGL_CORE_API PFNGLGETPROGRAMINFOLOGPROC
  opengl_core_GetProgramInfoLog;
EXTERN_OPENGL_CORE_API PFNGLGETPROGRAMIVPROC opengl_core_GetProgramiv;
EXTERN_OPENGL_CORE_API PFNGLGETSHADERINFOLOGPROC
  opengl_core_GetShaderInfoLog;
EXTERN_OPENGL_CORE_API PFNGLGETSHADERSOURCEPROC opengl_core_GetShaderSource;
EXTERN_OPENGL_CORE_API PFNGLGETSHADERIVPROC opengl_core_GetShaderiv;
EXTERN_OPENGL_CORE_API PFNGLGETUNIFORMLOCATIONPROC
  opengl_core_GetUniformLocation;
EXTERN_OPENGL_CORE_API PFNGLGETUNIFORMFVPROC opengl_core_GetUniformfv;
EXTERN_OPENGL_CORE_API PFNGLGETUNIFORMIVPROC opengl_core_GetUniformiv;
EXTERN_OPENGL_CORE_API PFNGLGETVERTEXATTRIBPOINTERVPROC
  opengl_core_GetVertexAttribPointerv;
EXTERN_OPENGL_CORE_API PFNGLGETVERTEXATTRIBDVPROC
  opengl_core_GetVertexAttribdv;
EXTERN_OPENGL_CORE_API PFNGLGETVERTEXATTRIBFVPROC
  opengl_core_GetVertexAttribfv;
EXTERN_OPENGL_CORE_API PFNGLGETVERTEXATTRIBIVPROC
  opengl_core_GetVertexAttribiv;
EXTERN_OPENGL_CORE_API PFNGLISPROGRAMPROC opengl_core_IsProgram;
EXTERN_OPENGL_CORE_API PFNGLISSHADERPROC opengl_core_IsShader;
EXTERN_OPENGL_CORE_API PFNGLLINKPROGRAMPROC opengl_core_LinkProgram;
EXTERN_OPENGL_CORE_API PFNGLSHADERSOURCEPROC opengl_core_ShaderSource;
EXTERN_OPENGL_CORE_API PFNGLSTENCILFUNCSEPARATEPROC
  opengl_core_StencilFuncSeparate;
EXTERN_OPENGL_CORE_API PFNGLSTENCILMASKSEPARATEPROC
  opengl_core_StencilMaskSeparate;
EXTERN_OPENGL_CORE_API PFNGLSTENCILOPSEPARATEPROC
  opengl_core_StencilOpSeparate;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM1FPROC opengl_core_Uniform1f;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM1FVPROC opengl_core_Uniform1fv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM1IPROC opengl_core_Uniform1i;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM1IVPROC opengl_core_Uniform1iv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM2FPROC opengl_core_Uniform2f;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM2FVPROC opengl_core_Uniform2fv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM2IPROC opengl_core_Uniform2i;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM2IVPROC opengl_core_Uniform2iv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM3FPROC opengl_core_Uniform3f;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM3FVPROC opengl_core_Uniform3fv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM3IPROC opengl_core_Uniform3i;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM3IVPROC opengl_core_Uniform3iv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM4FPROC opengl_core_Uniform4f;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM4FVPROC opengl_core_Uniform4fv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM4IPROC opengl_core_Uniform4i;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM4IVPROC opengl_core_Uniform4iv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORMMATRIX2FVPROC
  opengl_core_UniformMatrix2fv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORMMATRIX3FVPROC
  opengl_core_UniformMatrix3fv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORMMATRIX4FVPROC
  opengl_core_UniformMatrix4fv;
EXTERN_OPENGL_CORE_API PFNGLUSEPROGRAMPROC opengl_core_UseProgram;
EXTERN_OPENGL_CORE_API PFNGLVALIDATEPROGRAMPROC opengl_core_ValidateProgram;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB1DPROC opengl_core_VertexAttrib1d;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB1DVPROC opengl_core_VertexAttrib1dv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB1FPROC opengl_core_VertexAttrib1f;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB1FVPROC opengl_core_VertexAttrib1fv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB1SPROC opengl_core_VertexAttrib1s;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB1SVPROC opengl_core_VertexAttrib1sv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB2DPROC opengl_core_VertexAttrib2d;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB2DVPROC opengl_core_VertexAttrib2dv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB2FPROC opengl_core_VertexAttrib2f;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB2FVPROC opengl_core_VertexAttrib2fv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB2SPROC opengl_core_VertexAttrib2s;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB2SVPROC opengl_core_VertexAttrib2sv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB3DPROC opengl_core_VertexAttrib3d;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB3DVPROC opengl_core_VertexAttrib3dv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB3FPROC opengl_core_VertexAttrib3f;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB3FVPROC opengl_core_VertexAttrib3fv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB3SPROC opengl_core_VertexAttrib3s;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB3SVPROC opengl_core_VertexAttrib3sv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4NBVPROC
  opengl_core_VertexAttrib4Nbv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4NIVPROC
  opengl_core_VertexAttrib4Niv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4NSVPROC
  opengl_core_VertexAttrib4Nsv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4NUBPROC
  opengl_core_VertexAttrib4Nub;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4NUBVPROC
  opengl_core_VertexAttrib4Nubv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4NUIVPROC
  opengl_core_VertexAttrib4Nuiv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4NUSVPROC
  opengl_core_VertexAttrib4Nusv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4BVPROC opengl_core_VertexAttrib4bv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4DPROC opengl_core_VertexAttrib4d;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4DVPROC opengl_core_VertexAttrib4dv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4FPROC opengl_core_VertexAttrib4f;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4FVPROC opengl_core_VertexAttrib4fv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4IVPROC opengl_core_VertexAttrib4iv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4SPROC opengl_core_VertexAttrib4s;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4SVPROC opengl_core_VertexAttrib4sv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4UBVPROC
  opengl_core_VertexAttrib4ubv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4UIVPROC
  opengl_core_VertexAttrib4uiv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIB4USVPROC
  opengl_core_VertexAttrib4usv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBPOINTERPROC
  opengl_core_VertexAttribPointer;

#define glAttachShader opengl_core_AttachShader
#define glBindAttribLocation opengl_core_BindAttribLocation
#define glBlendEquationSeparate opengl_core_BlendEquationSeparate
#define glCompileShader opengl_core_CompileShader
#define glCreateProgram opengl_core_CreateProgram
#define glCreateShader opengl_core_CreateShader
#define glDeleteProgram opengl_core_DeleteProgram
#define glDeleteShader opengl_core_DeleteShader
#define glDetachShader opengl_core_DetachShader
#define glDisableVertexAttribArray opengl_core_DisableVertexAttribArray
#define glDrawBuffers opengl_core_DrawBuffers
#define glEnableVertexAttribArray opengl_core_EnableVertexAttribArray
#define glGetActiveAttrib opengl_core_GetActiveAttrib
#define glGetActiveUniform opengl_core_GetActiveUniform
#define glGetAttachedShaders opengl_core_GetAttachedShaders
#define glGetAttribLocation opengl_core_GetAttribLocation
#define glGetProgramInfoLog opengl_core_GetProgramInfoLog
#define glGetProgramiv opengl_core_GetProgramiv
#define glGetShaderInfoLog opengl_core_GetShaderInfoLog
#define glGetShaderSource opengl_core_GetShaderSource
#define glGetShaderiv opengl_core_GetShaderiv
#define glGetUniformLocation opengl_core_GetUniformLocation
#define glGetUniformfv opengl_core_GetUniformfv
#define glGetUniformiv opengl_core_GetUniformiv
#define glGetVertexAttribPointerv opengl_core_GetVertexAttribPointerv
#define glGetVertexAttribdv opengl_core_GetVertexAttribdv
#define glGetVertexAttribfv opengl_core_GetVertexAttribfv
#define glGetVertexAttribiv opengl_core_GetVertexAttribiv
#define glIsProgram opengl_core_IsProgram
#define glIsShader opengl_core_IsShader
#define glLinkProgram opengl_core_LinkProgram
#define glShaderSource opengl_core_ShaderSource
#define glStencilFuncSeparate opengl_core_StencilFuncSeparate
#define glStencilMaskSeparate opengl_core_StencilMaskSeparate
#define glStencilOpSeparate opengl_core_StencilOpSeparate
#define glUniform1f opengl_core_Uniform1f
#define glUniform1fv opengl_core_Uniform1fv
#define glUniform1i opengl_core_Uniform1i
#define glUniform1iv opengl_core_Uniform1iv
#define glUniform2f opengl_core_Uniform2f
#define glUniform2fv opengl_core_Uniform2fv
#define glUniform2i opengl_core_Uniform2i
#define glUniform2iv opengl_core_Uniform2iv
#define glUniform3f opengl_core_Uniform3f
#define glUniform3fv opengl_core_Uniform3fv
#define glUniform3i opengl_core_Uniform3i
#define glUniform3iv opengl_core_Uniform3iv
#define glUniform4f opengl_core_Uniform4f
#define glUniform4fv opengl_core_Uniform4fv
#define glUniform4i opengl_core_Uniform4i
#define glUniform4iv opengl_core_Uniform4iv
#define glUniformMatrix2fv opengl_core_UniformMatrix2fv
#define glUniformMatrix3fv opengl_core_UniformMatrix3fv
#define glUniformMatrix4fv opengl_core_UniformMatrix4fv
#define glUseProgram opengl_core_UseProgram
#define glValidateProgram opengl_core_ValidateProgram
#define glVertexAttrib1d opengl_core_VertexAttrib1d
#define glVertexAttrib1dv opengl_core_VertexAttrib1dv
#define glVertexAttrib1f opengl_core_VertexAttrib1f
#define glVertexAttrib1fv opengl_core_VertexAttrib1fv
#define glVertexAttrib1s opengl_core_VertexAttrib1s
#define glVertexAttrib1sv opengl_core_VertexAttrib1sv
#define glVertexAttrib2d opengl_core_VertexAttrib2d
#define glVertexAttrib2dv opengl_core_VertexAttrib2dv
#define glVertexAttrib2f opengl_core_VertexAttrib2f
#define glVertexAttrib2fv opengl_core_VertexAttrib2fv
#define glVertexAttrib2s opengl_core_VertexAttrib2s
#define glVertexAttrib2sv opengl_core_VertexAttrib2sv
#define glVertexAttrib3d opengl_core_VertexAttrib3d
#define glVertexAttrib3dv opengl_core_VertexAttrib3dv
#define glVertexAttrib3f opengl_core_VertexAttrib3f
#define glVertexAttrib3fv opengl_core_VertexAttrib3fv
#define glVertexAttrib3s opengl_core_VertexAttrib3s
#define glVertexAttrib3sv opengl_core_VertexAttrib3sv
#define glVertexAttrib4Nbv opengl_core_VertexAttrib4Nbv
#define glVertexAttrib4Niv opengl_core_VertexAttrib4Niv
#define glVertexAttrib4Nsv opengl_core_VertexAttrib4Nsv
#define glVertexAttrib4Nub opengl_core_VertexAttrib4Nub
#define glVertexAttrib4Nubv opengl_core_VertexAttrib4Nubv
#define glVertexAttrib4Nuiv opengl_core_VertexAttrib4Nuiv
#define glVertexAttrib4Nusv opengl_core_VertexAttrib4Nusv
#define glVertexAttrib4bv opengl_core_VertexAttrib4bv
#define glVertexAttrib4d opengl_core_VertexAttrib4d
#define glVertexAttrib4dv opengl_core_VertexAttrib4dv
#define glVertexAttrib4f opengl_core_VertexAttrib4f
#define glVertexAttrib4fv opengl_core_VertexAttrib4fv
#define glVertexAttrib4iv opengl_core_VertexAttrib4iv
#define glVertexAttrib4s opengl_core_VertexAttrib4s
#define glVertexAttrib4sv opengl_core_VertexAttrib4sv
#define glVertexAttrib4ubv opengl_core_VertexAttrib4ubv
#define glVertexAttrib4uiv opengl_core_VertexAttrib4uiv
#define glVertexAttrib4usv opengl_core_VertexAttrib4usv
#define glVertexAttribPointer opengl_core_VertexAttribPointer

EXTERN_OPENGL_CORE_API PFNGLUNIFORMMATRIX2X3FVPROC
  opengl_core_UniformMatrix2x3fv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORMMATRIX2X4FVPROC
  opengl_core_UniformMatrix2x4fv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORMMATRIX3X2FVPROC
  opengl_core_UniformMatrix3x2fv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORMMATRIX3X4FVPROC
  opengl_core_UniformMatrix3x4fv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORMMATRIX4X2FVPROC
  opengl_core_UniformMatrix4x2fv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORMMATRIX4X3FVPROC
  opengl_core_UniformMatrix4x3fv;

#define glUniformMatrix2x3fv opengl_core_UniformMatrix2x3fv
#define glUniformMatrix2x4fv opengl_core_UniformMatrix2x4fv
#define glUniformMatrix3x2fv opengl_core_UniformMatrix3x2fv
#define glUniformMatrix3x4fv opengl_core_UniformMatrix3x4fv
#define glUniformMatrix4x2fv opengl_core_UniformMatrix4x2fv
#define glUniformMatrix4x3fv opengl_core_UniformMatrix4x3fv

EXTERN_OPENGL_CORE_API PFNGLBEGINCONDITIONALRENDERPROC
  opengl_core_BeginConditionalRender;
EXTERN_OPENGL_CORE_API PFNGLBEGINTRANSFORMFEEDBACKPROC
  opengl_core_BeginTransformFeedback;
EXTERN_OPENGL_CORE_API PFNGLBINDFRAGDATALOCATIONPROC
  opengl_core_BindFragDataLocation;
EXTERN_OPENGL_CORE_API PFNGLCLAMPCOLORPROC opengl_core_ClampColor;
EXTERN_OPENGL_CORE_API PFNGLCLEARBUFFERFIPROC opengl_core_ClearBufferfi;
EXTERN_OPENGL_CORE_API PFNGLCLEARBUFFERFVPROC opengl_core_ClearBufferfv;
EXTERN_OPENGL_CORE_API PFNGLCLEARBUFFERIVPROC opengl_core_ClearBufferiv;
EXTERN_OPENGL_CORE_API PFNGLCLEARBUFFERUIVPROC opengl_core_ClearBufferuiv;
EXTERN_OPENGL_CORE_API PFNGLCOLORMASKIPROC opengl_core_ColorMaski;
EXTERN_OPENGL_CORE_API PFNGLDISABLEIPROC opengl_core_Disablei;
EXTERN_OPENGL_CORE_API PFNGLENABLEIPROC opengl_core_Enablei;
EXTERN_OPENGL_CORE_API PFNGLENDCONDITIONALRENDERPROC
  opengl_core_EndConditionalRender;
EXTERN_OPENGL_CORE_API PFNGLENDTRANSFORMFEEDBACKPROC
  opengl_core_EndTransformFeedback;
EXTERN_OPENGL_CORE_API PFNGLGETBOOLEANI_VPROC opengl_core_GetBooleani_v;
EXTERN_OPENGL_CORE_API PFNGLGETFRAGDATALOCATIONPROC
  opengl_core_GetFragDataLocation;
EXTERN_OPENGL_CORE_API PFNGLGETSTRINGIPROC opengl_core_GetStringi;
EXTERN_OPENGL_CORE_API PFNGLGETTEXPARAMETERIIVPROC
  opengl_core_GetTexParameterIiv;
EXTERN_OPENGL_CORE_API PFNGLGETTEXPARAMETERIUIVPROC
  opengl_core_GetTexParameterIuiv;
EXTERN_OPENGL_CORE_API PFNGLGETTRANSFORMFEEDBACKVARYINGPROC
  opengl_core_GetTransformFeedbackVarying;
EXTERN_OPENGL_CORE_API PFNGLGETUNIFORMUIVPROC opengl_core_GetUniformuiv;
EXTERN_OPENGL_CORE_API PFNGLGETVERTEXATTRIBIIVPROC
  opengl_core_GetVertexAttribIiv;
EXTERN_OPENGL_CORE_API PFNGLGETVERTEXATTRIBIUIVPROC
  opengl_core_GetVertexAttribIuiv;
EXTERN_OPENGL_CORE_API PFNGLISENABLEDIPROC opengl_core_IsEnabledi;
EXTERN_OPENGL_CORE_API PFNGLTEXPARAMETERIIVPROC opengl_core_TexParameterIiv;
EXTERN_OPENGL_CORE_API PFNGLTEXPARAMETERIUIVPROC
  opengl_core_TexParameterIuiv;
EXTERN_OPENGL_CORE_API PFNGLTRANSFORMFEEDBACKVARYINGSPROC
  opengl_core_TransformFeedbackVaryings;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM1UIPROC opengl_core_Uniform1ui;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM1UIVPROC opengl_core_Uniform1uiv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM2UIPROC opengl_core_Uniform2ui;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM2UIVPROC opengl_core_Uniform2uiv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM3UIPROC opengl_core_Uniform3ui;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM3UIVPROC opengl_core_Uniform3uiv;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM4UIPROC opengl_core_Uniform4ui;
EXTERN_OPENGL_CORE_API PFNGLUNIFORM4UIVPROC opengl_core_Uniform4uiv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI1IPROC opengl_core_VertexAttribI1i;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI1IVPROC
  opengl_core_VertexAttribI1iv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI1UIPROC
  opengl_core_VertexAttribI1ui;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI1UIVPROC
  opengl_core_VertexAttribI1uiv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI2IPROC opengl_core_VertexAttribI2i;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI2IVPROC
  opengl_core_VertexAttribI2iv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI2UIPROC
  opengl_core_VertexAttribI2ui;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI2UIVPROC
  opengl_core_VertexAttribI2uiv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI3IPROC opengl_core_VertexAttribI3i;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI3IVPROC
  opengl_core_VertexAttribI3iv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI3UIPROC
  opengl_core_VertexAttribI3ui;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI3UIVPROC
  opengl_core_VertexAttribI3uiv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI4BVPROC
  opengl_core_VertexAttribI4bv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI4IPROC opengl_core_VertexAttribI4i;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI4IVPROC
  opengl_core_VertexAttribI4iv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI4SVPROC
  opengl_core_VertexAttribI4sv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI4UBVPROC
  opengl_core_VertexAttribI4ubv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI4UIPROC
  opengl_core_VertexAttribI4ui;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI4UIVPROC
  opengl_core_VertexAttribI4uiv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBI4USVPROC
  opengl_core_VertexAttribI4usv;
EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBIPOINTERPROC
  opengl_core_VertexAttribIPointer;

#define glBeginConditionalRender opengl_core_BeginConditionalRender
#define glBeginTransformFeedback opengl_core_BeginTransformFeedback
#define glBindFragDataLocation opengl_core_BindFragDataLocation
#define glClampColor opengl_core_ClampColor
#define glClearBufferfi opengl_core_ClearBufferfi
#define glClearBufferfv opengl_core_ClearBufferfv
#define glClearBufferiv opengl_core_ClearBufferiv
#define glClearBufferuiv opengl_core_ClearBufferuiv
#define glColorMaski opengl_core_ColorMaski
#define glDisablei opengl_core_Disablei
#define glEnablei opengl_core_Enablei
#define glEndConditionalRender opengl_core_EndConditionalRender
#define glEndTransformFeedback opengl_core_EndTransformFeedback
#define glGetBooleani_v opengl_core_GetBooleani_v
#define glGetFragDataLocation opengl_core_GetFragDataLocation
#define glGetStringi opengl_core_GetStringi
#define glGetTexParameterIiv opengl_core_GetTexParameterIiv
#define glGetTexParameterIuiv opengl_core_GetTexParameterIuiv
#define glGetTransformFeedbackVarying opengl_core_GetTransformFeedbackVarying
#define glGetUniformuiv opengl_core_GetUniformuiv
#define glGetVertexAttribIiv opengl_core_GetVertexAttribIiv
#define glGetVertexAttribIuiv opengl_core_GetVertexAttribIuiv
#define glIsEnabledi opengl_core_IsEnabledi
#define glTexParameterIiv opengl_core_TexParameterIiv
#define glTexParameterIuiv opengl_core_TexParameterIuiv
#define glTransformFeedbackVaryings opengl_core_TransformFeedbackVaryings
#define glUniform1ui opengl_core_Uniform1ui
#define glUniform1uiv opengl_core_Uniform1uiv
#define glUniform2ui opengl_core_Uniform2ui
#define glUniform2uiv opengl_core_Uniform2uiv
#define glUniform3ui opengl_core_Uniform3ui
#define glUniform3uiv opengl_core_Uniform3uiv
#define glUniform4ui opengl_core_Uniform4ui
#define glUniform4uiv opengl_core_Uniform4uiv
#define glVertexAttribI1i opengl_core_VertexAttribI1i
#define glVertexAttribI1iv opengl_core_VertexAttribI1iv
#define glVertexAttribI1ui opengl_core_VertexAttribI1ui
#define glVertexAttribI1uiv opengl_core_VertexAttribI1uiv
#define glVertexAttribI2i opengl_core_VertexAttribI2i
#define glVertexAttribI2iv opengl_core_VertexAttribI2iv
#define glVertexAttribI2ui opengl_core_VertexAttribI2ui
#define glVertexAttribI2uiv opengl_core_VertexAttribI2uiv
#define glVertexAttribI3i opengl_core_VertexAttribI3i
#define glVertexAttribI3iv opengl_core_VertexAttribI3iv
#define glVertexAttribI3ui opengl_core_VertexAttribI3ui
#define glVertexAttribI3uiv opengl_core_VertexAttribI3uiv
#define glVertexAttribI4bv opengl_core_VertexAttribI4bv
#define glVertexAttribI4i opengl_core_VertexAttribI4i
#define glVertexAttribI4iv opengl_core_VertexAttribI4iv
#define glVertexAttribI4sv opengl_core_VertexAttribI4sv
#define glVertexAttribI4ubv opengl_core_VertexAttribI4ubv
#define glVertexAttribI4ui opengl_core_VertexAttribI4ui
#define glVertexAttribI4uiv opengl_core_VertexAttribI4uiv
#define glVertexAttribI4usv opengl_core_VertexAttribI4usv
#define glVertexAttribIPointer opengl_core_VertexAttribIPointer

EXTERN_OPENGL_CORE_API PFNGLDRAWARRAYSINSTANCEDPROC
  opengl_core_DrawArraysInstanced;
EXTERN_OPENGL_CORE_API PFNGLDRAWELEMENTSINSTANCEDPROC
  opengl_core_DrawElementsInstanced;
EXTERN_OPENGL_CORE_API PFNGLPRIMITIVERESTARTINDEXPROC
  opengl_core_PrimitiveRestartIndex;
EXTERN_OPENGL_CORE_API PFNGLTEXBUFFERPROC opengl_core_TexBuffer;

#define glDrawArraysInstanced opengl_core_DrawArraysInstanced
#define glDrawElementsInstanced opengl_core_DrawElementsInstanced
#define glPrimitiveRestartIndex opengl_core_PrimitiveRestartIndex
#define glTexBuffer opengl_core_TexBuffer

EXTERN_OPENGL_CORE_API PFNGLFRAMEBUFFERTEXTUREPROC
  opengl_core_FramebufferTexture;
EXTERN_OPENGL_CORE_API PFNGLGETBUFFERPARAMETERI64VPROC
  opengl_core_GetBufferParameteri64v;
EXTERN_OPENGL_CORE_API PFNGLGETINTEGER64I_VPROC opengl_core_GetInteger64i_v;
EXTERN_OPENGL_CORE_API PFNGLGENVERTEXARRAYSPROC opengl_core_GenVertexArrays;
EXTERN_OPENGL_CORE_API PFNGLBINDVERTEXARRAYPROC opengl_core_BindVertexArray;

#define glFramebufferTexture opengl_core_FramebufferTexture
#define glGetBufferParameteri64v opengl_core_GetBufferParameteri64v
#define glGetInteger64i_v opengl_core_GetInteger64i_v
#define glGenVertexArrays opengl_core_GenVertexArrays
#define glBindVertexArray opengl_core_BindVertexArray

EXTERN_OPENGL_CORE_API PFNGLVERTEXATTRIBDIVISORPROC
  opengl_core_VertexAttribDivisor;

#define glVertexAttribDivisor opengl_core_VertexAttribDivisor

EXTERN_OPENGL_CORE_API PFNGLBLENDEQUATIONSEPARATEIPROC
  opengl_core_BlendEquationSeparatei;
EXTERN_OPENGL_CORE_API PFNGLBLENDEQUATIONIPROC opengl_core_BlendEquationi;
EXTERN_OPENGL_CORE_API PFNGLBLENDFUNCSEPARATEIPROC
  opengl_core_BlendFuncSeparatei;
EXTERN_OPENGL_CORE_API PFNGLBLENDFUNCIPROC opengl_core_BlendFunci;
EXTERN_OPENGL_CORE_API PFNGLMINSAMPLESHADINGPROC
  opengl_core_MinSampleShading;

#define glBlendEquationSeparatei opengl_core_BlendEquationSeparatei
#define glBlendEquationi opengl_core_BlendEquationi
#define glBlendFuncSeparatei opengl_core_BlendFuncSeparatei
#define glBlendFunci opengl_core_BlendFunci
#define glMinSampleShading opengl_core_MinSampleShading

EXTERN_OPENGL_CORE_API PFNGLGETGRAPHICSRESETSTATUSPROC
  opengl_core_GetGraphicsResetStatus;

#define glGetGraphicsResetStatus opengl_core_GetGraphicsResetStatus

#include <cassert>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

namespace opengl_core
{
  struct gl_version
  {
    std::uint16_t major;
    std::uint16_t minor;

    friend bool operator==(const gl_version &lhs, const gl_version &rhs);
  };

  /**
   * This struct's function should only be called while a context has been
   * made current. The loading of extensions differs from platform to
   * platform. It should also be noted that this struct's public static
   * function should be called by the thread who owns the context.
   */
  struct gl_functions
  {
  private:
    OPENGL_CORE_API static void load_1_2();
    OPENGL_CORE_API static void load_1_3();
    OPENGL_CORE_API static void load_1_4();
    OPENGL_CORE_API static void load_1_5();
    OPENGL_CORE_API static void load_2_0();
    OPENGL_CORE_API static void load_2_1();
    OPENGL_CORE_API static void load_3_0();
    OPENGL_CORE_API static void load_3_1();
    OPENGL_CORE_API static void load_3_2();
    OPENGL_CORE_API static void load_3_3();
    OPENGL_CORE_API static void load_4_0();
    OPENGL_CORE_API static void load_4_1();
    OPENGL_CORE_API static void load_4_2();
    OPENGL_CORE_API static void load_4_3();
    OPENGL_CORE_API static void load_4_4();
    OPENGL_CORE_API static void load_4_5();

  public:
    static void configure(const gl_version &ctx_ver);
  };
}

#define DEBUG_GL 1

#if DEBUG_GL
#define GL_OUTPUT(func) \
  std::cout << "file = " << __FILE__ \
    << " line = " << __LINE__ \
    << " error = " << error \
    << " opengl function = " << #func \
    << std::endl << std::flush;
#else
#define GL_OUTPUT {int x = 0; x = x;}
#endif

#define GL_CALL(func) do { \
  GLint error; \
  while ((error = glGetError()) != 0) { \
    GL_OUTPUT(func) \
  } \
} while(false);

#endif
