/************************************************************************************

PublicHeader:   OVR.h
Filename    :   OVR_DeviceHandle.h
Content     :   Handle to a device that was enumerated
Created     :   February 5, 2013
Authors     :   Lee Cooper

Copyright   :   Copyright 2014 Oculus VR, Inc. All Rights reserved.

Licensed under the Oculus VR Rift SDK License Version 3.1 (the "License"); 
you may not use the Oculus VR Rift SDK except in compliance with the License, 
which is provided at the time of installation or download, or which 
otherwise accompanies this software in either electronic or hard copy form.

You may obtain a copy of the License at

http://www.oculusvr.com/licenses/LICENSE-3.1 

Unless required by applicable law or agreed to in writing, the Oculus VR SDK 
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*************************************************************************************/

#ifndef OVR_DeviceHandle_h
#define OVR_DeviceHandle_h

#include "OVR_DeviceConstants.h"

namespace OVR {

class DeviceBase;
class DeviceInfo;

// Internal
class DeviceCreateDesc;
class DeviceEnumerationArgs;


//-------------------------------------------------------------------------------------
// ***** DeviceHandle

// DeviceHandle references a specific device that was enumerated; it can be assigned
// directly from DeviceEnumerator.
//
// Devices represented by DeviceHandle are not necessarily created or available.
// A device may become unavailable if, for example, it its unplugged. If the device
// is available, it can be created by calling CreateDevice.
//

class DeviceHandle
{    
	friend class DeviceManager;
	friend class DeviceManagerImpl;
    template<class B> friend class HIDDeviceImpl;

public:
	DeviceHandle() : pImpl(0) { }    
	DeviceHandle(const DeviceHandle& src);
	~DeviceHandle();

	void operator = (const DeviceHandle& src);

	bool operator == (const DeviceHandle& other) const { return pImpl == other.pImpl; }
	bool operator != (const DeviceHandle& other) const { return pImpl != other.pImpl; }

	// operator bool() returns true if Handle/Enumerator points to a valid device.
	operator bool () const   { return GetType() != Device_None; }

    // Returns existing device, or NULL if !IsCreated. The returned ptr is 
    // addref-ed.
    DeviceBase* GetDevice_AddRef() const;
	DeviceType  GetType() const;
	bool        GetDeviceInfo(DeviceInfo* info) const;
	bool        IsAvailable() const;
	bool        IsCreated() const;
    // Returns true, if the handle contains the same device ptr
    // as specified in the parameter.
    bool        IsDevice(DeviceBase*) const;

	// Creates a device, or returns AddRefed pointer if one is already created.
	// New devices start out with RefCount of 1.
	DeviceBase* CreateDevice();

    // Creates a device, or returns AddRefed pointer if one is already created.
    // New devices start out with RefCount of 1. DeviceT is used to cast the
    // DeviceBase* to a concreete type.
    template <class DeviceT>
    DeviceT* CreateDeviceTyped() const
    {
        return static_cast<DeviceT*>(DeviceHandle(*this).CreateDevice());
    }

	// Resets the device handle to uninitialized state.
	void        Clear();

protected:
	explicit DeviceHandle(DeviceCreateDesc* impl);
	bool     enumerateNext(const DeviceEnumerationArgs& args);
	DeviceCreateDesc* pImpl;
};

} // namespace OVR

#endif