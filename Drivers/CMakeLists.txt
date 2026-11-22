cmake_minimum_required(VERSION 3.20)
project(ReactOSMobileDrivers C CXX RC)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ReactOSMobileSdk/cmake/ReactOSMobileSdk.cmake)

# Interfaces the drivers share, ahead of the SDK so they win
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Qualcomm SoC support every board uses
add_subdirectory(qcom/gen/dbg)
add_subdirectory(qcom/gen/pnp)
add_subdirectory(qcom/gen/geni)
add_subdirectory(qcom/gen/tlmm)

# OnePlus 6 parts the audio stack imports from
add_subdirectory(oneplus6/amp)

# SDM845
add_subdirectory(qcom/sdm845/apr)
add_subdirectory(qcom/sdm845/q6)
add_subdirectory(qcom/sdm845/audio)
add_subdirectory(qcom/sdm845/pwrkey)
add_subdirectory(qcom/sdm845/panel)
add_subdirectory(qcom/sdm845/sfr)

# Cellular: the IPA data adapter and the RIL
add_subdirectory(qcom/rmnet)
add_subdirectory(qcom/qcril)

# The rest of the OnePlus 6 board
add_subdirectory(oneplus6)

# Pixel 4 board drivers
add_subdirectory(pixel4)

# Registration of the Windows SDM850 drivers, last so the local overrides win
add_subdirectory(qcom/sdm845/windows)
