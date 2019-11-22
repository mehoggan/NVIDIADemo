#include "nvidia_demo/gl_functions.h"

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <functional>
#include <stdexcept>
#include <string>
#include <sstream>

PFNGLCOPYTEXSUBIMAGE3DPROC opengl_core_CopyTexSubImage3D = NULL;
PFNGLDRAWRANGEELEMENTSPROC opengl_core_DrawRangeElements = NULL;
PFNGLTEXIMAGE3DPROC opengl_core_TexImage3D = NULL;
PFNGLTEXSUBIMAGE3DPROC opengl_core_TexSubImage3D = NULL;

PFNGLACTIVETEXTUREPROC opengl_core_ActiveTexture = NULL;
PFNGLCLIENTACTIVETEXTUREPROC opengl_core_ClientActiveTexture = NULL;
PFNGLCOMPRESSEDTEXIMAGE1DPROC opengl_core_CompressedTexImage1D = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DPROC opengl_core_CompressedTexImage2D = NULL;
PFNGLCOMPRESSEDTEXIMAGE3DPROC opengl_core_CompressedTexImage3D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC opengl_core_CompressedTexSubImage1D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC opengl_core_CompressedTexSubImage2D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC opengl_core_CompressedTexSubImage3D = NULL;
PFNGLGETCOMPRESSEDTEXIMAGEPROC opengl_core_GetCompressedTexImage = NULL;
PFNGLLOADTRANSPOSEMATRIXDPROC opengl_core_LoadTransposeMatrixd = NULL;
PFNGLLOADTRANSPOSEMATRIXFPROC opengl_core_LoadTransposeMatrixf = NULL;
PFNGLMULTTRANSPOSEMATRIXDPROC opengl_core_MultTransposeMatrixd = NULL;
PFNGLMULTTRANSPOSEMATRIXFPROC opengl_core_MultTransposeMatrixf = NULL;
PFNGLMULTITEXCOORD1DPROC opengl_core_MultiTexCoord1d = NULL;
PFNGLMULTITEXCOORD1DVPROC opengl_core_MultiTexCoord1dv = NULL;
PFNGLMULTITEXCOORD1FPROC opengl_core_MultiTexCoord1f = NULL;
PFNGLMULTITEXCOORD1FVPROC opengl_core_MultiTexCoord1fv = NULL;
PFNGLMULTITEXCOORD1IPROC opengl_core_MultiTexCoord1i = NULL;
PFNGLMULTITEXCOORD1IVPROC opengl_core_MultiTexCoord1iv = NULL;
PFNGLMULTITEXCOORD1SPROC opengl_core_MultiTexCoord1s = NULL;
PFNGLMULTITEXCOORD1SVPROC opengl_core_MultiTexCoord1sv = NULL;
PFNGLMULTITEXCOORD2DPROC opengl_core_MultiTexCoord2d = NULL;
PFNGLMULTITEXCOORD2DVPROC opengl_core_MultiTexCoord2dv = NULL;
PFNGLMULTITEXCOORD2FPROC opengl_core_MultiTexCoord2f = NULL;
PFNGLMULTITEXCOORD2FVPROC opengl_core_MultiTexCoord2fv = NULL;
PFNGLMULTITEXCOORD2IPROC opengl_core_MultiTexCoord2i = NULL;
PFNGLMULTITEXCOORD2IVPROC opengl_core_MultiTexCoord2iv = NULL;
PFNGLMULTITEXCOORD2SPROC opengl_core_MultiTexCoord2s = NULL;
PFNGLMULTITEXCOORD2SVPROC opengl_core_MultiTexCoord2sv = NULL;
PFNGLMULTITEXCOORD3DPROC opengl_core_MultiTexCoord3d = NULL;
PFNGLMULTITEXCOORD3DVPROC opengl_core_MultiTexCoord3dv = NULL;
PFNGLMULTITEXCOORD3FPROC opengl_core_MultiTexCoord3f = NULL;
PFNGLMULTITEXCOORD3FVPROC opengl_core_MultiTexCoord3fv = NULL;
PFNGLMULTITEXCOORD3IPROC opengl_core_MultiTexCoord3i = NULL;
PFNGLMULTITEXCOORD3IVPROC opengl_core_MultiTexCoord3iv = NULL;
PFNGLMULTITEXCOORD3SPROC opengl_core_MultiTexCoord3s = NULL;
PFNGLMULTITEXCOORD3SVPROC opengl_core_MultiTexCoord3sv = NULL;
PFNGLMULTITEXCOORD4DPROC opengl_core_MultiTexCoord4d = NULL;
PFNGLMULTITEXCOORD4DVPROC opengl_core_MultiTexCoord4dv = NULL;
PFNGLMULTITEXCOORD4FPROC opengl_core_MultiTexCoord4f = NULL;
PFNGLMULTITEXCOORD4FVPROC opengl_core_MultiTexCoord4fv = NULL;
PFNGLMULTITEXCOORD4IPROC opengl_core_MultiTexCoord4i = NULL;
PFNGLMULTITEXCOORD4IVPROC opengl_core_MultiTexCoord4iv = NULL;
PFNGLMULTITEXCOORD4SPROC opengl_core_MultiTexCoord4s = NULL;
PFNGLMULTITEXCOORD4SVPROC opengl_core_MultiTexCoord4sv = NULL;
PFNGLSAMPLECOVERAGEPROC opengl_core_SampleCoverage = NULL;

