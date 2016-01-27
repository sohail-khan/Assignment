if(${ANDROID})
set(headers ${headers} platform/Android/KtxTextures
)
set(currsources
  platform/Android/KtxTextures/checkheader.c
  platform/Android/KtxTextures/CMakeLists.txt
  platform/Android/KtxTextures/etcdec.cxx
  platform/Android/KtxTextures/etcunpack.c
  platform/Android/KtxTextures/gl_funcptrs.h
  platform/Android/KtxTextures/gles1_funcptrs.h
  platform/Android/KtxTextures/gles2_funcptrs.h
  platform/Android/KtxTextures/hashtable.c
  platform/Android/KtxTextures/ktx.h
  platform/Android/KtxTextures/ktxint.h
  platform/Android/KtxTextures/loader.c
  platform/Android/KtxTextures/swap.c
  platform/Android/KtxTextures/uthash.h
  platform/Android/KtxTextures/writer.c
)
set(sources ${sources} ${currsources})
source_group(\\Android\\KtxTextures FILES ${currsources})
endif(${ANDROID})
