{
  "includes" : [
    # "linux.gypi",
    "platform/mac/binding.gypi",
    "platform/win/binding.gypi",
  ],

  "include_dirs": [
    ".",
    "types"
  ],

  "sources" : [
    "OculusRiftDevice.cc",
    "types/OvrFovPort.cc",
    "types/OvrSizei.cc",
    "types/OvrVector2i.cc",
  ],
}
