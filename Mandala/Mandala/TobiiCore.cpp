/*
 * This is an example that demonstrates how to connect to the EyeX Engine and subscribe to the lightly filtered gaze data stream.
 *
 * Copyright 2013-2014 Tobii Technology AB. All rights reserved.
 */

#include "TobiiCore.h"

glm::vec2 gaze;

glm::vec2 getGaze() {
	return gaze;
}

/*
 * Initializes g_hGlobalInteractorSnapshot with an interactor that has the Gaze Point behavior.
 */
BOOL InitializeGlobalInteractorSnapshot(TX_CONTEXTHANDLE hContext)
{
	TX_HANDLE hInteractor = TX_EMPTY_HANDLE;
	TX_GAZEPOINTDATAPARAMS params = { TX_GAZEPOINTDATAMODE_LIGHTLYFILTERED };
	BOOL success;

	success = txCreateGlobalInteractorSnapshot(
		hContext,
		InteractorId,
		&g_hGlobalInteractorSnapshot,
		&hInteractor) == TX_RESULT_OK;
	success &= txCreateGazePointDataBehavior(hInteractor, &params) == TX_RESULT_OK;

	txReleaseObject(&hInteractor);

	return success;
}

/*
 * Callback function invoked when a snapshot has been committed.
 */
void TX_CALLCONVENTION OnSnapshotCommitted(TX_CONSTHANDLE hAsyncData, TX_USERPARAM param)
{
	// check the result code using an assertion.
	// this will catch validation errors and runtime errors in debug builds. in release builds it won't do anything.

	TX_RESULT result = TX_RESULT_UNKNOWN;
	txGetAsyncDataResultCode(hAsyncData, &result);
	assert(result == TX_RESULT_OK || result == TX_RESULT_CANCELLED);
}

/*
 * Callback function invoked when the status of the connection to the EyeX Engine has changed.
 */
void TX_CALLCONVENTION OnEngineConnectionStateChanged(TX_CONNECTIONSTATE connectionState, TX_USERPARAM userParam)
{
	switch (connectionState) {
	case TX_CONNECTIONSTATE_CONNECTED: {
			BOOL success;
			printf("The connection state is now CONNECTED (We are connected to the EyeX Engine)\n");
			// commit the snapshot with the global interactor as soon as the connection to the engine is established.
			// (it cannot be done earlier because committing means "send to the engine".)
			success = txCommitSnapshotAsync(g_hGlobalInteractorSnapshot, OnSnapshotCommitted, NULL) == TX_RESULT_OK;
			if (!success) {
				printf("Failed to initialize the data stream.\n");
			}
			else {
				printf("Waiting for gaze data to start streaming...\n");
			}
		}
		break;

	case TX_CONNECTIONSTATE_DISCONNECTED:
		printf("The connection state is now DISCONNECTED (We are disconnected from the EyeX Engine)\n");
		break;

	case TX_CONNECTIONSTATE_TRYINGTOCONNECT:
		printf("The connection state is now TRYINGTOCONNECT (We are trying to connect to the EyeX Engine)\n");
		break;

	case TX_CONNECTIONSTATE_SERVERVERSIONTOOLOW:
		printf("The connection state is now SERVER_VERSION_TOO_LOW: this application requires a more recent version of the EyeX Engine to run.\n");
		break;

	case TX_CONNECTIONSTATE_SERVERVERSIONTOOHIGH:
		printf("The connection state is now SERVER_VERSION_TOO_HIGH: this application requires an older version of the EyeX Engine to run.\n");
		break;
	}
}

/*
 * Handles an event from the Gaze Point data stream.
 */
void OnGazeDataEvent(TX_HANDLE hGazeDataBehavior)
{
	TX_GAZEPOINTDATAEVENTPARAMS eventParams;
	if (txGetGazePointDataEventParams(hGazeDataBehavior, &eventParams) == TX_RESULT_OK) {
		printf("Gaze Data: (%.1f, %.1f) timestamp %.0f ms\n", eventParams.X, eventParams.Y, eventParams.Timestamp);
		gaze = glm::vec2(eventParams.X,eventParams.Y);
		

	} else {
		printf("Failed to interpret gaze data event packet.\n");
	}
}



/*
* Handles an event from the fixation data stream.
*/
void OnFixationDataEvent(TX_HANDLE hFixationDataBehavior)
{
	TX_FIXATIONDATAEVENTPARAMS eventParams;
	TX_FIXATIONDATAEVENTTYPE eventType;
	char* eventDescription;

	if (txGetFixationDataEventParams(hFixationDataBehavior, &eventParams) == TX_RESULT_OK) {
		eventType = eventParams.EventType;

		eventDescription = (eventType == TX_FIXATIONDATAEVENTTYPE_DATA) ? "Data"
			: ((eventType == TX_FIXATIONDATAEVENTTYPE_END) ? "End"
				: "Begin");

		printf("Fixation %s: (%.1f, %.1f) timestamp %.0f ms\n", eventDescription, eventParams.X, eventParams.Y, eventParams.Timestamp);
	}
	else {
		printf("Failed to interpret fixation data event packet.\n");
	}
}


/*
* Callback function invoked when an event has been received from the EyeX Engine.
*/
void TX_CALLCONVENTION HandleEvent(TX_CONSTHANDLE hAsyncData, TX_USERPARAM userParam)
{
	TX_HANDLE hEvent = TX_EMPTY_HANDLE;
	TX_HANDLE hBehavior = TX_EMPTY_HANDLE;

	TX_HANDLE fEvent = TX_EMPTY_HANDLE;
	TX_HANDLE fBehavior = TX_EMPTY_HANDLE;

	txGetAsyncDataContent(hAsyncData, &hEvent);

	// NOTE. Uncomment the following line of code to view the event object. The same function can be used with any interaction object.
	//OutputDebugStringA(txDebugObject(hEvent));

	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_GAZEPOINTDATA) == TX_RESULT_OK) {
		OnGazeDataEvent(hBehavior);
		txReleaseObject(&hBehavior);
	}


	if (txGetEventBehavior(fEvent, &fBehavior, TX_BEHAVIORTYPE_FIXATIONDATA) == TX_RESULT_OK) {
		OnFixationDataEvent(hBehavior);
		txReleaseObject(&hBehavior);
	}

	// NOTE since this is a very simple application with a single interactor and a single data stream, 
	// our event handling code can be very simple too. A more complex application would typically have to 
	// check for multiple behaviors and route events based on interactor IDs.

	txReleaseObject(&hEvent);
}