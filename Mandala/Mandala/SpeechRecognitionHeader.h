#pragma once


namespace SDKTemplate {
	ref class AudioCapturePermissions sealed
	{
	public:
		static Windows::Foundation::IAsyncOperation<bool>^ RequestMicrophonePermissionAsync();

	private:
		// If no recording device is attached, attempting to get access to audio capture devices will throw 
		// a System.Exception object, with this HResult set.
		static const int NoCaptureDevicesHResult = -1072845856;
	};
}