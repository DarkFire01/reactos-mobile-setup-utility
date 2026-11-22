
list(APPEND SOURCE
    ftm5.c
    ftm5touch.c
    hid.c
    spb.c
    ftm5touch.h)

add_library(ftm5touch MODULE ${SOURCE} ftm5touch.rc)
set_module_type(ftm5touch kmdfdriver)

target_compile_definitions(ftm5touch PRIVATE
    _WIN32_WINNT=0x603 NTDDI_VERSION=0x06030000)

target_link_libraries(ftm5touch ntoskrnl_vista libcntpr ${PSEH_LIB})
add_importlibs(ftm5touch wdfldr ntoskrnl hal)
add_cd_file(TARGET ftm5touch DESTINATION reactos/system32/drivers NO_CAB FOR all)
add_driver_inf(ftm5touch ftm5touch.inf)
add_registry_inf(ftm5touch_reg.inf)
