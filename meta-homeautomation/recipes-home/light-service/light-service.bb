SUMMARY = "Light Service"
LICENSE = "MIT"

LIC_FILES_CHKSUM = "file://MIT;md5=8d6b076cb8b417bbea13bc5930665379"

inherit cmake systemd

DEPENDS = "systemd pkgconfig-native"

SRC_URI = "file://light_service.cpp \
           file://CMakeLists.txt \
           file://light.service \
           file://MIT"

S = "${WORKDIR}"

SYSTEMD_SERVICE:${PN} = "light.service"
SYSTEMD_AUTO_ENABLE = "enable"

EXTRA_OECMAKE += "-DSYSTEMD_UNITDIR=${systemd_system_unitdir}"