PFNGLBLENDCOLORPROC opengl_core_BlendColor = NULL;
PFNGLBLENDEQUATIONPROC opengl_core_BlendEquation = NULL;
PFNGLBLENDFUNCSEPARATEPROC opengl_core_BlendFuncSeparate = NULL;
PFNGLFOGCOORDPOINTERPROC opengl_core_FogCoordPointer = NULL;
PFNGLFOGCOORDDPROC opengl_core_FogCoordd = NULL;
PFNGLFOGCOORDDVPROC opengl_core_FogCoorddv = NULL;
PFNGLFOGCOORDFPROC opengl_core_FogCoordf = NULL;
PFNGLFOGCOORDFVPROC opengl_core_FogCoordfv = NULL;
PFNGLMULTIDRAWARRAYSPROC opengl_core_MultiDrawArrays = NULL;
PFNGLMULTIDRAWELEMENTSPROC opengl_core_MultiDrawElements = NULL;
PFNGLPOINTPARAMETERFPROC opengl_core_PointParameterf = NULL;
PFNGLPOINTPARAMETERFVPROC opengl_core_PointParameterfv = NULL;
PFNGLPOINTPARAMETERIPROC opengl_core_PointParameteri = NULL;
PFNGLPOINTPARAMETERIVPROC opengl_core_PointParameteriv = NULL;
PFNGLSECONDARYCOLOR3BPROC opengl_core_SecondaryColor3b = NULL;
PFNGLSECONDARYCOLOR3BVPROC opengl_core_SecondaryColor3bv = NULL;
PFNGLSECONDARYCOLOR3DPROC opengl_core_SecondaryColor3d = NULL;
PFNGLSECONDARYCOLOR3DVPROC opengl_core_SecondaryColor3dv = NULL;
PFNGLSECONDARYCOLOR3FPROC opengl_core_SecondaryColor3f = NULL;
PFNGLSECONDARYCOLOR3FVPROC opengl_core_SecondaryColor3fv = NULL;
PFNGLSECONDARYCOLOR3IPROC opengl_core_SecondaryColor3i = NULL;
PFNGLSECONDARYCOLOR3IVPROC opengl_core_SecondaryColor3iv = NULL;
PFNGLSECONDARYCOLOR3SPROC opengl_core_SecondaryColor3s = NULL;
PFNGLSECONDARYCOLOR3SVPROC opengl_core_SecondaryColor3sv = NULL;
PFNGLSECONDARYCOLOR3UBPROC opengl_core_SecondaryColor3ub = NULL;
PFNGLSECONDARYCOLOR3UBVPROC opengl_core_SecondaryColor3ubv = NULL;
PFNGLSECONDARYCOLOR3UIPROC opengl_core_SecondaryColor3ui = NULL;
PFNGLSECONDARYCOLOR3UIVPROC opengl_core_SecondaryColor3uiv = NULL;
PFNGLSECONDARYCOLOR3USPROC opengl_core_SecondaryColor3us = NULL;
PFNGLSECONDARYCOLOR3USVPROC opengl_core_SecondaryColor3usv = NULL;
PFNGLSECONDARYCOLORPOINTERPROC opengl_core_SecondaryColorPointer = NULL;
PFNGLWINDOWPOS2DPROC opengl_core_WindowPos2d = NULL;
PFNGLWINDOWPOS2DVPROC opengl_core_WindowPos2dv = NULL;
PFNGLWINDOWPOS2FPROC opengl_core_WindowPos2f = NULL;
PFNGLWINDOWPOS2FVPROC opengl_core_WindowPos2fv = NULL;
PFNGLWINDOWPOS2IPROC opengl_core_WindowPos2i = NULL;
PFNGLWINDOWPOS2IVPROC opengl_core_WindowPos2iv = NULL;
PFNGLWINDOWPOS2SPROC opengl_core_WindowPos2s = NULL;
PFNGLWINDOWPOS2SVPROC opengl_core_WindowPos2sv = NULL;
PFNGLWINDOWPOS3DPROC opengl_core_WindowPos3d = NULL;
PFNGLWINDOWPOS3DVPROC opengl_core_WindowPos3dv = NULL;
PFNGLWINDOWPOS3FPROC opengl_core_WindowPos3f = NULL;
PFNGLWINDOWPOS3FVPROC opengl_core_WindowPos3fv = NULL;
PFNGLWINDOWPOS3IPROC opengl_core_WindowPos3i = NULL;
PFNGLWINDOWPOS3IVPROC opengl_core_WindowPos3iv = NULL;
PFNGLWINDOWPOS3SPROC opengl_core_WindowPos3s = NULL;
PFNGLWINDOWPOS3SVPROC opengl_core_WindowPos3sv = NULL;

PFNGLBEGINQUERYPROC opengl_core_BeginQuery = NULL;
PFNGLBINDBUFFERPROC opengl_core_BindBuffer = NULL;
PFNGLBUFFERDATAPROC opengl_core_BufferData = NULL;
PFNGLBUFFERSUBDATAPROC opengl_core_BufferSubData = NULL;
PFNGLDELETEBUFFERSPROC opengl_core_DeleteBuffers = NULL;
PFNGLDELETEQUERIESPROC opengl_core_DeleteQueries = NULL;
PFNGLENDQUERYPROC opengl_core_EndQuery = NULL;
PFNGLGENBUFFERSPROC opengl_core_GenBuffers = NULL;
PFNGLGENQUERIESPROC opengl_core_GenQueries = NULL;
PFNGLGETBUFFERPARAMETERIVPROC opengl_core_GetBufferParameteriv = NULL;
PFNGLGETBUFFERPOINTERVPROC opengl_core_GetBufferPointerv = NULL;
PFNGLGETBUFFERSUBDATAPROC opengl_core_GetBufferSubData = NULL;
PFNGLGETQUERYOBJECTIVPROC opengl_core_GetQueryObjectiv = NULL;
PFNGLGETQUERYOBJECTUIVPROC opengl_core_GetQueryObjectuiv = NULL;
PFNGLGETQUERYIVPROC opengl_core_GetQueryiv = NULL;
PFNGLISBUFFERPROC opengl_core_IsBuffer = NULL;
PFNGLISQUERYPROC opengl_core_IsQuery = NULL;
PFNGLMAPBUFFERPROC opengl_core_MapBuffer = NULL;
PFNGLUNMAPBUFFERPROC opengl_core_UnmapBuffer = NULL;

PFNGLATTACHSHADERPROC opengl_core_AttachShader = NULL;
PFNGLBINDATTRIBLOCATIONPROC opengl_core_BindAttribLocation = NULL;
PFNGLBLENDEQUATIONSEPARATEPROC opengl_core_BlendEquationSeparate = NULL;
PFNGLCOMPILESHADERPROC opengl_core_CompileShader = NULL;
PFNGLCREATEPROGRAMPROC opengl_core_CreateProgram = NULL;
PFNGLCREATESHADERPROC opengl_core_CreateShader = NULL;
PFNGLDELETEPROGRAMPROC opengl_core_DeleteProgram = NULL;
PFNGLDELETESHADERPROC opengl_core_DeleteShader = NULL;
PFNGLDETACHSHADERPROC opengl_core_DetachShader = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYPROC
  opengl_core_DisableVertexAttribArray = NULL;
