set(MipMapSDK_PATH "/path/to/mipmap" CACHE PATH "")
set(MipMap_INCLUDE_DIR ${MipMapSDK_PATH}/include)
message("mipmap include dir: " ${MipMap_INCLUDE_DIR})
if (${platform} STREQUAL "windows")
  set(MipMap_LIBRARIES 
    ${MipMapSDK_PATH}/lib/mipmap_engine.lib
    shlwapi.lib)
elseif (${platform} STREQUAL "ubuntu")
  set(MipMap_LIBRARIES ${MipMapSDK_PATH}/lib/*.a)
endif()
message("mipmap libs: " ${MipMap_LIBRARIES})
Set(MipMapSDK_FOUND TRUE)