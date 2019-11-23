/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <android-base/logging.h>
#include <cstdlib>
#include <fstream>
#include <string>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "property_service.h"
#include "vendor_init.h"

#include "init_msm8909.h"

using android::init::property_set;
using namespace std;

const char *APP_INFO = "/proc/app_info";

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_dual(char const system_prop[], char const vendor_prop[], char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void set_model(const char *model) {
    property_override("ro.build.product", model);
    property_override_dual("ro.product.device", "ro.vendor.product.device", model);
    property_override_dual("ro.product.model", "ro.vendor.product.model", model);
}

void init_target_properties()
{
    ifstream fin;
    string buf;

    fin.open(APP_INFO, ios::in);
    if (!fin) {
        LOG(ERROR) << __func__ << ": Failed to open " << APP_INFO;
        return;
    }

    while (getline(fin, buf))
        if (buf.find("huawei_fac_product_name") != string::npos)
            break;
    fin.close();

    /* SCL-AL00 */
    if (buf.find("SCL-AL00") != string::npos) {
        set_model("SCL-AL00");
        property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.telephony.ril.config", "simactivation");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("ro.multi.rild", "true");
        property_set("ro.config.hw_showSimName", "true");
        property_set("ro.dual.sim.phone", "true");
        property_override("ro.build.description", "SCL-AL00-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-AL00/hwSCL-Q:5.1.1/HuaweiSCL-AL00/C432B150:user/release-keys");
    }
    /* SCL-CL00 */
    else if (buf.find("SCL-CL00") != string::npos) {
        set_model("SCL-CL00");
        property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.telephony.ril.config", "simactivation");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("ro.multi.rild", "true");
        property_set("ro.config.hw_showSimName", "true");
        property_set("ro.dual.sim.phone", "true");
        property_override("ro.build.description", "SCL-CL00-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-CL00/hwSCL-Q:5.1.1/HuaweiSCL-CL00/C432B150:user/release-keys");
    }
    /* SCL-L01 */
    else if (buf.find("SCL-L01") != string::npos) {
        set_model("SCL-L01");
        property_override("ro.build.description", "SCL-L01-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-L01/hwSCL-Q:5.1.1/HuaweiSCL-L01/C432B150:user/release-keys");
    }
    /* SCL-L02 */
    else if (buf.find("SCL-L02") != string::npos) {
        set_model("SCL-L02");
        property_override("ro.build.description", "SCL-L02-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-L02/hwSCL-Q:5.1.1/HuaweiSCL-L02/C432B150:user/release-keys");
    }
    /* SCL-L03 */
    else if (buf.find("SCL-L03") != string::npos) {
        set_model("SCL-L03");
        property_override("ro.build.description", "SCL-L03-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-L03/hwSCL-Q:5.1.1/HuaweiSCL-L03/C432B150:user/release-keys");
    }
    /* SCL-L04 */
    else if (buf.find("SCL-L04") != string::npos) {
        set_model("SCL-L04");
        property_override("ro.build.description", "SCL-L04-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-L04/hwSCL-Q:5.1.1/HuaweiSCL-L04/C432B150:user/release-keys");
    }
    /* SCL-L21 */
    else if (buf.find("SCL-L21") != string::npos) {
        set_model("SCL-L21");
        property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.telephony.ril.config", "simactivation");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("ro.multi.rild", "true");
        property_set("ro.config.hw_showSimName", "true");
        property_set("ro.dual.sim.phone", "true");
        property_override("ro.build.description", "SCL-L21-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-L21/hwSCL-Q:5.1.1/HuaweiSCL-L21/C432B150:user/release-keys");
    }
    /* SCL-TL00 */
    else if (buf.find("SCL-TL00") != string::npos) {
        set_model("SCL-TL00");
        property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.telephony.ril.config", "simactivation");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("ro.multi.rild", "true");
        property_set("ro.config.hw_showSimName", "true");
        property_set("ro.dual.sim.phone", "true");
        property_override("ro.build.description", "SCL-TL00-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-TL00/hwSCL-Q:5.1.1/HuaweiSCL-TL00/C432B150:user/release-keys");
    }
    /* SCL-TL10 */
    else if (buf.find("SCL-TL10") != string::npos) {
        set_model("SCL-TL10");
        property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.telephony.ril.config", "simactivation");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("ro.multi.rild", "true");
        property_set("ro.config.hw_showSimName", "true");
        property_set("ro.dual.sim.phone", "true");
        property_override("ro.build.description", "SCL-TL10-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-TL10/hwSCL-Q:5.1.1/HuaweiSCL-TL10/C432B150:user/release-keys");
    }
    /* SCL-U03 */
    else if (buf.find("SCL-U03") != string::npos) {
        set_model("SCL-U03");
        property_override("ro.build.description", "SCL-U03-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-U03/hwSCL-Q:5.1.1/HuaweiSCL-U03/C432B150:user/release-keys");
    }
    /* SCL-U21 */
    else if (buf.find("SCL-U21") != string::npos) {
        set_model("SCL-U21");
        property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.telephony.ril.config", "simactivation");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("ro.multi.rild", "true");
        property_set("ro.config.hw_showSimName", "true");
        property_set("ro.dual.sim.phone", "true");
        property_override("ro.build.description", "SCL-U21-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-U21/hwSCL-Q:5.1.1/HuaweiSCL-U21/C432B150:user/release-keys");
    }
    /* SCL-U23 */
    else if (buf.find("SCL-L21") != string::npos) {
        set_model("SCL-L21");
        property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.telephony.ril.config", "simactivation");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("ro.multi.rild", "true");
        property_set("ro.config.hw_showSimName", "true");
        property_set("ro.dual.sim.phone", "true");
        property_override("ro.build.description", "SCL-U23-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-U23/hwSCL-Q:5.1.1/HuaweiSCL-U23/C432B150:user/release-keys");
    }
    /* SCL-U31 */
    else if (buf.find("SCL-U31") != string::npos) {
        set_model("SCL-U31");
        property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.telephony.ril.config", "simactivation");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("ro.multi.rild", "true");
        property_set("ro.config.hw_showSimName", "true");
        property_set("ro.dual.sim.phone", "true");
        property_override("ro.build.description", "SCL-U31-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCL-U31/hwSCL-Q:5.1.1/HuaweiSCL-U31/C432B150:user/release-keys");
    }
    /* SCC-U21 */
    else if (buf.find("SCC-U21") != string::npos) {
        set_model("SCC-U21");
        property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ro.telephony.ril.config", "simactivation");
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("ro.multi.rild", "true");
        property_set("ro.config.hw_showSimName", "true");
        property_set("ro.dual.sim.phone", "true");
        property_override("ro.build.description", "SCC-U21-user 5.1.1 GRJ90 C432B150 release-keys");
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint",
                               "Huawei/SCC-U21/hwSCL-Q:5.1.1/HuaweiSCC-U21/C432B150:user/release-keys");
    }
    else {
        LOG(ERROR) << __func__ << ": unexcepted huawei_fac_product_name!";
    }
}
