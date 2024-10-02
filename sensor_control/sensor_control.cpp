#include <android-base/properties.h>
//#include <devtitans/sysprop/SensorProperties.sysprop.h>
#include <iostream>
#include <cstring>

using namespace std;
using namespace android::base;
//using namespace android::sysprop;

int main (int argc, char **argv) {
	cout << "Control client" << endl;
	if (argc == 2 and !strcmp(argv[1], "status")) {
		bool enabled = GetBoolProperty("vendor.devtitans.smartlamp.enabled", false);
		//bool enabled = SensorProperties::smartlamp_enabled().value_or(false);
		if (enabled) cout << "Sensors on";
		else cout << "Sensors off";
		cout << endl;
	}
	else if (argc == 2 and !strcmp(argv[1], "toggle")) {
		bool enabled = GetBoolProperty("vendor.devtitans.smartlamp.enabled", false);
		//bool enabled = SensorProperties::smartlamp_enabled().value_or(false);
		if (enabled) {
			SetProperty("vendor.devtitans.smartlamp.enabled", "false");
			cout << "Sensors off";
		}
		else {
			SetProperty("vendor.devtitans.smartlamp.enabled", "true");
			cout << "Sensors on";
		}
		cout << endl;
	}
	else cout << "Invalid arguments" << endl;

	return 0;
}
