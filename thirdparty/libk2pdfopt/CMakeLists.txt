PROJECT(libk2pdfopt)
cmake_minimum_required(VERSION 2.8.3)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/../cmake_modules")
include("koreader_thirdparty_common")
include("koreader_thirdparty_asm")
include("koreader_thirdparty_git")

enable_language(C CXX ASM)

assert_var_defined(CC)
assert_var_defined(CFLAGS)
assert_var_defined(CXX)
assert_var_defined(CXXFLAGS)
assert_var_defined(AR)
assert_var_defined(LDFLAGS)
assert_var_defined(ZLIB)
assert_var_defined(ZLIB_DIR)
assert_var_defined(PNG_DIR)
assert_var_defined(LEPTONICA_DIR)
assert_var_defined(TESSERACT_DIR)
assert_var_defined(STDCPPLIB)

ep_get_source_dir(SOURCE_DIR)

set(BUILD_CMD "$(MAKE) -j${PARALLEL_JOBS} BUILDMODE=shared HOST=${HOST} CC=\"${CC}\" CFLAGS=\"${CFLAGS} -O3\"")
set(BUILD_CMD "${BUILD_CMD} CXX=\"${CXX}\" CXXFLAGS=\"${CXXFLAGS}\" AR=\"${AR}\" RANLIB=\"${RANLIB}\" ZLIB=${ZLIB}")
set(BUILD_CMD "${BUILD_CMD} TESSERACT_DIR=${TESSERACT_DIR} LEPTONICA_DIR=${LEPTONICA_DIR}")
set(BUILD_CMD "${BUILD_CMD} LEPT_CFLAGS=\"${CFLAGS} -I${ZLIB_DIR} -I${PNG_DIR}/include\"")
set(BUILD_CMD "${BUILD_CMD} LEPT_LDFLAGS=\"${LDFLAGS} -L${ZLIB_DIR} -L${PNG_DIR}/lib\"")
if ($ENV{DARWIN})
    set(BUILD_CMD "${BUILD_CMD} STDCPPLIB=\"${STDCPPLIB}\" ZLIB_LDFLAGS=\"-L${ZLIB_DIR}\"")
    set(BUILD_CMD sh -c "${BUILD_CMD} PNG_LDFLAGS=\"-L${PNG_DIR}/lib\" all")
else()
    set(BUILD_CMD "${BUILD_CMD} STDCPPLIB=\"${STDCPPLIB}\" ZLIB_LDFLAGS=\"-Wl,-rpath-link,${ZLIB_DIR}\"")
    set(BUILD_CMD sh -c "${BUILD_CMD} PNG_LDFLAGS=\"-Wl,-rpath-link,${PNG_DIR}/lib\" all")
endif()

ko_write_gitclone_script(
    GIT_CLONE_SCRIPT_FILENAME
    git://github.com/koreader/libk2pdfopt.git
    9aec09f52bf72bd7b747172c446d462c8b88f6b4
    ${SOURCE_DIR}
)

include(ExternalProject)
ExternalProject_Add(
    ${PROJECT_NAME}
    DOWNLOAD_COMMAND ${CMAKE_COMMAND} -P ${GIT_CLONE_SCRIPT_FILENAME}
    BUILD_IN_SOURCE 1
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ${BUILD_CMD}
    # skip install
    INSTALL_COMMAND ""
)