PFNGLDRAWBUFFERSPROC opengl_core_DrawBuffers = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC opengl_core_EnableVertexAttribArray = NULL;
PFNGLGETACTIVEATTRIBPROC opengl_core_GetActiveAttrib = NULL;
PFNGLGETACTIVEUNIFORMPROC opengl_core_GetActiveUniform = NULL;
PFNGLGETATTACHEDSHADERSPROC opengl_core_GetAttachedShaders = NULL;
PFNGLGETATTRIBLOCATIONPROC opengl_core_GetAttribLocation = NULL;
PFNGLGETPROGRAMINFOLOGPROC opengl_core_GetProgramInfoLog = NULL;
PFNGLGETPROGRAMIVPROC opengl_core_GetProgramiv = NULL;
PFNGLGETSHADERINFOLOGPROC opengl_core_GetShaderInfoLog = NULL;
PFNGLGETSHADERSOURCEPROC opengl_core_GetShaderSource = NULL;
PFNGLGETSHADERIVPROC opengl_core_GetShaderiv = NULL;
PFNGLGETUNIFORMLOCATIONPROC opengl_core_GetUniformLocation = NULL;
PFNGLGETUNIFORMFVPROC opengl_core_GetUniformfv = NULL;
PFNGLGETUNIFORMIVPROC opengl_core_GetUniformiv = NULL;
PFNGLGETVERTEXATTRIBPOINTERVPROC opengl_core_GetVertexAttribPointerv = NULL;
PFNGLGETVERTEXATTRIBDVPROC opengl_core_GetVertexAttribdv = NULL;
PFNGLGETVERTEXATTRIBFVPROC opengl_core_GetVertexAttribfv = NULL;
PFNGLGETVERTEXATTRIBIVPROC opengl_core_GetVertexAttribiv = NULL;
PFNGLISPROGRAMPROC opengl_core_IsProgram = NULL;
PFNGLISSHADERPROC opengl_core_IsShader = NULL;
PFNGLLINKPROGRAMPROC opengl_core_LinkProgram = NULL;
PFNGLSHADERSOURCEPROC opengl_core_ShaderSource = NULL;
PFNGLSTENCILFUNCSEPARATEPROC opengl_core_StencilFuncSeparate = NULL;
PFNGLSTENCILMASKSEPARATEPROC opengl_core_StencilMaskSeparate = NULL;
PFNGLSTENCILOPSEPARATEPROC opengl_core_StencilOpSeparate = NULL;
PFNGLUNIFORM1FPROC opengl_core_Uniform1f = NULL;
PFNGLUNIFORM1FVPROC opengl_core_Uniform1fv = NULL;
PFNGLUNIFORM1IPROC opengl_core_Uniform1i = NULL;
PFNGLUNIFORM1IVPROC opengl_core_Uniform1iv = NULL;
PFNGLUNIFORM2FPROC opengl_core_Uniform2f = NULL;
PFNGLUNIFORM2FVPROC opengl_core_Uniform2fv = NULL;
PFNGLUNIFORM2IPROC opengl_core_Uniform2i = NULL;
PFNGLUNIFORM2IVPROC opengl_core_Uniform2iv = NULL;
PFNGLUNIFORM3FPROC opengl_core_Uniform3f = NULL;
PFNGLUNIFORM3FVPROC opengl_core_Uniform3fv = NULL;
PFNGLUNIFORM3IPROC opengl_core_Uniform3i = NULL;
PFNGLUNIFORM3IVPROC opengl_core_Uniform3iv = NULL;
PFNGLUNIFORM4FPROC opengl_core_Uniform4f = NULL;
PFNGLUNIFORM4FVPROC opengl_core_Uniform4fv = NULL;
PFNGLUNIFORM4IPROC opengl_core_Uniform4i = NULL;
PFNGLUNIFORM4IVPROC opengl_core_Uniform4iv = NULL;
PFNGLUNIFORMMATRIX2FVPROC opengl_core_UniformMatrix2fv = NULL;
PFNGLUNIFORMMATRIX3FVPROC opengl_core_UniformMatrix3fv = NULL;
PFNGLUNIFORMMATRIX4FVPROC opengl_core_UniformMatrix4fv = NULL;
PFNGLUSEPROGRAMPROC opengl_core_UseProgram = NULL;
PFNGLVALIDATEPROGRAMPROC opengl_core_ValidateProgram = NULL;
PFNGLVERTEXATTRIB1DPROC opengl_core_VertexAttrib1d = NULL;
PFNGLVERTEXATTRIB1DVPROC opengl_core_VertexAttrib1dv = NULL;
PFNGLVERTEXATTRIB1FPROC opengl_core_VertexAttrib1f = NULL;
PFNGLVERTEXATTRIB1FVPROC opengl_core_VertexAttrib1fv = NULL;
PFNGLVERTEXATTRIB1SPROC opengl_core_VertexAttrib1s = NULL;
PFNGLVERTEXATTRIB1SVPROC opengl_core_VertexAttrib1sv = NULL;
PFNGLVERTEXATTRIB2DPROC opengl_core_VertexAttrib2d = NULL;
PFNGLVERTEXATTRIB2DVPROC opengl_core_VertexAttrib2dv = NULL;
PFNGLVERTEXATTRIB2FPROC opengl_core_VertexAttrib2f = NULL;
PFNGLVERTEXATTRIB2FVPROC opengl_core_VertexAttrib2fv = NULL;
PFNGLVERTEXATTRIB2SPROC opengl_core_VertexAttrib2s = NULL;
PFNGLVERTEXATTRIB2SVPROC opengl_core_VertexAttrib2sv = NULL;
PFNGLVERTEXATTRIB3DPROC opengl_core_VertexAttrib3d = NULL;
PFNGLVERTEXATTRIB3DVPROC opengl_core_VertexAttrib3dv = NULL;
PFNGLVERTEXATTRIB3FPROC opengl_core_VertexAttrib3f = NULL;
PFNGLVERTEXATTRIB3FVPROC opengl_core_VertexAttrib3fv = NULL;
PFNGLVERTEXATTRIB3SPROC opengl_core_VertexAttrib3s = NULL;
PFNGLVERTEXATTRIB3SVPROC opengl_core_VertexAttrib3sv = NULL;
PFNGLVERTEXATTRIB4NBVPROC opengl_core_VertexAttrib4Nbv = NULL;
PFNGLVERTEXATTRIB4NIVPROC opengl_core_VertexAttrib4Niv = NULL;
PFNGLVERTEXATTRIB4NSVPROC opengl_core_VertexAttrib4Nsv = NULL;
PFNGLVERTEXATTRIB4NUBPROC opengl_core_VertexAttrib4Nub = NULL;
PFNGLVERTEXATTRIB4NUBVPROC opengl_core_VertexAttrib4Nubv = NULL;
PFNGLVERTEXATTRIB4NUIVPROC opengl_core_VertexAttrib4Nuiv = NULL;
PFNGLVERTEXATTRIB4NUSVPROC opengl_core_VertexAttrib4Nusv = NULL;
PFNGLVERTEXATTRIB4BVPROC opengl_core_VertexAttrib4bv = NULL;
PFNGLVERTEXATTRIB4DPROC opengl_core_VertexAttrib4d = NULL;
PFNGLVERTEXATTRIB4DVPROC opengl_core_VertexAttrib4dv = NULL;
PFNGLVERTEXATTRIB4FPROC opengl_core_VertexAttrib4f = NULL;
PFNGLVERTEXATTRIB4FVPROC opengl_core_VertexAttrib4fv = NULL;
PFNGLVERTEXATTRIB4IVPROC opengl_core_VertexAttrib4iv = NULL;
PFNGLVERTEXATTRIB4SPROC opengl_core_VertexAttrib4s = NULL;
PFNGLVERTEXATTRIB4SVPROC opengl_core_VertexAttrib4sv = NULL;
PFNGLVERTEXATTRIB4UBVPROC opengl_core_VertexAttrib4ubv = NULL;
PFNGLVERTEXATTRIB4UIVPROC opengl_core_VertexAttrib4uiv = NULL;
PFNGLVERTEXATTRIB4USVPROC opengl_core_VertexAttrib4usv = NULL;
PFNGLVERTEXATTRIBPOINTERPROC opengl_core_VertexAttribPointer = NULL;

PFNGLUNIFORMMATRIX2X3FVPROC opengl_core_UniformMatrix2x3fv = NULL;
PFNGLUNIFORMMATRIX2X4FVPROC opengl_core_UniformMatrix2x4fv = NULL;
PFNGLUNIFORMMATRIX3X2FVPROC opengl_core_UniformMatrix3x2fv = NULL;
PFNGLUNIFORMMATRIX3X4FVPROC opengl_core_UniformMatrix3x4fv = NULL;
PFNGLUNIFORMMATRIX4X2FVPROC opengl_core_UniformMatrix4x2fv = NULL;
PFNGLUNIFORMMATRIX4X3FVPROC opengl_core_UniformMatrix4x3fv = NULL;

PFNGLBEGINCONDITIONALRENDERPROC opengl_core_BeginConditionalRender = NULL;
PFNGLBEGINTRANSFORMFEEDBACKPROC opengl_core_BeginTransformFeedback = NULL;
PFNGLBINDFRAGDATALOCATIONPROC opengl_core_BindFragDataLocation = NULL;
PFNGLCLAMPCOLORPROC opengl_core_ClampColor = NULL;
PFNGLCLEARBUFFERFIPROC opengl_core_ClearBufferfi = NULL;
PFNGLCLEARBUFFERFVPROC opengl_core_ClearBufferfv = NULL;
PFNGLCLEARBUFFERIVPROC opengl_core_ClearBufferiv = NULL;
PFNGLCLEARBUFFERUIVPROC opengl_core_ClearBufferuiv = NULL;
PFNGLCOLORMASKIPROC opengl_core_ColorMaski = NULL;
PFNGLDISABLEIPROC opengl_core_Disablei = NULL;
PFNGLENABLEIPROC opengl_core_Enablei = NULL;
PFNGLENDCONDITIONALRENDERPROC opengl_core_EndConditionalRender = NULL;
PFNGLENDTRANSFORMFEEDBACKPROC opengl_core_EndTransformFeedback = NULL;
PFNGLGETBOOLEANI_VPROC opengl_core_GetBooleani_v = NULL;
PFNGLGETFRAGDATALOCATIONPROC opengl_core_GetFragDataLocation = NULL;
PFNGLGETSTRINGIPROC opengl_core_GetStringi = NULL;
PFNGLGETTEXPARAMETERIIVPROC opengl_core_GetTexParameterIiv = NULL;
PFNGLGETTEXPARAMETERIUIVPROC opengl_core_GetTexParameterIuiv = NULL;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC
  opengl_core_GetTransformFeedbackVarying = NULL;
