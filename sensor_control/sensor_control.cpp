#include <android-base/properties.h>
//#include <devtitans/sysprop/SensorProperties.sysprop.h>
#include <iostream>
#include <cstring>

using namespace std;
using namespace android::base;
//using namespace android::sysprop;

int main (int argc, char **argv) {
	cout << "Control client" << endl;
		bool enabled = GetBoolProperty("persist.vendor.config.sensors_enabled", true);
	if (argc == 2 and !strcmp(argv[1], "status")) {
		//bool enabled = SensorProperties::smartlamp_enabled().value_or(false);
		if (enabled) cout << "Sensors on";
		else cout << "Sensors off";
		cout << endl;
	}
	else if (argc == 2 and !strcmp(argv[1], "toggle")) {
		//bool enabled = SensorProperties::smartlamp_enabled().value_or(false);
		if (enabled) {
			bool smartlamp_enabled = GetBoolProperty("vendor.devtitans.smartlamp.enabled", true);
			bool camera_disable = GetBoolProperty("config.disable_cameraservice", false);
			SetProperty("persist.vendor.config.sensors_enabled", "false");
			SetProperty("vendor.devtitans.smartlamp.enabled", "false");
			SetProperty("vendor.devtitans.smartlamp.previous_enabled", smartlamp_enabled ? "true" : "false");
			SetProperty("config.disable_cameraservice", "true");
			SetProperty("vendor.config.previous_disable_cameraservice", camera_disable ? "true" : "false");
			cout << "Sensors off";
		}
		else {
			bool smartlamp_enabled = GetBoolProperty("vendor.devtitans.smartlamp.previous_enabled", true);
			bool camera_disable = GetBoolProperty("vendor.config.previous_disable_cameraservice", false);
			SetProperty("persist.vendor.config.sensors_enabled", "true");
			SetProperty("vendor.devtitans.smartlamp.enabled", smartlamp_enabled ? "true" : "false");
			SetProperty("config.disable_cameraservice", camera_disable ? "true" : "false");
			cout << "Sensors on";
		}
		cout << endl;
	}
	else cout << "Invalid arguments" << endl;

	return 0;
}
