/* Copyright 2008-2009 Uppsala University
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ResourceMonitorLinux.h"

#include <libcpphaggle/Watch.h>
#include <haggleutils.h>

ResourceMonitorLinux::ResourceMonitorLinux(ResourceManager *m) : 
	ResourceMonitor(m, "ResourceMonitorLinux")
{
}

ResourceMonitorLinux::~ResourceMonitorLinux()
{
}

long ResourceMonitorLinux::getBatteryPercent() const 
{
	// Unknown: return 100%
    return 100;
}

unsigned int ResourceMonitorLinux::getBatteryLifeTime() const
{
	// Unknown: return 1 hour
    return 1*60*60;
}

unsigned long ResourceMonitorLinux::getAvaliablePhysicalMemory() const 
{
	// Unknown: return 1 GB
    return 1*1024*1024*1024;
}

unsigned long ResourceMonitorLinux::getAvaliableVirtualMemory() const 
{
	// Unknown: return 1 GB
    return 1*1024*1024*1024;
}

bool ResourceMonitorLinux::run()
{
	Watch w;

	HAGGLE_DBG("Running resource monitor\n");

	while (!shouldExit()) {
		int ret;

		w.reset();

		ret = w.wait();

		if (ret < 0) {
			HAGGLE_ERR("Wait on objects failed\n");
			break;
		}
	}
	return false;
}

void ResourceMonitorLinux::cleanup()
{
}
