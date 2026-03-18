SUMMARY = "Automation Controller"
LICENSE = "MIT"

LIC_FILES_CHKSUM = "file://MIT;md5=8d6b076cb8b417bbea13bc5930665379"

inherit cmake systemd

DEPENDS = "systemd pkgconfig-native"

SRC_URI = "file://automation_controller.cpp \
           file://CMakeLists.txt \
           file://automation.service \
           file://MIT"

S = "${WORKDIR}"

SYSTEMD_SERVICE:${PN} = "automation.service"
SYSTEMD_AUTO_ENABLE = "enable"

EXTRA_OECMAKE += "-DSYSTEMD_UNITDIR=${systemd_system_unitdir}"