PFNGLGETUNIFORMUIVPROC opengl_core_GetUniformuiv = NULL;
PFNGLGETVERTEXATTRIBIIVPROC opengl_core_GetVertexAttribIiv = NULL;
PFNGLGETVERTEXATTRIBIUIVPROC opengl_core_GetVertexAttribIuiv = NULL;
PFNGLISENABLEDIPROC opengl_core_IsEnabledi = NULL;
PFNGLTEXPARAMETERIIVPROC opengl_core_TexParameterIiv = NULL;
PFNGLTEXPARAMETERIUIVPROC opengl_core_TexParameterIuiv = NULL;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC
  opengl_core_TransformFeedbackVaryings = NULL;
PFNGLUNIFORM1UIPROC opengl_core_Uniform1ui = NULL;
PFNGLUNIFORM1UIVPROC opengl_core_Uniform1uiv = NULL;
PFNGLUNIFORM2UIPROC opengl_core_Uniform2ui = NULL;
PFNGLUNIFORM2UIVPROC opengl_core_Uniform2uiv = NULL;
PFNGLUNIFORM3UIPROC opengl_core_Uniform3ui = NULL;
PFNGLUNIFORM3UIVPROC opengl_core_Uniform3uiv = NULL;
PFNGLUNIFORM4UIPROC opengl_core_Uniform4ui = NULL;
PFNGLUNIFORM4UIVPROC opengl_core_Uniform4uiv = NULL;
PFNGLVERTEXATTRIBI1IPROC opengl_core_VertexAttribI1i = NULL;
PFNGLVERTEXATTRIBI1IVPROC opengl_core_VertexAttribI1iv = NULL;
PFNGLVERTEXATTRIBI1UIPROC opengl_core_VertexAttribI1ui = NULL;
PFNGLVERTEXATTRIBI1UIVPROC opengl_core_VertexAttribI1uiv = NULL;
PFNGLVERTEXATTRIBI2IPROC opengl_core_VertexAttribI2i = NULL;
PFNGLVERTEXATTRIBI2IVPROC opengl_core_VertexAttribI2iv = NULL;
PFNGLVERTEXATTRIBI2UIPROC opengl_core_VertexAttribI2ui = NULL;
PFNGLVERTEXATTRIBI2UIVPROC opengl_core_VertexAttribI2uiv = NULL;
PFNGLVERTEXATTRIBI3IPROC opengl_core_VertexAttribI3i = NULL;
PFNGLVERTEXATTRIBI3IVPROC opengl_core_VertexAttribI3iv = NULL;
PFNGLVERTEXATTRIBI3UIPROC opengl_core_VertexAttribI3ui = NULL;
PFNGLVERTEXATTRIBI3UIVPROC opengl_core_VertexAttribI3uiv = NULL;
PFNGLVERTEXATTRIBI4BVPROC opengl_core_VertexAttribI4bv = NULL;
PFNGLVERTEXATTRIBI4IPROC opengl_core_VertexAttribI4i = NULL;
PFNGLVERTEXATTRIBI4IVPROC opengl_core_VertexAttribI4iv = NULL;
PFNGLVERTEXATTRIBI4SVPROC opengl_core_VertexAttribI4sv = NULL;
PFNGLVERTEXATTRIBI4UBVPROC opengl_core_VertexAttribI4ubv = NULL;
PFNGLVERTEXATTRIBI4UIPROC opengl_core_VertexAttribI4ui = NULL;
PFNGLVERTEXATTRIBI4UIVPROC opengl_core_VertexAttribI4uiv = NULL;
PFNGLVERTEXATTRIBI4USVPROC opengl_core_VertexAttribI4usv = NULL;
PFNGLVERTEXATTRIBIPOINTERPROC opengl_core_VertexAttribIPointer = NULL;

PFNGLDRAWARRAYSINSTANCEDPROC opengl_core_DrawArraysInstanced = NULL;
PFNGLDRAWELEMENTSINSTANCEDPROC opengl_core_DrawElementsInstanced = NULL;
PFNGLPRIMITIVERESTARTINDEXPROC opengl_core_PrimitiveRestartIndex = NULL;
PFNGLTEXBUFFERPROC opengl_core_TexBuffer = NULL;

PFNGLFRAMEBUFFERTEXTUREPROC opengl_core_FramebufferTexture = NULL;
PFNGLGETBUFFERPARAMETERI64VPROC opengl_core_GetBufferParameteri64v = NULL;
PFNGLGETINTEGER64I_VPROC opengl_core_GetInteger64i_v = NULL;
PFNGLGENVERTEXARRAYSPROC opengl_core_GenVertexArrays = NULL;
PFNGLBINDVERTEXARRAYPROC opengl_core_BindVertexArray = NULL;

PFNGLVERTEXATTRIBDIVISORPROC opengl_core_VertexAttribDivisor = NULL;

PFNGLBLENDEQUATIONSEPARATEIPROC opengl_core_BlendEquationSeparatei = NULL;
PFNGLBLENDEQUATIONIPROC opengl_core_BlendEquationi = NULL;
PFNGLBLENDFUNCSEPARATEIPROC opengl_core_BlendFuncSeparatei = NULL;
PFNGLBLENDFUNCIPROC opengl_core_BlendFunci = NULL;
PFNGLMINSAMPLESHADINGPROC opengl_core_MinSampleShading = NULL;

PFNGLGETGRAPHICSRESETSTATUSPROC opengl_core_GetGraphicsResetStatus = NULL;

