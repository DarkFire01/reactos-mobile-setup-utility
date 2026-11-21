# Registry the SDM850 Windows drivers need on this board beside their own INFs, which
# sdm845-Package installs with rmsetup /Add-Driver
add_registry_inf(qcom850_tweaks_reg.inf)
add_registry_inf(trustedrt_reg.inf)
add_registry_inf(qcxhcifilter_reg.inf)
add_registry_inf(qcwlan_reg.inf)
add_registry_inf(qcmcfg_reg.inf)
add_registry_inf(basicdisplay_reg.inf)

# Local overrides of the files above, last so their values win
add_registry_inf(qcom850_override_reg.inf)
