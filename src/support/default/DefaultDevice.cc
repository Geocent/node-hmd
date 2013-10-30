/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#include <iostream>
#include <string>

#include "DefaultDevice.h"

const std::string DefaultDevice::displayDeviceName = "node-hmd mock device";
const std::string DefaultDevice::deviceName = "Default Device";
const std::string DefaultDevice::deviceManufacturer = "Geocent LLC";

void DefaultDevice::getDeviceInfo(HMDDeviceInfo* deviceInfo) {
	deviceInfo->hResolution = 800;
	deviceInfo->vResolution = 600;
	deviceInfo->vScreenCenter = 300;
	deviceInfo->eyetoScreenDistance = 0.01;
	deviceInfo->lensSeparationDistance = 0.02;
	deviceInfo->interpuillaryDistance = 0.025;
	deviceInfo->distortionK[0] = 1.1;
	deviceInfo->distortionK[1] = 2.2;
	deviceInfo->distortionK[2] = 3.3;
	deviceInfo->distortionK[3] = 4.4;
	deviceInfo->desktopX = 1920;
	deviceInfo->desktopY = 1080;
	displayDeviceName.copy(deviceInfo->displayDeviceName, MAX_DESCRIPTION_LENGTH);
	deviceInfo->displayId = 1234567890;
	deviceName.copy(deviceInfo->productName, MAX_DESCRIPTION_LENGTH);
	deviceManufacturer.copy(deviceInfo->manufacturer, MAX_DESCRIPTION_LENGTH);
	deviceInfo->version = 5;
}