namespace opengl_core
{
  void gl_functions::configure(const gl_version &ctx_ver)
  {
    // NOTE: glext.h from https://www.opengl.org/registry/api/GL/glext.h
    // intitialy groups functions by versions. Then it groups by extensions.
    // Some extensions are duplicated. Duplicates have the appropiate suffix.
    // e.g. ARB, NV, ..., etc.
    typedef std::function<void()> load_func;
    typedef std::pair<std::pair<int, int>, load_func> ver_to_func;
    std::vector<std::pair<std::pair<int, int>, load_func>> versions =
    {
      std::make_pair<std::pair<int, int>, load_func>({4, 5}, std::bind(
        &opengl_core::gl_functions::load_4_5)),
      std::make_pair<std::pair<int, int>, load_func>({4, 4}, std::bind(
        &opengl_core::gl_functions::load_4_4)),
      std::make_pair<std::pair<int, int>, load_func>({4, 3}, std::bind(
        &opengl_core::gl_functions::load_4_3)),
      std::make_pair<std::pair<int, int>, load_func>({4, 2}, std::bind(
        &opengl_core::gl_functions::load_4_2)),
      std::make_pair<std::pair<int, int>, load_func>({4, 1}, std::bind(
        &opengl_core::gl_functions::load_4_1)),
      std::make_pair<std::pair<int, int>, load_func>({4, 0}, std::bind(
        &opengl_core::gl_functions::load_4_0)),
      std::make_pair<std::pair<int, int>, load_func>({3, 3}, std::bind(
        &opengl_core::gl_functions::load_3_3)),
      std::make_pair<std::pair<int, int>, load_func>({3, 2}, std::bind(
        &opengl_core::gl_functions::load_3_2)),
      std::make_pair<std::pair<int, int>, load_func>({3, 1}, std::bind(
        &opengl_core::gl_functions::load_3_1)),
      std::make_pair<std::pair<int, int>, load_func>({3, 0}, std::bind(
        &opengl_core::gl_functions::load_3_0)),
      std::make_pair<std::pair<int, int>, load_func>({2, 1}, std::bind(
        &opengl_core::gl_functions::load_2_1)),
      std::make_pair<std::pair<int, int>, load_func>({2, 0}, std::bind(
        &opengl_core::gl_functions::load_2_0)),
      std::make_pair<std::pair<int, int>, load_func>({1, 5}, std::bind(
        &opengl_core::gl_functions::load_1_5)),
      std::make_pair<std::pair<int, int>, load_func>({1, 4}, std::bind(
        &opengl_core::gl_functions::load_1_4)),
      std::make_pair<std::pair<int, int>, load_func>({1, 3}, std::bind(
        &opengl_core::gl_functions::load_1_3)),
      std::make_pair<std::pair<int, int>, load_func>({1, 2}, std::bind(
        &opengl_core::gl_functions::load_1_2))
    };


    // Find the closest funtion to the specified version by the client.
    auto it = std::find_if(versions.begin(), versions.end(),
      [&](ver_to_func &p) {
        return (p.first.first <= ctx_ver.major &&
          p.first.second <= ctx_ver.minor);
      });
    if (it == versions.end()) {
      std::cerr << "Failed to provide a valid OpenGL version."
       << std::endl << std::flush;
      throw std::runtime_error("Failed to provide a valid OpenGL version.");
    }
    while (it != versions.end()) {
      it->second();
      ++it;
    }

    // For display purposes only. This does not imply that all functions
    // mapped to the extensions were loaded.
    std::vector<std::string> extensions_vector;

    if (ctx_ver.major >= 3) {
      glGetStringi = (PFNGLGETSTRINGIPROC)glXGetProcAddress(
        (GLubyte *)"glGetStringi");
      assert(glGetStringi && "Could not acquire glGetStringi");

      GLint n = 0;
      glGetIntegerv(GL_NUM_EXTENSIONS, &n); GL_CALL(glGetIntegerv)
      for (GLint i = 0; i < n; ++i) {
        const GLubyte *extension = glGetStringi(GL_EXTENSIONS, i);
          GL_CALL(glGetStringi(GL_EXTENSIONS))
        if (extension) {
          extensions_vector.push_back((const char *)extension);
        } else {
          std::cout << "Failed to load extension." << std::endl;
        }
      }
      std::cout << "Context version greater than or equal to "
        << (std::uint32_t)ctx_ver.major << "."
        << (std::uint32_t)ctx_ver.minor << " provides" << std::endl
        << std::flush;
      std::copy(extensions_vector.begin(), extensions_vector.end(),
        std::ostream_iterator<std::string>(std::cout, " "));
      std::cout << std::endl;
    } else {
      const GLubyte *extensions = glGetString(GL_EXTENSIONS);
        GL_CALL(glGetString(GL_EXTENSIONS))
      if (extensions) {
        std::string std_extensions((const char*)extensions);
        std::cout << "Context version less than "
          << (std::uint32_t)ctx_ver.major
          << "." << (std::uint32_t)ctx_ver.minor << "provides ";
        std::cout << "Context version less than 3.0 provides "
          << std_extensions << std::endl << std::flush;
        std::replace(std_extensions.begin(), std_extensions.end(), ' ',
          '\n');
        std::stringstream ss(std_extensions);
        while (ss.good()) {
          std::string extension;
          std::getline(ss, extension);
          extensions_vector.push_back(extension);
        }
      } else {
        std::cout << "Failed to load extensions string." << std::endl;
      }
    }
  }
}

