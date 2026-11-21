# OnePlus 6 (enchilada) on the SDM845, the amp is added earlier for the audio stack
add_subdirectory(touch)

# Devices bound to these drivers and the modem's RIL
add_registry_inf(oneplus6_board_reg.inf)

# Battery manager profile for the OnePlus 6 cell, over the SDM850 MTP tables in the DSDT
add_registry_inf(qcbattery_reg.inf)

# Quaternary MI2S lines and the AFE ports a voice call uses, read by qcomq6
add_registry_inf(qcomq6_board_reg.inf)

# T-Mobile modem configuration the OnePlus 6 PDC asks for on network 310240, qcmcfg_reg.inf maps it
add_cd_file(FILE firmware/OP6TMO.mbn DESTINATION reactos/system32/drivers/MCFG NO_CAB FOR all)