#define LOAD_GL_FUNCTION(type, name) \
  name = (type)glXGetProcAddress((GLubyte *)#name); \
  if (name == nullptr) { \
    assert(name != nullptr && "Failed to load "#name); \
  }

namespace opengl_core
{
  void gl_functions::load_1_2()
  {
    std::cout << "Loading OpenGL 1.2 Functions " << std::endl;
    LOAD_GL_FUNCTION(PFNGLBLENDCOLORPROC, glBlendColor);
    LOAD_GL_FUNCTION(PFNGLTEXIMAGE3DPROC, glTexImage3D);
    LOAD_GL_FUNCTION(PFNGLBLENDEQUATIONPROC, glBlendEquation);
    LOAD_GL_FUNCTION(PFNGLTEXSUBIMAGE3DPROC, glTexSubImage3D);
    LOAD_GL_FUNCTION(PFNGLDRAWRANGEELEMENTSPROC, glDrawRangeElements);
    LOAD_GL_FUNCTION(PFNGLCOPYTEXSUBIMAGE3DPROC, glCopyTexSubImage3D);
  }

  void gl_functions::load_1_3()
  {
    std::cout << "Loading OpenGL 1.3 Functions " << std::endl;
    LOAD_GL_FUNCTION(PFNGLACTIVETEXTUREPROC, glActiveTexture);
    LOAD_GL_FUNCTION(PFNGLSAMPLECOVERAGEPROC, glSampleCoverage);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD1DPROC, glMultiTexCoord1d);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD1FPROC, glMultiTexCoord1f);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD1IPROC, glMultiTexCoord1i);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD1SPROC, glMultiTexCoord1s);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD2DPROC, glMultiTexCoord2d);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD2FPROC, glMultiTexCoord2f);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD2IPROC, glMultiTexCoord2i);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD2SPROC, glMultiTexCoord2s);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD3DPROC, glMultiTexCoord3d);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD3FPROC, glMultiTexCoord3f);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD3IPROC, glMultiTexCoord3i);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD3SPROC, glMultiTexCoord3s);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD4DPROC, glMultiTexCoord4d);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD4FPROC, glMultiTexCoord4f);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD4IPROC, glMultiTexCoord4i);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD4SPROC, glMultiTexCoord4s);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD1DVPROC, glMultiTexCoord1dv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD1FVPROC, glMultiTexCoord1fv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD1IVPROC, glMultiTexCoord1iv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD1SVPROC, glMultiTexCoord1sv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD2DVPROC, glMultiTexCoord2dv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD2FVPROC, glMultiTexCoord2fv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD2IVPROC, glMultiTexCoord2iv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD2SVPROC, glMultiTexCoord2sv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD3DVPROC, glMultiTexCoord3dv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD3FVPROC, glMultiTexCoord3fv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD3IVPROC, glMultiTexCoord3iv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD3SVPROC, glMultiTexCoord3sv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD4DVPROC, glMultiTexCoord4dv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD4FVPROC, glMultiTexCoord4fv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD4IVPROC, glMultiTexCoord4iv);
    LOAD_GL_FUNCTION(PFNGLMULTITEXCOORD4SVPROC, glMultiTexCoord4sv);
    LOAD_GL_FUNCTION(PFNGLCLIENTACTIVETEXTUREPROC, glClientActiveTexture);
    LOAD_GL_FUNCTION(PFNGLLOADTRANSPOSEMATRIXFPROC, glLoadTransposeMatrixf);
    LOAD_GL_FUNCTION(PFNGLLOADTRANSPOSEMATRIXDPROC, glLoadTransposeMatrixd);
    LOAD_GL_FUNCTION(PFNGLMULTTRANSPOSEMATRIXFPROC, glMultTransposeMatrixf);
    LOAD_GL_FUNCTION(PFNGLMULTTRANSPOSEMATRIXDPROC, glMultTransposeMatrixd);
    LOAD_GL_FUNCTION(PFNGLCOMPRESSEDTEXIMAGE3DPROC, glCompressedTexImage3D);
    LOAD_GL_FUNCTION(PFNGLCOMPRESSEDTEXIMAGE2DPROC, glCompressedTexImage2D);
    LOAD_GL_FUNCTION(PFNGLCOMPRESSEDTEXIMAGE1DPROC, glCompressedTexImage1D);
    LOAD_GL_FUNCTION(PFNGLGETCOMPRESSEDTEXIMAGEPROC,
      glGetCompressedTexImage);
    LOAD_GL_FUNCTION(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC,
      glCompressedTexSubImage3D);
    LOAD_GL_FUNCTION(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC,
      glCompressedTexSubImage2D);
    LOAD_GL_FUNCTION(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC,
      glCompressedTexSubImage1D);
  }

  void gl_functions::load_1_4()
  {
    std::cout << "Loading OpenGL 1.4 Functions " << std::endl;
    LOAD_GL_FUNCTION(PFNGLFOGCOORDFPROC, glFogCoordf);
    LOAD_GL_FUNCTION(PFNGLFOGCOORDDPROC, glFogCoordd);
    LOAD_GL_FUNCTION(PFNGLFOGCOORDFVPROC, glFogCoordfv);
    LOAD_GL_FUNCTION(PFNGLFOGCOORDDVPROC, glFogCoorddv);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS2DPROC, glWindowPos2d);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS2FPROC, glWindowPos2f);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS2IPROC, glWindowPos2i);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS2SPROC, glWindowPos2s);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS3DPROC, glWindowPos3d);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS3FPROC, glWindowPos3f);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS3IPROC, glWindowPos3i);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS3SPROC, glWindowPos3s);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS2DVPROC, glWindowPos2dv);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS2FVPROC, glWindowPos2fv);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS2IVPROC, glWindowPos2iv);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS2SVPROC, glWindowPos2sv);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS3DVPROC, glWindowPos3dv);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS3FVPROC, glWindowPos3fv);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS3IVPROC, glWindowPos3iv);
    LOAD_GL_FUNCTION(PFNGLWINDOWPOS3SVPROC, glWindowPos3sv);
    LOAD_GL_FUNCTION(PFNGLFOGCOORDPOINTERPROC, glFogCoordPointer);
    LOAD_GL_FUNCTION(PFNGLMULTIDRAWARRAYSPROC, glMultiDrawArrays);
    LOAD_GL_FUNCTION(PFNGLPOINTPARAMETERFPROC, glPointParameterf);
    LOAD_GL_FUNCTION(PFNGLPOINTPARAMETERIPROC, glPointParameteri);
    LOAD_GL_FUNCTION(PFNGLPOINTPARAMETERFVPROC, glPointParameterfv);
    LOAD_GL_FUNCTION(PFNGLPOINTPARAMETERIVPROC, glPointParameteriv);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3BPROC, glSecondaryColor3b);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3DPROC, glSecondaryColor3d);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3FPROC, glSecondaryColor3f);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3IPROC, glSecondaryColor3i);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3SPROC, glSecondaryColor3s);
    LOAD_GL_FUNCTION(PFNGLBLENDFUNCSEPARATEPROC, glBlendFuncSeparate);
    LOAD_GL_FUNCTION(PFNGLMULTIDRAWELEMENTSPROC, glMultiDrawElements);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3BVPROC, glSecondaryColor3bv);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3FVPROC, glSecondaryColor3fv);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3IVPROC, glSecondaryColor3iv);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3SVPROC, glSecondaryColor3sv);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3UBPROC, glSecondaryColor3ub);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3UIPROC, glSecondaryColor3ui);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3USPROC, glSecondaryColor3us);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3UBVPROC, glSecondaryColor3ubv);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3UIVPROC, glSecondaryColor3uiv);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLOR3USVPROC, glSecondaryColor3usv);
    LOAD_GL_FUNCTION(PFNGLSECONDARYCOLORPOINTERPROC,
      glSecondaryColorPointer);
  }

  void gl_functions::load_1_5()
  {
    std::cout << "Loading OpenGL 1.5 Functions " << std::endl;
    LOAD_GL_FUNCTION(PFNGLISQUERYPROC, glIsQuery);
    LOAD_GL_FUNCTION(PFNGLENDQUERYPROC, glEndQuery);
    LOAD_GL_FUNCTION(PFNGLISBUFFERPROC, glIsBuffer);
    LOAD_GL_FUNCTION(PFNGLMAPBUFFERPROC, glMapBuffer);
    LOAD_GL_FUNCTION(PFNGLGENQUERIESPROC, glGenQueries);
    LOAD_GL_FUNCTION(PFNGLBEGINQUERYPROC, glBeginQuery);
    LOAD_GL_FUNCTION(PFNGLGETQUERYIVPROC, glGetQueryiv);
    LOAD_GL_FUNCTION(PFNGLBINDBUFFERPROC, glBindBuffer);
    LOAD_GL_FUNCTION(PFNGLGENBUFFERSPROC, glGenBuffers);
    LOAD_GL_FUNCTION(PFNGLBUFFERDATAPROC, glBufferData);
    LOAD_GL_FUNCTION(PFNGLUNMAPBUFFERPROC, glUnmapBuffer);
    LOAD_GL_FUNCTION(PFNGLDELETEQUERIESPROC, glDeleteQueries);
    LOAD_GL_FUNCTION(PFNGLDELETEBUFFERSPROC, glDeleteBuffers);
    LOAD_GL_FUNCTION(PFNGLBUFFERSUBDATAPROC, glBufferSubData);
    LOAD_GL_FUNCTION(PFNGLGETQUERYOBJECTIVPROC, glGetQueryObjectiv);
    LOAD_GL_FUNCTION(PFNGLGETBUFFERSUBDATAPROC, glGetBufferSubData);
    LOAD_GL_FUNCTION(PFNGLGETQUERYOBJECTUIVPROC, glGetQueryObjectuiv);
    LOAD_GL_FUNCTION(PFNGLGETBUFFERPOINTERVPROC, glGetBufferPointerv);
    LOAD_GL_FUNCTION(PFNGLGETBUFFERPARAMETERIVPROC, glGetBufferParameteriv);
  }

  void gl_functions::load_2_0()
  {
    std::cout << "Loading OpenGL 2.0 Functions " << std::endl;
    LOAD_GL_FUNCTION(PFNGLISSHADERPROC, glIsShader);
    LOAD_GL_FUNCTION(PFNGLISPROGRAMPROC, glIsProgram);
    LOAD_GL_FUNCTION(PFNGLUNIFORM1FPROC, glUniform1f);
    LOAD_GL_FUNCTION(PFNGLUNIFORM2FPROC, glUniform2f);
    LOAD_GL_FUNCTION(PFNGLUNIFORM3FPROC, glUniform3f);
    LOAD_GL_FUNCTION(PFNGLUNIFORM4FPROC, glUniform4f);
    LOAD_GL_FUNCTION(PFNGLUNIFORM1IPROC, glUniform1i);
    LOAD_GL_FUNCTION(PFNGLUNIFORM2IPROC, glUniform2i);
    LOAD_GL_FUNCTION(PFNGLUNIFORM3IPROC, glUniform3i);
    LOAD_GL_FUNCTION(PFNGLUNIFORM4IPROC, glUniform4i);
    LOAD_GL_FUNCTION(PFNGLUSEPROGRAMPROC, glUseProgram);
    LOAD_GL_FUNCTION(PFNGLUNIFORM1FVPROC, glUniform1fv);
    LOAD_GL_FUNCTION(PFNGLUNIFORM2FVPROC, glUniform2fv);
    LOAD_GL_FUNCTION(PFNGLUNIFORM3FVPROC, glUniform3fv);
    LOAD_GL_FUNCTION(PFNGLUNIFORM4FVPROC, glUniform4fv);
    LOAD_GL_FUNCTION(PFNGLUNIFORM1IVPROC, glUniform1iv);
    LOAD_GL_FUNCTION(PFNGLUNIFORM2IVPROC, glUniform2iv);
    LOAD_GL_FUNCTION(PFNGLUNIFORM3IVPROC, glUniform3iv);
    LOAD_GL_FUNCTION(PFNGLUNIFORM4IVPROC, glUniform4iv);
    LOAD_GL_FUNCTION(PFNGLDRAWBUFFERSPROC, glDrawBuffers);
    LOAD_GL_FUNCTION(PFNGLGETSHADERIVPROC, glGetShaderiv);
    LOAD_GL_FUNCTION(PFNGLLINKPROGRAMPROC, glLinkProgram);
    LOAD_GL_FUNCTION(PFNGLATTACHSHADERPROC, glAttachShader);
    LOAD_GL_FUNCTION(PFNGLCREATESHADERPROC, glCreateShader);
    LOAD_GL_FUNCTION(PFNGLDELETESHADERPROC, glDeleteShader);
    LOAD_GL_FUNCTION(PFNGLDETACHSHADERPROC, glDetachShader);
    LOAD_GL_FUNCTION(PFNGLGETPROGRAMIVPROC, glGetProgramiv);
    LOAD_GL_FUNCTION(PFNGLGETUNIFORMFVPROC, glGetUniformfv);
    LOAD_GL_FUNCTION(PFNGLGETUNIFORMIVPROC, glGetUniformiv);
    LOAD_GL_FUNCTION(PFNGLSHADERSOURCEPROC, glShaderSource);
    LOAD_GL_FUNCTION(PFNGLCOMPILESHADERPROC, glCompileShader);
    LOAD_GL_FUNCTION(PFNGLCREATEPROGRAMPROC, glCreateProgram);
    LOAD_GL_FUNCTION(PFNGLDELETEPROGRAMPROC, glDeleteProgram);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB1DPROC, glVertexAttrib1d);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB1FPROC, glVertexAttrib1f);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB1SPROC, glVertexAttrib1s);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB2DPROC, glVertexAttrib2d);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB2FPROC, glVertexAttrib2f);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB2SPROC, glVertexAttrib2s);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB3DPROC, glVertexAttrib3d);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB3FPROC, glVertexAttrib3f);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB3SPROC, glVertexAttrib3s);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4DPROC, glVertexAttrib4d);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4FPROC, glVertexAttrib4f);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4SPROC, glVertexAttrib4s);
    LOAD_GL_FUNCTION(PFNGLGETACTIVEATTRIBPROC, glGetActiveAttrib);
    LOAD_GL_FUNCTION(PFNGLGETSHADERSOURCEPROC, glGetShaderSource);
    LOAD_GL_FUNCTION(PFNGLVALIDATEPROGRAMPROC, glValidateProgram);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB1DVPROC, glVertexAttrib1dv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB1FVPROC, glVertexAttrib1fv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB1SVPROC, glVertexAttrib1sv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB2DVPROC, glVertexAttrib2dv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB2FVPROC, glVertexAttrib2fv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB2SVPROC, glVertexAttrib2sv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB3DVPROC, glVertexAttrib3dv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB3FVPROC, glVertexAttrib3fv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB3SVPROC, glVertexAttrib3sv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4BVPROC, glVertexAttrib4bv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4DVPROC, glVertexAttrib4dv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4FVPROC, glVertexAttrib4fv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4IVPROC, glVertexAttrib4iv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4SVPROC, glVertexAttrib4sv);
    LOAD_GL_FUNCTION(PFNGLGETACTIVEUNIFORMPROC, glGetActiveUniform);
    LOAD_GL_FUNCTION(PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog);
    LOAD_GL_FUNCTION(PFNGLUNIFORMMATRIX2FVPROC, glUniformMatrix2fv);
    LOAD_GL_FUNCTION(PFNGLUNIFORMMATRIX3FVPROC, glUniformMatrix3fv);
    LOAD_GL_FUNCTION(PFNGLUNIFORMMATRIX4FVPROC, glUniformMatrix4fv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4NBVPROC, glVertexAttrib4Nbv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4NIVPROC, glVertexAttrib4Niv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4NSVPROC, glVertexAttrib4Nsv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4NUBPROC, glVertexAttrib4Nub);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4UBVPROC, glVertexAttrib4ubv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4UIVPROC, glVertexAttrib4uiv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4USVPROC, glVertexAttrib4usv);
    LOAD_GL_FUNCTION(PFNGLSTENCILOPSEPARATEPROC, glStencilOpSeparate);
    LOAD_GL_FUNCTION(PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation);
    LOAD_GL_FUNCTION(PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog);
    LOAD_GL_FUNCTION(PFNGLGETVERTEXATTRIBDVPROC, glGetVertexAttribdv);
    LOAD_GL_FUNCTION(PFNGLGETVERTEXATTRIBFVPROC, glGetVertexAttribfv);
    LOAD_GL_FUNCTION(PFNGLGETVERTEXATTRIBIVPROC, glGetVertexAttribiv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4NUBVPROC, glVertexAttrib4Nubv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4NUIVPROC, glVertexAttrib4Nuiv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIB4NUSVPROC, glVertexAttrib4Nusv);
    LOAD_GL_FUNCTION(PFNGLBINDATTRIBLOCATIONPROC, glBindAttribLocation);
    LOAD_GL_FUNCTION(PFNGLGETATTACHEDSHADERSPROC, glGetAttachedShaders);
    LOAD_GL_FUNCTION(PFNGLGETUNIFORMLOCATIONPROC, glGetUniformLocation);
    LOAD_GL_FUNCTION(PFNGLSTENCILFUNCSEPARATEPROC, glStencilFuncSeparate);
    LOAD_GL_FUNCTION(PFNGLSTENCILMASKSEPARATEPROC, glStencilMaskSeparate);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer);
    LOAD_GL_FUNCTION(PFNGLBLENDEQUATIONSEPARATEPROC,
      glBlendEquationSeparate);
    LOAD_GL_FUNCTION(PFNGLENABLEVERTEXATTRIBARRAYPROC,
      glEnableVertexAttribArray);
    LOAD_GL_FUNCTION(PFNGLGETVERTEXATTRIBPOINTERVPROC,
      glGetVertexAttribPointerv);
    LOAD_GL_FUNCTION(PFNGLDISABLEVERTEXATTRIBARRAYPROC,
      glDisableVertexAttribArray);
  }

  void gl_functions::load_2_1()
  {
    std::cout << "Loading OpenGL 2.1 Functions " << std::endl;
    LOAD_GL_FUNCTION(PFNGLUNIFORMMATRIX2X3FVPROC, glUniformMatrix2x3fv);
    LOAD_GL_FUNCTION(PFNGLUNIFORMMATRIX3X2FVPROC, glUniformMatrix3x2fv);
    LOAD_GL_FUNCTION(PFNGLUNIFORMMATRIX2X4FVPROC, glUniformMatrix2x4fv);
    LOAD_GL_FUNCTION(PFNGLUNIFORMMATRIX4X2FVPROC, glUniformMatrix4x2fv);
    LOAD_GL_FUNCTION(PFNGLUNIFORMMATRIX3X4FVPROC, glUniformMatrix3x4fv);
    LOAD_GL_FUNCTION(PFNGLUNIFORMMATRIX4X3FVPROC, glUniformMatrix4x3fv);
  }

  void gl_functions::load_3_0()
  {
    std::cout << "Loading OpenGL 3.0 Functions " << std::endl;
    LOAD_GL_FUNCTION(PFNGLENABLEIPROC, glEnablei);
    LOAD_GL_FUNCTION(PFNGLDISABLEIPROC, glDisablei);
    LOAD_GL_FUNCTION(PFNGLCOLORMASKIPROC, glColorMaski);
    LOAD_GL_FUNCTION(PFNGLISENABLEDIPROC, glIsEnabledi);
    LOAD_GL_FUNCTION(PFNGLCLAMPCOLORPROC, glClampColor);
    LOAD_GL_FUNCTION(PFNGLUNIFORM1UIPROC, glUniform1ui);
    LOAD_GL_FUNCTION(PFNGLUNIFORM2UIPROC, glUniform2ui);
    LOAD_GL_FUNCTION(PFNGLUNIFORM3UIPROC, glUniform3ui);
    LOAD_GL_FUNCTION(PFNGLUNIFORM4UIPROC, glUniform4ui);
    LOAD_GL_FUNCTION(PFNGLUNIFORM1UIVPROC, glUniform1uiv);
    LOAD_GL_FUNCTION(PFNGLUNIFORM2UIVPROC, glUniform2uiv);
    LOAD_GL_FUNCTION(PFNGLUNIFORM3UIVPROC, glUniform3uiv);
    LOAD_GL_FUNCTION(PFNGLUNIFORM4UIVPROC, glUniform4uiv);
    LOAD_GL_FUNCTION(PFNGLGETBOOLEANI_VPROC, glGetBooleani_v);
    LOAD_GL_FUNCTION(PFNGLGETUNIFORMUIVPROC, glGetUniformuiv);
    LOAD_GL_FUNCTION(PFNGLCLEARBUFFERIVPROC, glClearBufferiv);
    LOAD_GL_FUNCTION(PFNGLCLEARBUFFERFVPROC, glClearBufferfv);
    LOAD_GL_FUNCTION(PFNGLCLEARBUFFERFIPROC, glClearBufferfi);
    LOAD_GL_FUNCTION(PFNGLCLEARBUFFERUIVPROC, glClearBufferuiv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI1IPROC, glVertexAttribI1i);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI2IPROC, glVertexAttribI2i);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI3IPROC, glVertexAttribI3i);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI4IPROC, glVertexAttribI4i);
    LOAD_GL_FUNCTION(PFNGLTEXPARAMETERIIVPROC, glTexParameterIiv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI1UIPROC, glVertexAttribI1ui);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI2UIPROC, glVertexAttribI2ui);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI3UIPROC, glVertexAttribI3ui);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI4UIPROC, glVertexAttribI4ui);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI1IVPROC, glVertexAttribI1iv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI2IVPROC, glVertexAttribI2iv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI3IVPROC, glVertexAttribI3iv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI4IVPROC, glVertexAttribI4iv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI4BVPROC, glVertexAttribI4bv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI4SVPROC, glVertexAttribI4sv);
    LOAD_GL_FUNCTION(PFNGLTEXPARAMETERIUIVPROC, glTexParameterIuiv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI1UIVPROC, glVertexAttribI1uiv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI2UIVPROC, glVertexAttribI2uiv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI3UIVPROC, glVertexAttribI3uiv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI4UIVPROC, glVertexAttribI4uiv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI4UBVPROC, glVertexAttribI4ubv);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBI4USVPROC, glVertexAttribI4usv);
    LOAD_GL_FUNCTION(PFNGLGETVERTEXATTRIBIIVPROC, glGetVertexAttribIiv);
    LOAD_GL_FUNCTION(PFNGLGETTEXPARAMETERIIVPROC, glGetTexParameterIiv);
    LOAD_GL_FUNCTION(PFNGLGETVERTEXATTRIBIUIVPROC, glGetVertexAttribIuiv);
    LOAD_GL_FUNCTION(PFNGLGETFRAGDATALOCATIONPROC, glGetFragDataLocation);
    LOAD_GL_FUNCTION(PFNGLGETTEXPARAMETERIUIVPROC, glGetTexParameterIuiv);
    LOAD_GL_FUNCTION(PFNGLENDTRANSFORMFEEDBACKPROC, glEndTransformFeedback);
    LOAD_GL_FUNCTION(PFNGLENDCONDITIONALRENDERPROC, glEndConditionalRender);
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBIPOINTERPROC, glVertexAttribIPointer);
    LOAD_GL_FUNCTION(PFNGLBINDFRAGDATALOCATIONPROC, glBindFragDataLocation);
    LOAD_GL_FUNCTION(PFNGLBEGINTRANSFORMFEEDBACKPROC,
      glBeginTransformFeedback);
    LOAD_GL_FUNCTION(PFNGLBEGINCONDITIONALRENDERPROC,
      glBeginConditionalRender);
    LOAD_GL_FUNCTION(PFNGLTRANSFORMFEEDBACKVARYINGSPROC,
      glTransformFeedbackVaryings);
    LOAD_GL_FUNCTION(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC,
      glGetTransformFeedbackVarying);
  }

  void gl_functions::load_3_1()
  {
    LOAD_GL_FUNCTION(PFNGLDRAWARRAYSINSTANCEDPROC,
      glDrawArraysInstanced);
    LOAD_GL_FUNCTION(PFNGLDRAWELEMENTSINSTANCEDPROC,
      glDrawElementsInstanced);
    LOAD_GL_FUNCTION(PFNGLPRIMITIVERESTARTINDEXPROC,
      glPrimitiveRestartIndex);
    LOAD_GL_FUNCTION(PFNGLTEXBUFFERPROC, glTexBuffer);
  }

  void gl_functions::load_3_2()
  {
    LOAD_GL_FUNCTION(PFNGLFRAMEBUFFERTEXTUREPROC,
      glFramebufferTexture);
    LOAD_GL_FUNCTION(PFNGLGETBUFFERPARAMETERI64VPROC,
      glGetBufferParameteri64v);
    LOAD_GL_FUNCTION(PFNGLGETINTEGER64I_VPROC,
      glGetInteger64i_v);
    LOAD_GL_FUNCTION(PFNGLGENVERTEXARRAYSPROC,
      glGenVertexArrays);
    LOAD_GL_FUNCTION(PFNGLBINDVERTEXARRAYPROC,
      glBindVertexArray);
  }

  void gl_functions::load_3_3()
  {
    LOAD_GL_FUNCTION(PFNGLVERTEXATTRIBDIVISORPROC,
      glVertexAttribDivisor);
  }

  void gl_functions::load_4_0()
  {
    LOAD_GL_FUNCTION(PFNGLBLENDEQUATIONSEPARATEIPROC,
      glBlendEquationSeparatei);
    LOAD_GL_FUNCTION(PFNGLBLENDEQUATIONIPROC,
      glBlendEquationi);
    LOAD_GL_FUNCTION(PFNGLBLENDFUNCSEPARATEIPROC,
      glBlendFuncSeparatei);
    LOAD_GL_FUNCTION(PFNGLBLENDFUNCIPROC,
      glBlendFunci);
    LOAD_GL_FUNCTION(PFNGLMINSAMPLESHADINGPROC,
      glMinSampleShading);
  }

  void gl_functions::load_4_1()
  {
  }

  void gl_functions::load_4_2()
  {
  }

  void gl_functions::load_4_3()
  {
  }

  void gl_functions::load_4_4()
  {
  }

  void gl_functions::load_4_5()
  {
    LOAD_GL_FUNCTION(PFNGLGETGRAPHICSRESETSTATUSPROC,
      glGetGraphicsResetStatus);
  }
}
